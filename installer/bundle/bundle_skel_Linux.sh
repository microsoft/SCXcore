#!/bin/sh

#
# Shell Bundle installer package for the SCX project
#

PATH=/usr/bin:/usr/sbin:/bin:/sbin
umask 022

# Can't use something like 'readlink -e $0' because that doesn't work everywhere
# And HP doesn't define $PWD in a sudo environment, so we define our own
case $0 in
    /*|~*)
        SCRIPT_INDIRECT="`dirname $0`"
        ;;
    *)
        PWD="`pwd`"
        SCRIPT_INDIRECT="`dirname $PWD/$0`"
        ;;
esac

SCRIPT_DIR="`(cd \"$SCRIPT_INDIRECT\"; pwd -P)`"
SCRIPT="$SCRIPT_DIR/`basename $0`"
EXTRACT_DIR="`pwd -P`/scxbundle.$$"
DPKG_CONF_QUALS="--force-confold --force-confdef"

# These symbols will get replaced during the bundle creation process.
#
# The OM_PKG symbol should contain something like:
#       scx-1.5.1-115.rhel.6.x64 (script adds .rpm or .deb, as appropriate)
# Note that for non-Linux platforms, this symbol should contain full filename.
#
# PROVIDER_ONLY is normally set to '0'. Set to non-zero if you wish to build a
# version of SCX that is only the provider (no OMI, no bundled packages). This
# essentially provides a "scx-cimprov" type package if just the provider alone
# must be included as part of some other package.

TAR_FILE=<TAR_FILE>
OM_PKG=<OM_PKG>
OMI_PKG=<OMI_PKG>
PROVIDER_ONLY=0

SCRIPT_LEN=<SCRIPT_LEN>
SCRIPT_LEN_PLUS_ONE=<SCRIPT_LEN+1>

# Packages to be installed are collected in this variable and are installed together 
ADD_PKG_QUEUE=

# Packages to be updated are collected in this variable and are updated together 
UPD_PKG_QUEUE=

usage()
{
    echo "usage: $1 [OPTIONS]"
    echo "Options:"
    echo "  --extract              Extract contents and exit."
    echo "  --force                Force upgrade (override version checks)."
    echo "  --install              Install the package from the system."
    echo "  --purge                Uninstall the package and remove all related data."
    echo "  --remove               Uninstall the package from the system."
    echo "  --restart-deps         Reconfigure and restart dependent service"
    echo "  --source-references    Show source code reference hashes."
    echo "  --upgrade              Upgrade the package in the system."
    echo "  --enable-opsmgr        Enable port 1270 for usage with opsmgr."
    echo "  --version              Version of this shell bundle."
    echo "  --version-check        Check versions already installed to see if upgradable"
    echo "                         (Linux platforms only)."
    echo "  --debug                use shell debug mode."
    echo "  -? | --help            shows this usage text."
}

source_references()
{
    cat <<EOF
-- Source code references --
EOF
}

cleanup_and_exit()
{
    # $1: Exit status
    # $2: Non-blank (if we're not to delete bundles), otherwise empty

    if [ -z "$2" -a -d "$EXTRACT_DIR" ]; then
        cd $EXTRACT_DIR/..
        rm -rf $EXTRACT_DIR
    fi

    if [ -n "$1" ]; then
        exit $1
    else
        exit 0
    fi
}

check_version_installable() {
    # POSIX Semantic Version <= Test
    # Exit code 0 is true (i.e. installable).
    # Exit code non-zero means existing version is >= version to install.
    #
    # Parameter:
    #   Installed: "x.y.z.b" (like "4.2.2.135"), for major.minor.patch.build versions
    #   Available: "x.y.z.b" (like "4.2.2.135"), for major.minor.patch.build versions

    if [ $# -ne 2 ]; then
        echo "INTERNAL ERROR: Incorrect number of parameters passed to check_version_installable" >&2
        cleanup_and_exit 1
    fi

    # Current version installed
    local INS_MAJOR=`echo $1 | cut -d. -f1`
    local INS_MINOR=`echo $1 | cut -d. -f2`
    local INS_PATCH=`echo $1 | cut -d. -f3`
    local INS_BUILD=`echo $1 | cut -d. -f4`

    # Available version number
    local AVA_MAJOR=`echo $2 | cut -d. -f1`
    local AVA_MINOR=`echo $2 | cut -d. -f2`
    local AVA_PATCH=`echo $2 | cut -d. -f3`
    local AVA_BUILD=`echo $2 | cut -d. -f4`

    # Check bounds on MAJOR
    if [ $INS_MAJOR -lt $AVA_MAJOR ]; then
        return 0
    elif [ $INS_MAJOR -gt $AVA_MAJOR ]; then
        return 1
    fi

    # MAJOR matched, so check bounds on MINOR
    if [ $INS_MINOR -lt $AVA_MINOR ]; then
        return 0
    elif [ $INS_MINOR -gt $AVA_MINOR ]; then
        return 1
    fi

    # MINOR matched, so check bounds on PATCH
    if [ $INS_PATCH -lt $AVA_PATCH ]; then
        return 0
    elif [ $INS_PATCH -gt $AVA_PATCH ]; then
        return 1
    fi

    # PATCH matched, so check bounds on BUILD
    if [ $INS_BUILD -lt $AVA_BUILD ]; then
        return 0
    elif [ $INS_BUILD -gt $AVA_BUILD ]; then
        return 1
    fi

    # Version available is idential to installed version, so don't install
    return 1
}

getVersionNumber()
{
    # Parse a version number from a string.
    #
    # Parameter 1: string to parse version number string from
    #     (should contain something like mumble-4.2.2.135.universal.x86.tar)
    # Parameter 2: prefix to remove ("mumble-" in above example)

    if [ $# -ne 2 ]; then
        echo "INTERNAL ERROR: Incorrect number of parameters passed to getVersionNumber" >&2
        cleanup_and_exit 1
    fi

    echo $1 | sed -e "s/$2//" -e 's/\.universal\..*//' -e 's/\.x64.*//' -e 's/\.x86.*//' -e 's/-/./'
}

verifyNoInstallationOption()
{
    if [ -n "${installMode}" ]; then
        echo "$0: Conflicting qualifiers, exiting" >&2
        cleanup_and_exit 1
    fi

    return;
}

is_suse11_platform_with_openssl1(){
  if [ -e /etc/SuSE-release ];then
     VERSION=`cat /etc/SuSE-release|grep "VERSION = 11"|awk 'FS=":"{print $3}'`
     if [ ! -z "$VERSION" ];then
        which openssl1>/dev/null 2>&1
        if [ $? -eq 0 -a $VERSION -eq 11 ];then
           return 0
        fi
     fi
  fi
  return 1
}

ulinux_detect_openssl_version() {
    TMPBINDIR=
    # the system OpenSSL version is 0.9.8.  Likewise with OPENSSL_SYSTEM_VERSION_100 and OPENSSL_SYSTEM_VERSION_110
    is_suse11_platform_with_openssl1
    if [ $? -eq 0 ];then
       OPENSSL_SYSTEM_VERSION_FULL=`openssl1 version | awk '{print $2}'`
    else
       OPENSSL_SYSTEM_VERSION_FULL=`openssl version | awk '{print $2}'`
    fi
    OPENSSL_SYSTEM_VERSION_FULL=`openssl version | awk '{print $2}'`
    OPENSSL_SYSTEM_VERSION_100=`echo $OPENSSL_SYSTEM_VERSION_FULL | grep -Eq '^1.0.'; echo $?`
    [ `uname -m` = "x86_64" ] && OPENSSL_SYSTEM_VERSION_110=`echo $OPENSSL_SYSTEM_VERSION_FULL | grep -Eq '^1.1.'; echo $?`
    if [ $OPENSSL_SYSTEM_VERSION_100 = 0 ]; then
        TMPBINDIR=100
    elif [ $OPENSSL_SYSTEM_VERSION_110 = 0 ]; then
        TMPBINDIR=110
    else
        echo "Error: This system does not have a supported version of OpenSSL installed."
        echo "This system's OpenSSL version: $OPENSSL_SYSTEM_VERSION_FULL"
        if [ `uname -m` = "x86_64" ];then
           echo "Supported versions: 1.0.*, 1.1.*"
        else
           echo "Supported versions: 1.0.*"
        fi
        cleanup_and_exit 60
    fi
}

ulinux_detect_installer()
{
    INSTALLER=

    # If DPKG lives here, assume we use that. Otherwise we use RPM.
    type dpkg > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        INSTALLER=DPKG
    else
        INSTALLER=RPM
    fi
}

# $1 - The name of the package to check as to whether it's installed
check_if_pkg_is_installed() {
    if [ "$INSTALLER" = "DPKG" ]
    then
        dpkg -s $1 2> /dev/null | grep Status | grep " installed" 2> /dev/null 1> /dev/null
    else
        rpm -q $1 2> /dev/null 1> /dev/null
    fi
}

# $1 - The filename of the package to be installed
# $2 - The package name of the package to be installed
# Enqueues the package to the queue of packages to be added
pkg_add() {
    pkg_filename=$1
    pkg_name=$2

    echo "----- Installing package: $pkg_name ($pkg_filename) -----"
    ulinux_detect_openssl_version
    pkg_filename=$TMPBINDIR/$pkg_filename

    if [ "$INSTALLER" = "DPKG" ]
    then
        dpkg ${DPKG_CONF_QUALS} --install --refuse-downgrade ${pkg_filename}.deb
        return $?
    else
        rpm --install ${pkg_filename}.rpm
        return $?
    fi
}

# $1 - The package name of the package to be uninstalled
# $2 - Optional parameter. Only used when forcibly removing a package
pkg_rm() {
    echo "----- Removing package: $1 -----"
    if [ "$INSTALLER" = "DPKG" ]
    then
        if [ "$installMode" = "P" ]; then
            dpkg --purge ${1}
        elif [ "$2" = "force" ]; then
            dpkg --remove --force-all ${1}
        else
            dpkg --remove ${1}
        fi
    else
        if [ "$2" = "force" ]; then
            rpm --erase --nodeps ${1}
        else
            rpm --erase ${1}
        fi
    fi
}

# $1 - The filename of the package to be installed
# $2 - The package name of the package to be installed
# $3 - Okay to upgrade the package? (Optional)
pkg_upd() {
    pkg_filename=$1
    pkg_name=$2
    pkg_allowed=$3

    echo "----- Upgrading package: $pkg_name ($pkg_filename) -----"

    if [ -z "${forceFlag}" -a -n "$pkg_allowed" ]; then
        if [ $pkg_allowed -ne 0 ]; then
            echo "Skipping package since existing version >= version available"
            return 0
        fi
    fi

    ulinux_detect_openssl_version
    pkg_filename=$TMPBINDIR/$pkg_filename

    if [ "$INSTALLER" = "DPKG" ]
    then
        [ -z "${forceFlag}" ] && FORCE="--refuse-downgrade" || FORCE=""
        dpkg ${DPKG_CONF_QUALS} --install $FORCE ${pkg_filename}.deb
        return $?
    else
        [ -n "${forceFlag}" ] && FORCE="--force" || FORCE=""
        rpm --upgrade $FORCE ${pkg_filename}.rpm
        return $?
    fi
}

getInstalledVersion()
{
    # Parameter: Package to check if installed
    # Returns: Printable string (version installed or "None")
    if check_if_pkg_is_installed $1; then
        if [ "$INSTALLER" = "DPKG" ]; then
            local version="`dpkg -s $1 2> /dev/null | grep 'Version: '`"
            getVersionNumber "$version" "Version: "
        else
            local version=`rpm -q $1 2> /dev/null`
            getVersionNumber $version ${1}-
        fi
    else
        echo "None"
    fi
}

shouldInstall_omi()
{
    local versionInstalled=`getInstalledVersion omi`
    [ "$versionInstalled" = "None" ] && return 0
    local versionAvailable=`getVersionNumber $OMI_PKG omi-`

    check_version_installable $versionInstalled $versionAvailable
}

shouldInstall_scx()
{
    local versionInstalled=`getInstalledVersion scx`
    [ "$versionInstalled" = "None" ] && return 0
    local versionAvailable=`getVersionNumber $OM_PKG scx-`

    check_version_installable $versionInstalled $versionAvailable
}

remove_and_install()
{
    if [ -f /opt/microsoft/scx/bin/uninstall ]; then
        /opt/microsoft/scx/bin/uninstall R force
    else
        check_if_pkg_is_installed apache-cimprov
        if [ $? -eq 0 ]; then
            pkg_rm apache-cimprov
        fi
        check_if_pkg_is_installed mysql-cimprov
        if [ $? -eq 0 ]; then
            pkg_rm mysql-cimprov
        fi
        pkg_rm scx force
        pkg_rm omi force
    fi
    pkg_add $OMI_PKG omi
    if [ "$?" -ne 0 ]; then
        return 1
    fi
    pkg_add $OM_PKG scx
    if [ "$?" -ne 0 ]; then
        return 1
    fi
    return 0
}
#
# Main script follows
#

set +e

# Validate package and initialize
ulinux_detect_installer

while [ $# -ne 0 ]
do
    case "$1" in
        --extract-script)
            # hidden option, not part of usage
            # echo "  --extract-script FILE  extract the script to FILE."
            head -${SCRIPT_LEN} "${SCRIPT}" > "$2"
            local shouldexit=true
            shift 2
            ;;

        --extract-binary)
            # hidden option, not part of usage
            # echo "  --extract-binary FILE  extract the binary to FILE."
            tail -n +${SCRIPT_LEN_PLUS_ONE} "${SCRIPT}" > "$2"
            local shouldexit=true
            shift 2
            ;;

        --extract)
            verifyNoInstallationOption
            installMode=E
            shift 1
            ;;

        --force)
            forceFlag=true
            shift 1
            ;;

        --install)
            verifyNoInstallationOption
            installMode=I
            shift 1
            ;;

        --purge)
            verifyNoInstallationOption
            installMode=P
            shouldexit=true
            shift 1
            ;;

        --remove)
            verifyNoInstallationOption
            installMode=R
            shouldexit=true
            shift 1
            ;;

        --restart-deps)
            restartDependencies=--restart-deps
            shift 1
            ;;

        --source-references)
            source_references
            cleanup_and_exit 0
            ;;

        --upgrade)
            verifyNoInstallationOption
            installMode=U
            shift 1
            ;;

        --enable-opsmgr)
            if [ ! -f /etc/scxagent-enable-port ]; then
                touch /etc/scxagent-enable-port
            fi
            shift 1
            ;;

        --version)
            echo "Version: `getVersionNumber $OM_PKG scx-`"
            exit 0
            ;;

        --version-check)
            printf '%-15s%-15s%-15s%-15s\n\n' Package Installed Available Install?

            # omi
            versionInstalled=`getInstalledVersion omi`
            versionAvailable=`getVersionNumber $OMI_PKG omi-`
            if shouldInstall_omi; then shouldInstall="Yes"; else shouldInstall="No"; fi
            printf '%-15s%-15s%-15s%-15s\n' omi $versionInstalled $versionAvailable $shouldInstall

            # scx
            versionInstalled=`getInstalledVersion scx`
            versionAvailable=`getVersionNumber $OM_PKG scx-cimprov-`
            if shouldInstall_scx; then shouldInstall="Yes"; else shouldInstall="No"; fi
            printf '%-15s%-15s%-15s%-15s\n' scx $versionInstalled $versionAvailable $shouldInstall

            exit 0
            ;;

        --debug)
            echo "Starting shell debug mode." >&2
            echo "" >&2
            echo "SCRIPT_INDIRECT: $SCRIPT_INDIRECT" >&2
            echo "SCRIPT_DIR:      $SCRIPT_DIR" >&2
            echo "EXTRACT DIR:     $EXTRACT_DIR" >&2
            echo "SCRIPT:          $SCRIPT" >&2
            echo >&2
            set -x
            shift 1
            ;;

        -? | --help)
            usage `basename $0` >&2
            cleanup_and_exit 0
            ;;

        *)
            usage `basename $0` >&2
            cleanup_and_exit 1
            ;;
    esac
done

if [ -z "${installMode}" ]; then
    echo "$0: No options specified, specify --help for help" >&2
    cleanup_and_exit 3
fi

#
# Note: From this point, we're in a temporary directory. This aids in cleanup
# from bundled packages in our package (we just remove the diretory when done).
#

mkdir -p $EXTRACT_DIR
cd $EXTRACT_DIR

# Do we need to remove the package?
if [ "$installMode" = "R" -o "$installMode" = "P" ]
then
    if [ -f /opt/microsoft/scx/bin/uninstall ]; then
        /opt/microsoft/scx/bin/uninstall $installMode
    else
        # This is an old kit.  Let's remove each separate provider package
        for i in /opt/microsoft/*-cimprov; do
            PKG_NAME=`basename $i`
            if [ "$PKG_NAME" != "*-cimprov" ]; then
                echo "Removing ${PKG_NAME} ..."
                pkg_rm ${PKG_NAME}
            fi
        done

        # Now just simply pkg_rm scx (and omi if it has no dependencies)
        pkg_rm scx
        pkg_rm omi
    fi

    if [ "$installMode" = "P" ]
    then
        check_if_pkg_is_installed apache-cimprov
        if [ $? -ne 0 ]; then
            echo "Purging all files in apache provider ..."
            rm -rf /etc/opt/microsoft/apache-cimprov /opt/microsoft/apache-cimprov /var/opt/microsoft/apache-cimprov
        fi
        check_if_pkg_is_installed mysql-cimprov
        if [ $? -ne 0 ]; then
            echo "Purging all files in mysql provider ..."
            rm -rf /etc/opt/microsoft/mysql-cimprov /opt/microsoft/mysql-cimprov /var/opt/microsoft/mysql-cimprov
        fi
        # Remove directories only if scx got removed successfully (Other products might be dependent on scx)
        check_if_pkg_is_installed scx
        if [ $? -ne 0 ]; then
            echo "Purging all files in cross-platform agent ..."
            rm -rf /etc/opt/microsoft/scx /opt/microsoft/scx /var/opt/microsoft/scx
            rmdir /etc/opt/microsoft /opt/microsoft /var/opt/microsoft 1>/dev/null 2>/dev/null
        fi
        # If OMI is not installed, purge its directories as well.
        check_if_pkg_is_installed omi
        if [ $? -ne 0 ]; then
            rm -rf /etc/opt/omi /opt/omi /var/opt/omi
        fi
    fi
fi

if [ -n "${shouldexit}" ]
then
    # when extracting script/tarball don't also install
    cleanup_and_exit 0
fi

#
# Do stuff before extracting the binary here, for example test [ `id -u` -eq 0 ],
# validate space, platform, uninstall a previous version, backup config data, etc...
#

#
# Extract the binary here.
#

echo "Extracting..."
tail -n +${SCRIPT_LEN_PLUS_ONE} "${SCRIPT}" | tar xzf -
STATUS=$?
if [ ${STATUS} -ne 0 ]
then
    echo "Failed: could not extract the install bundle."
    cleanup_and_exit ${STATUS}
fi

#
# Do stuff after extracting the binary here, such as actually installing the package.
#

EXIT_STATUS=0
BUNDLE_EXIT_STATUS=0
OMI_EXIT_STATUS=0
SCX_EXIT_STATUS=0

case "$installMode" in
    E)
        # Files are extracted, so just exit
        cleanup_and_exit 0 "SAVE"
        ;;

    I)
        echo "Installing cross-platform agent ..."

        if [ $PROVIDER_ONLY -eq 0 ]; then
            check_if_pkg_is_installed omi
            if [ $? -eq 0 ]; then
                shouldInstall_omi
                pkg_upd $OMI_PKG omi $?
                OMI_EXIT_STATUS=$?
            else
                pkg_add $OMI_PKG omi
                OMI_EXIT_STATUS=$?
            fi
        fi

        pkg_add $OM_PKG scx
        SCX_EXIT_STATUS=$?

        if [ "${OMI_EXIT_STATUS}" -ne 0 -o "${SCX_EXIT_STATUS}" -ne 0 ]; then
            remove_and_install
            if [ "$?" -ne 0 ]; then
                echo "Install failed"
                cleanup_and_exit 1
            fi
        fi

        if [ $PROVIDER_ONLY -eq 0 ]; then
            # Install bundled providers
            [ -n "${forceFlag}" ] && FORCE="--force" || FORCE=""
            for i in *-oss-test.sh; do
                # If filespec didn't expand, break out of loop
                [ ! -f $i ] && break
                ./$i
                if [ $? -eq 0 ]; then
                    OSS_BUNDLE=`basename $i -oss-test.sh`
                    ./${OSS_BUNDLE}-cimprov-*.sh --install $FORCE $restartDependencies
                    TEMP_STATUS=$?
                    [ $TEMP_STATUS -ne 0 ] && BUNDLE_EXIT_STATUS="$TEMP_STATUS"
                fi
            done
        fi
        ;;

    U)
        echo "Updating cross-platform agent ..."
        if [ $PROVIDER_ONLY -eq 0 ]; then
            shouldInstall_omi
            pkg_upd $OMI_PKG omi $?
            OMI_EXIT_STATUS=$?
        fi

        shouldInstall_scx
        pkg_upd $OM_PKG scx $?
        SCX_EXIT_STATUS=$?

        if [ "${OMI_EXIT_STATUS}" -ne 0 -o "${SCX_EXIT_STATUS}" -ne 0 ]; then
            remove_and_install
            if [ "$?" -ne 0 ]; then
                echo "Upgrade failed"
                cleanup_and_exit 1
            fi
        fi

        if [ $PROVIDER_ONLY -eq 0 ]; then
            # Upgrade bundled providers
            [ -n "${forceFlag}" ] && FORCE="--force" || FORCE=""
            echo "----- Updating bundled packages -----"
            for i in *-oss-test.sh; do
                # If filespec didn't expand, break out of loop
                [ ! -f $i ] && break
                ./$i
                if [ $? -eq 0 ]; then
                    OSS_BUNDLE=`basename $i -oss-test.sh`
                    ./${OSS_BUNDLE}-cimprov-*.sh --upgrade $FORCE $restartDependencies
                    TEMP_STATUS=$?
                    [ $TEMP_STATUS -ne 0 ] && BUNDLE_EXIT_STATUS="$TEMP_STATUS"
                fi
            done
        fi
        ;;

    *)
        echo "$0: Invalid setting of variable \$installMode, exiting" >&2
        cleanup_and_exit 2
esac

# Remove temporary files (now part of cleanup_and_exit) and exit
if [ "$BUNDLE_EXIT_STATUS" -ne 0 ]; then
    cleanup_and_exit 1
else
    cleanup_and_exit 0
fi

#####>>- This must be the last line of this script, followed by a single empty line. -<<#####

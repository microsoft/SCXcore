#!/bin/bash
#
#
# This script will create a bundle file given an existing kit.
#
# See usage for parameters that must be passed to this script.
#
# We expect this script to run from the BUILD directory (i.e. scxcore/build).
# Directory paths are hard-coded for this location.

SOURCE_DIR=`(cd ../installer/bundle; pwd -P)`
INTERMEDIATE_DIR=`(cd ../installer/intermediate; pwd -P)`

# Exit on error

set -e
set -x

usage()
{
    echo "usage: $0 platform directory tar-file scx-package-name omi-package-name [scx-package-name-100 omi-package-name-100]"
    echo "  where"
    echo "    platform is one of: linux, ulinux-r, ulinux-d, aix, hpux, sun"
    echo "    directory is directory path to package file"
    echo "    tar-file is the name of the tar file that contains the following packages"
    echo "    scx-package-name is the name of the scx installation package"
    echo "    omi-package-name is the name of the omi installation package"
    echo "  If ULINUX, the default packages above are for openssl 0.9.8 versions, and below:"
    echo "    scx-package-name-100 is the name of the openssl 1.0.0 scx installation package"
    echo "    omi-package-name-100 is the name of the openssl 1.0.0 omi installation package"
    echo ""
    echo "  If omi-package-name is blank, we assume a 'combined' universal build, agent only."
    echo "  This means: No OMI is bundled, no open-source kits are bundled, we only include the"
    echo "              agent, but built for each of SSL 0.9.8 and SSL 1.0.0, RPM & Debian"
    exit 1
}

# Validate parameters

PLATFORM_TYPE="$1"
if [ -z "$PLATFORM_TYPE" ]; then
    echo "Missing parameter: Platform type" >&2
    echo ""
    usage
    exit 1
fi

case "$PLATFORM_TYPE" in
    Linux_REDHAT|Linux_SUSE|Linux_UBUNTU_D|Linux_ULINUX_R|Linux_ULINUX_D|Linux_ULINUX|AIX|HPUX|SunOS)
	;;

    *)
	echo "Invalid platform type specified: $PLATFORM_TYPE" >&2
	exit 1
esac

if [ -z "$2" ]; then
    echo "Missing parameter: Directory to platform file" >&2
    echo ""
    usage
    exit 1
fi

if [ ! -d "$2" ]; then
    echo "Directory \"$2\" does not exist" >&2
    exit 1
fi

if [ -z "$3" ]; then
    echo "Missing parameter: tar-file" >&2
    echo ""
    usage
    exit 1
fi

if [ -z "$4" ]; then
    echo "Missing parameter: scx-package-name" >&2
    echo ""
    usage
    exit 1
fi

SCX_PACKAGE=`echo $4 | sed -e 's/.rpm$//' -e 's/.deb$//'`

if [ -n "$5" ]; then
    if [ "$PLATFORM_TYPE" = "ulinux-d" ]; then
        # $6 and $7 need to be set for ULINUX
        if [ -z "$6" ]; then
            echo "Missing parameter: scx-package-name-098" >&2
            echo ""
            usage
            exit 1
        fi

        if [ -z "$7" ]; then
            echo "Missing parameter: omi-package-name-100" >&2
            echo ""
            usage
            exit 1
        fi
    fi
    COMBINED_PACKAGE=0
else
    COMBINED_PACKAGE=1
fi

OMI_PACKAGE=`echo $5 | sed -e 's/.rpm$//' -e 's/.deb$//'`

if [ ! -f "$2/$3" ]; then
    echo "Tar file \"$2/$3\" does not exist"
    exit 1
fi

# Determine the output file name
OUTPUT_DIR=`(cd $2; pwd -P)`

# Work from the temporary directory from this point forward

cd $INTERMEDIATE_DIR

# Fetch the bundle skeleton file
cp $SOURCE_DIR/primary.skel .
chmod u+w primary.skel

# Edit the bundle file for hard-coded values
sed -e "s/PLATFORM=<PLATFORM_TYPE>/PLATFORM=$PLATFORM_TYPE/" < primary.skel > primary.$$
mv primary.$$ primary.skel

sed -e "s/TAR_FILE=<TAR_FILE>/TAR_FILE=$3/" primary.skel > primary.$$
mv primary.$$ primary.skel

sed -e "s/OM_PKG=<OM_PKG>/OM_PKG=$SCX_PACKAGE/" primary.skel > primary.$$
mv primary.$$ primary.skel

sed -e "s/OMI_PKG=<OMI_PKG>/OMI_PKG=$OMI_PACKAGE/" primary.skel > primary.$$
mv primary.$$ primary.skel

if [ $COMBINED_PACKAGE -ne 0 ]; then
    sed -e "s/PROVIDER_ONLY=0/PROVIDER_ONLY=1/" < primary.skel > primary.$$
    mv primary.$$ primary.skel
fi


SCRIPT_LEN=`wc -l < primary.skel | sed -e 's/ //g'`
SCRIPT_LEN_PLUS_ONE="$((SCRIPT_LEN + 1))"

sed -e "s/SCRIPT_LEN=<SCRIPT_LEN>/SCRIPT_LEN=${SCRIPT_LEN}/" < primary.skel > primary.$$
mv primary.$$ primary.skel

sed -e "s/SCRIPT_LEN_PLUS_ONE=<SCRIPT_LEN+1>/SCRIPT_LEN_PLUS_ONE=${SCRIPT_LEN_PLUS_ONE}/" < primary.skel > primary.$$
mv primary.$$ primary.skel


# Fetch the kit
cp $OUTPUT_DIR/$3 .

# Build the bundle
case "$PLATFORM_TYPE" in
    Linux_REDHAT|Linux_SUSE|Linux_ULINUX_R)
	BUNDLE_FILE=`echo $3 | sed -e "s/.rpm//" | sed -e "s/.tar//"`.sh
	gzip -c $3 | cat primary.skel - > $BUNDLE_FILE
	;;

    Linux_UBUNTU_D|Linux_ULINUX_D)
	BUNDLE_FILE=`echo $3 | sed -e "s/.deb//" | sed -e "s/.tar//"`.sh
	gzip -c $3 | cat primary.skel - > $BUNDLE_FILE
	;;

    Linux_ULINUX)
        BUNDLE_FILE=${SCX_PACKAGE}.sh
        gzip -c $3 | cat primary.skel - > $BUNDLE_FILE
        ;;

    AIX)
	BUNDLE_FILE=`echo $3 | sed -e "s/.lpp//" | sed -e "s/.tar//"`.sh
	gzip -c $3 | cat primary.skel - > $BUNDLE_FILE
	;;

    HPUX)
	BUNDLE_FILE=`echo $3 | sed -e "s/.depot//" | sed -e "s/.tar//"`.sh
	compress -c $3 | cat primary.skel - > $BUNDLE_FILE
	;;

    SunOS)
	BUNDLE_FILE=`echo $3 | sed -e "s/.pkg//" | sed -e "s/.tar//"`.sh
	compress -c $3 | cat primary.skel - > $BUNDLE_FILE
	;;

    *)
	echo "Invalid platform encoded in variable \$PACKAGE; aborting" >&2
	exit 2
esac

chmod +x $BUNDLE_FILE
rm primary.skel

# Remove the kit and copy the bundle to the kit location
rm $3
mv $BUNDLE_FILE $OUTPUT_DIR/

exit 0

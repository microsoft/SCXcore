#! /bin/bash

#
# Note: FindApacheConfigFile() is found in apache/installer/conf/apache_config.sh!
#       If this function is modified, modify in that file as well!
#

FindApacheConfigFile()
{
    if [ -z "${APACHE_CONF}" -o -z "${CONF_STYLE}" ]; then
        # Source code installation w/default directories
        APACHE_CONF=/usr/local/apache2/conf/httpd.conf
        CONF_STYLE=f
        [ -e "${APACHE_CONF}" ] && return

        # Favor the conf.d-style directories
        APACHE_CONF=/etc/httpd/conf.d
        CONF_STYLE=d
        [ -d "${APACHE_CONF}" ] && return

        # Favor the conf.d-style directories
        APACHE_CONF=/etc/apache2/conf.d
        CONF_STYLE=d
        [ -d "${APACHE_CONF}" ] && return

        # Redhat-type installation
        APACHE_CONF=/etc/httpd/conf/httpd.conf
        CONF_STYLE=f
        [ -e "${APACHE_CONF}" ] && return

        # SuSE-type installation
        APACHE_CONF=/etc/apache2/default-server.conf
        CONF_STYLE=f
        [ -e "${APACHE_CONF}" ] && return

        # Ubuntu-type installation
        APACHE_CONF=/etc/apache2/apache2.conf
        CONF_STYLE=f
        [ -e "${APACHE_CONF}" ] && return

        # Unable to find it, so indicate so
        APACHE_CONF=
        CONF_STYLE=
    fi
}

CheckIfApacheIsInstalled()
{
    # See if the service actually exists

    ISRPM=`(which rpm | grep /rpm | wc -l) 2>/dev/null`
    ISDPKG=`(which dpkg | grep /dpkg | wc -l) 2>/dev/null`

    if [ $ISRPM -eq 1 ]; then
        if [ `(rpm -q httpd | grep httpd- | wc -l) 2>/dev/null` -eq 1 ]; then
            # Found package httpd-*
            return 0
        fi

        if [ `(rpm -q apache2 | grep apache2- | wc -l) 2>/dev/null` -eq 1 ]; then
            # Found package apache2-*
            return 0
        fi
    fi

    if [ $ISDPKG -eq 1 ]; then
        if [ `(dpkg -l apache2 | grep -e '^ii' | wc -l) 2>/dev/null` -eq 1 ]; then
            # Found package apache2-*
            return 0
        fi
    fi

    # Check source

    if [ -e "/usr/local/apache2/conf/httpd.conf" ]; then
        # Found source
        return 0
    fi

    return 1
}

echo "Checking if Apache is installed ..."

# Find the service?

CheckIfApacheIsInstalled
if [ $? -ne 0 ]; then
    echo "  Apache not found, will not install"
    exit 1
fi

# Verify that we can find configuration files

FindApacheConfigFile
if [ -z "${APACHE_CONF}" -o -z "${CONF_STYLE}" ]; then
    echo "  Apache not found, will not install"
    exit 1
fi

echo "  Apache found, Apache agent will be installed"
exit 0

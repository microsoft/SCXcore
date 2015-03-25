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

echo "Checking if Apache is installed ..."

# Find anything?
FindApacheConfigFile
if [ -z "${APACHE_CONF}" -o -z "${CONF_STYLE}" ]; then
    echo "  Apache not found, will not install"
    exit 1
fi

echo "  Apache found, Apache agent will be installed"
exit 0

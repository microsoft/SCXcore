#! /bin/bash

#
# Note: FindClientLibrary() is found in mysql/installer/datafiles/linux.data!
#       If this function is modified, modify in that file as well!
#

FindClientLibrary()
{
    MYSQL_NAME=libmysqlclient.so
    CLIENT_LIBRARY=

    # Note that we do not want to install on a system WITH the client library but
    # without a server installed. While this is technically possible, it is not
    # desirable. Thus, pre-flight known MySQL server installations and refuse to
    # install if it appears that the server location does not exist.

    SERVER_SEARCH_LIST="/var/lib/mysql /usr/local/mysql/data /usr/local/var/mysql /opt/mysql*"
    SERVER_FOUND=0
    for i in ${SERVER_SEARCH_LIST}; do
	if [ -d "$i" ]; then
	    SERVER_FOUND=1
	    break
	fi
    done

    [ "$SERVER_FOUND" -eq 0 ] && return

    # We use a variety of means to find libmysqlclient.so:
    #
    # 1. Via ldd of 'mysql' client program (may not be installed, or may link statically to MySQL)
    # 2. Via ldconfig -p (doesn't work properly on all systems)
    # 3. Search a list of likely directories
    #
    # If, after all that, we don't find it, then CLIENT_LIBRARY is empty, signifying a failure

    MYSQL_PATH=`which mysql`
    [ -n "${MYSQL_PATH}" ] && CLIENT_LIBRARY=`ldd ${MYSQL_PATH} | grep ${MYSQL_NAME} | awk '{print $3}'`

    # Be aware that /sbin/ldconfig may return multiple hits; if so, we'll use the first one
    [ -z "${CLIENT_LIBRARY}" ] && CLIENT_LIBRARY=`/sbin/ldconfig -p | grep ${MYSQL_NAME} | head -1 | awk '{print $NF}'`

    if [ -z "${CLIENT_LIBRARY}" ]; then
        SEARCH_LIST_64="/usr/lib64 /usr/lib64/mysql /lib64 /lib64/mysql /usr/lib/x86_64-linux-gnu"
        SEARCH_LIST_32="/usr/lib /usr/lib/mysql /lib /lib/mysql /usr/lib/*86-linux-gnu /usr/local/mysql/lib"
        # Fix for Debian systems - packages installed in /opt, library built into mysql cli program statically
        SEARCH_LIST_32="$SEARCH_LIST_32 /opt/mysql*/*/lib"

        if [ `uname -m` = "x86_64" ]; then
            SEARCH_LIST="${SEARCH_LIST_64} ${SEARCH_LIST_32}"
        else
            SEARCH_LIST="${SEARCH_LIST_32}"
        fi

        # echo "Searching for ${MYSQL_NAME} in: ${SEARCH_LIST}"
        for i in ${SEARCH_LIST}; do
            # echo "  Checking $i ..."
            if [ -e $i/${MYSQL_NAME} ]; then
                CLIENT_LIBRARY=$i/${MYSQL_NAME}
                break
            fi
        done
    fi
}

echo "Checking if MySQL is installed ..."

# Find anything?
FindClientLibrary
if [ -z "${CLIENT_LIBRARY}" ]; then
    echo "  MySQL not found, will not install"
    exit 1
fi

echo "  MySQL found, MySQL agent will be installed"
exit 0

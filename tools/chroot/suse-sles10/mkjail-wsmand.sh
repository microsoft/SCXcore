#!/bin/bash

#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#

SCX_WSMAND_CHROOT=/var/opt/microsoft/scx/chroot/wsmand

if [ -d ${SCX_WSMAND_CHROOT} ]; then
  echo "Jail already exist in ${SCX_WSMAND_CHROOT}"
  echo ""
  exit 1
fi


execute() {
  echo "*** Executing: $*"
  `$*`
}

function createdir() {
  if [ ! -d $1 ]; then
    echo "*** Creating directory $1"
    mkdir -p $1
  fi
}

function copyfile() {
  while [ "$1" ]; do
    createdir ${SCX_WSMAND_CHROOT}`dirname $1`
    echo "*** Copying file $1 to ${SCX_WSMAND_CHROOT}$1"
    cp $1 ${SCX_WSMAND_CHROOT}$1
    shift
  done
}

function copydir() {
  while [ "$1" ]; do
    if [ -d $1 ]; then
      createdir ${SCX_WSMAND_CHROOT}`dirname $1`
      echo "*** Copying directory $1 to ${SCX_WSMAND_CHROOT}$1"
      cp -R $1 ${SCX_WSMAND_CHROOT}$1
      shift
    else
      echo "*** Not a directory: $1"
    fi
  done
}

function copylink() {
  if [ -h $1 ]; then
    linksource=`ls -l $1 | grep -o -P "[-_+.\w]+$"`
    copyfile `dirname $1`/$linksource
    pushd ${SCX_WSMAND_CHROOT}`dirname $1` >/dev/null 2>&1
    execute ln -s $linksource `basename $1`
    popd >/dev/null
  else
    if [ -f $1 ]; then
      copyfile $1
    fi
  fi
}


# Make devices
createdir ${SCX_WSMAND_CHROOT}/dev
execute mknod -m 666 ${SCX_WSMAND_CHROOT}/dev/null c 1 3
execute mknod -m 444 ${SCX_WSMAND_CHROOT}/dev/random c 1 8
execute mknod -m 444 ${SCX_WSMAND_CHROOT}/dev/urandom c 1 9

# etc
createdir ${SCX_WSMAND_CHROOT}/etc
copyfile /etc/opt/microsoft/scx/conf/openwsman.conf 
copyfile /etc/opt/microsoft/scx/ssl/scx-seclevel1-key.pem /etc/opt/microsoft/scx/ssl/scx-seclevel1.pem
copyfile /etc/passwd /etc/group /etc/shadow /etc/nsswitch.conf
copydir /etc/security
copyfile /etc/pam.d/scx

# PAM
pushd /etc/pam.d > /dev/null 2>&1
pam_includes=`grep -o -P "include\W+[-\w]+" /etc/pam.d/scx | awk '{print $2}' | xargs`
pam_modules=`grep -v -P "^#" /etc/pam.d/scx | grep -o -P "pam_[-\w]+\.so" | xargs`

pam_includedmodules=""
for pam_file in $pam_includes; do
  pam_includedmodules+="`grep -v -P "^#" $pam_file | grep -o -P "pam_[-\w]+\.so" | xargs` "
done

pam_allmodules="`echo \"$pam_modules $pam_includedmodules\" | xargs -n 1 | sort | uniq | xargs`"
popd > /dev/null 2>&1

for pam_file in $pam_allmodules; do
  copyfile /lib/security/$pam_file
done
for pam_file in $pam_includes; do
  copyfile /etc/pam.d/$pam_file
done

# lib
copylink /lib/ld-linux.so.2 
copylink /lib/libaudit.so.0 
copylink /lib/libc.so.6 
copylink /lib/libcrypt.so.1 
copylink /lib/libdl.so.2 
copylink /lib/libgcc_s.so.1 
copylink /lib/libhistory.so.5
copylink /lib/libm.so.6
copylink /lib/libncurses.so.5
copylink /lib/libnsl.so.1
copylink /lib/libnss_compat-2.4.so 
copylink /lib/libnss_compat.so.2 
copylink /lib/libnss_files-2.4.so 
copylink /lib/libnss_files.so.2
copylink /lib/libpam.so.0 
copylink /lib/libpam.so.0.81.5 
copylink /lib/libpam_misc.so.0 
copylink /lib/libpam_misc.so.0.81.2 
copylink /lib/libpamc.so.0 
copylink /lib/libpamc.so.0.81.0
copylink /lib/libpthread.so.0
copylink /lib/libreadline.so.5
copylink /lib/libxcrypt.so.1
copylink /lib/libz.so.1

# opt
copyfile /opt/microsoft/scx/COPYRIGHT
copyfile /opt/microsoft/scx/LICENSE
copyfile /opt/microsoft/scx/bin/openwsmand
copylink /opt/microsoft/scx/lib/libpegclient.so
copylink /opt/microsoft/scx/lib/libpegcommon.so
copylink /opt/microsoft/scx/lib/libwsman.so
copylink /opt/microsoft/scx/lib/libwsman_server.so
copylink /opt/microsoft/scx/lib/openwsman/authenticators/libwsman_pam_auth.so
copylink /opt/microsoft/scx/lib/openwsman/plugins/libwsman_cim_plugin.so

# usr
copylink /usr/lib/libcrack.so.2
copylink /usr/lib/libcrypto.so.0.9.8
copylink /usr/lib/libssl.so.0.9.8
copylink /usr/lib/libstdc++.so.6
copylink /usr/lib/libxml2.so.2

# var
createdir ${SCX_WSMAND_CHROOT}/var/opt/microsoft/scx/log
createdir ${SCX_WSMAND_CHROOT}/var/opt/microsoft/scx/tmp
execute touch ${SCX_WSMAND_CHROOT}/var/opt/microsoft/scx/log/wsmand.log

# create startup script
execute cp `dirname ${SCX_WSMAND_CHROOT}`/scx-wsmand.chroot /etc/init.d/


echo ""
echo "done."
echo ""

exit 0













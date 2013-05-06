# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing classes to create a Linux RPM file
#
# Date:   2007-10-08 10:42:48
#

import os
import scxutil
from installer import Installer
from scriptgenerator import Script

##
# Class containing logic for creating a Linux RPM file
#
class LinuxRPMFile(Installer):
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        Installer.__init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration)
        self.specFileName = os.path.join(self.tempDir, 'scx.spec')
        self.preInstallPath = os.path.join(self.tempDir, "preinstall.sh")
        self.postInstallPath = os.path.join(self.tempDir, "postinstall.sh")
        self.preUninstallPath = os.path.join(self.tempDir, "preuninstall.sh")

    ##
    # Generate the package description files (e.g. prototype file)
    #
    def GeneratePackageDescriptionFiles(self):
        self.GenerateSpecFile()

    ##
    # Generate pre-, post-install scripts and friends
    #
    def GenerateScripts(self):
        #
        # For RPM, we have three control scripts:
        #   preinstall.sh	preInstall object
        #   preuninstall.sh	preUninstall object
        #   postinstall.sh	postInstall object
        #
        # Parameters passed to scripts:
        #
        #   Action	Script		Parameter
        #
        #   Install	preInstall	1
        #		postInstall	1
        #
        #   Upgrade	preInstall	2
        #		postInstall	2
        #		preUninstall	1    (from old kit)
        #
        #   Remove	preUninstall	0
        #

        preInstall = Script(self.preInstallPath, self.configuration)
        preInstall.CallFunction(preInstall.VerifySSLVersion())
        preInstall.WriteLn('if [ $1 -eq 2 ]; then')
        # If this is an upgrade then remove the services.
        preInstall.CallFunction(preInstall.StopOmiService())
        preInstall.CallFunction(preInstall.RemoveOmiService())
        preInstall.CallFunction(preInstall.RemoveLinksForProperSSLVersion())
        preInstall.CallFunction(preInstall.CreateConfBackupTemp())
        preInstall.WriteLn('fi')
        preInstall.WriteLn('exit 0')
        preInstall.Generate()
        
        postInstall = Script(self.postInstallPath, self.configuration)
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.CreateLinksForProperSSLVersion())
        postInstall.CallFunction(postInstall.CreateSoftLinkToSudo())
        postInstall.CallFunction(postInstall.WriteInstallInfo())
        postInstall.CallFunction(postInstall.GenerateCertificate())
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.UnconfigureScxPAM())
        postInstall.CallFunction(postInstall.ConfigurePAM())
        postInstall.WriteLn('if [ $1 -eq 1 ]; then')
        # If this is a fresh install and not an upgrade
        postInstall.CallFunction(postInstall.ConfigureRunas())
        postInstall.WriteLn('fi')
        postInstall.WriteLn('set -e')        
        postInstall.CallFunction(postInstall.HandleConfigFiles())
        postInstall.CallFunction(postInstall.RemoveConfBackupTemp())
        postInstall.CallFunction(postInstall.ConfigureOmiService())
        postInstall.CallFunction(postInstall.StartOmiService())
        postInstall.WriteLn('set +e')
        postInstall.WriteLn('exit 0')
        postInstall.Generate()

        preUninstall = Script(self.preUninstallPath, self.configuration)
        preUninstall.WriteLn('if [ $1 -eq 0 ]; then')
        # If this is a clean uninstall and not part of an upgrade
        preUninstall.CallFunction(preUninstall.StopOmiService())
        preUninstall.CallFunction(preUninstall.RemoveOmiService())
        preUninstall.CallFunction(preUninstall.RemoveConfigFiles())
        preUninstall.CallFunction(preUninstall.UnconfigureScxPAM())
        preUninstall.CallFunction(preUninstall.UnconfigurePAM())
        preUninstall.CallFunction(preUninstall.RemoveAdditionalFiles())
        preUninstall.CallFunction(preUninstall.DeleteSoftLinkToSudo())
        preUninstall.CallFunction(preUninstall.RemoveLinksForProperSSLVersion())
        preUninstall.WriteLn('fi')
        preUninstall.WriteLn('exit 0')
        preUninstall.Generate()

    ##
    # Creates the specification file used for packing.
    #
    def GenerateSpecFile(self):
        specfile = open(self.specFileName, 'w')

        specfile.write('%define __find_requires %{nil}\n')
        specfile.write('%define _use_internal_dependency_generator 0\n')

        if self.configuration['pfdistro'] == 'REDHAT':
            specfile.write('%%define dist el%(DISTNUM)d\n\n' % {'DISTNUM': self.configuration['pfmajor']} )
        elif self.configuration['pfdistro'] == 'SUSE' or self.configuration['pfdistro'] == 'ULINUX':
            # SUSE doesn't appear to have a release standard in their RPMs
            # ULINUX doesn't need a release standard - there aren't multiple releases in same version #
            specfile.write('\n')
        else:
            raise PlatformNotImplementedError(self.configuration['pfdistro'])

        specfile.write('Name: ' + self.configuration['short_name'] + '\n')
        specfile.write('Version: ' + self.configuration['version'] + '\n')

        if self.configuration['pfdistro'] == 'REDHAT':
            specfile.write('Release: ' + self.configuration['release'] + '.%{?dist}\n')
        else:
            specfile.write('Release: ' + self.configuration['release'] + '\n')

        specfile.write('Summary: ' + self.configuration['long_name'] + '\n')
        specfile.write('Group: Applications/System\n')
        specfile.write('License: ' + self.configuration['license'] + '\n')
        specfile.write('Vendor: ' + self.configuration['vendor'] + '\n')
        if self.configuration['pfdistro'] == 'SUSE':
            if self.configuration['pfmajor'] == 11:
            	specfile.write('Requires: glibc >= 2.9-7.18, openssl >= 0.9.8h-30.8, pam >= 1.0.2-17.2\n')
            elif self.configuration['pfmajor'] == 10:
            	specfile.write('Requires: glibc >= 2.4-31.30, openssl >= 0.9.8a-18.15, pam >= 0.99.6.3-28.8\n')
            elif self.configuration['pfmajor'] == 9:
            	specfile.write('Requires: glibc >= 2.3.3-98.28, libstdc++-41 >= 4.1.2, libgcc-41 >= 4.1.2, openssl >= 0.9.7d-15.10, pam >= 0.77-221.1\n')
            else:
                raise PlatformNotImplementedError(self.configuration['pfdistro'] + self.configuration['pfmajor']) 
        elif self.configuration['pfdistro'] == 'REDHAT':
            if self.configuration['pfmajor'] == 6:
                specfile.write('Requires: glibc >= 2.12-1.7, openssl >= 1.0.0-4, pam >= 1.1.1-4\n')
            elif self.configuration['pfmajor'] == 5:
                specfile.write('Requires: glibc >= 2.5-12, openssl >= 0.9.8b-8.3.el5, pam >= 0.99.6.2-3.14.el5\n')
            elif self.configuration['pfmajor'] == 4:
                specfile.write('Requires: glibc >= 2.3.4-2, openssl >= 0.9.7a-43.1, pam >= 0.77-65.1\n')
            else:
                raise PlatformNotImplementedError(self.configuration['pfdistro'] + self.configuration['pfmajor'])
        elif self.configuration['pfdistro'] == 'ULINUX':
            # Dependencies aren't encoded in the RPM - they are determined dynamically in preinstall
            pass
        else:
            raise PlatformNotImplementedError(self.configuration['pfdistro'])
        specfile.write('Provides: cim-server\n')
        specfile.write('Conflicts: %{name} < %{version}-%{release}\n')
        specfile.write('Obsoletes: %{name} < %{version}-%{release}\n')
        specfile.write('%description\n')
        specfile.write(self.configuration['description'] + '\n')
        
        specfile.write('%files\n')

        # Now list all files in staging directory
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'sysdir':
                pass
            else:
                specfile.write('%defattr(' + str(stagingObject.GetPermissions()) + \
                               ',' + stagingObject.GetOwner() + \
                               ',' + stagingObject.GetGroup() + ')\n')
                if stagingObject.GetFileType() == 'dir':
                    specfile.write('%dir /' + stagingObject.GetPath() + '\n')
                elif stagingObject.GetFileType() == 'conffile':
                    specfile.write('%config /' + stagingObject.GetPath() + '\n')
                else:
                    specfile.write('/' + stagingObject.GetPath() + '\n')

        preinstall = open(self.preInstallPath, 'r')
        postinstall = open(self.postInstallPath, 'r')
        preuninstall = open(self.preUninstallPath, 'r')
        specfile.write('%pre\n')
        specfile.write(preinstall.read())
        specfile.write('%post\n')
        specfile.write(postinstall.read())
        specfile.write('%preun\n')
        specfile.write(preuninstall.read())
        

    ##
    # Create the RPM directive file (to refer to our own RPM directory tree)
    #
    def CreateRPMDirectiveFile(self):
        # Create the RPM directory tree

        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/BUILD"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/athlon"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/i386"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/i486"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/i586"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/i686"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/RPMS/noarch"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/SOURCES"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/SPECS"))
        scxutil.MkAllDirs(os.path.join(self.targetDir, "RPM-packages/SRPMS"))

        # Create the RPM directive file

        if os.path.exists(os.path.join(os.path.expanduser('~'), '.rpmmacros')):
            scxutil.Move(os.path.join(os.path.expanduser('~'), '.rpmmacros'),
                         os.path.join(os.path.expanduser('~'), '.rpmmacros.save'))

        rpmfile = open(os.path.join(os.path.expanduser('~'), '.rpmmacros'), 'w')
        rpmfile.write('%%_topdir\t%s\n' % os.path.join(self.targetDir, "RPM-packages"))
        rpmfile.close()

    ##
    # Cleanup RPM directive file
    #
    # (If a prior version of the file exists, retain that)
    #
    def DeleteRPMDirectiveFile(self):
        if os.path.exists(os.path.join(os.path.expanduser('~'), '.rpmmacros.save')):
            scxutil.Move(os.path.join(os.path.expanduser('~'), '.rpmmacros.save'),
                         os.path.join(os.path.expanduser('~'), '.rpmmacros'))
        else:
            os.unlink(os.path.join(os.path.expanduser('~'), '.rpmmacros'))

    ##
    # Actually creates the finished package file.
    #
    def BuildPackage(self):
        # Create the RPM working directory tree
        self.CreateRPMDirectiveFile()

        # Build the RPM. This puts the finished rpm in /usr/src/packages/RPMS/<arch>/
        os.system('rpmbuild --buildroot ' + self.stagingDir.GetRootPath() + ' -bb ' + self.specFileName)
        self.DeleteRPMDirectiveFile()

        # Now we try to find the file so we can copy it to the installer directory.
        # We need to find the build arch of the file:
        fin, fout = os.popen4('rpm -q --specfile --qf "%{arch}\n" ' + self.specFileName)
        arch = fout.read().strip()
        rpmpath = os.path.join(os.path.join(self.targetDir, "RPM-packages/RPMS"), arch)
        if self.configuration['pfdistro'] == 'SUSE':
            rpmNewFileName = 'scx-' + \
                             self.configuration['version'] + '-' + \
                             self.configuration['release'] + '.sles.' + \
                             str(self.configuration['pfmajor']) + '.' + self.configuration['pfarch'] + '.rpm'
        elif self.configuration['pfdistro'] == 'REDHAT':
            rpmNewFileName = 'scx-' + \
                             self.configuration['version'] + '-' + \
                             self.configuration['release'] + '.rhel.' + \
                             str(self.configuration['pfmajor'])  + '.' + self.configuration['pfarch'] + '.rpm'
        elif self.configuration['pfdistro'] == 'ULINUX':
            rpmNewFileName = 'scx-' + \
                             self.configuration['version'] + '-' + \
                             self.configuration['release'] + '.universalr.' + \
                             str(self.configuration['pfmajor'])  + '.' + self.configuration['pfarch'] + '.rpm'
        else:
            raise PlatformNotImplementedError(self.configuration['pfdistro'])

        if self.configuration['pfdistro'] == 'REDHAT':
            # RedHat has a SPEC file that includes distribution
            rpmfilename = self.configuration['short_name'] + '-' + \
                          self.configuration['version'] + '-' + \
                          self.configuration['release'] + '.el%d' % self.configuration['pfmajor'] + \
                          '.' + arch + '.rpm'
        else:
            rpmfilename = self.configuration['short_name'] + '-' + \
                          self.configuration['version'] + '-' + \
                          self.configuration['release'] + '.' + arch + '.rpm'
                         
        
        scxutil.Move(os.path.join(rpmpath, rpmfilename), os.path.join(self.targetDir, rpmNewFileName))
        print "Moved to: " + os.path.join(self.targetDir, rpmNewFileName)


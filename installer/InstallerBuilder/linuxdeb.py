# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing classes to create a Linux Debian file (Ubuntu support)
#
# Date:   2009-03-30
#

import os
import scxutil
from installer import Installer
from scriptgenerator import Script

##
# Class containing logic for creating a Linux DEB file
#
class LinuxDebFile(Installer):
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        Installer.__init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration)

        self.controlDir = os.path.join(self.stagingRootDir, 'DEBIAN')
        self.controlFileName = os.path.join(self.controlDir, 'control')
        self.configFileName = os.path.join(self.controlDir, 'conffiles')
        self.preInstallPath = os.path.join(self.controlDir, 'preinst')
        self.postInstallPath = os.path.join(self.controlDir, 'postinst')
        self.preUninstallPath = os.path.join(self.controlDir, 'prerm')
        self.postUninstallPath = os.path.join(self.controlDir, 'postrm')

    ##
    # Generate the package description files (e.g. prototype file)
    #
    def GeneratePackageDescriptionFiles(self):
        self.GenerateControlFile()

    ##
    # Generate pre-, post-install scripts and friends
    #
    def GenerateScripts(self):
        #
        # On Ubuntu, we have four control scripts:
        #   preinst
        #   postinst
        #   prerm
        #   postrm
        #
        # Parameters passed to scripts:
        #
        #   Action	Script		Parameter
        #
        #   Install	preinst		install
        #		postinst	configure
        #
        #   Upgrade	prerm		upgrade		<version>    (from old kit)
        #		preinst		upgrade		<version>    (from new kit)
        #		postinst	configure	<version>    (from new kit)
        #
        #   Remove	prerm		remove
        #		postrm		remove
        #
        #   Purge	postrm		purge
        #

        # Create the directory (under staging directory) for control files
        scxutil.MkDir(self.controlDir)

        # Configuration file 'preinst' ...
        preInstall = Script(self.preInstallPath, self.configuration)
        preInstall.CallFunction(preInstall.VerifySSLVersion())
        preInstall.CallFunction(preInstall.CreateConfBackupTemp())
        preInstall.WriteLn('exit 0')
        preInstall.Generate()

        # Configuration file 'postinst'
        postInstall = Script(self.postInstallPath, self.configuration)
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.CreateLinksForProperSSLVersion())
        postInstall.CallFunction(postInstall.CreateSoftLinkToSudo())
        postInstall.CallFunction(postInstall.WriteInstallInfo())
        postInstall.CallFunction(postInstall.GenerateCertificate())
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.UnconfigureScxPAM())
        postInstall.CallFunction(postInstall.ConfigurePAM())
        postInstall.CallFunction(postInstall.ConfigureRunas())
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.HandleConfigFiles())
        postInstall.CallFunction(postInstall.RemoveConfBackupTemp())
        postInstall.CallFunction(postInstall.ConfigureOmiService())
        postInstall.CallFunction(postInstall.StartOmiService())
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.RegisterExtProviders())
        postInstall.WriteLn('exit 0')
        postInstall.Generate()

        # Configuration file 'prerm'
        preUninstall = Script(self.preUninstallPath, self.configuration)
        preUninstall.CallFunction(preUninstall.StopOmiService())
        preUninstall.CallFunction(preUninstall.RemoveOmiService())
        preUninstall.CallFunction(preUninstall.RemoveConfigFiles())
        preUninstall.CallFunction(preUninstall.UnconfigureScxPAM())
        preUninstall.CallFunction(preUninstall.UnconfigurePAM())
        preUninstall.CallFunction(preUninstall.RemoveAdditionalFiles())
        preUninstall.CallFunction(preUninstall.DeleteSoftLinkToSudo())
        preUninstall.CallFunction(preUninstall.RemoveLinksForProperSSLVersion())
        preUninstall.WriteLn('exit 0')
        preUninstall.Generate()

        # Configuration file 'postrm' is a placeholder only
        postUninstall = Script(self.postUninstallPath, self.configuration)
        postUninstall.WriteLn('exit 0')
        postUninstall.Generate()

        # Fix up owner/permissions in staging directory
        # (Files are installed on destination as staged)

        for obj in self.stagingDir.GetStagingObjectList():
            if obj.GetFileType() in ['conffile', 'file', 'dir', 'sysdir']:
                filePath = os.path.join(self.stagingRootDir, obj.GetPath())

                # Don't change the staging directory itself
                if obj.GetPath() != '':
                    scxutil.ChOwn(filePath, obj.GetOwner(), obj.GetGroup())
                    scxutil.ChMod(filePath, obj.GetPermissions())
            elif obj.GetFileType() == 'link':
                os.system('sudo chown --no-dereference %s:%s %s' \
                              % (obj.GetOwner(), obj.GetGroup(), filePath))
            else:
                print "Unrecognized type (%s) for object %s" % (obj.GetFileType(), obj.GetPath())

    ##
    # Issues a du -s command to retrieve the total size of our package
    #
    def GetSizeInformation(self):
        pipe = os.popen("du -s " + self.stagingRootDir)

        sizeinfo = 0
        for line in pipe:
            [size, directory] = line.split()
            sizeinfo += int(size)

        return sizeinfo

    ##
    # Creates the control file used for packing.
    #
    def GenerateControlFile(self):
        # Build architecture string:
        #   For x86, the architecture should be: i386
        #   For x64, the architecture should be: amd64

        archType = self.configuration['pfarch']
        if archType == 'x86':
            archType = 'i386'
        elif archType == 'x64':
            archType = 'amd64'

        # Open and write the control file

        controlfile = open(self.controlFileName, 'w')

        controlfile.write('Package:      ' + self.configuration['short_name'] + '\n')
        controlfile.write('Source:       ' + self.configuration['short_name'] + '\n')
        controlfile.write('Version:      ' + self.configuration['version'] + '.' + self.configuration['release'] + '\n')
        controlfile.write('Architecture: %s\n' % archType)
        controlfile.write('Maintainer:   Microsoft Corporation\n')
        controlfile.write('Installed-Size: %d\n' % self.GetSizeInformation())
        controlfile.write('Depends:      libc6 (>= 2.3.6), libpam-runtime (>= 0.79-3)\n')
        controlfile.write('Provides:     ' + self.configuration['short_name'] + '\n')
        controlfile.write('Section:      utils\n')
        controlfile.write('Priority:     optional\n')
        controlfile.write('Description:  ' + self.configuration['long_name'] + '\n')
        controlfile.write(' %s\n' % self.configuration['description'])
        controlfile.write('\n')

        conffile = open(self.configFileName, 'w')

        # Now list all configuration files in staging directory
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'conffile':
                conffile.write(stagingObject.GetPath() + '\n')

    ##
    # Actually creates the finished package file.
    #
    def BuildPackage(self):
        pkgName = 'scx-' + \
            self.configuration['version'] + '-' + \
            self.configuration['release'] + '.universald.' + \
            str(self.configuration['pfmajor'])  + '.' + self.configuration['pfarch'] + '.deb'

        # Build the package - 'cd' to the directory where we want to store result
        os.system('cd ' + self.targetDir + '; dpkg -b ' + self.stagingDir.GetRootPath() + ' ' + pkgName)

        # Undo the permissions settings so we can delete properly
        os.system('sudo chown -R $USER:`id -gn` %s' % self.stagingDir.GetRootPath())

# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing classes to create a Solaris PKG file
#
# Date:   2007-09-26 11:16:44
#

import os
from time import strftime

import scxutil
from installer import Installer
from scriptgenerator import Script

##
# Class containing logic for creating a Solaris PKG file
#
class SunOSPKGFile(Installer):
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        Installer.__init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration)
        self.prototypeFileName = os.path.join(self.tempDir, 'prototype')
        self.pkginfoFile = PKGInfoFile(self.tempDir, self.configuration)
        self.depFileName = os.path.join(self.tempDir, 'depend')
        self.preInstallPath = os.path.join(self.tempDir, "preinstall.sh")
        self.postInstallPath = os.path.join(self.tempDir, "postinstall.sh")
        self.preUninstallPath = os.path.join(self.tempDir, "preuninstall.sh")
        self.postUninstallPath = os.path.join(self.tempDir, "postuninstall.sh")
        self.iConfigFileName = os.path.join(self.tempDir, 'i.config')
        self.rConfigFileName = os.path.join(self.tempDir, 'r.config')

    ##
    # Generate the package description files (e.g. prototype file)
    #
    def GeneratePackageDescriptionFiles(self):
        self.GeneratePrototypeFile()
        self.pkginfoFile.Generate()
        self.GenerateDepFile()

    ##
    # Generate pre-, post-install scripts and friends
    #
    def GenerateScripts(self):
        preInstall = Script(self.preInstallPath, self.configuration)
        preInstall.CallFunction(preInstall.CheckAdditionalDeps())
        preInstall.CallFunction(preInstall.CreateConfBackupTemp())
        preInstall.Generate()

        postInstall = Script(self.postInstallPath, self.configuration)
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.CreateSoftLinkToSudo())
        postInstall.CallFunction(postInstall.WriteInstallInfo())
        if self.configuration['bt'] == 'Bullseye':
            postInstall.WriteLn('COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov' + '\n')
            postInstall.WriteLn('export COVFILE' + '\n')
        if self.configuration['pfmajor'] >= 6 or self.configuration['pfminor'] >= 10:
            # Create soft link without error checking: In zone, we may not have
            # write access to the /usr/sbin/scxadmin directory ...
            postInstall.WriteLn('set +e')
            postInstall.CallFunction(postInstall.CreateLink_usr_sbin_scxadmin())
            postInstall.WriteLn('set -e')
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.UnconfigureScxPAM())
        postInstall.CallFunction(postInstall.ConfigurePAM())
        postInstall.CallFunction(postInstall.ConfigureRunas())
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.HandleConfigFiles())
        postInstall.CallFunction(postInstall.RemoveConfBackupTemp())
        # Generate only after everything else been done (allow manual recovery)
        postInstall.CallFunction(postInstall.GenerateCertificate())
        postInstall.CallFunction(postInstall.ConfigureOmiService())
        postInstall.CallFunction(postInstall.StartOmiService())
        postInstall.WriteLn('exit 0')
        postInstall.Generate()

        preUninstall = Script(self.preUninstallPath, self.configuration)
        preUninstall.CallFunction(preUninstall.StopOmiService())
        preUninstall.CallFunction(preUninstall.RemoveOmiService())
        preUninstall.CallFunction(preUninstall.RemoveConfigFiles())
        preUninstall.CallFunction(preUninstall.UnconfigureScxPAM())
        preUninstall.CallFunction(preUninstall.UnconfigurePAM())
        preUninstall.CallFunction(preUninstall.RemoveAdditionalFiles())
        preUninstall.CallFunction(preUninstall.DeleteSoftLinkToSudo())
        preUninstall.WriteLn('exit 0')
        preUninstall.Generate()

        if self.configuration['pfmajor'] >= 6 or self.configuration['pfminor'] >= 10:
            postUninstall = Script(self.postUninstallPath, self.configuration)
            postUninstall.CallFunction(postUninstall.RemoveLink_usr_sbin_scxadmin())

            if self.configuration['pfmajor'] >= 6 or self.configuration['pfminor'] >= 11:
                # On Solaris 11:
                # Now that the manifest file has been deleted, restart the
                # manifest-import service.  This allows it to see our manifest
                # file (once again) if we reinstall our kit again.
                postUninstall.WriteLn('svcadm restart svc:/system/manifest-import')
                postUninstall.CallFunction(postUninstall.WaitForService(),
                                           'svc:/system/manifest-import')

            postUninstall.WriteLn('exit 0')
            postUninstall.Generate()

        #
        # The i.config script is used to perform the installation
        # of all files tagged as configuration files.
        # A copy of each original file is kept in a special place
        # to make a good choice about what to do in case of a conflict
        # with an existing file
        #
        iConfig = Script(self.iConfigFileName, self.configuration)
        iConfig.WriteLn('error=no')
        iConfig.WriteLn('while read src dest; do')
        iConfig.CallFunction(iConfig.InstallConfigurationFile(), '$src $dest')
        iConfig.WriteLn('if [ $? -ne 0 ]; then')
        iConfig.WriteLn('  error=yes')
        iConfig.WriteLn('fi')
        iConfig.WriteLn('done')
        iConfig.WriteLn('[ \"$error\" = yes ] && exit 2')
        iConfig.WriteLn('exit 0')
        iConfig.Generate()
        
        #
        # The r.config script is used to perform the uninstallation
        # of all files tagged as configuration files.
        # A copy of each original file is kept in a special place
        # to make a good choice about what to do in case the user has
        # changed the file after installation
        #
        rConfig = Script(self.rConfigFileName, self.configuration)
        rConfig.WriteLn('error=no')
        rConfig.WriteLn('while read dest; do')
        rConfig.CallFunction(rConfig.UninstallConfigurationFile(), '$dest')
        rConfig.WriteLn('if [ $? -ne 0 ]; then')
        rConfig.WriteLn('  error=yes')
        rConfig.WriteLn('fi')
        rConfig.WriteLn('done')
        rConfig.WriteLn('[ \"$error\" = yes ] && exit 2')
        rConfig.WriteLn('exit 0')
        rConfig.Generate()

    ##
    # Creates the prototype file used for packing.
    #
    def GeneratePrototypeFile(self):
        prototype = open(self.prototypeFileName, 'w')

        # include the info file
        prototype.write('i pkginfo=' + self.pkginfoFile.GetFileName() + '\n')
        # include depencency file
        prototype.write('i depend=' + self.depFileName + '\n')
        # include the install scripts
        prototype.write('i preinstall=' + self.preInstallPath + '\n')
        prototype.write('i postinstall=' + self.postInstallPath + '\n')
        prototype.write('i preremove=' + self.preUninstallPath + '\n')
        if self.configuration['pfmajor'] >= 6 or self.configuration['pfminor'] >= 10:
            prototype.write('i postremove=' + self.postUninstallPath + '\n')
        prototype.write('i i.config=' + self.iConfigFileName + '\n')
        prototype.write('i r.config=' + self.rConfigFileName + '\n')

        # Now list all files in staging directory
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetPath() != '':
                if stagingObject.GetFileType() == 'dir':
                    prototype.write('d none')
                elif stagingObject.GetFileType() == 'sysdir':
                    # Ignore sysdir - see bug 4065
                    continue
                elif stagingObject.GetFileType() == 'file':
                    prototype.write('f none')
                elif stagingObject.GetFileType() == 'conffile':
                    prototype.write('f config')
                elif stagingObject.GetFileType() == 'link':
                    prototype.write('s none')
                else:
                    pass
                    # ToDo: Error
                prototype.write(' /' + stagingObject.GetPath())

                if stagingObject.GetFileType() == 'link':
                    prototype.write('=' + stagingObject.lnPath + '\n')
                else:
                    prototype.write(' ' + str(stagingObject.GetPermissions()) + \
                                    ' ' + stagingObject.GetOwner() + \
                                    ' ' + stagingObject.GetGroup() + '\n')

    ##
    # Creates the dependency file used for packing.
    #
    def GenerateDepFile(self):
        depfile = open(self.depFileName, 'w')

        # The format of the dependency file is as follows:
        #
        # <type> <pkg>  <name>
        #       [(<arch>)<version>]
        #

        if self.configuration['pfminor'] == 9:
            # We need some core os packages
            depfile.write("P SUNWcsl\tCore Solaris, (Shared Libs)\n")
            depfile.write("P SUNWlibC\tSun Workshop Compilers Bundled libC\n")
            depfile.write("P SUNWlibms\tSun WorkShop Bundled shared libm\n")

            # We need openssl
            depfile.write("P SMCosslg\topenssl\n")
        elif self.configuration['pfminor'] == 10:
            # We need some core os packages
            depfile.write("P SUNWcsr\tCore Solaris, (Root)\n") # This includes PAM
            depfile.write("P SUNWcslr\tCore Solaris Libraries (Root)\n")
            depfile.write("P SUNWcsl\tCore Solaris, (Shared Libs)\n")
            depfile.write("P SUNWlibmsr\tMath & Microtasking Libraries (Root)\n")
            depfile.write("P SUNWlibC\tSun Workshop Compilers Bundled libC\n")
            
            # We need openssl
            depfile.write("P SUNWopenssl-libraries\tOpenSSL Libraries (Usr)\n")
        #elif self.configuration['pfminor'] == 11:
            # Solaris 11 uses a new package manager (Image Packaging System), and all of our dependencies 
            # are installed in it.  For now, do our dependency checks in the preinstall script, but in the
            # long term, we will create an IPS package for Solaris 11 that references IPS dependencies.

    ##
    # Actually creates the finished package file.
    #
    def BuildPackage(self):
        os.system('pkgmk -o' + \
                  ' -r ' + self.stagingDir.GetRootPath() + \
                  ' -f ' + self.prototypeFileName + \
                  ' -d ' + self.tempDir)
        pkgfilename = os.path.join(self.targetDir, 'scx-' + \
                                   self.configuration['version'] + '-' + \
                                   self.configuration['release'] + \
                                   '.solaris.' + str(self.configuration['pfminor']) + '.' + \
                                   self.configuration['pfarch'] + '.pkg')
        os.system('pkgtrans -s ' + self.tempDir + ' ' + pkgfilename + ' ' + 'MSFT' + self.configuration['short_name'])

        # Note: On a "Core System Support" installation, gzip doesn't exist - use compress instead
        os.system('compress -f ' + pkgfilename)


##
# Represents pkg info file used for packing.
#
class PKGInfoFile:
    
    def __init__(self, directory, configuration):
        self.filename = os.path.join(directory, 'pkginfo')
        self.properties = []

        # Required entries
        self.AddProperty('PKG', 'MSFT' + configuration['short_name'])
        self.AddProperty('ARCH', configuration['pfarch'])
        self.AddProperty('CLASSES', 'application config none')
        self.AddProperty('PSTAMP', strftime("%Y%m%d-%H%M"))
        self.AddProperty('NAME', configuration['long_name'])
        self.AddProperty('VERSION', configuration['version'] + "-" + configuration['release'])
        self.AddProperty('CATEGORY', 'system')
        
        # Optional entries:
        self.AddProperty('DESC', configuration['description'])
        self.AddProperty('VENDOR', configuration['vendor'])
        self.AddProperty('SUNW_PKG_ALLZONES', 'false')
        self.AddProperty('SUNW_PKG_HOLLOW', 'false')
        self.AddProperty('SUNW_PKG_THISZONE', 'true')
        
    def AddProperty(self, key, value):
        self.properties.append((key, value))
        
    def Generate(self):
        pkginfo = open(self.filename, 'w')
        for (key, value) in self.properties:
            pkginfo.write(key + '=' + value + '\n')

    def GetFileName(self):
        return self.filename

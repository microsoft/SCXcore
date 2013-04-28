# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing classes to create an AIX package file (lpp)
#
# Date:   2008-03-24 03:15:03
#

import os

import scxutil
from installer import Installer
from scriptgenerator import Script

##
# Class containing logic for creating an AIX package file
#
class AIXLPPFile(Installer):
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        Installer.__init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration)
        self.filesetName = self.configuration['short_name'] + '.rte'
        self.lppNameFileName = os.path.join(self.stagingRootDir, 'lpp_name')
        self.alFileName = os.path.join(self.tempDir, self.filesetName + '.al')
        self.cfgfilesFileName = os.path.join(self.tempDir, self.filesetName + '.cfgfiles')
        self.copyrightFileName = os.path.join(self.tempDir, self.filesetName + '.copyright')
        self.inventoryFileName = os.path.join(self.tempDir, self.filesetName + '.inventory')
        self.sizeFileName = os.path.join(self.tempDir, self.filesetName + '.size')
        self.productidFileName = os.path.join(self.tempDir, 'productid')
        self.liblppFileName = os.path.join(self.stagingRootDir, 'usr/lpp/' + self.filesetName +'/liblpp.a')
        # Need to specify new file names for scripts.
        self.preInstallPath = os.path.join(self.tempDir, self.filesetName + '.pre_i')
        self.postInstallPath = os.path.join(self.tempDir, self.filesetName + '.config')
        self.preUninstallPath = os.path.join(self.tempDir, self.filesetName + '.unconfig')
        self.preUpgradePath = os.path.join(self.tempDir, self.filesetName + '.pre_rm')

    ##
    # Generate the package description files (e.g. prototype file)
    # In the AIX case we generate an lpp_name and a liblpp.a file.
    #
    def GeneratePackageDescriptionFiles(self):
        self.GenerateLppNameFile()
        self.GenerateLiblppFile()
 
    ##
    # Generate pre-, post-install scripts and friends
    #
    def GenerateScripts(self):
        preInstall = Script(self.preInstallPath, self.configuration)
        preInstall.CallFunction(preInstall.CheckAdditionalDeps())
        preInstall.Generate()

        preUpgrade = Script(self.preUpgradePath, self.configuration)
        preUpgrade.CallFunction(preUpgrade.StopOmiService())
        preUpgrade.CallFunction(preUpgrade.RemoveOmiService())
        preUpgrade.CallFunction(preUpgrade.CreateConfBackupTemp())
        preUpgrade.WriteLn('exit 0')
        preUpgrade.Generate()

        postInstall = Script(self.postInstallPath, self.configuration)
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.CreateSoftLinkToSudo())
        postInstall.CallFunction(postInstall.WriteInstallInfo())
        postInstall.CallFunction(postInstall.GenerateCertificate())
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.UnconfigureScxPAM())
        postInstall.CallFunction(postInstall.ConfigurePAM())
        postInstall.WriteLn('if [ \"$INSTALLED_LIST\" = \"\" ]; then')
        # If this is not an upgrade.
        postInstall.CallFunction(postInstall.ConfigureRunas())
        postInstall.WriteLn('fi')
        postInstall.CallFunction(postInstall.HandleConfigFiles())
        postInstall.CallFunction(postInstall.RemoveConfBackupTemp())
        postInstall.CallFunction(postInstall.ConfigureOmiService())
        postInstall.WriteLn('set -e')
        postInstall.CallFunction(postInstall.StartOmiService())
        postInstall.WriteLn('set +e')
        postInstall.CallFunction(postInstall.RegisterExtProviders())
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
        
    ##
    # Generate the lpp_name file
    #
    def GenerateLppNameFile(self):
        specfile = open(self.lppNameFileName, 'w')

        specfile.write('4 R I ' + self.filesetName + ' {\n')
        specfile.write(self.filesetName + ' ' + self.configuration['version'] + '.' + self.configuration['release'] + ' 1 N U en_US ' + self.configuration['long_name'] + '\n')
        specfile.write('[\n')
        # Requisite information would go here.
        if self.configuration['pfmajor'] == 5:
            specfile.write('*prereq openssl.base 0.9.8.4\n')
            specfile.write('*prereq xlC.rte 9.0.0.2\n')
            specfile.write('*prereq xlC.aix50.rte 9.0.0.2\n')
            specfile.write('*prereq bos.rte.libc 5.3.0.65\n')
        elif self.configuration['pfmajor'] == 6:
            specfile.write('*prereq openssl.base 0.9.8.4\n')
            # WI 30583: No need to specify xlC.aix50.rte. Covered by xlC.rte
            # anyway, and xlC.aix50.rte would only normally be on AIX 5.0,
            # not AIX 6.0.
            specfile.write('*prereq xlC.rte 9.0.0.2\n')
            specfile.write('*prereq bos.rte.libc 5.3.0.65\n')
        elif self.configuration['pfmajor'] == 7:
            specfile.write('*prereq openssl.base 0.9.8.1300\n')
            specfile.write('*prereq xlC.rte 11.1.0.1\n')
            specfile.write('*prereq bos.rte.libc 7.1.0.1\n')
        else:
            raise PlatformNotImplementedError(self.configuration['pfmajor'])

        specfile.write('%\n')
        # Now we write the space requirements.
        sizeInfo = self.GetSizeInformation()
        for [directory, size] in sizeInfo:
            specfile.write('/' + directory + ' ' + size + '\n')
        specfile.write('%\n')
        specfile.write('%\n')
        specfile.write('%\n')
        specfile.write(']\n')
        specfile.write('}\n')

    ##
    # Issues a du -s command to retrieve a list of [directory, size] pairs
    #
    def GetSizeInformation(self):
        pipe = os.popen("du -s " + os.path.join(self.stagingRootDir, '*'))

        sizeinfo = []
        for line in pipe:
            [size, directory] = line.split()
            directory = os.path.basename(directory)
            sizeinfo.append([directory, size])

        return sizeinfo

    ##
    # Generates the liblpp.a file.
    #
    def GenerateLiblppFile(self):
        self.GenerateALFile()
        self.GenerateCfgfilesFile()
        self.GenerateCopyrightFile()
        self.GenerateInventoryFile()
        self.GenerateSizeFile()
        self.GenerateProductidFile()

        # Now create a .a archive package
        os.system('ar -vqg ' + self.liblppFileName + ' ' + os.path.join(self.tempDir, '*')) 

    ##
    # Generates the applied list file.
    #
    def GenerateALFile(self):
        alfile = open(self.alFileName, 'w')
        # The lpp_name file should be first.
        alfile.write('./lpp_name\n')
        # Now list everything in the stagingdir except sysdirs.
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'file' or \
                   stagingObject.GetFileType() == 'conffile' or \
                   stagingObject.GetFileType() == 'link' or \
                   stagingObject.GetFileType() == 'dir':
                alfile.write('./' + stagingObject.GetPath() + '\n')

    ##
    # Generates the cfgfiles file.
    #
    def GenerateCfgfilesFile(self):
        cfgfilesfile = open(self.cfgfilesFileName, 'w')

        # Now list all conffiles in the stagingdir.
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'conffile':
                cfgfilesfile.write('./' + stagingObject.GetPath() + ' preserve\n')

    ##
    # Generates the copyright file.
    #
    def GenerateCopyrightFile(self):
        copyrightfile = open(self.copyrightFileName, 'w')

        copyrightfile.write('For copyright and license information please refer to\n/opt/microsoft/scx/COPYRIGHT and /opt/microsoft/scx/LICENSE.\n')
                
    ##
    # Generates the inventory file.
    #
    def GenerateInventoryFile(self):
        inventoryfile = open(self.inventoryFileName, 'w')

        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'sysdir':
                pass
            else:
                inventoryfile.write('/' + stagingObject.GetPath() + ':\n')
                inventoryfile.write('   owner = ' + stagingObject.GetOwner() + '\n')
                inventoryfile.write('   group = ' + stagingObject.GetGroup() + '\n')
                inventoryfile.write('   mode = ' + str(stagingObject.GetPermissions()) + '\n')
                inventoryfile.write('   class = apply,inventory,' + self.filesetName + '\n')
                
                if stagingObject.GetFileType() == 'file' or stagingObject.GetFileType() == 'conffile':
                    inventoryfile.write('   type = FILE\n')
                    inventoryfile.write('   size = \n')
                    inventoryfile.write('   checksum = \n')

                if stagingObject.GetFileType() == 'link':
                    inventoryfile.write('   type = SYMLINK\n')
                    inventoryfile.write('   target = ' + stagingObject.GetTarget() + '\n')

                if stagingObject.GetFileType() == 'dir':
                    inventoryfile.write('   type = DIRECTORY\n')

                inventoryfile.write('\n')

    ##
    # Generate the size file
    #
    def GenerateSizeFile(self):
        sizefile = open(self.sizeFileName, 'w')

        sizeInfo = self.GetSizeInformation()
        for [directory, size] in sizeInfo:
            sizefile.write('/' + directory + ' ' + size + '\n')

    ##
    # Generates the productid file.
    #
    def GenerateProductidFile(self):
        productidfile = open(self.productidFileName, 'w')

        productidfile.write(self.configuration['short_name'] + ',' + self.configuration['version'] + '-' + self.configuration['release'])


    ##
    # Actually creates the finished package file.
    #
    def BuildPackage(self):
        lppfilename = os.path.join(self.targetDir, 'scx-' + \
                                   self.configuration['version'] + '-' + \
                                   self.configuration['release'] + \
                                   '.aix.' + str(self.configuration['pfmajor']) + '.' + \
                                   self.configuration['pfarch'] + '.lpp')
        os.system('cd ' + self.stagingRootDir + \
                  ' && find . | grep -v \"^\\.$\" | backup -ivqf ' + lppfilename)
        os.system('gzip -f ' + lppfilename)



# coding: utf-8

##
# Module containing classes to create a HP-UX package file
#
# Date:   2007-10-12 11:16:44
#

import os

import scxutil
from installer import Installer
from scriptgenerator import Script

##
# Class containing logic for creating a HP-UX package file
#
class HPUXPackageFile(Installer):
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        Installer.__init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration)
        self.specificationFileName = os.path.join(self.tempDir, 'product_specification')
        self.configurePath = os.path.join(self.tempDir, "configure.sh")
        self.unconfigurePath = os.path.join(self.tempDir, "unconfigure.sh")
        self.preinstallPath = os.path.join(self.tempDir, "preinstall.sh")
        self.postremovePath = os.path.join(self.tempDir, "postremove.sh")

    ##
    # Generate the package description files (e.g. prototype file)
    #
    def GeneratePackageDescriptionFiles(self):
        self.GenerateSpecificationFile()
        
    ##
    # Generate pre-, post-install scripts and friends
    #
    def GenerateScripts(self):
        # Stop services if scx is installed
        preinstall = Script(self.preinstallPath, self.configuration)
        preinstall.WriteLn('if [ -f /etc/opt/microsoft/scx/conf/installinfo.txt ]; then')
        # This is an upgrade
        preinstall.CallFunction(preinstall.StopOmiService())
        preinstall.CallFunction(preinstall.RemoveOmiService())
        preinstall.CallFunction(preinstall.RemoveDeletedFiles())
        preinstall.CallFunction(preinstall.CreateConfBackupTemp())
        preinstall.WriteLn('fi')
        # Back up any configuration files that are present at install time.
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'conffile':
                preinstall.CallFunction(preinstall.BackupConfigurationFile(),
                                        '/' + stagingObject.GetPath())

        preinstall.WriteLn('exit 0')
        preinstall.Generate()

        configure = Script(self.configurePath, self.configuration)
        # Restore any configuration files that were present at install time.
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'conffile':
                configure.CallFunction(configure.RestoreConfigurationFile(),
                                       '/' + stagingObject.GetPath())
        configure.WriteLn('set -e')
        configure.CallFunction(configure.CreateSoftLinkToSudo())
        configure.CallFunction(configure.WriteInstallInfo())
        configure.CallFunction(configure.GenerateCertificate())
        configure.WriteLn('set +e')
        configure.CallFunction(configure.UnconfigureScxPAM())
        configure.CallFunction(configure.ConfigurePAM())
        configure.CallFunction(configure.ConfigureRunas())
        configure.CallFunction(configure.HandleConfigFiles())
        configure.CallFunction(configure.RemoveConfBackupTemp())
        configure.CallFunction(configure.ConfigureOmiService())
        configure.WriteLn('set -e')
        configure.CallFunction(configure.StartOmiService())
        configure.WriteLn('set +e')
        configure.WriteLn('exit 0')
        configure.Generate()

        unconfigure = Script(self.unconfigurePath, self.configuration)
        unconfigure.CallFunction(unconfigure.StopOmiService())
        unconfigure.CallFunction(unconfigure.RemoveOmiService())
        unconfigure.CallFunction(unconfigure.RemoveConfigFiles())
        unconfigure.CallFunction(unconfigure.UnconfigureScxPAM())
        unconfigure.CallFunction(unconfigure.UnconfigurePAM())
        unconfigure.CallFunction(unconfigure.RemoveAdditionalFiles())
        unconfigure.WriteLn('exit 0')
        unconfigure.Generate()

        postremove = Script(self.postremovePath, self.configuration)
        postremove.CallFunction(postremove.DeleteSoftLinkToSudo())
        postremove.CallFunction(postremove.RemoveEmptyDirectoryRecursive(), '/opt/microsoft')
        postremove.CallFunction(postremove.RemoveEmptyDirectoryRecursive(), '/etc/opt/microsoft')
        postremove.CallFunction(postremove.RemoveEmptyDirectoryRecursive(), '/var/opt/microsoft')
        postremove.WriteLn('exit 0')
        postremove.Generate()
        
    ##
    # Creates the prototype file used for packing.
    #
    def GenerateSpecificationFile(self):
        specfile = open(self.specificationFileName, 'w')

        specfile.write('depot\n')
        specfile.write('  layout_version   1.0\n')
        specfile.write('\n')
        specfile.write('# Vendor definition:\n')
        specfile.write('vendor\n')
        specfile.write('  tag           MSFT\n')
        specfile.write('  title         ' + self.configuration['vendor'] + '\n')
        specfile.write('category\n')
        specfile.write('  tag           scx\n')
        specfile.write('  revision      ' + self.configuration['version'] + \
                       '-' + self.configuration['release'] + '\n')
        specfile.write('end\n')
        specfile.write('\n')
        specfile.write('# Product definition:\n')
        specfile.write('product\n')
        specfile.write('  tag            scx\n')
        specfile.write('  revision       ' + self.configuration['version']  + \
                       '-' + self.configuration['release'] + '\n')
        specfile.write('  architecture   HP-UX_B.11.00_32/64\n')
        specfile.write('  vendor_tag     MSFT\n')
        specfile.write('\n')
        specfile.write('  title          ' + self.configuration['short_name'] + '\n')
        specfile.write('  number         ' + self.configuration['release'] + '\n')
        specfile.write('  category_tag   scx\n')
        specfile.write('\n')
        specfile.write('  description    ' + self.configuration['description'] + '\n')
        specfile.write('  copyright      Copyright (c) Microsoft Corporation.  All rights reserved.')
        specfile.write('\n')
        if self.configuration['pfarch'] == 'ia64':
            specfile.write('  machine_type   ia64*\n')
        else:
            specfile.write('  machine_type   9000*\n')
        specfile.write('  os_name        HP-UX\n')
        specfile.write('  os_release     ?.11.*\n')
        specfile.write('  os_version     ?\n')
        specfile.write('\n')
        specfile.write('  directory      /\n')
        specfile.write('  is_locatable   false\n')
        specfile.write('\n')
        specfile.write('  # Fileset definitions:\n')
        specfile.write('  fileset\n')
        specfile.write('    tag          core\n')
        specfile.write('    title        scx Core\n')
        specfile.write('    revision     ' + self.configuration['version'] + \
                       '-' + self.configuration['release'] + '\n')
        specfile.write('\n')
        specfile.write('    # Dependencies\n')
        # Require a late version of ssl 0.9.7 or a late version of 0.9.8.
        specfile.write('    prerequisites openssl.OPENSSL-LIB,r>=A.00.09.07l.003,r<A.00.09.08 | openssl.OPENSSL-LIB,r>=A.00.09.08d.002\n')

        specfile.write('\n')
        specfile.write('    # Control files:\n')
        specfile.write('    configure     ' + self.configurePath + '\n')
        specfile.write('    unconfigure   ' + self.unconfigurePath + '\n')
        specfile.write('    preinstall    ' + self.preinstallPath + '\n')
        specfile.write('    postremove    ' + self.postremovePath + '\n')
        specfile.write('\n')
        specfile.write('    # Files:\n')

        # Now list all files in staging directory
        for stagingObject in self.stagingDir.GetStagingObjectList():
            if stagingObject.GetFileType() == 'file' or \
                   stagingObject.GetFileType() == 'conffile' or \
                   stagingObject.GetFileType() == 'link' or \
                   stagingObject.GetFileType() == 'dir':
                specfile.write('    file -m ' + str(stagingObject.GetPermissions()) + \
                               ' -o ' + stagingObject.GetOwner() + \
                               ' -g ' + stagingObject.GetGroup() + \
                               ' ' + os.path.join(stagingObject.rootDir, stagingObject.GetPath()) + \
                               ' /' + stagingObject.GetPath() + '\n')


        specfile.write('\n')
        specfile.write('  end # core\n')
        specfile.write('\n')
        specfile.write('end  # SD\n')

    ##
    # Actually creates the finished package file.
    #
    def BuildPackage(self):
        if self.configuration['pfminor'] < 30:
            osversion = '11iv2'
        else:
            osversion = '11iv3'
        if self.configuration['pfarch'] == 'pa-risc':
            arch = 'parisc'
        else:
            arch = self.configuration['pfarch']

        depotfilename = os.path.join(self.targetDir, 'scx-' + \
                                     self.configuration['version'] + '-' + \
                                     self.configuration['release'] + \
                                     '.hpux.' + osversion + '.' + arch + '.depot')
        os.system('/usr/sbin/swpackage -s ' + os.path.join(self.tempDir, self.specificationFileName) + ' -x run_as_superuser=false -x admin_directory=' + self.intermediateDir + ' -x media_type=tape @ ' + depotfilename)
        os.system('compress -f ' + depotfilename)
        


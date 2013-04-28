# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing base classes to create an installer
#
# Date:   2007-09-26 15:55:44
#

import os
import scxutil
from stagingdir import StagingDir
from scriptgenerator import Script
import scxexceptions

##
# Class containing generic logic for creating a package file
#
class Installer:
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory.
    # \param[in] targetDir Absolute path to target directory.
    # \param[in] installerDir Absolute path to installer directory.
    # \param[in] configuration Configuration map.
    #
    def __init__(self, srcDir, targetDir, installerDir, intermediateDir, configuration):
        self.srcDir = srcDir
        self.targetDir = targetDir
        self.installerDir = installerDir
        self.intermediateDir = intermediateDir
        self.tempDir = os.path.join(installerDir, 'intermediate')
        self.stagingRootDir = os.path.join(self.targetDir, 'staging')
        self.configuration = configuration

    ##
    # Go through all steps to generate the installer package.
    #
    def Generate(self):
        self.GenerateFiles()
        self.GenerateStagingDir()
        self.ClearTempDir()
        self.GenerateScripts()
        self.GeneratePackageDescriptionFiles()
        self.BuildPackage()

    ##
    # Generate and populate the staging directory.
    #
    def GenerateStagingDir(self):
        if not os.path.isdir(self.stagingRootDir):
            scxutil.MkAllDirs(self.stagingRootDir)

        self.stagingDir = StagingDir(self.srcDir,
                                     self.targetDir,
                                     self.installerDir,
                                     self.intermediateDir,
                                     self.stagingRootDir,
                                     self.configuration)


    ##
    # Clears the temp directory.
    #
    def ClearTempDir(self):
        scxutil.RmTree(self.tempDir)
        scxutil.MkAllDirs(self.tempDir)

    ##
    # Generate setup script for bin directory
    #
    def GenerateSetupScriptFile(self):
        shfile = open(os.path.join(self.intermediateDir, 'scx_setup.sh'), 'w')
        shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n')
        # Configure script to not complain if environment variable isn't currently set
        shfile.write('set +u\n')
        if self.configuration['pf'] == 'MacOS':
            shfile.write('PATH=/usr/libexec/microsoft/scx/bin:$PATH' + '\n')
        else:
            shfile.write('PATH=/opt/microsoft/scx/bin:$PATH' + '\n')
        shfile.write('export PATH' + '\n')
        if self.configuration['pf'] == 'MacOS':
            shfile.write('DYLD_LIBRARY_PATH=/usr/libexec/microsoft/scx/lib:$DYLD_LIBRARY_PATH' + '\n')
            shfile.write('export DYLD_LIBRARY_PATH' + '\n')
        elif self.configuration['pf'] == 'HPUX' and self.configuration['pfarch'] == "pa-risc":
            shfile.write('SHLIB_PATH=/opt/microsoft/scx/lib:$SHLIB_PATH' + '\n')
            shfile.write('export SHLIB_PATH' + '\n')
        elif self.configuration['pf'] == "SunOS" and self.configuration['pfmajor'] == 5 and self.configuration['pfminor'] <= 9:
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:/usr/local/ssl/lib:$LD_LIBRARY_PATH' + '\n')
            shfile.write('export LD_LIBRARY_PATH' + '\n')
        elif self.configuration['pf'] == "AIX":
            shfile.write('LIBPATH=/opt/microsoft/scx/lib:$LIBPATH\n')
            shfile.write('export LIBPATH\n')
# Since AIX searches LIBPATH first, it is questionable whether we need to define LD_LIBRARY_PATH also, but 
# in the interests of avoiding side effects of code that looks for it, we will set it here.
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
            shfile.write('export LD_LIBRARY_PATH\n')
        else:
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
            shfile.write('export LD_LIBRARY_PATH' + '\n')
        if self.configuration['bt'] == 'Bullseye':
            shfile.write('COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov' + '\n')
            shfile.write('export COVFILE' + '\n')
       
    ##
    # Generate setup script for tools directory
    #
    def GenerateToolsSetupScriptFile(self):
        shfile = open(os.path.join(self.intermediateDir, 'scx_setup_tools.sh'), 'w')
        shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n')
        # Configure script to not complain if environment variable isn't currently set
        shfile.write('set +u\n')
        if self.configuration['pf'] == 'MacOS':
            shfile.write('PATH=/usr/libexec/microsoft/scx/bin/tools:$PATH' + '\n')
        else:
            shfile.write('PATH=/opt/microsoft/scx/bin/tools:$PATH' + '\n')
        shfile.write('export PATH' + '\n')
        if self.configuration['pf'] == 'MacOS':
            shfile.write('DYLD_LIBRARY_PATH=/usr/libexec/microsoft/scx/lib:$DYLD_LIBRARY_PATH' + '\n')
            shfile.write('export DYLD_LIBRARY_PATH' + '\n')
        elif self.configuration['pf'] == 'HPUX' and self.configuration['pfarch'] == "pa-risc":
            shfile.write('SHLIB_PATH=/opt/microsoft/scx/lib:$SHLIB_PATH' + '\n')
            shfile.write('export SHLIB_PATH' + '\n')
        elif self.configuration['pf'] == "SunOS" and self.configuration['pfmajor'] == 5 and self.configuration['pfminor'] <= 9:
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:/usr/local/ssl/lib:$LD_LIBRARY_PATH' + '\n')
            shfile.write('export LD_LIBRARY_PATH' + '\n')
        elif self.configuration['pf'] == 'AIX':
            shfile.write('LIBPATH=/opt/microsoft/scx/lib:$LIBPATH\n')
            shfile.write('export LIBPATH' + '\n')
# Since AIX searches LIBPATH first, it is questionable whether we need to define LD_LIBRARY_PATH also, but 
# in the interests of avoiding side effects of code that looks for it, we will set it here.
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH\n')
            shfile.write('export LD_LIBRARY_PATH\n')
        else:
            shfile.write('LD_LIBRARY_PATH=/opt/microsoft/scx/lib:$LD_LIBRARY_PATH' + '\n')
            shfile.write('export LD_LIBRARY_PATH' + '\n')
        if self.configuration['bt'] == 'Bullseye':
            shfile.write('COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov' + '\n')
            shfile.write('export COVFILE' + '\n')
 
    ##
    # Generate script to easily run the SCX admin tool
    #
    def GenerateAdminToolScriptFile(self):
        shfile = open(os.path.join(self.intermediateDir, 'scxadmin.sh'), 'w')
        shfile.write( scxutil.Get_sh_path(self) );
        shfile.write( '\n\n' );
        shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n\n')

        if self.configuration['pf'] == 'MacOS':
            scxpath = "/usr/libexec"
        else:
            scxpath = "/opt"

        shfile.write('. ' + scxpath + '/microsoft/scx/bin/tools/setup.sh\n')
        shfile.write('exec ' + scxpath + '/microsoft/scx/bin/tools/.scxadmin "$@"\n')

    ##
    # Generate script to easily run the SCX ssl configuration tool
    #
    def GenerateSSLToolScriptFile(self):
        shfile = open(os.path.join(self.intermediateDir, 'scxsslconfig.sh'), 'w')
        shfile.write( scxutil.Get_sh_path(self) );
        shfile.write( '\n\n' );
        shfile.write('# Copyright (c) Microsoft Corporation.  All rights reserved.\n\n')

        if self.configuration['pf'] == 'MacOS':
            scxpath = "/usr/libexec"
        else:
            scxpath = "/opt"

        shfile.write('. ' + scxpath + '/microsoft/scx/bin/tools/setup.sh\n')
        shfile.write('exec ' + scxpath + '/microsoft/scx/bin/tools/.scxsslconfig "$@"\n')

    ##
    # Generate files needed by installation
    #
    def GenerateFiles(self):
        self.GenerateSetupScriptFile()
        self.GenerateToolsSetupScriptFile()
        self.GenerateAdminToolScriptFile()
        self.GenerateSSLToolScriptFile()

    ##
    # Generate the package description files (e.g. prototype file)
    #
    def GeneratePackageDescriptionFiles(self):
        raise PlatformNotImplementedError("")

    ##
    # Create the actuall installer package.
    #
    def BuildPackage(self):
        raise PlatformNotImplementedError("")
        

# coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Module containing classes to populate a staging directory
#
# Date:   2007-09-25 13:45:34
#

import filegenerator
import scxutil
from os import path

##
# Class containing logic for creating the staging directory
# structure.
#
class StagingDir:
    ##
    # Ctor.
    # \param[in] srcDir Absolute path to source directory root.
    # \param[in] targetDir Absolute path to target directory (including platform string).
    # \param[in] installerDir Absolute path to installer directory root.
    # \param[in] stagingDir Absolute path to staging directory root.
    #
    def __init__(self,
                 srcDir,
                 targetDir,
                 installerDir,
                 intermediateDir,
                 stagingDir,
                 configuration):

        self.srcDir = srcDir
        self.targetDir = targetDir
        self.installerDir = installerDir
        self.intermediateDir = intermediateDir
        self.stagingDir = stagingDir
        self.configuration = configuration

        self.sharedLibrarySuffix = 'so'
        if self.configuration['pf'] == 'HPUX' and self.configuration['pfarch'] == "pa-risc":
            self.sharedLibrarySuffix = 'sl'
        elif self.configuration['pf'] == 'MacOS':
            self.sharedLibrarySuffix = 'dylib'

        # Where is /etc, /opt, and /var?
        if self.configuration['pf'] == 'MacOS':
            self.etcRoot = 'private/etc'
            self.optRoot = 'usr/libexec'
            self.varRoot = 'private/var'
        else:
            self.etcRoot = 'etc'
            self.optRoot = 'opt'
            self.varRoot = 'var'

            if self.configuration['pfdistro'] == 'ULINUX':
                if self.configuration['pfarch'] == "x86":
                    self.usrlibRoot = '/usr/lib'
                else:
                    self.usrlibRoot = '/usr/lib64'

        # Name of group with id 0
        self.rootGroupName = 'root'
        if self.configuration['pf'] == 'AIX':
            self.rootGroupName = 'system'
        elif self.configuration['pf'] == 'MacOS':
            self.rootGroupName = 'wheel'

        if self.configuration['pfdistro'] == 'ULINUX':
            # SSL-specific directories
            self.sslDirectoryList = [ '_openssl_0.9.8/', '_openssl_1.0.0/' ];
        else:
            self.sslDirectoryList = [ '/' ];

        scxutil.RmTree(self.stagingDir)

        self.CreateStagingObjectList()
        self.DoGenerate()

    ##
    # Creates a file map mapping destination path to source path
    #
    def CreateStagingObjectList(self):

        stagingDirectories = [
            filegenerator.NewDirectory('',                                               700, 'root', self.rootGroupName,'sysdir'),
            ]

        # For MacOS, create /private (/private/etc, and /private/var)
        if self.configuration['pf'] == 'MacOS':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory('private',                                    755, 'root', self.rootGroupName, 'sysdir')
            ]

        stagingDirectories = stagingDirectories + [
            filegenerator.NewDirectory('usr',                                            755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory('usr/sbin',                                       755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.optRoot,                                     755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.etcRoot,                                     755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.etcRoot + '/opt',                            755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.varRoot,                                     755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.varRoot + '/opt',                            755, 'root', self.rootGroupName, 'sysdir'),
            filegenerator.NewDirectory(self.optRoot + '/microsoft',                      755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.optRoot + '/microsoft/scx',                  755, 'root', self.rootGroupName)
            ]

        if self.configuration['pfdistro'] != 'ULINUX':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin',              755, 'root', self.rootGroupName)
                ]
        else:
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin_openssl_0.9.8', 755, 'root', self.rootGroupName),
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin_openssl_1.0.0', 755, 'root', self.rootGroupName)
                ]

        # Create an empty scxUninstall.sh script for now (bit of a chicken and egg thing)
        # The contents of this file will be filled in later on (after files are staged)
        # Note: Do this as early as possible so scxUninstall.sh is deleted near the very end!
        if self.configuration['pf'] == 'MacOS':
            stagingDirectories = stagingDirectories + [
                filegenerator.EmptyFile(self.optRoot + '/microsoft/scx/bin/scxUninstall.sh',
                                    744, 'root', self.rootGroupName)
                ]

        if self.configuration['pfdistro'] != 'ULINUX':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin/tools', 755, 'root', self.rootGroupName)
                ]
        else:
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin_openssl_0.9.8/tools', 755, 'root', self.rootGroupName),
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/bin_openssl_1.0.0/tools', 755, 'root', self.rootGroupName)
                ]
        
        if self.configuration['pfdistro'] != 'ULINUX':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/lib',              755, 'root', self.rootGroupName)
                ]
        else:
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/lib_openssl_0.9.8', 755, 'root', self.rootGroupName),
                filegenerator.NewDirectory(self.optRoot + '/microsoft/scx/lib_openssl_1.0.0', 755, 'root', self.rootGroupName)
                ]

        stagingDirectories = stagingDirectories + [
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft',                                755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx',                            755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/conf',                       755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/conf/.baseconf',             755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/conf/omiregister' ,          755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/conf/omiregister/root-omi' , 755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/conf/omiregister/root-scx',  755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.etcRoot + '/opt/microsoft/scx/ssl',                        755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft',                                755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx',                            755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/log',                        755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/lib',                        755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/lib/state',                  755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/run',                        755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/tmp',                        755, 'root', self.rootGroupName),
            filegenerator.NewDirectory(self.varRoot + '/opt/microsoft/scx/omiauth',                    755, 'root', self.rootGroupName),
            ]


        # MacOS doesn't have /etc/init.d
        if self.configuration['pf'] != 'MacOS':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory(self.etcRoot + '/init.d',                     755, 'root', 'sys', 'sysdir')
                ]


        if self.configuration['pf'] == 'SunOS':
            if self.configuration['pfmajor'] == 5 and self.configuration['pfminor'] < 10:
                stagingDirectories = stagingDirectories + [
                    filegenerator.NewDirectory(self.etcRoot + '/rc2.d',  755, 'root', 'bin', 'sysdir')
                ]
            else:
                stagingDirectories = stagingDirectories + [
                    filegenerator.NewDirectory('var/svc/',                                   755, 'root', 'sys', 'sysdir'),
                    filegenerator.NewDirectory('var/svc/manifest',                           755, 'root', 'sys', 'sysdir'),
                    filegenerator.NewDirectory('var/svc/manifest/application',               755, 'root', 'sys', 'sysdir'),
                    filegenerator.NewDirectory('var/svc/manifest/application/management',    755, 'root', 'sys', 'sysdir')
                    ]
        elif self.configuration['pf'] == 'HPUX':
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory('var/log',                                    755, 'root', 'sys', 'sysdir'),
                filegenerator.NewDirectory('sbin',                                       755, 'root', 'bin', 'sysdir'),
                filegenerator.NewDirectory('sbin/init.d',                                755, 'root', 'bin', 'sysdir'),
                filegenerator.NewDirectory('sbin/rc1.d',                                 755, 'root', 'bin', 'sysdir'),
                filegenerator.NewDirectory('sbin/rc2.d',                                 755, 'root', 'bin', 'sysdir')
                ]
        elif self.configuration['pf'] == 'AIX':
            # These directories are actually only needed for the package format itself.
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory('usr/lpp',                                    755, 'root', self.rootGroupName, 'sysdir'),
                filegenerator.NewDirectory('usr/lpp/scx.rte',                            755, 'root', self.rootGroupName)
                ]
        elif self.configuration['pf'] == 'MacOS':
            # These directories are needed for the launchd startup scripts
            stagingDirectories = stagingDirectories + [
                filegenerator.NewDirectory('Library',                                    775, 'root', 'admin', 'sysdir'),
                filegenerator.NewDirectory('Library/LaunchDaemons',                      755, 'root', self.rootGroupName, 'sysdir')
                ]

        installerStagingFiles = [
            ###################################################################
            # ToDo: By mucking with ./configure, can we make these empty files?
            ###################################################################
            filegenerator.FileCopy(self.etcRoot + '/opt/microsoft/scx/conf/.baseconf/omiserver.backup',
                                   'conf/omi/omiserver.conf',
                                   444, 'root', 'sys'),
            filegenerator.FileCopy(self.etcRoot + '/opt/microsoft/scx/conf/omicli.conf',
                                   'conf/omi/omicli.conf',
                                   444, 'root', 'sys')
            ]

        # For service start on solaris
        if self.configuration['pf'] == 'SunOS':
            if self.configuration['pfmajor'] == 5 and self.configuration['pfminor'] < 10:
                cimdTemplate = filegenerator.FileTemplate(self.etcRoot + '/init.d/scx-cimd',
                                                          'conf/init.d/scx-cimd.sun8',
                                                          744, 'root', self.rootGroupName)
                installerStagingFiles = installerStagingFiles + [
                    cimdTemplate,
                    filegenerator.SoftLink('etc/rc2.d/S999scx-cimd',
                                          '../init.d/scx-cimd',
                                           744, 'root', self.rootGroupName),
                    ]
            else:
                cimdTemplate = filegenerator.FileTemplate('opt/microsoft/scx/bin/tools/scx-cimd',
                                                          'conf/svc-method/scx-cimd',
                                                          555, 'root', 'bin')
                installerStagingFiles = installerStagingFiles + [
                    cimdTemplate,
                    filegenerator.FileCopy('var/svc/manifest/application/management/scx-cimd.xml',
                                           'conf/svc-manifest/scx-cimd.xml',
                                           444, 'root', 'sys')
                    ]


            if self.configuration['bt']  == 'Bullseye':
                cimdTemplate.AddRule('#TEMPLATE_CODEVOV_ENV#',
                                     ['COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov',
                                      'export COVFILE'])
            else:
                cimdTemplate.AddRule('#TEMPLATE_CODEVOV_ENV#', '')
        # For service start on linux
        elif self.configuration['pf'] == 'Linux' and self.configuration['pfdistro'] == 'SUSE':
            installerStagingFiles = installerStagingFiles + [
                filegenerator.FileCopy(self.etcRoot + '/init.d/scx-cimd',
                                       'conf/init.d/scx-cimd.sles',
                                       744, 'root', self.rootGroupName)
                ]
        elif self.configuration['pf'] == 'Linux' and self.configuration['pfdistro'] == 'REDHAT':
            cimdTemplate = filegenerator.FileTemplate(self.etcRoot + '/init.d/scx-cimd',
                                                      'conf/init.d/scx-cimd.rhel',
                                                      744, 'root', self.rootGroupName)
            if self.configuration['bt']  == 'Bullseye':
                cimdTemplate.AddRule('#TEMPLATE_CODEVOV_ENV#',
                                     ['COVFILE=/var/opt/microsoft/scx/log/OpsMgr.cov',
                                      'export COVFILE'])
            else:
                cimdTemplate.AddRule('#TEMPLATE_CODEVOV_ENV#', '')

            installerStagingFiles = installerStagingFiles + [
                cimdTemplate
                ]
        elif self.configuration['pf'] == 'Linux' and self.configuration['pfdistro'] == 'ULINUX':
            installerStagingFiles = installerStagingFiles + [
                filegenerator.FileCopy(self.etcRoot + '/init.d/scx-cimd',
                                           'conf/init.d/scx-cimd.ulinux',
                                           744, 'root', self.rootGroupName)
                ]

            for ssldir in self.sslDirectoryList:
                installerStagingFiles = installerStagingFiles + [
                    filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/GetLinuxOS.sh',
                                           self.targetDir + '/GetLinuxOS.sh',
                                           755, 'root', self.rootGroupName)
                    ]

        # For service start on hpux
        elif self.configuration['pf'] == 'HPUX':
            installerStagingFiles = installerStagingFiles + [
                filegenerator.FileCopy('sbin/init.d/scx-cimd',
                                       'conf/init.d/scx-cimd.hpux',
                                       744, 'root', self.rootGroupName),
                filegenerator.SoftLink('sbin/rc2.d/S999scx-cimd',
                                       '../init.d/scx-cimd',
                                       744, 'root', self.rootGroupName),
                filegenerator.SoftLink('sbin/rc1.d/K100scx-cimd',
                                       '../init.d/scx-cimd',
                                       744, 'root', self.rootGroupName),
                ]
        # For service start on Mac OS
        elif self.configuration['pf'] == 'MacOS':
            installerStagingFiles = installerStagingFiles + [
                filegenerator.FileCopy('Library/LaunchDaemons/com.microsoft.scx-cimd.plist',
                                       'conf/launchd/com.microsoft.scx-cimd.plist',
                                       644, 'root', self.rootGroupName),
                ]

        for stagingFile in installerStagingFiles:
            stagingFile.SetSrcRootDir(self.installerDir)

        # These files are added here as empty files. In some cases they are filled
        # with information in the postinstall script. In some cases they are empty
        # configuration files that could be edited once installed.
        emptyStagingFiles = [
            filegenerator.EmptyFile(self.etcRoot + '/opt/microsoft/scx/conf/installinfo.txt',
                                    644, 'root', self.rootGroupName),
            filegenerator.EmptyFile(self.etcRoot + '/opt/microsoft/scx/conf/scxlog.conf',
                                    644, 'root', self.rootGroupName, 'conffile'),
            filegenerator.EmptyFile(self.etcRoot + '/opt/microsoft/scx/conf/scxrunas.conf',
                                   644, 'root', self.rootGroupName, 'conffile')
            ]

        GeneratedFiles = []
        for ssldir in self.sslDirectoryList:
            GeneratedFiles += [
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'setup.sh',
                                       'scx_setup.sh',
                                       644, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/setup.sh',
                                       'scx_setup_tools.sh',
                                       644, 'root', self.rootGroupName),
                # The scxadmin script is intentionally w:x - we want non-privileged functions to work
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/scxadmin',
                                       'scxadmin.sh',
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/scxsslconfig',
                                       'scxsslconfig.sh',
                                       755, 'root', self.rootGroupName),
                ]

        # Create a link to make scxadmin easier to run ...
        #
        # On Solaris 5.10 and later, we deal with the /usr/sbin/scxadmin link via postinstall;
        # This is to allow zones to work properly for sparse root zones
        if self.configuration['pf'] != 'SunOS' or (self.configuration['pfmajor'] == 5 and self.configuration['pfminor'] < 10):
            GeneratedFiles = GeneratedFiles + [
                filegenerator.SoftLink('usr/sbin/scxadmin',
                                       '../../' + self.optRoot + '/microsoft/scx/bin/tools/scxadmin',
                                       755, 'root', self.rootGroupName)
                ]
                
        if self.configuration['bt']  == 'Bullseye':
            GeneratedFiles = GeneratedFiles + [
               filegenerator.FileCopy(self.varRoot + '/opt/microsoft/scx/log/OpsMgr.cov',
                                      'OpsMgr.cov',
                                      777, 'root', self.rootGroupName) ]

        for stagingFile in GeneratedFiles:
            stagingFile.SetSrcRootDir(self.intermediateDir)

        omiBinStagingFiles = []
        for ssldir in self.sslDirectoryList:
            omiBinStagingFiles += [
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'omiagent',
                                       'output' + ssldir + 'bin/omiagent',
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/omicli',
                                       'output' + ssldir + 'bin/omicli',
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'omiserver',
                                       'output' + ssldir + 'bin/omiserver',
                                       755, 'root', self.rootGroupName)
                ]

        for stagingFile in omiBinStagingFiles:
            stagingFile.SetSrcRootDir( self.configuration['omidir'] )

        # File name suffixes are added later.
        omiLibStagingFiles = []

        for ssldir in self.sslDirectoryList:
            omiLibStagingFiles += [
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/lib' + ssldir + 'libmicxx.' + self.sharedLibrarySuffix,
                                       'output' + ssldir + 'lib/libmicxx.' + self.sharedLibrarySuffix,
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/lib' + ssldir + 'libomiclient.' + self.sharedLibrarySuffix,
                                       'output' + ssldir + 'lib/libomiclient.' + self.sharedLibrarySuffix,
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/lib' + ssldir + 'libomiidentify.' + self.sharedLibrarySuffix,
                                       'output' + ssldir + 'lib/libomiidentify.' + self.sharedLibrarySuffix,
                                       755, 'root', self.rootGroupName)
                ]

        # OMI requires libbase.sl on HP pa-risc platforms ...
        if self.configuration['pf'] == 'HPUX' and self.configuration['pfarch'] == "pa-risc":
            omiLibStagingFiles += [
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/lib' + ssldir + 'libbase.' + self.sharedLibrarySuffix,
                                       'output' + ssldir + 'lib/libbase.' + self.sharedLibrarySuffix,
                                       755, 'root', self.rootGroupName)
                ]

        for stagingFile in omiLibStagingFiles:
            stagingFile.SetSrcRootDir( self.configuration['omidir'] )

        # Add some links to resolve SSL for version 0.9.8 (resolve libssl.so.0.9.8,
        # which we link against, to find the system's libssl.so file).
        if self.configuration['pfdistro'] == 'ULINUX':
                omiLibStagingFiles += [
                    filegenerator.SoftLink(self.optRoot + '/microsoft/scx/lib_openssl_0.9.8/libssl.so.0.9.8',
                                           self.usrlibRoot + '/libssl.so',
                                           755, 'root', self.rootGroupName),
                    filegenerator.SoftLink(self.optRoot + '/microsoft/scx/lib_openssl_0.9.8/libcrypto.so.0.9.8',
                                           self.usrlibRoot + '/libcrypto.so',
                                           755, 'root', self.rootGroupName)
                    ]

        # OMI repository files
        scxRepositoryFiles = [
            filegenerator.FileCopy(self.etcRoot + '/opt/microsoft/scx/conf/omiregister/root-scx/SCXProvider-root.reg',
                                   'installer/conf/omi/SCXProvider-root.reg',
                                   755, 'root', self.rootGroupName),
            filegenerator.FileCopy(self.etcRoot + '/opt/microsoft/scx/conf/omiregister/root-scx/SCXProvider-req.reg',
                                   'installer/conf/omi/SCXProvider-req.reg',
                                   755, 'root', self.rootGroupName)
            ]

        for stagingFile in scxRepositoryFiles:
            stagingFile.SetSrcRootDir( self.configuration['basedir'] )

        omiRepositoryFiles = [
            filegenerator.FileCopy(self.etcRoot + '/opt/microsoft/scx/conf/omiregister/root-omi/omiidentify.reg',
                                   'etc/omiregister/root-omi/omiidentify.reg',
                                   755, 'root', self.rootGroupName)
            ]

        for stagingFile in omiRepositoryFiles:
            stagingFile.SetSrcRootDir( self.configuration['omidir'] )

        repositoryFiles = scxRepositoryFiles + omiRepositoryFiles;


        scxCoreStagingFiles = []
        for ssldir in self.sslDirectoryList:
            scxCoreStagingFiles += [
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/lib' + ssldir + 'libSCXCoreProviderModule.' + self.sharedLibrarySuffix,
                                       'libSCXCoreProviderModule.' + self.sharedLibrarySuffix,
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'scxlogfilereader',
                                       'scxlogfilereader',
                                       755, 'root', self.rootGroupName),

                # Make tool binaries "hidden" ('.' prefix) since we have scripts to run it
                #
                # Permissions are intentionally w:x.  We protect the resources (files, etc), not
                # the binary itself.  This also allows non-prived functions (i.e. -status) to work.
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/.scxsslconfig',
                                       ssldir[1:] + 'scxsslconfig',
                                       755, 'root', self.rootGroupName),
                filegenerator.FileCopy(self.optRoot + '/microsoft/scx/bin' + ssldir + 'tools/.scxadmin',
                                       'scxadmin',
                                       755, 'root', self.rootGroupName),
                ]

        for stagingFile in scxCoreStagingFiles:
            stagingFile.SetSrcRootDir(self.targetDir)

        if self.configuration['pf'] == "Linux":
            extraLibFiles = [
                ]
        elif self.configuration['pf'] == "SunOS":
            if self.configuration['pfarch'] == "x86":
                extraLibFiles = [
                    ]
            else:
                extraLibFiles = [
                    ]
        elif self.configuration['pf'] == "HPUX":
            if self.configuration['pfarch'] == "ia64":
                extraLibFiles = [
                    ]
            else:
#               Add files here when we add support for pa-risc
                extraLibFiles = [ ]
        else:
            extraLibFiles = [ ]

        for extraLibFile in extraLibFiles:
            extraLibFile.SetSrcRootDir(self.srcDir)

        self.stagingObjectList = stagingDirectories + \
                                 installerStagingFiles + \
                                 emptyStagingFiles + \
                                 GeneratedFiles + \
                                 omiBinStagingFiles + \
                                 omiLibStagingFiles + \
                                 repositoryFiles + \
                                 scxCoreStagingFiles + \
                                 extraLibFiles

        for stagingObject in self.stagingObjectList:
            stagingObject.SetRootDir(self.stagingDir)

    ##
    # Return the list of staging objects.
    # \returns The list of staging objects.
    #
    def GetStagingObjectList(self):
        return self.stagingObjectList

    ##
    # Return the root path of the staging directory.
    # \returns The root path of the staging directory.
    #
    def GetRootPath(self):
        return self.stagingDir

    ##
    # Generate the staging directory.
    #
    def DoGenerate(self):
        for stagingObject in self.stagingObjectList:
            stagingObject.DoCreate()

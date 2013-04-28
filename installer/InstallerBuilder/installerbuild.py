#coding: utf-8
#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Contains main program to build installer packages.
#
# Date:   2007-09-25 14:33:04
#

from optparse import OptionParser
from os import path
import sys
import scxutil
from hpuxpackage import HPUXPackageFile
from sunospkg import SunOSPKGFile
from linuxrpm import LinuxRPMFile
from linuxdeb import LinuxDebFile
from aixlpp import AIXLPPFile
from macospackage import MacOSPackageFile
import scxexceptions
    
##
# Main program class
#
class InstallerBuild:
    ##
    # Handle program parameters.
    #
    def ParseParameters(self):
        # Get all command line parameters and arguments.
        usage = "usage: %prog [options]"
        parser = OptionParser(usage)

        parser.add_option("--basedir",
                          type="string",
                          dest="basedir",
                          help="Path to the scx_core root directory.")
        parser.add_option("--pf",
                          type="choice",
                          choices=["Windows", "Linux", "SunOS", "HPUX", "AIX", "MacOS"],
                          dest="pf",
                          help="Specifies what platform to build installer for.")
        parser.add_option("--pfmajor",
                          type="int",
                          dest="pfmajor",
                          help="Specifies the platform major version")
        parser.add_option("--pfminor",
                          type="string",
                          dest="pfminor",
                          help="Specifies the platform minor version")
        parser.add_option("--pfdistro",
                          type="choice",
                          choices=["", "SUSE", "REDHAT", "ULINUX"],
                          dest="pfdistro",
                          help="Specifies the distribution, or none")
        parser.add_option("--pfagenttype",
                          type="choice",
                          choices=["", "D", "R"],
                          dest="pfagenttype",
                          help="Specifies the type of distribution for ULINXU (R=rpmbuild, D=dpkg, or none")
        parser.add_option("--pfarch",
                          type="choice",
                          choices=["sparc", "pa-risc", "x86", "x64", "ia64", "ppc"],
                          dest="pfarch",
                          help="Specifies the platform architecture")
        parser.add_option("--pfwidth",
                          type="choice",
                          choices=["32", "64"],
                          dest="pfwidth",
                          help="Specifies the platform width")
        parser.add_option("--bt",
                          type="choice",
                          choices=["Debug", "Release", "Bullseye"],
                          dest="bt",
                          help="Debug, Release, or Bullseye build")
        parser.add_option("--cc",
                          action="store_true",
                          dest="cc",
                          help="Signals this is a code coverage build")
        parser.add_option("--major",
                          type="string",
                          dest="major",
                          help="Build major version number.")
        parser.add_option("--minor",
                          type="string",
                          dest="minor",
                          help="Build minor version number.")
        parser.add_option("--patch",
                          type="string",
                          dest="patch",
                          help="Build version patch number.")
        parser.add_option("--buildnr",
                          type="string",
                          dest="buildnr",
                          help="Build version build number.")
        parser.add_option("--omidir",
                          type="string",
                          dest="omidir",
                          help="OMI output directory path.")
        
        (options, args) = parser.parse_args()

        self.configuration = {}
        if options.basedir == None:
            parser.error("You must specify a base directory")
        else:
            self.basedir = options.basedir
            self.configuration['basedir'] = options.basedir
        if options.pf      == None: parser.error("You must specify a platform")
        else: self.configuration['pf'] = options.pf
        if options.pfmajor == None: parser.error("You must specify a platform major")
        else: self.configuration['pfmajor'] = options.pfmajor
        if options.pfminor == None: parser.error("You must specify a platform minor")
        else:
            self.configuration['pfminor'] = int(options.pfminor)
            self.configuration['pfminor_str'] = options.pfminor
        if options.pfmajor == None: parser.error("You must specify a distribution")
        else: self.configuration['pfdistro'] = options.pfdistro
        if options.pfagenttype == None: parser.error("You must specify a distribution type")
        else: self.configuration['pfagenttype'] = options.pfagenttype
        if options.pfarch  == None: parser.error("You must specify a platform architecture")
        else: self.configuration['pfarch'] = options.pfarch
        if options.pfwidth == None: parser.error("You must specify a platform width")
        else: self.configuration['pfwidth'] = options.pfwidth
        if options.bt      == None: parser.error("You must specify a build type")
        else: self.configuration['bt'] = options.bt
        self.configuration['cc'] = options.cc
        if options.major == None: parser.error("You must specify a major version number")
        else: self.configuration['major'] = options.major
        if options.minor == None: parser.error("You must specify a minor version number")
        else: self.configuration['minor'] = options.minor
        if options.patch == None: parser.error("You must specify a version patch number")
        else: self.configuration['patch'] = options.patch
        if options.buildnr == None: parser.error("You must specify a build number")
        else: self.configuration['buildnr'] = options.buildnr
        if options.omidir == None: parser.error("You must specify an OMI directory")
        else: self.configuration['omidir'] = options.omidir

        self.configuration['version'] = self.configuration['major'] + \
                                        '.' + self.configuration['minor'] + \
                                        '.' + self.configuration['patch']
        self.configuration['release'] = self.configuration['buildnr']

    ##
    # Create the platform string
    #
    def CreatePlatformString(self):
        if self.configuration['pf'] == "Linux":
            distroStr = "_%s" % (self.configuration['pfdistro'])
        else:
            distroStr = ""

        self.platformString = "%s%s_%s.%s_%s_%s_%s" % (self.configuration['pf'],
                                                       distroStr,
                                                       self.configuration['pfmajor'],
                                                       self.configuration['pfminor_str'],
                                                       self.configuration['pfarch'],
                                                       self.configuration['pfwidth'],
                                                       self.configuration['bt'])
        if self.configuration['cc']:
            self.platformString = self.platformString + "_cc"


    ##
    # Main program
    #
    def main(self):

        # Get command line parameters.
        self.ParseParameters()
        self.CreatePlatformString()

        # Some constant strings defined.
        # Some of these will certainly be options instead of handled this way.
        self.configuration['short_name'] = "scx"
        self.configuration['long_name'] = "Microsoft System Center 2012 Operations Manager for UNIX/Linux agent"
        self.configuration['description'] = "Microsoft CIM server for System Center 2012 Operations Manager."
        self.configuration['vendor'] = "http://www.microsoft.com"
        self.configuration['license'] = "none"
        
        srcDir              = path.join(self.basedir,  "source")
        targetBaseDir       = path.join(self.basedir,  "target")
        intermediateBaseDir = path.join(self.basedir,  "intermediate")
        installerDir        = path.join(self.basedir,  "installer")
        targetDir           = path.join(targetBaseDir, self.platformString)
        intermediateDir     = path.join(intermediateBaseDir, self.platformString)

        if not path.isdir(targetDir):
            print "Path to target directory is incorrect or target not built yet."
            print targetDir
            sys.exit(2)
        
        if self.configuration['pf'] == "Windows":
            raise PlatformNotImplementedError(self.configuration['pf'])
        elif self.configuration['pf'] == "Linux":
            if self.configuration['pfagenttype'] == "D":
                installerFile = LinuxDebFile(srcDir,
                                             targetDir,
                                             installerDir,
                                             intermediateDir,
                                             self.configuration)
            else:
                installerFile = LinuxRPMFile(srcDir,
                                             targetDir,
                                             installerDir,
                                             intermediateDir,
                                             self.configuration)
        elif self.configuration['pf'] == "SunOS":
            installerFile = SunOSPKGFile(srcDir,
                                         targetDir,
                                         installerDir,
                                         intermediateDir,
                                         self.configuration)
        elif self.configuration['pf'] == "HPUX":
            installerFile = HPUXPackageFile(srcDir,
                                            targetDir,
                                            installerDir,
                                            intermediateDir,
                                            self.configuration)
        elif self.configuration['pf'] == "AIX":
            installerFile = AIXLPPFile(srcDir,
                                       targetDir,
                                       installerDir,
                                       intermediateDir,
                                       self.configuration)
        elif self.configuration['pf'] == "MacOS":
            installerFile = MacOSPackageFile(srcDir,
                                       targetDir,
                                       installerDir,
                                       intermediateDir,
                                       self.configuration)
        else:
            raise PlatformNotImplementedError(self.configuration['pf'])

        installerFile.Generate()

if __name__ == '__main__': InstallerBuild().main()


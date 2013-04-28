import unittest
import sys
sys.path.append('../')
import sunospkg
import scriptgenerator
import filegenerator
import testutils
import re

class TestablePackageMaker(sunospkg.SunOSPKGFile):
    def __init__(self, pfmajor, pfminor):
        sunospkg.SunOSPKGFile.__init__(self, '', '', '', '', { 'short_name' : 'scx',
                                                               'long_name' : 'scx',
                                                               'pf' : 'SunOS',
                                                               'pfarch' : 'sparc',
                                                               'pfmajor' : pfmajor,
                                                               'pfminor' : pfminor,
                                                               'version' : '1.2.3',
                                                               'release' : '4',
                                                               'description' : '',
                                                               'vendor' : '' })
        sunospkg.open = testutils.FakeOpen
        scriptgenerator.open = testutils.FakeOpen
        self.stagingDir = testutils.FakeStagingDir()
        self.stagingDir.Add(filegenerator.SoftLink('usr/sbin/scxadmin', '', 755, 'root', 'root'))
        self.stagingDir.Add(filegenerator.FileCopy('opt/microsoft/scx/bin/tools/scx-cimd', '', 555, 'root', 'bin'))

    def __del__(self):
        testutils.thefakefiles = {}

    def GetPkgInfoSetting(self, key):
        pattern = re.compile(key + '=(.*)')
        return pattern.search(testutils.GetFileContent('intermediate/pkginfo')).group(1)
        
    def GetProtoTypeLineMatching(self, regex):
        pattern = re.compile(regex)
        return pattern.search(testutils.GetFileContent('intermediate/prototype')).group(0)

##
# Test cases for the sunos package.
#
class SunOSPKGFileTestCase(unittest.TestCase):

    def testZonesFlagsSetToInstallInCurrentZoneOnly(self):
        package = TestablePackageMaker(5, 10)
        package.GeneratePackageDescriptionFiles()
        self.assertEqual('false', package.GetPkgInfoSetting('SUNW_PKG_ALLZONES'))
        self.assertEqual('false', package.GetPkgInfoSetting('SUNW_PKG_HOLLOW'))
        self.assertEqual('true', package.GetPkgInfoSetting('SUNW_PKG_THISZONE'))
        
    def testServiceScriptFileExists(self):
        package = TestablePackageMaker(5, 10)
        package.GeneratePackageDescriptionFiles()
        self.assertEqual('f none /opt/microsoft/scx/bin/tools/scx-cimd',
                         package.GetProtoTypeLineMatching('.*/opt/microsoft/scx/bin/tools/scx-cimd'))

    def testPKGInfoFileDefinesAllClasses(self):
        package = TestablePackageMaker(5, 10)
        package.GeneratePackageDescriptionFiles()
        self.assertEqual('application config none', package.GetPkgInfoSetting('CLASSES'))

    def testPostRemoveFileWasCreatedOnNewerSolaris(self):
        package = TestablePackageMaker(5, 10)
        package.GenerateScripts()
        self.assert_(testutils.FileHasBeenWritten('intermediate/postuninstall.sh'))

    def testPostRemoveFileOnNewSolarisHasCorrectContent(self):
        package = TestablePackageMaker(5, 10)
        package.GenerateScripts()
        self.assert_(testutils.GetFileContent('intermediate/postuninstall.sh').find('rm /usr/sbin/scxadmin > /dev/null 2>&1\n') != -1)

    def testPostRemoveFileWasNotCreatedOnOlderSolaris(self):
        package = TestablePackageMaker(5, 9)
        package.GenerateScripts()
        self.assert_(not testutils.FileHasBeenWritten('intermediate/postuninstall.sh'))

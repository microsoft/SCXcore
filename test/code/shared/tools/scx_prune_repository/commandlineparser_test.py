import unittest
import sys
sys.path.append('../../../../source/code/tools/scx_prune_repository')
from commandlineparser import CommandLineParser

class CommandLineParserTestCase(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    def testOptParserHasCimSchemaDir(self):
        sys.argv.append("--cim_schema_dir=/some/directory")
        cmdLineParser = CommandLineParser()
        self.assert_(cmdLineParser.has_option('--cim_schema_dir'))
        self.assertEqual(cmdLineParser.getCIMSchemaDir(), '/some/directory')

    def testOneArgument(self):
        sys.argv.append("--cim_schema_dir=/some/directory")
        sys.argv.append('myFile.mof')
        cmdLineParser = CommandLineParser()
        self.assertEqual(cmdLineParser.getArguments(), ['myFile.mof'])



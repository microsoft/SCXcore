import unittest
import os
import sys
sys.path.append('../../../../source/code/tools/scx_prune_repository')
from moffile import MofFile

class MofFileTestCase(unittest.TestCase):
    def setUp(self):
        pass
    
    def tearDown(self):
        try:
            os.remove('EmptyFile.mof')
            os.remove('FileWithNoDependentClasses.mof')
            os.remove('FileWithOneDependentClass.mof')
            os.remove('TwoSubClasses.mof')
            os.remove('SameFileDependency.mof')
        except OSError:
            pass
    
    def testNoSuchFile(self):
        moffile = MofFile('ThisFileShouldNotExist.mof')
        self.assertEqual(moffile.GetDependentClasses(), [])

    def testEmptyFile(self):
        open('EmptyFile.mof', 'w')
        moffile = MofFile('EmptyFile.mof')
        self.assertEqual(moffile.GetDependentClasses(), [])

    def testMofFileWithNoDependentClasses(self):
        out = open('FileWithNoDependentClasses.mof', 'w')
        out.write('class TestClass {\n')
        out.write('  string Caption\n')
        out.write('}')
        out.close()
        moffile = MofFile('FileWithNoDependentClasses.mof')
        self.assertEqual(moffile.GetDependentClasses(), [])

    def testMofFileWithOneDependentClass(self):
        out = open('FileWithOneDependentClass.mof', 'w')
        out.write('class TestClass : DependentClass {\n')
        out.write('  string Caption\n')
        out.write('}')
        out.close()
        moffile = MofFile('FileWithOneDependentClass.mof')
        self.assertEqual(moffile.GetDependentClasses(), ['DependentClass'])

    def testMofFileWithTwoClassesWithOneBaseClass(self):
        out = open('TwoSubClasses.mof', 'w')
        out.write('class SubClass1 : BaseClass {\n')
        out.write('}')
        out.write('class SubClass2 : BaseClass {\n')
        out.write('}')
        out.close()
        moffile = MofFile('TwoSubClasses.mof')
        self.assertEqual(moffile.GetDependentClasses(), ['BaseClass'])

    def testMofFileWithInterDependency(self):
        out = open('SameFileDependency.mof', 'w')
        out.write('class BaseClass {\n')
        out.write('}')
        out.write('class SubClass2 : BaseClass {\n')
        out.write('}')
        out.close()
        moffile = MofFile('SameFileDependency.mof')
        self.assertEqual(moffile.GetDependentClasses(), [])

    def testDefinedClasses(self):
        out = open('SameFileDependency.mof', 'w')
        out.write('class BaseClass {\n')
        out.write('}')
        out.write('class SubClass1 : BaseClass {\n')
        out.write('}')
        out.write('class SubClass2 : BaseClass {\n')
        out.write('}')
        out.write('class SubClass3 : SubClass1 {\n')
        out.write('}')
        out.close()
        moffile = MofFile('SameFileDependency.mof')
        self.assertEqual(moffile.GetDefinedClasses(), ['BaseClass', 'SubClass1', 'SubClass2', 'SubClass3'])

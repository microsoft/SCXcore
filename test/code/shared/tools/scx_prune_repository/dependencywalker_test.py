import unittest
import os
import shutil
import sys
sys.path.append('../../../../source/code/tools/scx_prune_repository')
from dependencywalker import DependencyWalker
from moffilerepository import MofFileRepository
from moffile import MofFile

class DependencyWalkerTestCase(unittest.TestCase):
    def setUp(self):
        try:
            os.mkdir('./repository')
            out = open('./repository/BaseClass.mof', 'w')
            out.write('class BaseClass {\n')
            out.write('}')
            out.close()
            out = open('./repository/SubClass.mof', 'w')
            out.write('class SubClass : BaseClass {\n')
            out.write('}')
        except OSError:
            pass
        
    def tearDown(self):
        try:
            shutil.rmtree('./repository', 1)
            os.remove('./TestFile.mof')
        except OSError:
            pass

    def testNoFiles(self):
        mofrepository = MofFileRepository('./repository')
        depLister = DependencyWalker(mofrepository, [])
        self.assertEqual(depLister.GetRequiredFiles(), [])

    def testMofFileWithNoDependentClasses(self):
        out = open('./TestFile.mof', 'w')
        out.write('class TestClass {\n')
        out.write('}\n')
        out.close()

        mofrepository = MofFileRepository('./repository')
        moffile = MofFile('./TestFile.mof')
        depLister = DependencyWalker(mofrepository, [moffile])
        self.assertEqual(depLister.GetRequiredFiles(), [])

    def testMofFileWithOneDependentClass(self):
        out = open('./TestFile.mof', 'w')
        out.write('class TestClass : BaseClass {\n')
        out.write('}')
        out.close()

        mofrepository = MofFileRepository('./repository')
        moffile = MofFile('./TestFile.mof')
        depLister = DependencyWalker(mofrepository, [moffile])

        self.assertEqual(self.GetMofFileNames(depLister.GetRequiredFiles()),
                         ['./repository/BaseClass.mof'])

    def GetMofFileNames(self, moffiles):
        filenames = []
        for moffile in moffiles:
            self.assert_(isinstance(moffile, MofFile))
            filenames.append(moffile.GetFileName())
        return filenames
    

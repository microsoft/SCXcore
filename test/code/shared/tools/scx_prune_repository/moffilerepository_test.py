import unittest
import os
import shutil
import sys
sys.path.append('../../../../source/code/tools/scx_prune_repository')
from moffilerepository import MofFileRepository
from moffile import MofFile

class MofFileRepositoryTestCase(unittest.TestCase):
    def setUp(self):
        try:
            os.mkdir('./repository')
        except OSError:
            pass
        
    def tearDown(self):
        shutil.rmtree('./repository', 1)

    def testEmptyRepository(self):
        repository = MofFileRepository('./repository/')
        self.assertEqual(repository.GetAllMofFiles(), [])

    def testRepositoryWithOneFile(self):
        self.GivenRepositoryStructure(['File1.mof'])

        repository = MofFileRepository('./repository/')
        moffiles = repository.GetAllMofFiles()
        moffilenames = self.GetMofFileNames(moffiles)
        self.assertEqual(moffilenames, ['./repository/File1.mof'])

    def testRecursiveRepositoryWith3Files(self):
        self.GivenRepositoryStructure(['File1.mof',
                                       'directory1/File2.mof',
                                       'directory2/File3.mof'])

        repository = MofFileRepository('./repository/')
        self.assertEqual(self.GetMofFileNames(repository.GetAllMofFiles()).sort(),
                         ['./repository/File1.mof',
                          './repository/directory1/File2.mof',
                          './repository/directory2/File3.mof'].sort())

    def testNonMofFilesAreIgnored(self):
        self.GivenRepositoryStructure(['File1.mof',
                                       'directory1/File2.mof',
                                       'directory2/File3.notmof'])

        repository = MofFileRepository('./repository/')
        self.assertEqual(self.GetMofFileNames(repository.GetAllMofFiles()).sort(),
                         ['./repository/File1.mof',
                          './repository/directory1/File2.mof'].sort())
        
    def testGetFileDefiningClass(self):
        self.GivenRepositoryStructure(['File1.mof',
                                       'directory1/File2.mof',
                                       'directory2/File3.mof'])
        out = open('./repository/directory1/File4.mof', 'w')
        out.write('class TestClass {\n')
        out.write('}')
        out.close()
        
        repository = MofFileRepository('./repository/')
        self.assertEqual(repository.GetFileDefiningClass('TestClass').GetFileName(),
                         './repository/directory1/File4.mof')
        self.assertEqual(repository.GetFileDefiningClass('NoSuchClass'), None)


    def GivenRepositoryStructure(self, filenames):
        for filename in filenames:
            path = os.path.join('./repository', filename)
            try:
                os.makedirs(os.path.dirname(path))
            except OSError:
                pass
            out = open(path, 'w')
            out.write('class Class1 {\n')
            out.write('}')
            out.close()

    def GetMofFileNames(self, moffiles):
        filenames = []
        for moffile in moffiles:
            self.assert_(isinstance(moffile, MofFile))
            filenames.append(moffile.GetFileName())
        return filenames

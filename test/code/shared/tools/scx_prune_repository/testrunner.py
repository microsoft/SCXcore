import unittest
import moffile_test
import moffilerepository_test
import dependencywalker_test
import commandlineparser_test

##
# Entry point to the test suite.
#
if __name__ == '__main__':
    suite = unittest.TestSuite()
    suite.addTest(unittest.TestLoader().loadTestsFromModule(moffile_test))
    suite.addTest(unittest.TestLoader().loadTestsFromModule(moffilerepository_test))
    suite.addTest(unittest.TestLoader().loadTestsFromModule(dependencywalker_test))
    suite.addTest(unittest.TestLoader().loadTestsFromModule(commandlineparser_test))
    
    result = unittest.TextTestRunner(verbosity=2).run(suite)
    if not result.wasSuccessful():
        sys.exit(1)
    

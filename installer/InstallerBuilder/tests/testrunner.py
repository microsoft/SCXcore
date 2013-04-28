import unittest
import scriptgenerator_test
import macospackage_test
import sunospkg_test
import sys

##
# Entry point to the test suite.
#
if __name__ == '__main__':
    suite = unittest.TestSuite()
    suite.addTest(unittest.TestLoader().loadTestsFromModule(scriptgenerator_test))
    suite.addTest(unittest.TestLoader().loadTestsFromModule(macospackage_test))
    suite.addTest(unittest.TestLoader().loadTestsFromModule(sunospkg_test))
    
    result = unittest.TextTestRunner(verbosity=2).run(suite)
    if not result.wasSuccessful():
        sys.exit(1)

#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Contains the command line parser
#
# Date:   2008-10-28 16:17:23
#

from optparse import OptionParser

##
# This class takes care of parsing the
# command line parameters of the program
#
class CommandLineParser(OptionParser):
    ##
    # Constructor does the parsing
    #
    def __init__(self):
        OptionParser.__init__(self, 'usage: %prog [options]')
        self.add_option("--cim_schema_dir",
                        type="string",
                        dest="cim_schema_dir",
                        help="Path to a directory housing all mof files of a complete cim repository.")
        (options, self.arguments) = self.parse_args()
        self.cimSchemaDir = options.cim_schema_dir

    ##
    # Returns the value sent in as --cim_schema_dir
    #
    def getCIMSchemaDir(self):
        return self.cimSchemaDir

    ##
    # Returns a list of all arguments (except --cim_schema_dir)
    #
    def getArguments(self):
        return self.arguments

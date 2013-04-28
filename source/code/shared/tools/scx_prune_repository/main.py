#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Contains main program to generate a "pruned" repository.
#
# This program should be called with parameters like this:
#
# python main.py --cim_schema_dir="/some/path/dmtf/cimv2171" "/some/other/path/scx.mof"
#
# Date:   2008-10-28 16:16:59
#

from commandlineparser import CommandLineParser
from moffilerepository import MofFileRepository
from moffile import MofFile
from dependencywalker import DependencyWalker

##
# Main entry point
#
if __name__ == '__main__':

    # Parse command line parameters
    cmdLineParser = CommandLineParser()

    # Parse the complete mof file repository
    mofRepository = MofFileRepository(cmdLineParser.getCIMSchemaDir())

    # Parse the mof files supplied as arguments
    moffiles = []
    for filename in cmdLineParser.getArguments():
        moffiles.append(MofFile(filename))

    # This will generate the dependency list.
    depWalker = DependencyWalker(mofRepository, moffiles)

    # The paths in the generated output will be stripped of the --cim_schema_dir part of the path.
    includeDir = cmdLineParser.getCIMSchemaDir()
    if not includeDir.endswith('/'):
        includeDir = includeDir + '/'

    # Print to standard output in mof format.
    for moffile in depWalker.GetRequiredFiles():
        filename = moffile.GetFileName().replace(includeDir, '', 1)
        print '#pragma include (\"' + filename + '\")'

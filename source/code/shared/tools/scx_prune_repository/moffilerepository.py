#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Contains the MofFileRepository class
#
# Date:   2008-10-28 16:18:10
#

import os
from moffile import MofFile

##
# This class recursively enumerates all mof files
# in a certain directory. From this enumeration you can
# then retrieve which file defines a speciffic cim class.
#
class MofFileRepository:
    ##
    # Constructor.
    # Enumerates all mof files in path and creates
    # MofFile objects out of them.
    # Saves the MofFile objects in a dictionary for
    # later access.
    #
    def __init__(self, path):
        self.moffiles = []
        self.classToFileDict = {}
        for root, dirs, files in os.walk(path):
            for filename in files:
                if filename.endswith('.mof'):
                    moffile = MofFile(os.path.join(root, filename))
                    self.moffiles.append(moffile)
                    for cimclass in moffile.GetDefinedClasses():
                        self.classToFileDict[cimclass] = moffile
        
    ##
    # Retrueves all mof files enumerated as a
    # list of MofFile objects.
    #
    def GetAllMofFiles(self):
        return self.moffiles

    ##
    # Retrieve the moffile that contains the definition
    # of cimclass and return it as a MofFile object.
    # Returns None if no file defines cimclass.
    #
    def GetFileDefiningClass(self, cimclass):
        try:
            return self.classToFileDict[cimclass]
        except KeyError:
            return None

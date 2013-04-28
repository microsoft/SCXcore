#
# Copyright (c) Microsoft Corporation.  All rights reserved.
#
##
# Contains the MofFile class
#
# Date:   2008-10-28 16:18:50
#

import re

##
# Class representing necessary information
# from a mof file.
#
class MofFile:

    ##
    # Constructor
    # Parses the mof file to find all class definitions.
    # The defined class names and their base classes are saved
    # for later access.
    #
    def __init__(self, filename):
        self.filename = filename

        self.definedClasses = []
        self.dependentClasses = []

        try:
            content = open(self.filename, 'r')
        except IOError:
            return

        pattern = re.compile('class\s+(\S+)\s*(:\s*(\S+)\s*)?{')
        iterator = pattern.finditer(content.read())
        for match in iterator:
            (cimclass, baseclass) = match.group(1, 3)
            
            if baseclass and baseclass not in self.dependentClasses and baseclass not in self.definedClasses:
                self.dependentClasses.append(baseclass)
            self.definedClasses.append(cimclass)

    ##
    # Retrieve the filename that this MofFile was created with.
    #
    def GetFileName(self):
        return self.filename

    ##
    # Retrieve the names of all external cim classes that are refered
    # to as base classes in this mof file as a list of strings.
    #
    def GetDependentClasses(self):
        return self.dependentClasses

    ##
    # Retrieve the class names of all cim classes defined in this
    # mof file.
    #
    def GetDefinedClasses(self):
        return self.definedClasses

##
# Makes sure we can fake all file writing so that we write to strings instead.
#
class FakeFile:
    def __init__(self):
        self.content = ''

    def write(self, text):
        self.content = self.content + text

    def readlines(self):
        return self.content.splitlines(True)

thefakefiles = {}

##
# Fakes the open system command.
#
def FakeOpen(path, mode):
    if mode == 'r':
        try:
            return thefakefiles[path]
        except KeyError:
            return FakeFile()
    thefakefiles[path] = FakeFile()
    return thefakefiles[path]

##
# Returns true if the file passed as argument
# has been written to. Otherwise false.
#
def FileHasBeenWritten(filename):
    try:
        thefakefiles[filename]
        return True
    except:
        return False

##
# Returns the contents of a file.
#
def GetFileContent(filename):
    return thefakefiles[filename].content

##
# Fakes parts of the os module.
#
class FakeOS:
    def __init__(self):
        self.systemCalls = []

    def system(self, command):
        self.systemCalls.append(command)

##
# Fake scripts
# Lets us inspect the main section of generated scripts.
#
class FakeScript:
    def __init__(self):
        self.mainSection = ''

    def WriteLn(self, line):
        self.mainSection = self.mainSection + line + '\n'

##
# Stubbes out the staging dir class.
#
class FakeStagingDir:
    def __init__(self):
        self.objects = []

    def Add(self, object):
        self.objects.append(object)

    def GetStagingObjectList(self):
        return self.objects
  
    def GetRootPath(self):
        return ''


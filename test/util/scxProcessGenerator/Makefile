#--------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation.  All rights reserved.
#--------------------------------------------------------------------------------
# Makefile for scxProcessGenerator
# 2010-02-26    a-rpease        Created
# 2010-03-02    a-rpease        Removed WIN32 support, because there is no make
#                               program that can support this file's syntax.
#--------------------------------------------------------------------------------


#================================================================================
# Identify the basic platform the build is running on.
#================================================================================
UNAME = $(shell uname)

PF = UNKNOWN
ifeq ($(UNAME),AIX)
	PF = AIX
endif
ifeq ($(UNAME),HP-UX)
	PF = HPUX
endif
ifeq ($(UNAME),Linux)
	PF = Linux
endif
ifeq ($(UNAME),SunOS)
	PF = SunOS
endif

ifeq ($(PF),UNKNOWN)
	$(error Unrecognized build platform: $(UNAME))
endif

# Get the path to the project's location.
PWD := $(shell pwd)


#================================================================================
# Set some macros that will help manage the build.
#================================================================================

# The type of build to perform. A Release build can be performed by
# pre-defining this variable in the environment with the value 'Release'.
BUILD_TYPE ?= Debug

# Location of the source (.cpp) files.
SOURCE_DIR = $(PROJECT_DIR)

# Location of the header (.h) files.
INCLUDE_DIR = $(PROJECT_DIR)

#--------------------------------------------------------------------------------
# The directory for the build output files. The output of private builds
# can be redirected by pre-defining this variable in the environment.
OUT_DIR ?= $(PROJECT_DIR)

# A unique directory for build output files based on platform differences.
ifeq ($(PF),Linux)
	BUILD_CONFIGURATION = $(BUILD_TYPE)/$(PF)_$(PF_DISTRO)_$(PF_MAJOR).$(PF_MINOR)_$(PF_ARCH)_$(PF_WIDTH)
else
	BUILD_CONFIGURATION = $(BUILD_TYPE)/$(PF)_$(PF_MAJOR).$(PF_MINOR)_$(PF_ARCH)_$(PF_WIDTH)
endif

# Location to put intermediate (.o or .obj) files.
OBJ_DIR = $(OUT_DIR)/obj/$(BUILD_CONFIGURATION)

# Location to put final build result files.
TARGET_DIR = $(OUT_DIR)/bin/$(BUILD_CONFIGURATION)

EXE_FILE = $(TARGET_DIR)/scxProcessGenerator


#================================================================================
# Define some tools needed to interact with the platform.
#================================================================================
# Tool descriptions
# ECHO   - Echo the argument string to standard out.
# MKPATH - Create a directory and all necessary dirs along the way
# RM     - Remove a file
# RMDIR  - Remove a directory
# 
# src_to_obj - Convert a list of src files with absolute paths in $(SOURCE_DIR)
#              to corresponding object files with absolute paths in $(OBJ_DIR).
#       USAGE: src_to_obj(list_of_cppfiles)
#--------------------------------------------------------------------------------
ECHO=@echo
MKPATH=mkdir -p
RM=rm -f
RMDIR=rm -rf

src_to_obj = $(patsubst $(SOURCE_DIR)%, $(OBJ_DIR)%, $(patsubst %.cpp, %.o, $(1)))


#================================================================================
# Platform specific flags and other settings for AIX.
#================================================================================
ifeq ($(PF),AIX)
	# Platform archetecture
	PF_ARCH = ppc

	# Platform version (Typically 5.3 or 6.1)
	PF_MAJOR = $(shell uname -v)
	PF_MINOR = $(shell uname -r)

	# Build width
	PF_WIDTH = 32

	#--------------------------------------------------------------------------------
	# Compiler and linker flags.

	# Define flags. (These will be submitted to all commands that use the preprocesor)
	DEFINES = -Daix

	# Common compiler flags (sent to compile command and link commands)
	# -q32          Generate 32 bit code. (Default)
	# -qextchk      Generates bind-time type-checking
	COMMONFLAGS = -q32 -qextchk

	# Compiler flags that regulate warning level.
	# -qformat      Warns of problems with string I/O format specifications.
	# -qhalt=w      Stop compiler for warnings or worse.
	# -qflag=w      Output warnings or worse.
	CXX_WARN_FLAGS = -qformat -qhalt=w -qflag=w

	# CXX Debug flags for debug builds
	ifeq ($(BUILD_TYPE),Debug)
		# -g            Generate debugging information.
		# -qcheck       Generate runtime checks for array bounds, div by 0, and null pointer.
		COMMONFLAGS += -g -qcheck 
		DEFINES += -D_DEBUG
	else
		# -O2	        Selects certain code optimizations
		# -qcompact	Reduce code size at the expense of execution speed.
		COMMONFLAGS += -O2 -qcompact
		DEFINES += -DNDEBUG
	endif

	# CXX Compiler flags 
	CXXFLAGS = $(COMMONFLAGS) $(DEFINES) $(CXX_WARN_FLAGS)

	# Include paths
	INCLUDES = -I$(INCLUDE_DIR)

	# Linker flags
	LINK_OUTFLAG = -o $@
	LDFLAGS_EXECUTABLE =

	#--------------------------------------------------------------------------------
	# Build tool commands for this platform

	# Compiler for CPP files
	CXX = xlC_r

	# Link command for executables
	LINK = $(CXX) $(COMMONFLAGS) -L$(OBJ_DIR)

	# Command for making dependecies
	# Note that we need a special rule that redirects the output with -MF rather that '>'
	MKDEP = xlc++_r -E -qmakedep=gcc 
endif # End AIX


#================================================================================
# Platform specific flags and other settings for HPUX.
#================================================================================
ifeq ($(PF),HPUX)
	# Platform archetecture
	UNAME_M = $(shell uname -m)

	ifeq ($(UNAME_M),ia64)
		PF_ARCH = ia64
	else
		PF_ARCH = pa-risc
	endif

	# Platform version (Typically 11.23 or 11.31)
	PF_PARTS = $(subst ., ,$(shell uname -r))

	PF_MAJOR = $(word 2,$(PF_PARTS))
	PF_MINOR = $(word 3,$(PF_PARTS))

	# Build width
	PF_WIDTH = 32

	#--------------------------------------------------------------------------------
	# Compiler and linker flags.

	# Define flags. (These will be submitted to all commands that use the preprocesor)
	DEFINES = -Dhpux

	# Common compiler flags (sent to compile command and link commands)
	#~ +DD32        Generate 32 bit code.
	COMMONFLAGS = +DD32

	# Compiler flags that regulate warning levels
	CXX_WARN_FLAGS = 

	# Use "warnings as errors", if available
	ifeq ($(PF_ARCH),ia64)
		#~ +check=stack  Enable detecting writes outside stack boundaries.
		COMMONFLAGS += +check=stack
		# Note: -We exists in the PARISC compiler also, but is buggy and 
		# exits with "fatal error #523:" for many files.
		#~ +We  Interpret warnings as errors.
		CXX_WARN_FLAGS += +We
	endif

	# CXX Compiler flags (Redefined to include COMMONFLAGS)
	CXXFLAGS = $(COMMONFLAGS) $(DEFINES) $(CXX_WARN_FLAGS)

	# CXX Debug flags for debug builds
	ifeq ($(BUILD_TYPE),Debug)
		#~ -g1  Generate minimal symbolic debug information.
		CXXFLAGS += -g1
		DEFINES += -D_DEBUG
	else
		#~ +O1  Optimize in basic blocks only. (default)
		CXXFLAGS += +O1
		ifeq ($(PF_ARCH),ia64)
			#~ +Osize       Suppress optimizations that significantly increase code size.
			CXXFLAGS += +Osize
		endif
		DEFINES += -DNDEBUG
	endif


	# Include paths
	INCLUDES = -I$(INCLUDE_DIR)

	# Linker flags
	LINK_OUTFLAG = -o $@
	LDFLAGS_EXECUTABLE =

	#--------------------------------------------------------------------------------
	# Build tool commands for this platform

	# Compiler for CPP files
	CXX = aCC

	# Link command for executables
	LINK = $(CXX) $(COMMONFLAGS) -L$(OBJ_DIR)

	# Command for making dependecies
	MKDEP = aCC +make -E
endif # End HPUX


#================================================================================
# Platform specific flags and other settings for Linux.
#================================================================================
ifeq ($(PF),Linux)
	# Platform archetecture
	UNAME_P = $(shell uname -p)+

	# Platform distribution (Either REDHAT or SUSE).
	ifneq (,$(findstring 64,$(UNAME_P)))
		PF_ARCH = x64
	else
		ifneq (,$(findstring 86,$(UNAME_P)))
			PF_ARCH = x86
		else
			ifneq (,$(findstring athlon,$(UNAME_P)))
				PF_ARCH = x86
			else
				PF_ARCH = UNKNOWN
			endif
		endif
	endif

	CHECK_SUSE = $(shell if [ -e /etc/SuSE-release ]; then echo 1; fi)
	CHECK_RHEL = $(shell if [ -e /etc/redhat-release ]; then echo 1; fi)

	# Platform version (Typically 4.0, 5.0, 5.2 for REDHAT; 9.0, 10.0, 11.0 for SUSE).
	# Scripts below extract version information from the corresponding "release" file,
	# assuming that the version can be found as "<space><Major>[.<Minor>]".
	# If minor is not set, "0" is returned.
	ifeq ($(CHECK_SUSE),1)
		PF_DISTRO = SUSE
		PF_MAJOR = $(shell head -n 1 /etc/SuSE-release | sed 's/.* \([0-9][0-9]*\)[ \.].*/\1/')
		PF_MINOR = $(shell (head -n 1 /etc/SuSE-release | sed 's/.* [0-9][0-9]*[\.]\([0-9][0-9]*\).*/\1/') | grep -v '[^0-9]' || echo '0')
	endif

	ifeq ($(CHECK_RHEL),1)
		PF_DISTRO = REDHAT
		PF_MAJOR = $(shell head -n 1 /etc/redhat-release | sed 's/.* \([0-9][0-9]*\)[ \.].*/\1/')
		PF_MINOR = $(shell (head -n 1 /etc/redhat-release | sed 's/.* [0-9][0-9]*[\.]\([0-9][0-9]*\).*/\1/') | grep -v '[^0-9]' || echo '0')
	endif

	# Catchall
	ifeq (,$(PF_DISTRO))
		PF_DISTRO = UNKNOWN
		PF_MAJOR = UNKNOWN
		PF_MINOR = UNKNOWN
		$(warning "Unmatched version string")
	endif

	# Build width
	ifeq ($(PF_ARCH),x86)
		PF_WIDTH = 32
	else
		PF_WIDTH = 64
	endif


	#--------------------------------------------------------------------------------
	# Compiler and linker flags.

	# Define flags. (These will be submitted to all commands that use the preprocesor)
	DEFINES = -Dlinux

	# Compiler flags that reglulate warning levels
	#~ -Wall        Add standard warning checks.
	#~ -Werror      Treat all warnings as errors.
	CXX_WARN_FLAGS = -Wall -Werror

	ifneq ($(PF_DISTRO)$(PF_MAJOR),REDHAT4)
		#~ -Wextra      Add extra warnings.
		CXX_WARN_FLAGS += -Wextra 
	endif		

	# Compiler code-generation options
	#~ -Wuninitialized      Warn if automatic variable used before initialization.
	CXX_CGEN_FLAGS = -Wuninitialized

	# Compiler Optimization flags
	CXX_OPTIMIZATION_FLAGS =

	# -fstack-protector-all not supported on RedHat 4 or Sles 9
	ifneq ($(PF_DISTRO)$(PF_MAJOR),REDHAT4)
		ifneq ($(PF_DISTRO)$(PF_MAJOR),SUSE9)
			#~ -fstack-protector-all        UNKNOWN.
			CXX_OPTIMIZATION_FLAGS = -fstack-protector-all
		endif
	endif

	# CXX Debug flags for debug builds
	ifeq ($(BUILD_TYPE),Debug)
		DEFINES += -D_DEBUG
		#~ -ggdb        Produce debugging information for GDB.
		CXXFLAGS += -ggdb 
	else
		DEFINES += -DNDEBUG
		#~ -Os          Optimize for size.
		CXXFLAGS += -Os
	endif 

	# Avoid stack frame corruption when throwing exceptions from 
	# callbacks by not allowing the optimizer to omit frame pointers
	# (implicit with the -Os option). This bug was observed with the
	# GCC 3.4.3 compiler on Red Hat 3.4.3-9. See WI-11657 for more.
	#~ -fno-omit-frame-pointer      Do not omit frame pointer generation.
	CXXFLAGS += -fno-omit-frame-pointer

	# CXX Compiler flags
	CXXFLAGS += $(DEFINES) $(CXX_OPTIMIZATION_FLAGS) $(CXX_WARN_FLAGS) $(CXX_CGEN_FLAGS)

	# Include paths
	INCLUDES = -I$(INCLUDE_DIR)

	# Linker flags
	LINK_OUTFLAG = -o $@
	LDFLAGS_EXECUTABLE = 


	#--------------------------------------------------------------------------------
	# Build tool commands for this platform

	# Compiler for CPP files
	CXX = g++

	# Link command for executables
	LINK = $(CXX) -L$(OBJ_DIR)

	# Command for making dependecies
	MKDEP = g++ -MM
endif # End Linux


#================================================================================
# Platform specific flags and other settings for SunOS.
#================================================================================
ifeq ($(PF),SunOS)
	# Platform archetecture
	UNAME_P = $(shell uname -p)

	ifeq ($(UNAME_P),sparc)
		PF_ARCH = sparc
	endif
	ifeq ($(UNAME_P),i386)
		PF_ARCH = x86
	endif

	# Platform version (Typically 5.8, 5.9, 5.10)
	PF_PARTS = $(subst ., ,$(shell uname -r))
	PF_MAJOR = $(word 1,$(PF_PARTS))
	PF_MINOR = $(word 2,$(PF_PARTS))

	# Build width
	PF_WIDTH = 32

	#--------------------------------------------------------------------------------
	# Compiler and linker flags.

	# Define flags. (These will be submitted to all commands that use the preprocesor)
	DEFINES = -Dsun

	# Compiler flags that regulates warning levels
	#~ -errtags     Display error messages with message tags; <b>={yes|no}
	#~ -xwe         Convert all warnings to errors
	#~ +w           Print warnings about additional questionable constructs
	CXX_WARN_FLAGS = -errtags -xwe +w

	# These flags are used for all link commands.
	#~ -i   Tell linker to ignore any LD_LIBRARY_PATH setting
	LDFLAGS_COMMON = -i

	# CXX Debug flags for debug builds
	ifeq ($(BUILD_TYPE),Debug)
		#~ -g   Compile and link for debugging
		CXXFLAGS += -g
		DEFINES += -D_DEBUG
		LDFLAGS_COMMON += -g
		ifeq ($(PF_ARCH),sparc)
			#~ -xcheck=%all   Generate all runtime checks for stack overflows.
			LDFLAGS_COMMON += -xcheck=%all
		endif
	else
		#~ -xO1         Basic optimization only.
		CXXFLAGS += -xO1
		DEFINES += -DNDEBUG
	endif

	# CXX Compiler flags 
	#~ -xspace      Do not do optimizations that increase code size
	CXXFLAGS = $(DEFINES) $(CXX_WARN_FLAGS) -xspace

	# Include paths
	INCLUDES = -I$(INCLUDE_DIR)

	# Linker flags
	LINK_OUTFLAG = -o $@

	# Link switches for this platform
	LDFLAGS_EXECUTABLE = $(LDFLAGS_COMMON)

	#--------------------------------------------------------------------------------
	# Build tool commands for this platform

	# Compiler for CPP files
	CXX = CC

	# Link command for executables
	LINK = $(CXX) -L$(OBJ_DIR)

	# Command for making dependecies
	MKDEP = CC -xM1
endif # End SunOS


#================================================================================
# Set some rules for building the project.
#================================================================================

# No default rules, please
.SUFFIX: 

# Rule for compiling cpp files in source tree, ouptut in mirrored object dir
# HACK - The dependency on $(HEADERS) should be replaced with build-generated dependencies.
$(OBJ_DIR)/%.o : $(SOURCE_DIR)/%.cpp $(HEADERS)
	$(ECHO) "========================= Compiling $(<F)"
	$(MKPATH) $(@D)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $<


#================================================================================
# List the source files, headers, etc. for the project.
#================================================================================

HEADERS = $(INCLUDE_DIR)/platform.h \
	  $(INCLUDE_DIR)/scxProcess.h \
	  $(INCLUDE_DIR)/scxProcessGenerator.h \
	  $(INCLUDE_DIR)/StringArrayGenerator.h \
	  $(INCLUDE_DIR)/TempCopyFile.h \
	  $(INCLUDE_DIR)/Usage.h

SOURCES = $(SOURCE_DIR)/main.cpp \
	  $(SOURCE_DIR)/platform.cpp \
	  $(SOURCE_DIR)/scxProcess.cpp \
	  $(SOURCE_DIR)/scxProcessGenerator.cpp \
	  $(SOURCE_DIR)/StringArrayGenerator.cpp \
	  $(SOURCE_DIR)/TempCopyFile.cpp \
	  $(SOURCE_DIR)/Usage.cpp

OBJ_FILES = $(call src_to_obj,$(SOURCES))


#================================================================================
# Build targets for build, clean up, progress reporting, etc.
#================================================================================
all : $(EXE_FILE)

clean : 
	$(ECHO) "========================= Performing make clean"
	$(RM) $(EXE_FILE)
	$(RM) $(OBJ_FILES)

$(EXE_FILE) : $(OBJ_FILES)
	$(ECHO) "========================= Linking $(@F)"
	-$(MKPATH) $(TARGET_DIR)
	-$(LINK) $(LINK_OUTFLAG) $(OBJ_FILES) $(LDFLAGS_EXECUTABLE)

#-------------------------------- End of File -----------------------------------

#--------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation.  All rights reserved.
#--------------------------------------------------------------------------------

# Get the root of the SCXPAL directory (and other easy locations)
SCXCORE_DIR=$(shell cd ../../..; pwd)
SCXPAL_DIR := $(shell cd ../../../../pal; pwd)

# Pull in the PAL's config.mak file, verify we have symbols
include $(SCXPAL_DIR)/build/config.mak

ifndef BUILD_CONFIGURATION
$(error "BUILD_CONFIGURATION not defined. Please re-run configure")
endif

TARGET_DIR := $(SCXCORE_DIR)/target/$(BUILD_CONFIGURATION)

# Back to our regularly scheduled program ...

UNAME=$(shell uname)

ifeq ($(UNAME),SunOS)
	CXX=CC -o $@
endif
ifeq ($(UNAME),HP-UX)
	UNAME_M=$(shell uname -m)
	ifeq ($(UNAME_M),ia64)
		CXX=aCC -Dhpux +DD64 -D_LARGE_FILES -AA -mt +We +W2236,2111,2815,2334 -o $@
	else
		CXX=aCC -Dhpux +DD64 -D_LARGE_FILES -AA -mt +W2236,2111,2815,2334 -o $@
	endif
endif
ifeq ($(UNAME),Linux)
	CXX=g++ -Wall -D_FILE_OFFSET_BITS=64 -o $@
endif 
ifeq ($(UNAME),AIX)
	CXX=xlC_r -q64 -Daix -lperfstat -o $@
endif 

all : $(TARGET_DIR)/testapp
 
$(TARGET_DIR)/testapp : testapp.cpp memdata.cpp diskdata.cpp memdata.h diskdata.h diskinfo.h
	-cov01 -0
	mkdir -p $(TARGET_DIR)
	$(CXX) testapp.cpp memdata.cpp diskdata.cpp -lpthread -o $(TARGET_DIR)/testapp

stub : 
	@echo Stub file for testing tfsbuild > testapp
	@echo Testapp Makefile Stub Target Specified, Creating stubfile testapp
	@echo Returning Success

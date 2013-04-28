#--------------------------------------------------------------------------------
# Copyright (c) Microsoft Corporation.  All rights reserved.
#--------------------------------------------------------------------------------

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

all : testapp
 
testapp : testapp.cpp memdata.cpp diskdata.cpp memdata.h diskdata.h diskinfo.h
	-cov01 -0
	$(CXX) testapp.cpp memdata.cpp diskdata.cpp -lpthread

stub : 
	@echo Stub file for testing tfsbuild > testapp
	@echo Testapp Makefile Stub Target Specified, Creating stubfile testapp
	@echo Returning Success

/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Tests for cim (i.e. openpegasus) configurator functionality which is part of the scx_admin tool

    \date        2008-08-27 11:08:12

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <cimconfigurator.h> 
#include <testutils/scxunit.h> /* This will include CPPUNIT helper macros too */

#include <scxcorelib/scxexception.h> 

#include <iostream>

using namespace std;


//#define RUN_SERVER_TESTS

class CIMOMConfigTest : public CPPUNIT_NS::TestFixture, public SCX_CimConfigurator
{
    CPPUNIT_TEST_SUITE( CIMOMConfigTest );

    CPPUNIT_TEST( TestLogRotate );
    CPPUNIT_TEST( TestPrint );
    CPPUNIT_TEST( TestReset );
    CPPUNIT_TEST( TestSet );

    CPPUNIT_TEST_SUITE_END();

private:


public:
    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void TestLogRotate(void)
    {
        // LogRotate isn't supported by OMI - be sure method returns false
        CPPUNIT_ASSERT_MESSAGE("Unexpected return value from method LogRotate()", LogRotate() == false);
    }

    void TestPrint(void)
    {
        // Print isn't supported by OMI - be sure method returns false
        std::wostringstream buf;
        CPPUNIT_ASSERT_MESSAGE("Unexpected return value from method Print()", Print(buf) == false);
    }

    void TestReset(void)
    {
        // Reset isn't supported by OMI - be sure method returns false
        CPPUNIT_ASSERT_MESSAGE("Unexpected return value from method Reset()", Reset() == false);
    }

    void TestSet(void)
    {
        // Set isn't supported by OMI - be sure method returns false

        LogLevelEnum level = eLogLevel_Verbose;
        CPPUNIT_ASSERT_MESSAGE("Unexpected return value from method Set()", Set(level) == false);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( CIMOMConfigTest ); 

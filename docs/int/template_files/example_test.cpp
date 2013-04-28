/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Example test class.

    \date        2007-06-04 12:34:56

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <class_to_test.h> /* CUSTOMIZE: Include whatever you need to test here */
#include <scxcorelib/scxunit.h> /* This will include CPPUNIT helper macros too */

#include <scxcorelib/scxexception.h> /* CUSTOMIZE: Only needed if you want to test exception throwing */

class SCXExampleTest : public CPPUNIT_NS::TestFixture /* CUSTOMIZE: use a class name with relevant name */
{
    CPPUNIT_TEST_SUITE( SCXExampleTest ); /* CUSTOMIZE: Name must be same as classname */
    CPPUNIT_TEST( TestSomething ); /* Will use the default test timeout */
    SCXUNIT_TEST( SomeOtherTest, 60 /* test timeout in seconds */ );
    /* CUSTOMIZE: Add more tests here */
    CPPUNIT_TEST_SUITE_END();

private:
    /* CUSTOMIZE: Add any data commonly used in several tests as members here. */

public:
    void setUp(void)
    {
        /* CUSTOMIZE: This method will be called once before each test function. Use it to set up commonly used objects */
    }

    void tearDown(void)
    {
        /* CUSTOMIZE: This method will be called once after each test function with no regard of success or failure. */
    }

    void TestSomething(void)
    {
        /* CUSTOMIZE: Add your test code here. */
        CPPUNIT_ASSERT(! "Not Implemented");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXExampleTest ); /* CUSTOMIZE: Name must be same as classname */

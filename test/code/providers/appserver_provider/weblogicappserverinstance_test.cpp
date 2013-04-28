/*---------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved.
 */
/**
 \file        weblogicappserverinstance_test.h

 \brief       Tests for the logic of the weblogic instance

 \date        11-08-18 12:00:00

 */

/*------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <testutils/scxunit.h>

#include <appserverconstants.h>
#include <appserverinstance.h>
#include <weblogicappserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

#include <iostream>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

namespace SCXUnitTests {
    /*
     * Unit Tests for the logic of WebLogic instances.
     * 
     * WebLogic has a unique concept of versioning from the
     * Oracle Marketing department. These unit-tests will
     * verify that the mapping logic works correctly.
     */
    class WebLogicAppServerInstance_Test: public CPPUNIT_NS::TestFixture {
            CPPUNIT_TEST_SUITE( WebLogicAppServerInstance_Test);

            CPPUNIT_TEST( ExtractMajorVersionPriorTo10Maps);
            CPPUNIT_TEST( ExtractMajorVersion_10_0_MapsTo10g);
            CPPUNIT_TEST( ExtractMajorVersion_10_1_MapsTo10g);
            CPPUNIT_TEST( ExtractMajorVersion_10_2_MapsTo10g);
            CPPUNIT_TEST( ExtractMajorVersion_10_3_0_MapsTo10g);
            CPPUNIT_TEST( ExtractMajorVersion_10_3_2_MapsTo11g);
            CPPUNIT_TEST( ExtractMajorVersion_10_3_4_MapsTo11g);
            CPPUNIT_TEST( ExtractMajorVersion_10_3_5_MapsTo11g);
            CPPUNIT_TEST( ExtractMajorVersion_10_4_plus_MapsTo11g);
            CPPUNIT_TEST( ExtractMajorVersion11MapsTo11g);

            CPPUNIT_TEST_SUITE_END();

        public:
            /*--------------------------------------------------------*/
            /*
             * Unit Test setup method run before each test.
             */
            void setUp(void) {
            }

            /*--------------------------------------------------------*/
            /*
             * Unit Test tear down method run after each test.
             */
            void tearDown(void) {
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify all major version numbers prior to 10 map to 10g. 
             */
            void ExtractMajorVersionPriorTo10Maps() {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"1.0.0");
                CPPUNIT_ASSERT( L"1" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"2.0.0");
                CPPUNIT_ASSERT( L"2" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"3.0.0");
                CPPUNIT_ASSERT( L"3" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"4.0.0");
                CPPUNIT_ASSERT( L"4" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"5.0.0");
                CPPUNIT_ASSERT( L"5" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"6.0.0");
                CPPUNIT_ASSERT( L"6" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"7.0.0");
                CPPUNIT_ASSERT( L"7" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"8.0.0");
                CPPUNIT_ASSERT( L"8" ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"9.0.0");
                CPPUNIT_ASSERT( L"9" ==
                        sut.GetMajorVersion() );
            };

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.0.0.x maps to 10g. 
             */
           void ExtractMajorVersion_10_0_MapsTo10g() {
                 WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.0.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                        sut.GetMajorVersion() );

                // Right-most version (i.e. 10) should not matter
                sut.SetVersion(L"10.0.10.10");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                        sut.GetMajorVersion() );
            };

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.1.0.x maps to 10g. 
             */
            void ExtractMajorVersion_10_1_MapsTo10g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.1.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                            sut.GetMajorVersion() );

                // Right-most version (i.e. 1) should not matter
                sut.SetVersion(L"10.1.10.111");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                            sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.2.0.x maps to 10g. 
             */
            void ExtractMajorVersion_10_2_MapsTo10g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.2.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                            sut.GetMajorVersion() );

                // Right-most version (i.e. 1) should not matter
                sut.SetVersion(L"10.2.0.1");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                            sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.3.0.x maps to 10g. 
             */
            void ExtractMajorVersion_10_3_0_MapsTo10g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.3.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                            sut.GetMajorVersion() );

                // Right-most version (i.e. 25) should not matter
                sut.SetVersion(L"10.3.0.25");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_10 ==
                        sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.3.2.x maps to 11g. 
             */
            void ExtractMajorVersion_10_3_2_MapsTo11g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.3.2.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                // Right-most version (i.e. 4) should not matter
                sut.SetVersion(L"10.3.2.4");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.3.5.x maps to 11g. 
             */
            void ExtractMajorVersion_10_3_5_MapsTo11g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");
            
                sut.SetVersion(L"10.3.5.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                // Right-most version (i.e. 8) should not matter
                sut.SetVersion(L"10.3.5.8");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.3.4.x maps to 11g. 
             */
            void ExtractMajorVersion_10_3_4_MapsTo11g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");
            
                sut.SetVersion(L"10.3.4.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                // Right-most version (i.e. 18) should not matter
                sut.SetVersion(L"10.3.4.18");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
            sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 10.4+.x maps to 11g. 
             */
            void ExtractMajorVersion_10_4_plus_MapsTo11g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"10.4.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                // Right-most version (i.e. 18) should not matter
                sut.SetVersion(L"10.4.10.18");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.5.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.6.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.7.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.8.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.9.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"10.10.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );
            }

            // --------------------------------------------------------
            /*
             * Verify that the WebLogic's overriden functionality for
             * ExtractMajorVersion works as expected.  The branded name
             * does not coincide with the numbered versioning.
             * 
             * Verify major version 11.x maps to 11g
             */
            void ExtractMajorVersion11MapsTo11g()
            {
                WebLogicAppServerInstance sut(L"/fake/path");

                sut.SetVersion(L"11.0.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"11.1.0");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );

                sut.SetVersion(L"11.1.1");
                CPPUNIT_ASSERT( WEBLOGIC_BRANDED_VERSION_11 ==
                        sut.GetMajorVersion() );
            }

        }; // End WebLogicAppServerInstance_Test 

    } // End namespace

CPPUNIT_TEST_SUITE_REGISTRATION( SCXUnitTests::WebLogicAppServerInstance_Test);

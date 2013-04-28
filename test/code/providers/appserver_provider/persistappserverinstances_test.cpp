/*----------------------------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved. 
 
 */
/**
 \file        persistappserverinstances_test.cpp

 \brief       Tests the persistence of application servers

 \date        11-05-19 12:00:00

 */
/*-----------------------------------------------------------------*/

#include <sys/wait.h>
#if defined(aix)
#include <unistd.h>
#endif
#include <string>

#include <testutils/scxunit.h>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxpersistence.h>
#include <scxcorelib/stringaid.h>

#include "source/code/scxcorelib/util/persist/scxfilepersistmedia.h"

#include "appserverconstants.h"
#include "appserverinstance.h"
#include "weblogicappserverinstance.h"
#include "websphereappserverinstance.h"
#include "persistappserverinstances.h"
#include "removenonexistentappserverinstances.h"

/*
 * dynamic_cast fix - wi 11220
 * Using this fix because this unit-test is very
 * similar to the scxpersistence_test.cpp. This
 * unit-test requires this fix, see WI for details.
 */
#ifdef dynamic_cast
#undef dynamic_cast
#endif

using namespace std;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXUnitTests
{
    const static std::wstring JBOSS_SIMPLE_PATH = L"/opt/jboss/jboss-5.1.0/default/";

    const static std::wstring JBOSS_SIMPLE_HTTP_PORT = L"8080";

    const static std::wstring JBOSS_SIMPLE_HTTPS_PORT = L"8443";

    const static std::wstring JBOSS_SIMPLE_PROTOCOL = PROTOCOL_HTTP;

    const static std::wstring JBOSS_SIMPLE_TYPE = APP_SERVER_TYPE_JBOSS;

    const static std::wstring JBOSS_SIMPLE_VERSION = L"5.1.0-GA";

    const static std::wstring JBOSS_WITH_SPACE_PATH = L"/opt/jboss app server/jboss-5.1.0/default number one/";

    const static std::wstring JBOSS_WITH_SPACE_HTTP_PORT = L"8081";

    const static std::wstring JBOSS_WITH_SPACE_HTTPS_PORT = L"8444";

    const static std::wstring JBOSS_WITH_SPACE_PROTOCOL = PROTOCOL_HTTP;

    const static std::wstring JBOSS_WITH_SPACE_TYPE = APP_SERVER_TYPE_JBOSS;

    const static std::wstring JBOSS_WITH_SPACE_VERSION = L"5.1.1-GA";

    const static std::wstring JBOSS_NOT_RUNNING_PATH = L"/opt/jbossNotRunning/jboss-5.1.0/default/";

    const static std::wstring JBOSS_NOT_RUNNING_HTTP_PORT = L"8082";

    const static std::wstring JBOSS_NOT_RUNNING_HTTPS_PORT = L"8445";

    const static std::wstring JBOSS_NOT_RUNNING_PROTOCOL = PROTOCOL_HTTP;

    const static std::wstring JBOSS_NOT_RUNNING_TYPE = APP_SERVER_TYPE_JBOSS;

    const static std::wstring JBOSS_NOT_RUNNING_VERSION = L"5.1.2-GA";

    const static std::wstring WEBSPHERE_PATH = L"/opt/websphere/AppServer/profiles/AppSrv01/";

    const static std::wstring WEBSPHERE_ID = L"AppSrv01-Node01Cell-Node01-server1";

    const static std::wstring WEBSPHERE_HTTP_PORT = L"9080";

    const static std::wstring WEBSPHERE_HTTPS_PORT = L"9443";

    const static std::wstring WEBSPHERE_PROTOCOL = PROTOCOL_HTTP;

    const static std::wstring WEBSPHERE_TYPE = APP_SERVER_TYPE_WEBSPHERE;

    const static std::wstring WEBSPHERE_VERSION = L"7.0.0.0";

    const static std::wstring WEBSPHERE_PROFILE = L"AppSrv01";

    const static std::wstring WEBSPHERE_CELL = L"Node01Cell";

    const static std::wstring WEBSPHERE_NODE = L"Node01";

    const static std::wstring WEBSPHERE_SERVER = L"server1";

    const static std::wstring WEBLOGIC_PATH = L"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain/";

    const static std::wstring WEBLOGIC_ID = L"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain/";

    const static std::wstring WEBLOGIC_HTTP_PORT = L"7011";

    const static std::wstring WEBLOGIC_HTTPS_PORT = L"7012";

    const static std::wstring WEBLOGIC_PROTOCOL = PROTOCOL_HTTP;

    const static std::wstring WEBLOGIC_TYPE = APP_SERVER_TYPE_WEBLOGIC;

    const static std::wstring WEBLOGIC_VERSION = L"10.3.2.0";

    const static std::wstring WEBLOGIC_SERVER = WEBLOGIC_SERVER_TYPE_ADMIN;

/*
 * Mock implementation of the real PersistAppServerInstances
 * class. This implementation allows for the overriding of some 
 * functionality. For instance, this object will not remove any
 * instances because they could not be found on disk.
 * 
 */
class MockPersistAppServerInstances: 
    public SCXSystemLib::PersistAppServerInstances
{

public:

    /*
     * Default constructor (no args)
     */
    MockPersistAppServerInstances() :
        PersistAppServerInstances()
    {
    }

    /*-----------------------------------------------------------------*/
    /**
     Constructor where the path of to write persisted output to disk
     */
    MockPersistAppServerInstances(const SCXFilePath& directory)
    {
        // Need to convert a handle of the SCXPersistMedia to
        // a type of SCXFilePersistMedia
        SCXHandle<SCXPersistMedia> physicalTestMedia;
        physicalTestMedia = GetPersistMedia();
        SCXFilePersistMedia
                * m =
                        dynamic_cast<SCXFilePersistMedia*> (physicalTestMedia.GetData());
        m->SetBasePath(directory);
        m_pmedia = physicalTestMedia;
    }
    
    /*-----------------------------------------------------------------------*/
    /*
     * Overriden Function from Base Class
     * 
     * For unit-tests, this class will make it look like all instances 
     * can be found on disk
     */
    void RemoveNonExistentInstances(
            std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& /* instances*/,
            SCXSystemLib::RemoveNonexistentAppServerInstances)
    {
        // Do nothing (i.e. do not remove any instances)
    }
};
    
    /*
     * Mock implementation of the real PersistAppServerInstances
     * class. This object will remove all instances because they 
     * could not be found on disk.
     */
    class MockPersistAppServerInstancesWithNothingOnDisk: 
        public SCXSystemLib::PersistAppServerInstances
    {

    public:
        /*
         * Default constructor (no args)
         */
            MockPersistAppServerInstancesWithNothingOnDisk() :
            PersistAppServerInstances()
        {
        }

        /*-----------------------------------------------------------------*/
        /**
         Constructor where the path of to write persisted output to disk
         */
        MockPersistAppServerInstancesWithNothingOnDisk(const SCXFilePath& directory)
        {
            // Need to convert a handle of the SCXPersistMedia to
            // a type of SCXFilePersistMedia
            SCXHandle<SCXPersistMedia> physicalTestMedia;
            physicalTestMedia = GetPersistMedia();
            SCXFilePersistMedia
                    * m =
                            dynamic_cast<SCXFilePersistMedia*> (physicalTestMedia.GetData());
            m->SetBasePath(directory);
            m_pmedia = physicalTestMedia;
        }
        
        /*-----------------------------------------------------------------------*/
        /*
         * Overriden Function from Base Class
         * 
         * For unit-tests, this class will make it look like all instances 
         * can NOT be found on disk.
         */
        void RemoveNonExistentInstances(
                std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances,
                SCXSystemLib::RemoveNonexistentAppServerInstances)
        {
            instances.clear();
        }
    };

/*
 * The Unit Test class for PersistAppServerInstances.
 * This extends the CPPUNIT (because it is a unit test) and
 * PersistAppServerInstances (because access is needed to 
 * the protected method GetPersistedAppServerName()).
 */
class PersistAppServerInstancesTest: public CPPUNIT_NS::TestFixture,
        public SCXSystemLib::PersistAppServerInstances
{
    CPPUNIT_TEST_SUITE( PersistAppServerInstancesTest);
    CPPUNIT_TEST( TestRemovingNonExistentItemsRemovesNothing );
    CPPUNIT_TEST( TestRemovingNonExistentItemsRemovesEverything );
    CPPUNIT_TEST( TestReadingNonExistentCache );
    CPPUNIT_TEST( TestReadingEmptyCache );
    CPPUNIT_TEST( TestReadingSingleEntryCache );
    CPPUNIT_TEST( TestReadingSingleEntryCacheWithEmptyHttpPort );
    CPPUNIT_TEST( TestReadingMultiEntryCache );
    CPPUNIT_TEST( TestReadingMultiEntryCacheButAllEntriesAreDeleted );
    CPPUNIT_TEST( TestReadingMangledCacheHasWrongPositiveNumber );
    CPPUNIT_TEST( TestReadingMangledCacheHasWrongNegativeNumber );
    CPPUNIT_TEST( TestReadingMangledCacheMissingProperty );
    CPPUNIT_TEST( TestReadingMangledCacheHasMissingInstance );
    CPPUNIT_TEST( TestPersistingInstancesArraySizeZero);
    CPPUNIT_TEST( TestPersistingInstancesArraySizeOne);
    CPPUNIT_TEST( TestPersistingInstancesArraySizeFour);
    CPPUNIT_TEST( TestUnpersistingInstancesArraySizeZeroForNoPreviousWrite );
    CPPUNIT_TEST( TestUnpersistingInstancesArraySizeZeroForPreviousWrite );
    CPPUNIT_TEST( TestReadingSingleEntryCache_WebSphere );
    CPPUNIT_TEST( TestReadingSingleEntryCache_WebLogic );
    CPPUNIT_TEST_SUITE_END();

private:
    /*
     * Overriden location of where to persist data
     */
    SCXFilePath m_path;

    /*
     * Directly read the persisted media for verification
     */
    SCXHandle<SCXPersistMedia> m_pmedia;

public:
    /*
     * Default constructor
     */
    PersistAppServerInstancesTest(void)
    {
        m_path = SCXFilePath(L"./");
    }

    /*-----------------------------------------------------------------*/
    /*
     * Unit Test Setup: run before each test
     */
    void setUp(void)
    {
        m_pmedia = GetPersistMedia();
        SCXCoreLib::SCXFilePersistMedia* m =
        dynamic_cast<SCXCoreLib::SCXFilePersistMedia*> (m_pmedia.GetData());
        CPPUNIT_ASSERT(m != 0);
        m->SetBasePath(m_path);
    }

    /*-----------------------------------------------------------------*/
    /*
     * Unit Test Teardown: run after each test
     * 
     */
    void tearDown(void)
    {
        UnpersistAllInstances();
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a plain, vanilla instance of JBoss
     */
    SCXHandle<AppServerInstance> createPlainRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_SIMPLE_PATH,
                        JBOSS_SIMPLE_TYPE));
        instance->SetHttpPort(JBOSS_SIMPLE_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_SIMPLE_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_SIMPLE_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_SIMPLE_VERSION);

        return instance;
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a instance of WebSphere
     */
    SCXHandle<AppServerInstance> createWebSphereInstance(void)
    {
        SCXHandle<WebSphereAppServerInstance> instance(
                new WebSphereAppServerInstance (
                        WEBSPHERE_ID, WEBSPHERE_CELL, WEBSPHERE_NODE, WEBSPHERE_PROFILE, WEBSPHERE_SERVER));
        instance->SetDiskPath(WEBSPHERE_PATH);
        instance->SetHttpPort(WEBSPHERE_HTTP_PORT);
        instance->SetHttpsPort(WEBSPHERE_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, WEBSPHERE_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(WEBSPHERE_VERSION);

        return instance;
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a instance of WebLogic
     */
    SCXHandle<AppServerInstance> createWebLogicInstance(void)
    {
        SCXHandle<AppServerInstance> instance(new WebLogicAppServerInstance(WEBLOGIC_ID));
        instance->SetDiskPath(WEBLOGIC_PATH);
        instance->SetHttpPort(WEBLOGIC_HTTP_PORT);
        instance->SetHttpsPort(WEBLOGIC_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, WEBLOGIC_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(WEBLOGIC_VERSION);
        instance->SetServer(WEBLOGIC_SERVER);
        return instance;
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a JBoss instance with a space in the path that is not running.
     * This is the same as the other JBoss instance with a space, but not running
     * (i.e. represent data from a cache)
     */
    SCXHandle<AppServerInstance> createNotRunningJBossInstanceWithSpaceInPath(void)
    {
        SCXHandle<AppServerInstance> instance(
                createRunningJBossInstanceWithSpaceInPath());
        instance->SetIsRunning(false);
        return instance;
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a JBoss instance with a space in the path that is running
     */
    SCXHandle<AppServerInstance> createRunningJBossInstanceWithSpaceInPath(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_WITH_SPACE_PATH,
                        JBOSS_WITH_SPACE_TYPE));
        instance->SetHttpPort(JBOSS_WITH_SPACE_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_WITH_SPACE_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_WITH_SPACE_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_WITH_SPACE_VERSION);

        return instance;
    }

    
    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a JBoss instance that is not running
     */
    SCXHandle<AppServerInstance> createJBossInstanceNotRunning(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_NOT_RUNNING_PATH,
                        JBOSS_NOT_RUNNING_TYPE));
        instance->SetHttpPort(JBOSS_NOT_RUNNING_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_NOT_RUNNING_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_NOT_RUNNING_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(JBOSS_NOT_RUNNING_VERSION);

        return instance;
    }

    /*-----------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Use the underlying persistence framework to remove
     * any persisted data that would have been created during
     * the unit-test.
     */
    void UnpersistAllInstances(void)
    {
        try
        {
            m_pmedia->UnPersist(APP_SERVER_PROVIDER);
        }
        catch (PersistDataNotFoundException&)
        {
            // Ignore.
        }
    }

    /*
     * Verify that the mocked out implementation of removing
     * non-existent application servers works as expected. This
     * really tests the test code, but it it is broken then
     * other tests will fail that depend on this fake functionality.
     * 
     * The expect behavior is that all of the application servers
     * are found on disk and thus the returned list of instances is unchanged.
     */
    void TestRemovingNonExistentItemsRemovesNothing(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );

        vector<SCXHandle<AppServerInstance> > instances;
        instances.push_back(createPlainRunningJBossInstance());
        instances.push_back(createRunningJBossInstanceWithSpaceInPath());
        instances.push_back(createJBossInstanceNotRunning());

        size_t checkSize = 3;
        CPPUNIT_ASSERT_EQUAL(checkSize, instances.size());

        // Run the Test
        RemoveNonexistentAppServerInstances unusedRemover;
        CPPUNIT_ASSERT_NO_THROW(
                sut->RemoveNonExistentInstances(instances, unusedRemover));
        
        // Verify that the mock implementation does not remove any of the 
        // instances because the necessary method has been overridden to
        // always think that items are on disk.
        CPPUNIT_ASSERT_EQUAL(checkSize, instances.size());
    }

    /*
     * Verify that the mocked out implementation of removing
     * non-existent application servers works as expected. This
     * really tests the test code, but it it is broken then
     * other tests will fail that depend on this fake functionality.
     * 
     * The expect behavior is that none of the application servers
     * are found on disk and thus the returned list of instances is empty.
     */
    void TestRemovingNonExistentItemsRemovesEverything(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstancesWithNothingOnDisk> sut( 
                new MockPersistAppServerInstancesWithNothingOnDisk(m_path) );

        vector<SCXHandle<AppServerInstance> > instances;
        instances.push_back(createPlainRunningJBossInstance());
        instances.push_back(createRunningJBossInstanceWithSpaceInPath());
        instances.push_back(createJBossInstanceNotRunning());

        size_t three = 3;
        CPPUNIT_ASSERT_EQUAL(three, instances.size());

        // Run the Test
        RemoveNonexistentAppServerInstances unusedRemover;
        CPPUNIT_ASSERT_NO_THROW(
                sut->RemoveNonExistentInstances(instances, unusedRemover));
        
        // Verify that the mock implementation does not remove any of the 
        // instances because the necessary method has been overridden to
        // always think that items are on disk.
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL(zero, instances.size());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading an empty cache
     */
    void TestReadingEmptyCache(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"0");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array is STILL empty
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }
    
    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a non-existent cache
     */
    void TestReadingNonExistentCache(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // This is run as part of the setup, but re-run just to be sure
        UnpersistAllInstances();

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array is STILL empty
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify the reading the cache behaves as expected if corrupted.
     * If it cannot be read, then assume it is corrupt and disregard the cache.
     *
     * In this case the cache looks right, but someone has adjust the number
     * of instances to be a number larger than the actual number of written
     * in the persistent store.
     */
    void TestReadingMangledCacheHasWrongPositiveNumber(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NUMBER, L"8"));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_WITH_SPACE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_WITH_SPACE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_WITH_SPACE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_WITH_SPACE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 1

        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        //CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));
        sut->ReadFromDisk(readInstances);

        // Test Verification
        // Verify after the call nothing was returned
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify the reading the cache behaves as expected if corrupted.
     * If it cannot be read, then assume it is corrupt and disregard the cache.
     *
     * In this case the cache looks right, but someone has adjust the number
     * of instances to be a negative number. 
     */
    void TestReadingMangledCacheHasWrongNegativeNumber(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NUMBER, L"-1"));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        //CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));
        sut->ReadFromDisk(readInstances);

        // Test Verification
        // Verify after the call the test that the array has one entry
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify the reading the cache behaves as expected if corrupted.
     * If it cannot be read, then assume it is corrupt and disregard the cache.
     *
     * In this case the cache looks right, but someone has remove a property.
     * In theory any property should do, so this test has chosen HTTP PORT.
     */
    void TestReadingMangledCacheMissingProperty(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NUMBER, L"1"));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        // Purposely NOT writing HTTP PORT
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        //CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));
        sut->ReadFromDisk(readInstances);

        // Test Verification
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    
    /*-----------------------------------------------------------------*/
    /*
     * Verify the reading the cache behaves reasonable well if the cache
     * has been corrupted.  In this case, some nefarious person has
     * overwritten the number of instances to contain a number less
     * than the number of values in the cache.
     */
    void TestReadingMangledCacheHasMissingInstance(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( 
                new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_METADATA));
        // this should be 2, but someone lied and made it one
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NUMBER, L"1"));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true)));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_PROFILE, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_CELL, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NODE, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_SERVER, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing this instance 0

        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_NOT_RUNNING_PATH));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_ID, JBOSS_NOT_RUNNING_PATH));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_NOT_RUNNING_HTTP_PORT));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_NOT_RUNNING_HTTPS_PORT));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true)));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_NOT_RUNNING_TYPE));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_NOT_RUNNING_VERSION));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_PROFILE, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_CELL, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_NODE, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteValue(APP_SERVER_SERVER, L""));
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing this instance 1
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));
        
        // Test Verification
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    
    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a single entry cache
     * with some fairly bland data.
     */
    void TestReadingSingleEntryCache(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"1");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_SIMPLE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetId());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == inst->GetVersion());
        CPPUNIT_ASSERT(L"" == inst->GetProfile());
        CPPUNIT_ASSERT(L"" == inst->GetCell());
        CPPUNIT_ASSERT(L"" == inst->GetNode());
        CPPUNIT_ASSERT(L"" == inst->GetServer());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a single entry cache
     * with some fairly bland data without the Id & WebSphere data saved.
     */
    void TestReadingSingleEntryCacheWithoutWebSphereData(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"1");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_SIMPLE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetId());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == inst->GetVersion());
        CPPUNIT_ASSERT(L"" == inst->GetProfile());
        CPPUNIT_ASSERT(L"" == inst->GetCell());
        CPPUNIT_ASSERT(L"" == inst->GetNode());
        CPPUNIT_ASSERT(L"" == inst->GetServer());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a single entry cache
     * with some fairly bland data. What is interesting is that the
     * HTTP Port is empty.
     */
    void TestReadingSingleEntryCacheWithEmptyHttpPort(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"1");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, L"");
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_SIMPLE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetId());
        CPPUNIT_ASSERT(L"" == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(L"" == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == inst->GetVersion());
    }

    /*
     * Verify no errors are thrown if reading a multiple entries from cache.
     */
    void TestReadingMultiEntryCache(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"3");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_SIMPLE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_NOT_RUNNING_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_NOT_RUNNING_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_NOT_RUNNING_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_NOT_RUNNING_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_NOT_RUNNING_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_NOT_RUNNING_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_NOT_RUNNING_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 1

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_WITH_SPACE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_WITH_SPACE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_WITH_SPACE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_WITH_SPACE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_WITH_SPACE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 2

        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        size_t three = 3;
        CPPUNIT_ASSERT_EQUAL( three, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == inst->GetId());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == inst->GetVersion());
        
        inst = readInstances[1];
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PATH == inst->GetId());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_HTTP_PORT == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_HTTP_PORT == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_VERSION == inst->GetVersion());

        inst = readInstances[2];
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PATH == inst->GetDiskPath());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PATH == inst->GetId());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_HTTP_PORT == inst->GetHttpPort());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PROTOCOL == inst->GetProtocol());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_HTTP_PORT == inst->GetPort());
        CPPUNIT_ASSERT(true == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(false == inst->GetIsRunning());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_TYPE == inst->GetType());
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_VERSION == inst->GetVersion());
    }
    
    /**
     * This unit test has a version of the cache that has entries, but
     * thinks that none of them are on disk.  Thus the list of items
     * returned from the cache is empty.
     */
    void TestReadingMultiEntryCacheButAllEntriesAreDeleted(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstancesWithNothingOnDisk> sut(
                new MockPersistAppServerInstancesWithNothingOnDisk(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = 
                m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"3");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_SIMPLE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_SIMPLE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_SIMPLE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_SIMPLE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_SIMPLE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_SIMPLE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 0
        
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_NOT_RUNNING_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_NOT_RUNNING_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_NOT_RUNNING_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_NOT_RUNNING_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_NOT_RUNNING_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_NOT_RUNNING_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_NOT_RUNNING_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 1

        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, JBOSS_WITH_SPACE_PATH);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, JBOSS_WITH_SPACE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, JBOSS_WITH_SPACE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, JBOSS_WITH_SPACE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, JBOSS_WITH_SPACE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, JBOSS_WITH_SPACE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, L"");
        pwriter->WriteValue(APP_SERVER_CELL, L"");
        pwriter->WriteValue(APP_SERVER_NODE, L"");
        pwriter->WriteValue(APP_SERVER_SERVER, L"");
        pwriter->WriteEndGroup(); // Closing this instance 2

        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());
    }

    /*-----------------------------------------------------------------*/
    /*
     * Persisting a list of zero application servers should succeed
     * without any errors, but nothing will happen on disk.
     */
    void TestPersistingInstancesArraySizeZero(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > zeroInstances;
        
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, zeroInstances.size());
        
        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->WriteToDisk(zeroInstances));
        
        // Test Verification
        SCXHandle<SCXPersistDataReader> preader;
        CPPUNIT_ASSERT_NO_THROW(
                preader = m_pmedia->CreateReader(APP_SERVER_PROVIDER));

        // Verify number of entries
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT(L"0" == preader->ConsumeValue(APP_SERVER_NUMBER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // APP_SERVER_METADATA

        // Verify there is nothing else
        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(L"0"), 
                PersistDataNotFoundException);
    }

    /*
     * Given a list of one application server to persist that
     * is a real instance, verify that said information is persisted
     * to the disk.
     */
    void TestPersistingInstancesArraySizeOne(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );

        vector<SCXHandle<AppServerInstance> > oneInstance;
        oneInstance.push_back(createPlainRunningJBossInstance());

        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL(one, oneInstance.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->WriteToDisk(oneInstance));

        //Test Verification
        SCXHandle<SCXPersistDataReader> preader;
        CPPUNIT_ASSERT_NO_THROW(
                preader = m_pmedia->CreateReader(APP_SERVER_PROVIDER)
                );

        // Verify number of entries
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_NUMBER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // APP_SERVER_METADATA

        // Verify the only entry
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == preader->ConsumeValue(APP_SERVER_DISK_PATH));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == preader->ConsumeValue(APP_SERVER_ID));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == preader->ConsumeValue(APP_SERVER_HTTP_PORT));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == preader->ConsumeValue(APP_SERVER_HTTPS_PORT));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == preader->ConsumeValue(APP_SERVER_PROTOCOL));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == preader->ConsumeValue(APP_SERVER_TYPE));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == preader->ConsumeValue(APP_SERVER_VERSION));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_PROFILE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_CELL));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_NODE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_SERVER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // JBOSS_SIMPLE_PATH
        
        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(L"1"), 
                PersistDataNotFoundException);
    }

    /*
     * Given a list of four application server to persist that
     * is a real instance, verify that said information is persisted
     * to the disk.
     */
    void TestPersistingInstancesArraySizeFour(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );

        vector<SCXHandle<AppServerInstance> > instances;
        instances.push_back(createPlainRunningJBossInstance());
        instances.push_back(createRunningJBossInstanceWithSpaceInPath());
        instances.push_back(createJBossInstanceNotRunning());
        instances.push_back(createWebSphereInstance());

        size_t checkSize = 4;
        CPPUNIT_ASSERT_EQUAL(checkSize, instances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->WriteToDisk(instances));

        //Test Verification
        SCXHandle<SCXPersistDataReader> preader;
        CPPUNIT_ASSERT_NO_THROW(
                preader = m_pmedia->CreateReader(APP_SERVER_PROVIDER)
                );
        
        // Verify number of entries
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_METADATA));
        CPPUNIT_ASSERT(L"4" == preader->ConsumeValue(APP_SERVER_NUMBER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // APP_SERVER_METADATA

        
        // Verify the simple instance (again)
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == preader->ConsumeValue(APP_SERVER_DISK_PATH));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PATH == preader->ConsumeValue(APP_SERVER_ID));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTP_PORT == preader->ConsumeValue(APP_SERVER_HTTP_PORT));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_HTTPS_PORT == preader->ConsumeValue(APP_SERVER_HTTPS_PORT));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_PROTOCOL == preader->ConsumeValue(APP_SERVER_PROTOCOL));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_TYPE == preader->ConsumeValue(APP_SERVER_TYPE));
        CPPUNIT_ASSERT(JBOSS_SIMPLE_VERSION == preader->ConsumeValue(APP_SERVER_VERSION));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_PROFILE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_CELL));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_NODE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_SERVER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // JBOSS_SIMPLE_PATH
        
        // Verify the instance with a space in the path
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PATH == preader->ConsumeValue(APP_SERVER_DISK_PATH));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PATH == preader->ConsumeValue(APP_SERVER_ID));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_HTTP_PORT == preader->ConsumeValue(APP_SERVER_HTTP_PORT));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_HTTPS_PORT == preader->ConsumeValue(APP_SERVER_HTTPS_PORT));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_PROTOCOL == preader->ConsumeValue(APP_SERVER_PROTOCOL));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_TYPE == preader->ConsumeValue(APP_SERVER_TYPE));
        CPPUNIT_ASSERT(JBOSS_WITH_SPACE_VERSION == preader->ConsumeValue(APP_SERVER_VERSION));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_PROFILE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_CELL));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_NODE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_SERVER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // JBOSS_WITH_SPACE_PATH
        
        // Verify the instance that is not running
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PATH == preader->ConsumeValue(APP_SERVER_DISK_PATH));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PATH == preader->ConsumeValue(APP_SERVER_ID));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_HTTP_PORT == preader->ConsumeValue(APP_SERVER_HTTP_PORT));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_HTTPS_PORT == preader->ConsumeValue(APP_SERVER_HTTPS_PORT));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_PROTOCOL == preader->ConsumeValue(APP_SERVER_PROTOCOL));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_TYPE == preader->ConsumeValue(APP_SERVER_TYPE));
        CPPUNIT_ASSERT(JBOSS_NOT_RUNNING_VERSION == preader->ConsumeValue(APP_SERVER_VERSION));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_PROFILE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_CELL));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_NODE));
        CPPUNIT_ASSERT(L"" == preader->ConsumeValue(APP_SERVER_SERVER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // JBOSS_NOT_RUNNING_PATH
        
        // Verify the WebSphere instance
        CPPUNIT_ASSERT(preader->ConsumeStartGroup(APP_SERVER_INSTANCE));
        CPPUNIT_ASSERT(WEBSPHERE_PATH == preader->ConsumeValue(APP_SERVER_DISK_PATH));
        CPPUNIT_ASSERT(WEBSPHERE_ID == preader->ConsumeValue(APP_SERVER_ID));
        CPPUNIT_ASSERT(WEBSPHERE_HTTP_PORT == preader->ConsumeValue(APP_SERVER_HTTP_PORT));
        CPPUNIT_ASSERT(WEBSPHERE_HTTPS_PORT == preader->ConsumeValue(APP_SERVER_HTTPS_PORT));
        CPPUNIT_ASSERT(WEBSPHERE_PROTOCOL == preader->ConsumeValue(APP_SERVER_PROTOCOL));
        CPPUNIT_ASSERT(L"1" == preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED));
        CPPUNIT_ASSERT(WEBSPHERE_TYPE == preader->ConsumeValue(APP_SERVER_TYPE));
        CPPUNIT_ASSERT(WEBSPHERE_VERSION == preader->ConsumeValue(APP_SERVER_VERSION));
        CPPUNIT_ASSERT(WEBSPHERE_PROFILE == preader->ConsumeValue(APP_SERVER_PROFILE));
        CPPUNIT_ASSERT(WEBSPHERE_CELL == preader->ConsumeValue(APP_SERVER_CELL));
        CPPUNIT_ASSERT(WEBSPHERE_NODE == preader->ConsumeValue(APP_SERVER_NODE));
        CPPUNIT_ASSERT(WEBSPHERE_SERVER == preader->ConsumeValue(APP_SERVER_SERVER));
        CPPUNIT_ASSERT(preader->ConsumeEndGroup(true)); // WEBSPHERE
        
        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(APP_SERVER_INSTANCE), 
                PersistDataNotFoundException);
    }

    /*
     * Unpersisting a list of zero application servers should succeed
     * without any errors when nothing has ever been writen on disk
     */
    void TestUnpersistingInstancesArraySizeZeroForNoPreviousWrite(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > zeroInstances;
        
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, zeroInstances.size());
        
        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->EraseFromDisk());
        
        // Test Verification
        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(APP_SERVER_PROVIDER),
                PersistDataNotFoundException);

        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(JBOSS_SIMPLE_PATH), 
                PersistDataNotFoundException);
    }

    /*
     * Unpersisting a list of zero application servers should succeed
     * without any errors when something is there already
     */
    void TestUnpersistingInstancesArraySizeZeroForPreviousWrite(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > zeroInstances;
        
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, zeroInstances.size());
        
        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->WriteToDisk(zeroInstances));
        CPPUNIT_ASSERT_NO_THROW(sut->EraseFromDisk());
        
        // Test Verification
        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(APP_SERVER_PROVIDER),
                PersistDataNotFoundException);

        CPPUNIT_ASSERT_THROW(
                m_pmedia->CreateReader(JBOSS_SIMPLE_PATH), 
                PersistDataNotFoundException);
    }

    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a single entry cache
     * with some fairly bland data.
     * This test is specifically tailored for WebSphere as the ID is created from the 
     * cell,node.profile and server.
     */
    void TestReadingSingleEntryCache_WebSphere(void)
    {
        // Test setup
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > readInstances;

        SCXHandle<SCXPersistDataWriter> pwriter = m_pmedia->CreateWriter(APP_SERVER_PROVIDER);
        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, L"1");
        CPPUNIT_ASSERT_NO_THROW(pwriter->WriteEndGroup()); // Closing APP_SERVER_METADATA
        pwriter->WriteStartGroup(APP_SERVER_INSTANCE);
        pwriter->WriteValue(APP_SERVER_DISK_PATH, WEBSPHERE_PATH);
        pwriter->WriteValue(APP_SERVER_ID, WEBSPHERE_ID);
        pwriter->WriteValue(APP_SERVER_HTTP_PORT, WEBSPHERE_HTTP_PORT);
        pwriter->WriteValue(APP_SERVER_HTTPS_PORT, WEBSPHERE_HTTPS_PORT);
        pwriter->WriteValue(APP_SERVER_PROTOCOL, WEBSPHERE_PROTOCOL);
        pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, StrFrom(true));
        pwriter->WriteValue(APP_SERVER_TYPE, WEBSPHERE_TYPE);
        pwriter->WriteValue(APP_SERVER_VERSION, WEBSPHERE_VERSION);
        pwriter->WriteValue(APP_SERVER_PROFILE, WEBSPHERE_PROFILE);
        pwriter->WriteValue(APP_SERVER_CELL, WEBSPHERE_CELL);
        pwriter->WriteValue(APP_SERVER_NODE, WEBSPHERE_NODE);
        pwriter->WriteValue(APP_SERVER_SERVER, WEBSPHERE_SERVER);
        pwriter->WriteEndGroup(); // Closing this instance 0
        CPPUNIT_ASSERT_NO_THROW(pwriter->DoneWriting()); // Closing APP_SERVER_PROVIDER

        // Verify before the call that the array is empty
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];

        CPPUNIT_ASSERT(WEBSPHERE_PATH       == inst->GetDiskPath());
        CPPUNIT_ASSERT(WEBSPHERE_ID         == inst->GetId());
        CPPUNIT_ASSERT(WEBSPHERE_HTTP_PORT  == inst->GetHttpPort());
        CPPUNIT_ASSERT(WEBSPHERE_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(WEBSPHERE_PROTOCOL   == inst->GetProtocol());
        CPPUNIT_ASSERT(true                 == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(WEBSPHERE_TYPE       == inst->GetType());
        CPPUNIT_ASSERT(WEBSPHERE_VERSION    == inst->GetVersion());
        CPPUNIT_ASSERT(WEBSPHERE_PROFILE    == inst->GetProfile());
        CPPUNIT_ASSERT(WEBSPHERE_CELL       == inst->GetCell());
        CPPUNIT_ASSERT(WEBSPHERE_NODE       == inst->GetNode());
        CPPUNIT_ASSERT(WEBSPHERE_SERVER     == inst->GetServer());
    }

    
    /*-----------------------------------------------------------------*/
    /*
     * Verify no errors are thrown if reading a single entry cache
     * with some fairly bland data.
     * This test is specifically tailored for WebLogic to test the specific version
     * numbering for WebLogic
     */
    void TestReadingSingleEntryCache_WebLogic(void)
    {
        SCXHandle<MockPersistAppServerInstances> sut( new MockPersistAppServerInstances(m_path) );
        vector<SCXHandle<AppServerInstance> > instances;

        instances.push_back(createWebLogicInstance());

        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL(one, instances.size());

        CPPUNIT_ASSERT(WEBLOGIC_BRANDED_VERSION_11  == instances[0]->GetMajorVersion());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->WriteToDisk(instances));

        vector<SCXHandle<AppServerInstance> > readInstances;

        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, readInstances.size());

        // Run the Test
        CPPUNIT_ASSERT_NO_THROW(sut->ReadFromDisk(readInstances));

        // Test Verification
        // Verify after the call the test that the array has one entry
        CPPUNIT_ASSERT_EQUAL( one, readInstances.size());
        
        // Verify that data is correct
        SCXHandle<AppServerInstance> inst = readInstances[0];
        
        CPPUNIT_ASSERT(WEBLOGIC_PATH       == inst->GetDiskPath());
        CPPUNIT_ASSERT(WEBLOGIC_ID         == inst->GetId());
        CPPUNIT_ASSERT(WEBLOGIC_HTTP_PORT  == inst->GetHttpPort());
        CPPUNIT_ASSERT(WEBLOGIC_HTTPS_PORT == inst->GetHttpsPort());
        CPPUNIT_ASSERT(WEBLOGIC_PROTOCOL   == inst->GetProtocol());
        CPPUNIT_ASSERT(true                == inst->GetIsDeepMonitored());
        CPPUNIT_ASSERT(WEBLOGIC_TYPE       == inst->GetType());
        CPPUNIT_ASSERT(WEBLOGIC_VERSION    == inst->GetVersion());
        CPPUNIT_ASSERT(WEBLOGIC_SERVER     == inst->GetServer());
        CPPUNIT_ASSERT(WEBLOGIC_BRANDED_VERSION_11  == inst->GetMajorVersion());
    }
    
};

CPPUNIT_TEST_SUITE_REGISTRATION( PersistAppServerInstancesTest);
}

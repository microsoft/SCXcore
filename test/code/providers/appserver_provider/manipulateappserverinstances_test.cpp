/*----------------------------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved. 
 
 */
/**
 \file        manipulateappserverinstances_test.cpp

 \brief       Tests merging two arrays that represent processes and a cache

 \date        11-05-26 12:00:00

 */
/*----------------------------------------------------------------------------*/
#include <string>
#include <vector>
#include <testutils/scxunit.h>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>

#include "appserverinstance.h"
#include "manipulateappserverinstances.h"
#include "removenonexistentappserverinstances.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXUnitTests
{
    const static std::wstring JBOSS_A_PROCESS_PATH = L"/opt/a/jboss-5.1.0/default";
    const static std::wstring JBOSS_A_PROCESS_HTTP_PORT = L"18080";
    const static std::wstring JBOSS_A_PROCESS_HTTPS_PORT = L"18443";
    const static std::wstring JBOSS_A_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_A_PROCESS_TYPE = L"JBOSS";
    const static std::wstring JBOSS_A_PROCESS_VERSION = L"5.1.0-GA";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_PATH = L"/b/jboss-5.1.0/default";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_HTTP_PORT = L"34080";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_HTTPS_PORT = L"34443";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_TYPE = L"JBOSS";
    const static std::wstring JBOSS_CACHED_BUT_RUNNING_VERSION = L"5.1.0-GA";
    const static std::wstring JBOSS_CACHED_PATH = L"/a/H_H/a space/jboss-5.1.0/full";
    const static std::wstring JBOSS_CACHED_HTTP_PORT = L"28080";
    const static std::wstring JBOSS_CACHED_HTTPS_PORT = L"28443";
    const static std::wstring JBOSS_CACHED_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_CACHED_TYPE = L"JBOSS";
    const static std::wstring JBOSS_CACHED_VERSION = L"5.1.0-GA";
    const static std::wstring JBOSS_MINIMAL_PATH = L"/opt/jboss/jboss-5.1.0/minimal";
    const static std::wstring JBOSS_MINIMAL_HTTP_PORT = L"8080";
    const static std::wstring JBOSS_MINIMAL_HTTPS_PORT = L"8443";
    const static std::wstring JBOSS_MINIMAL_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_MINIMAL_TYPE = L"JBOSS";
    const static std::wstring JBOSS_MINIMAL_VERSION = L"5.1.0-GA";
    const static std::wstring JBOSS_SIMPLE_PATH = L"/opt/jboss/jboss-5.1.0/default";
    const static std::wstring JBOSS_SIMPLE_HTTP_PORT = L"8080";
    const static std::wstring JBOSS_SIMPLE_HTTPS_PORT = L"8443";
    const static std::wstring JBOSS_SIMPLE_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_SIMPLE_TYPE = L"JBOSS";
    const static std::wstring JBOSS_SIMPLE_VERSION = L"5.1.0-GA";
    const static std::wstring JBOSS_NEW_RUNNING_PATH = L"/var/home/dcrammo/jbossNotRunning/jboss-5.1.0/default";
    const static std::wstring JBOSS_NEW_RUNNING_HTTP_PORT = L"38082";
    const static std::wstring JBOSS_NEW_RUNNING_HTTPS_PORT = L"38445";
    const static std::wstring JBOSS_NEW_RUNNING_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_NEW_RUNNING_TYPE = L"JBOSS";
    const static std::wstring JBOSS_NEW_RUNNING_VERSION = L"5.1.2-GA";
    const static std::wstring JBOSS_NOT_RUNNING_PATH = L"/var/home/ccrammo/jbossNotRunning/jboss-5.1.0/default";
    const static std::wstring JBOSS_NOT_RUNNING_HTTP_PORT = L"8082";
    const static std::wstring JBOSS_NOT_RUNNING_HTTPS_PORT = L"8445";
    const static std::wstring JBOSS_NOT_RUNNING_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_NOT_RUNNING_TYPE = L"JBOSS";
    const static std::wstring JBOSS_NOT_RUNNING_VERSION = L"5.1.2-GA";
    const static std::wstring JBOSS_WITH_SPACE_PATH = L"/opt/app server/jboss/jboss-5.1.0/default number one";
    const static std::wstring JBOSS_WITH_SPACE_HTTP_PORT = L"8081";
    const static std::wstring JBOSS_WITH_SPACE_HTTPS_PORT = L"8444";
    const static std::wstring JBOSS_WITH_SPACE_PROTOCOL = L"HTTP";
    const static std::wstring JBOSS_WITH_SPACE_TYPE = L"JBOSS";
    const static std::wstring JBOSS_WITH_SPACE_VERSION = L"5.1.1-GA";

    /*
     * Object that in production code should remove instances that
     * are not on disk, but in practice 
     * 
     */
    class FakeRemover : 
        public SCXSystemLib::IRemoveNonexistentAppServerInstances
    {

    public:

        /*
         * Default constructor
         */
        FakeRemover(void) : 
            m_removeAllInstances(false)
        {
        }

        /*
         * Constructor that toggles if all the instances are removed or not
         */
        FakeRemover(bool removeAllInstances) : 
            m_removeAllInstances(removeAllInstances)
        {
        }

        /*-----------------------------------------------------------------------*/
        /*
         * Overriden Function from Base Class
         * 
         * Depending on flags set in the constructor, this will or will not remove
         * all instances 
         */
        void RemoveNonexistentInstances(
                std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances)
        {
            if (m_removeAllInstances)
            {
                instances.clear();
            }
        }
        
    private:
        const bool m_removeAllInstances;
    };

    
/*
 * The Unit Test class for the logic of merging two vectors
 * that represent a list of processes and a list of cache items
 */
class ManipulateAppServerInstancesTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ManipulateAppServerInstancesTest);
    CPPUNIT_TEST( TestUpdatingKnownInstancesWithTwoEmptyInputs );
    CPPUNIT_TEST( TestUpdatingKnownInstancesThatIsInitiallyEmptyWithOneNewProcess );
    CPPUNIT_TEST( TestUpdatingKnownInstancesThatContains22RunningProcsWithTheSameProcs );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWhenPreviouslyKnownStateOfNotRunningAndNoProcessesInput );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWhenPreviouslyKnownStateOfRunningAndNoProcessesInput );
    CPPUNIT_TEST( TestUpdatingKnownInstancesForPortChangeOfSingleInstance );
    CPPUNIT_TEST( TestUpdatingKnownInstancesForDeepMonitoredOfSingleRunningInstance );
    CPPUNIT_TEST( TestUpdatingKnownInstancesForDeepMonitoredOfSingleNotRunningInstance );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWithManyDuplicatesWhereThePreviousEntriesAreNotRunning );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWithManyDuplicatesWhereSomePreviousEntriesAreRunning );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWithManyDuplicatesChangesToAllFlags );
    CPPUNIT_TEST( TestUpdatingKnownInstancesWhenAllKnownInstancesAreNotOnDisk); 
    CPPUNIT_TEST( TestManipulateAppServerInstancesBothEmpty );
    CPPUNIT_TEST( TestMergeOneProcessAndEmptyCache );
    CPPUNIT_TEST( TestMergeEmptyProcessAndOneCache );
    CPPUNIT_TEST( TestMergeOneProcessAndOneCache );
    CPPUNIT_TEST( TestMergeSameFromProcessAndCache );
    CPPUNIT_TEST( TestMergeManyDuplicateProcessesAndCacheItemsThatAreOutOfOrder );
    CPPUNIT_TEST_SUITE_END();

public:
    /*
     * Default constructor
     */
    ManipulateAppServerInstancesTest(void)
    {
    }

    /*----------------------------------------------------------------------*/
    /*
     * Unit Test Setup: run before each test
     */
    void setUp(void)
    {
    }

    /*----------------------------------------------------------------------*/
    /*
     * Unit Test Teardown: run after each test
     * 
     */
    void tearDown(void)
    {
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of JBoss that is NOT running
     */
    SCXHandle<AppServerInstance> createANotRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(createARunningDeepMonitoredJBossInstance());
        instance->SetIsRunning(false);
        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of JBoss that should be inserted into the is running
     */
    SCXHandle<AppServerInstance> createCachedButRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_CACHED_BUT_RUNNING_PATH,
                        JBOSS_CACHED_BUT_RUNNING_TYPE));
        instance->SetHttpPort(JBOSS_CACHED_BUT_RUNNING_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_CACHED_BUT_RUNNING_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_CACHED_BUT_RUNNING_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_CACHED_BUT_RUNNING_VERSION);

        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of JBoss that is running and deep monitored
     */
    SCXHandle<AppServerInstance> createARunningDeepMonitoredJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_A_PROCESS_PATH,
                        JBOSS_A_PROCESS_TYPE));
        instance->SetHttpPort(JBOSS_A_PROCESS_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_A_PROCESS_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_A_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_A_PROCESS_VERSION);

        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a cached instance of JBoss
     */
    SCXHandle<AppServerInstance> createCachedJBossInstanceWithSpaceAndUnderscoreInPath(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_CACHED_PATH,
                        JBOSS_CACHED_TYPE));
        instance->SetHttpPort(JBOSS_CACHED_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_CACHED_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_CACHED_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(JBOSS_CACHED_VERSION);

        return instance;
    }

    
    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a plain, vanilla instance of JBoss with a given id
     */
    SCXHandle<AppServerInstance> createRunningJBossInstance(std::wstring id)
    {
        std::wstring diskpath(L"/u/hcswl1030/apps/");
        diskpath.append(id).append(L"/jboss/server/").append(id);

        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        diskpath,
                        JBOSS_SIMPLE_TYPE));
        instance->SetHttpPort(JBOSS_SIMPLE_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_SIMPLE_HTTPS_PORT);
        instance->SetIsDeepMonitored(false, JBOSS_SIMPLE_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_SIMPLE_VERSION);

        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a plain, vanilla instance of JBoss
     */
    SCXHandle<AppServerInstance> createDefaultRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_SIMPLE_PATH,
                        JBOSS_SIMPLE_TYPE));
        instance->SetHttpPort(JBOSS_SIMPLE_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_SIMPLE_HTTPS_PORT);
        instance->SetIsDeepMonitored(false, JBOSS_SIMPLE_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_SIMPLE_VERSION);

        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of the default JBOSS instance that is not running. 
     * This cached item should disappear in the merge.
     */
    SCXHandle<AppServerInstance> createDefaultNotRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(createDefaultRunningJBossInstance());
        instance->SetIsRunning(false);
        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of the default JBOSS instance and change its ports and 
     * it to not running.  This cached item should disappear in the merge.
     */
    SCXHandle<AppServerInstance> createDefaultNotRunningJBossInstanceWithDifferentPorts(void)
    {
        SCXHandle<AppServerInstance> instance(createDefaultRunningJBossInstance());
        instance->SetIsRunning(false);
        instance->SetHttpPort(L"12345");
        instance->SetHttpsPort(L"");
        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a MINIMAL instance of JBoss
     */
    SCXHandle<AppServerInstance> createMinimalNotRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_MINIMAL_PATH,
                        JBOSS_MINIMAL_TYPE));
        instance->SetHttpPort(JBOSS_MINIMAL_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_MINIMAL_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, JBOSS_MINIMAL_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(JBOSS_MINIMAL_VERSION);

        return instance;
    }

    /*----------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a NEW JBoss instance that is running.  This represents a new
     * process that has not been previously cached.
     */
    SCXHandle<AppServerInstance> createNewRunningJBossInstance(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        JBOSS_NEW_RUNNING_PATH,
                        JBOSS_NEW_RUNNING_TYPE));
        instance->SetHttpPort(JBOSS_NEW_RUNNING_HTTP_PORT);
        instance->SetHttpsPort(JBOSS_NEW_RUNNING_HTTPS_PORT);
        instance->SetIsDeepMonitored(false, JBOSS_NEW_RUNNING_PROTOCOL);
        instance->SetIsRunning(true);
        instance->SetVersion(JBOSS_NEW_RUNNING_VERSION);

        return instance;
    }
    
    /*----------------------------------------------------------------------*/
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

    /*----------------------------------------------------------------------*/
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

    
    /*----------------------------------------------------------------------*/
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

    /*
     * Verify that merging two empty lists results in with an empty list.
     */
    void TestUpdatingKnownInstancesWithTwoEmptyInputs(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        vector<SCXHandle<AppServerInstance> > processList;

        // Verify input
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( zero, processList.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( zero, previouslyKnownStates.size());
    }

    /*
     * Verify that merging an initially empty list with one running process 
     * results in the known states being updated so that it is equal to the
     * process list.
     */
    void TestUpdatingKnownInstancesThatIsInitiallyEmptyWithOneNewProcess(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createDefaultRunningJBossInstance());

        CPPUNIT_ASSERT_EQUAL( false, processList[0]->GetIsDeepMonitored());
        CPPUNIT_ASSERT_EQUAL( true, processList[0]->GetIsRunning());

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( zero, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( one, processList.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT( 
                *(createDefaultRunningJBossInstance()) == 
                        *(previouslyKnownStates[0]) );
    }

    /*
     * Verify that merging an initially empty list with one running process 
     * results in the known states being updated so that it is equal to the
     * process list.
     */
    void TestUpdatingKnownInstancesThatContains22RunningProcsWithTheSameProcs(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        vector<SCXHandle<AppServerInstance> > processList;

        processList.push_back(createRunningJBossInstance(L"adminrx"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"adminrx"));
        processList.push_back(createRunningJBossInstance(L"contextagent"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"contextagent"));
        processList.push_back(createRunningJBossInstance(L"ha"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"ha"));
        processList.push_back(createRunningJBossInstance(L"hcservice"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hcservice"));
        processList.push_back(createRunningJBossInstance(L"hdm"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hdm"));
        processList.push_back(createRunningJBossInstance(L"hdv"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hdv"));
        processList.push_back(createRunningJBossInstance(L"hec"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hec"));
        processList.push_back(createRunningJBossInstance(L"hed"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hed"));
        processList.push_back(createRunningJBossInstance(L"hen"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hen"));
        processList.push_back(createRunningJBossInstance(L"hep"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hep"));
        processList.push_back(createRunningJBossInstance(L"hep_author"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hep_author"));
        processList.push_back(createRunningJBossInstance(L"hhs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hhs"));
        processList.push_back(createRunningJBossInstance(L"hmrcs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hmrcs"));
        processList.push_back(createRunningJBossInstance(L"hocs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hocs"));
        processList.push_back(createRunningJBossInstance(L"hot"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hot"));
        processList.push_back(createRunningJBossInstance(L"hpcs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hpcs"));
        processList.push_back(createRunningJBossInstance(L"hqmct"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hqmct"));
        processList.push_back(createRunningJBossInstance(L"hscs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hscs"));
        processList.push_back(createRunningJBossInstance(L"hwc"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"hwc"));
        processList.push_back(createRunningJBossInstance(L"security"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"security"));
        processList.push_back(createRunningJBossInstance(L"updatemgr"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"updatemgr"));
        processList.push_back(createRunningJBossInstance(L"vfs"));
        previouslyKnownStates.push_back(createRunningJBossInstance(L"vfs"));
        
        // Verify input
        CPPUNIT_ASSERT( 22 == previouslyKnownStates.size());
        CPPUNIT_ASSERT( 22 == processList.size());

        // Test the desired method
        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output
        CPPUNIT_ASSERT( 22 == previouslyKnownStates.size());
        vector<SCXHandle<AppServerInstance> >::iterator it;
        for (it = previouslyKnownStates.begin(); it != previouslyKnownStates.end(); ++it)
        {
            CPPUNIT_ASSERT((*it)->GetIsRunning());
        }
    }

    /*
     * Verify that have a previously known state that id not running
     * looks the same after merging it with an empty set of running
     * processes.
     */
    void TestUpdatingKnownInstancesWhenPreviouslyKnownStateOfNotRunningAndNoProcessesInput(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsDeepMonitored());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning());
        
        vector<SCXHandle<AppServerInstance> > processList;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( zero, processList.size());

        // Test the desired method
        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output - the instance should be the same (i.e. the known
        // state should not have been updated)
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT( 
                *(createDefaultNotRunningJBossInstanceWithDifferentPorts()) == 
                        *(previouslyKnownStates[0]) );
    }

    /*
     * Verify that have a previously known state that is running shows up in 
     * the known state array but has been marked as not running
     */
    void TestUpdatingKnownInstancesWhenPreviouslyKnownStateOfRunningAndNoProcessesInput(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        previouslyKnownStates.push_back(createDefaultRunningJBossInstance());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsDeepMonitored());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning());
        
        vector<SCXHandle<AppServerInstance> > processList;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( zero, processList.size());

        // Test the desired method
        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output - the instance should be different than the input.
        // Specifically IsRunning should now be off 
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_MESSAGE( "The IsRunning state should have changed", 
                *(createDefaultRunningJBossInstance()) != 
                        *(previouslyKnownStates[0]) );
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning() );
        CPPUNIT_ASSERT( 
                *(createDefaultNotRunningJBossInstance()) == 
                        *(previouslyKnownStates[0]) );
    }

    /*
     * Verify that port update works on a single instance
     */
    void TestUpdatingKnownInstancesForPortChangeOfSingleInstance(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsDeepMonitored());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning());
        
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createDefaultRunningJBossInstance());
        CPPUNIT_ASSERT_EQUAL( false, processList[0]->GetIsDeepMonitored());
        CPPUNIT_ASSERT_EQUAL( true, processList[0]->GetIsRunning());

        CPPUNIT_ASSERT( 
                previouslyKnownStates[0]->GetHttpPort() !=
                processList[0]->GetHttpPort());
        CPPUNIT_ASSERT( 
                previouslyKnownStates[0]->GetHttpsPort() !=
                processList[0]->GetHttpsPort());

        // Verify input
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( one, processList.size());

        // Test the desired method
        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output - the instance should be different than the input.
        // Specifically IsRunning should now be off 
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_MESSAGE( "The ports should be different", 
                *(createDefaultNotRunningJBossInstanceWithDifferentPorts()) != 
                        *(previouslyKnownStates[0]) );
        CPPUNIT_ASSERT( 
                *(createDefaultRunningJBossInstance()) == 
                        *(previouslyKnownStates[0]) );
    }

    /*
     * Verify that the deep monitored flag is updated appropriately for
     * a single (running) instance.
     */
    void TestUpdatingKnownInstancesForDeepMonitoredOfSingleRunningInstance(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        SCXHandle<AppServerInstance> desiredResult =
                createDefaultRunningJBossInstance();
        desiredResult->SetIsDeepMonitored(true, L"HTTP");
        previouslyKnownStates.push_back(desiredResult);
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning() );
        
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createDefaultRunningJBossInstance());
        CPPUNIT_ASSERT_EQUAL( false, processList[0]->GetIsDeepMonitored());
        
        CPPUNIT_ASSERT( 
                *(previouslyKnownStates[0]) !=
                *(processList[0]));

        // Verify input
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( one, processList.size());

        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output - the instance should be different than the input.
        // Specifically IsRunning should now be off 
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_MESSAGE( "The IsDeepMonitored state should have changed", 
                *(createDefaultRunningJBossInstance()) != 
                        *(previouslyKnownStates[0]) );
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsDeepMonitored() );
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning() );
    }

    /*
     * Verify that the deep monitored flag is updated appropriately for
     * a single (not running) instance.
     */
    void TestUpdatingKnownInstancesForDeepMonitoredOfSingleNotRunningInstance(void)
    {
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        SCXHandle<AppServerInstance> desiredResult =
                createDefaultNotRunningJBossInstance();
        desiredResult->SetIsDeepMonitored(true, L"HTTP");
        previouslyKnownStates.push_back(desiredResult);
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning() );
        
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createDefaultRunningJBossInstance());
        CPPUNIT_ASSERT_EQUAL( false, processList[0]->GetIsDeepMonitored());
        
        CPPUNIT_ASSERT( 
                *(previouslyKnownStates[0]) !=
                *(processList[0]));

        // Verify input
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_EQUAL( one, processList.size());

        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output - the instance should be different than the input.
        // Specifically IsRunning should now be off 
        CPPUNIT_ASSERT_EQUAL( one, previouslyKnownStates.size());
        CPPUNIT_ASSERT_MESSAGE( "The IsDeepMonitored state should have changed", 
                *(createDefaultRunningJBossInstance()) != 
                        *(previouslyKnownStates[0]) );
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsDeepMonitored() );
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning() );
    }

    /*
     * Just a warning, this is a complex test. This combines several of the
     * simplier tests so that they are all handled at once.
     */
    void TestUpdatingKnownInstancesWithManyDuplicatesWhereThePreviousEntriesAreNotRunning(void)
    {
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createARunningDeepMonitoredJBossInstance());
        processList.push_back(createRunningJBossInstanceWithSpaceInPath());
        processList.push_back(createDefaultRunningJBossInstance());
        processList.push_back(createNewRunningJBossInstance());
        
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        
        // Duplicate
        previouslyKnownStates.push_back(createNotRunningJBossInstanceWithSpaceInPath());
        
        // Duplicate
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        
        // Unique
        previouslyKnownStates.push_back(createMinimalNotRunningJBossInstance());
        
        // Duplicate
        previouslyKnownStates.push_back(createANotRunningJBossInstance());
        
        // Unique
        previouslyKnownStates.push_back(createCachedJBossInstanceWithSpaceAndUnderscoreInPath());

        // Verify all previous entries are off
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[1]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[2]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[3]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[4]->GetIsRunning());

        // Verify input
        size_t four = 4;
        size_t five = 5;
        CPPUNIT_ASSERT_EQUAL( four, processList.size());
        CPPUNIT_ASSERT_EQUAL( five, previouslyKnownStates.size());

        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output
        size_t six= 6;
        CPPUNIT_ASSERT_EQUAL( six, previouslyKnownStates.size());
        CPPUNIT_ASSERT( 
                *(createCachedJBossInstanceWithSpaceAndUnderscoreInPath()) ==
                        *(previouslyKnownStates[0]));
        CPPUNIT_ASSERT( 
                *(createARunningDeepMonitoredJBossInstance()) == 
                        *(previouslyKnownStates[1]));
        CPPUNIT_ASSERT( 
                *(createRunningJBossInstanceWithSpaceInPath()) == 
                        *(previouslyKnownStates[2]));
        CPPUNIT_ASSERT( 
                *(createDefaultRunningJBossInstance()) == 
                        *(previouslyKnownStates[3]));
        CPPUNIT_ASSERT( 
                *(createMinimalNotRunningJBossInstance()) == 
                        *(previouslyKnownStates[4]));
        CPPUNIT_ASSERT( 
                *(createNewRunningJBossInstance()) == 
                        *(previouslyKnownStates[5]));
    }

    /*
     * Merge two lists where things are out-of-order and some of the 
     * previous entries were marked as running.
     * 
     * Just a warning, this is a complex test. This combines several of the
     * simplier tests so that they are all handled at once.
     */
    void TestUpdatingKnownInstancesWithManyDuplicatesWhereSomePreviousEntriesAreRunning(void)
    {
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createARunningDeepMonitoredJBossInstance());
        processList.push_back(createRunningJBossInstanceWithSpaceInPath());
        processList.push_back(createDefaultRunningJBossInstance());
        processList.push_back(createNewRunningJBossInstance());
        
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        
        // Duplicate (0)
        previouslyKnownStates.push_back(createRunningJBossInstanceWithSpaceInPath());
        
        // Duplicate (1)
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        
        // Unique (2)
        previouslyKnownStates.push_back(createMinimalNotRunningJBossInstance());
        
        // Unique (3)
        previouslyKnownStates.push_back(createCachedButRunningJBossInstance());
        
        // Duplicate (4)
        previouslyKnownStates.push_back(createARunningDeepMonitoredJBossInstance());
        
        // Unique (5)
        previouslyKnownStates.push_back(createCachedJBossInstanceWithSpaceAndUnderscoreInPath());

        // Verify IsRunning for the previous states
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[1]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[2]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[3]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[4]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[5]->GetIsRunning());

        // Verify input
        size_t four = 4;
        size_t six = 6;
        CPPUNIT_ASSERT_EQUAL( four, processList.size());
        CPPUNIT_ASSERT_EQUAL( six, previouslyKnownStates.size());

        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output
        size_t seven = 7;
        CPPUNIT_ASSERT_EQUAL( seven, previouslyKnownStates.size());
        CPPUNIT_ASSERT( 
                *(createCachedJBossInstanceWithSpaceAndUnderscoreInPath()) ==
                        *(previouslyKnownStates[0]));
        
        // This instance was previously running (hence the not equals!)
        SCXHandle<AppServerInstance> flippedIsRunning = 
                createCachedButRunningJBossInstance();
        CPPUNIT_ASSERT( 
                *(flippedIsRunning) != 
                        *(previouslyKnownStates[1]));
        flippedIsRunning->SetIsRunning(false);
        CPPUNIT_ASSERT( 
                *(flippedIsRunning) == 
                        *(previouslyKnownStates[1]));
        
        CPPUNIT_ASSERT( 
                *(createARunningDeepMonitoredJBossInstance()) == 
                        *(previouslyKnownStates[2]));
        
        CPPUNIT_ASSERT( 
                *(createRunningJBossInstanceWithSpaceInPath()) == 
                        *(previouslyKnownStates[3]));
        CPPUNIT_ASSERT( 
                *(createDefaultRunningJBossInstance()) == 
                        *(previouslyKnownStates[4]));
        CPPUNIT_ASSERT( 
                *(createMinimalNotRunningJBossInstance()) == 
                        *(previouslyKnownStates[5]));
        CPPUNIT_ASSERT( 
                *(createNewRunningJBossInstance()) == 
                        *(previouslyKnownStates[6]));
    }

    /*
     * Merge two lists where things are out-of-order, some of the 
     * previous entries were marked as running, and changes to the 
     * deep monitored flag too. In short, this has everything.
     * 
     * Just a warning, this is a complex test. This combines several of the
     * simplier tests so that they are all handled at once.
     */
    void TestUpdatingKnownInstancesWithManyDuplicatesChangesToAllFlags(void)
    {
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createARunningDeepMonitoredJBossInstance());
        processList[0]->SetIsDeepMonitored(false, L"");
        processList.push_back(createRunningJBossInstanceWithSpaceInPath());
        processList.push_back(createDefaultRunningJBossInstance());
        processList.push_back(createNewRunningJBossInstance());
        
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        
        // Duplicate (0)
        previouslyKnownStates.push_back(createRunningJBossInstanceWithSpaceInPath());
        
        // Duplicate (1)
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        
        // Unique (2)
        previouslyKnownStates.push_back(createMinimalNotRunningJBossInstance());
        
        // Unique (3)
        previouslyKnownStates.push_back(createCachedButRunningJBossInstance());
        
        // Duplicate (4)
        previouslyKnownStates.push_back(createARunningDeepMonitoredJBossInstance());
        
        // Unique (5)
        previouslyKnownStates.push_back(createCachedJBossInstanceWithSpaceAndUnderscoreInPath());

        // Verify IsRunning for the previous states
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[0]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[1]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[2]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[3]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[4]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[5]->GetIsRunning());

        // Verify input
        size_t four = 4;
        size_t six = 6;
        CPPUNIT_ASSERT_EQUAL( four, processList.size());
        CPPUNIT_ASSERT_EQUAL( six, previouslyKnownStates.size());

        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesNotRemove(new FakeRemover(false));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesNotRemove));

        // Verify output
        size_t seven = 7;
        CPPUNIT_ASSERT_EQUAL( seven, previouslyKnownStates.size());
        CPPUNIT_ASSERT( 
                *(createCachedJBossInstanceWithSpaceAndUnderscoreInPath()) ==
                        *(previouslyKnownStates[0]));
        
        // This instance was previously running (hence the not equals!)
        SCXHandle<AppServerInstance> flippedIsRunning = 
                createCachedButRunningJBossInstance();
        CPPUNIT_ASSERT_MESSAGE("This instance should no longer be marked as running", 
                *(flippedIsRunning) != 
                        *(previouslyKnownStates[1]));
        flippedIsRunning->SetIsRunning(false);
        CPPUNIT_ASSERT( 
                *(flippedIsRunning) == 
                        *(previouslyKnownStates[1]));
        
        // This was manually set to not be deep monitored in
        // the process list. The IsDeepMonitored flag should have
        // been picked up by the previous state
        CPPUNIT_ASSERT_MESSAGE( "Failed to pick-up the deep monitored flag from the previously known state",
                *(createARunningDeepMonitoredJBossInstance()) == 
                        *(previouslyKnownStates[2]));
        
        CPPUNIT_ASSERT( 
                *(createRunningJBossInstanceWithSpaceInPath()) == 
                        *(previouslyKnownStates[3]));
        CPPUNIT_ASSERT( 
                *(createDefaultRunningJBossInstance()) == 
                        *(previouslyKnownStates[4]));
        CPPUNIT_ASSERT( 
                *(createMinimalNotRunningJBossInstance()) == 
                        *(previouslyKnownStates[5]));
        CPPUNIT_ASSERT( 
                *(createNewRunningJBossInstance()) == 
                        *(previouslyKnownStates[6]));
    }

    /*
     * Merge two lists where things are out-of-order, some of the 
     * previous entries were marked as running, and changes to the 
     * deep monitored flag too. In short, this has everything.
     * 
     * Just a warning, this is a complex test. This combines several of the
     * simplier tests so that they are all handled at once.
     */
    void TestUpdatingKnownInstancesWhenAllKnownInstancesAreNotOnDisk(void)
    {
        vector<SCXHandle<AppServerInstance> > processList;
        processList.push_back(createRunningJBossInstanceWithSpaceInPath());
        processList.push_back(createNewRunningJBossInstance());
        
        vector<SCXHandle<AppServerInstance> > previouslyKnownStates;
        
        // Duplicate (0)
        previouslyKnownStates.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        
        // Unique (1)
        previouslyKnownStates.push_back(createMinimalNotRunningJBossInstance());
        
        // Unique (2)
        previouslyKnownStates.push_back(createCachedButRunningJBossInstance());
        
        // Unique (3)
        previouslyKnownStates.push_back(createCachedJBossInstanceWithSpaceAndUnderscoreInPath());

        // Verify IsRunning for the previous states
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[0]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[1]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( true, previouslyKnownStates[2]->GetIsRunning());
        CPPUNIT_ASSERT_EQUAL( false, previouslyKnownStates[3]->GetIsRunning());

        // Verify input
        size_t two = 2;
        size_t four = 4;
        CPPUNIT_ASSERT_EQUAL( two, processList.size());
        CPPUNIT_ASSERT_EQUAL( four, previouslyKnownStates.size());

        // This is different, will get rid of all the cache entries
        // that are not on disk
        SCXHandle<IRemoveNonexistentAppServerInstances> 
                  removerThatDoesRemove(new FakeRemover(true));

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
                        previouslyKnownStates, 
                        processList,
                        removerThatDoesRemove));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( two, previouslyKnownStates.size());

        CPPUNIT_ASSERT( 
                *(createRunningJBossInstanceWithSpaceInPath()) == 
                        *(previouslyKnownStates[0]));
        CPPUNIT_ASSERT( 
                *(createNewRunningJBossInstance()) == 
                        *(previouslyKnownStates[1]));
    }

    /*
     * Verify that merging an empty process list and empty cache
     * results in nothing.
     */
    void TestManipulateAppServerInstancesBothEmpty()
    {
        vector<SCXHandle<AppServerInstance> > processes;
        vector<SCXHandle<AppServerInstance> > cache;
        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        CPPUNIT_ASSERT_EQUAL( zero, processes.size());
        CPPUNIT_ASSERT_EQUAL( zero, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache(processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( zero, processes.size());
        CPPUNIT_ASSERT_EQUAL( zero, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());
    }

    /*
     * Verify that merging a non-empty process list and empty cache
     * results in one item (just that from the process list).
     */
    void TestMergeOneProcessAndEmptyCache()
    {
        vector<SCXHandle<AppServerInstance> > processes;
        processes.push_back(createDefaultRunningJBossInstance());
        vector<SCXHandle<AppServerInstance> > cache;
        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT_EQUAL( zero, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache(processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT( *(createDefaultRunningJBossInstance()) == *(processes[0]));
        CPPUNIT_ASSERT_EQUAL( zero, cache.size());
        CPPUNIT_ASSERT_EQUAL( one, result.size());
        CPPUNIT_ASSERT( *(createDefaultRunningJBossInstance()) == *(result[0]));
    }
    
    /*
     * Verify that merging a non-empty process list and empty cache
     * results in one item (just that from the process list).
     */
    void TestMergeEmptyProcessAndOneCache(void)
    {
        vector<SCXHandle<AppServerInstance> > processes;
        vector<SCXHandle<AppServerInstance> > cache;
        cache.push_back(createJBossInstanceNotRunning());
        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( zero, processes.size());
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache(processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( zero, processes.size());
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT( *(createJBossInstanceNotRunning()) == *(cache[0]));
        CPPUNIT_ASSERT_EQUAL( one, result.size());
        CPPUNIT_ASSERT( *(createJBossInstanceNotRunning()) == *(result[0]));
    }

    /*
     * Verify a very simple merge scenario: a unique process and a 
     * unique cache item are merged, the result is both items. 
     */
    void TestMergeOneProcessAndOneCache()
    {
        vector<SCXHandle<AppServerInstance> > processes;
        processes.push_back(createDefaultRunningJBossInstance());
        vector<SCXHandle<AppServerInstance> > cache;
        cache.push_back(createJBossInstanceNotRunning());
        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        size_t two = 2;
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache(processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT( *(createDefaultRunningJBossInstance()) == *(processes[0]));
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT( *(createJBossInstanceNotRunning()) == *(cache[0]));
        CPPUNIT_ASSERT_EQUAL( two, result.size());
        CPPUNIT_ASSERT( *(createDefaultRunningJBossInstance()) == *(result[0]));
        CPPUNIT_ASSERT( *(createJBossInstanceNotRunning()) == *(result[1]));
    }
    
    /*
     * Verify the a merge overlap of a process and it's cached 
     * representation. The result should just be a copy of the item
     * from the list of running processes.
     */
    void TestMergeSameFromProcessAndCache()
    {
        vector<SCXHandle<AppServerInstance> > processes;
        processes.push_back(createRunningJBossInstanceWithSpaceInPath());
        vector<SCXHandle<AppServerInstance> > cache;
        cache.push_back(createNotRunningJBossInstanceWithSpaceInPath());
        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        size_t one = 1;
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache (processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( one, processes.size());
        CPPUNIT_ASSERT( *(createRunningJBossInstanceWithSpaceInPath()) == *(processes[0]));
        CPPUNIT_ASSERT_EQUAL( one, cache.size());
        CPPUNIT_ASSERT( *(createNotRunningJBossInstanceWithSpaceInPath()) == *(cache[0]));
        CPPUNIT_ASSERT_EQUAL( one, result.size());
        CPPUNIT_ASSERT( *(createRunningJBossInstanceWithSpaceInPath()) == *(result[0]));
    }

    /*
     * Verify a complex merge. The inputs have several duplicate process and 
     * cache items as well as some unique ones. Another factor is that the
     * vectors supplied are out-of-order. 
     */
    void TestMergeManyDuplicateProcessesAndCacheItemsThatAreOutOfOrder()
    {
        vector<SCXHandle<AppServerInstance> > processes;
        processes.push_back(createARunningDeepMonitoredJBossInstance());
        processes.push_back(createRunningJBossInstanceWithSpaceInPath());
        processes.push_back(createDefaultRunningJBossInstance());
        processes.push_back(createNewRunningJBossInstance());
        
        vector<SCXHandle<AppServerInstance> > cache;
        
        // Duplicate
        cache.push_back(createNotRunningJBossInstanceWithSpaceInPath());
        
        // Duplicate
        cache.push_back(createDefaultNotRunningJBossInstanceWithDifferentPorts());
        
        // Unique
        cache.push_back(createMinimalNotRunningJBossInstance());
        
        // Duplicate
        cache.push_back(createANotRunningJBossInstance());
        
        // Unique
        cache.push_back(createCachedJBossInstanceWithSpaceAndUnderscoreInPath());

        vector<SCXHandle<AppServerInstance> > result;

        // Verify input
        size_t zero = 0;
        size_t four = 4;
        size_t five = 5;
        CPPUNIT_ASSERT_EQUAL( four, processes.size());
        CPPUNIT_ASSERT_EQUAL( five, cache.size());
        CPPUNIT_ASSERT_EQUAL( zero, result.size());

        // Test the desired method
        CPPUNIT_ASSERT_NO_THROW(
                ManipulateAppServerInstances::MergeProcessesAndCache (processes, cache, result));

        // Verify output
        CPPUNIT_ASSERT_EQUAL( four, processes.size());
        CPPUNIT_ASSERT_EQUAL( five, cache.size());
        size_t six= 6;
        CPPUNIT_ASSERT_EQUAL( six, result.size());
        CPPUNIT_ASSERT( *(createCachedJBossInstanceWithSpaceAndUnderscoreInPath()) == *(result[0]));
        CPPUNIT_ASSERT( *(createARunningDeepMonitoredJBossInstance()) == *(result[1]));
        CPPUNIT_ASSERT( *(createRunningJBossInstanceWithSpaceInPath()) == *(result[2]));
        CPPUNIT_ASSERT( *(createDefaultRunningJBossInstance()) == *(result[3]));
        CPPUNIT_ASSERT( *(createMinimalNotRunningJBossInstance()) == *(result[4]));
        CPPUNIT_ASSERT( *(createNewRunningJBossInstance()) == *(result[5]));
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( ManipulateAppServerInstancesTest );
}

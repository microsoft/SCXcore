/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
    
    Created date    2011-05-18

    Appserver data colletion test class.
    
    Only tests the functionality of the enumeration class.
    The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>

#include <appserverenumeration.h>
#include <appserverinstance.h>

#include <testutils/scxunit.h>
#include <iostream>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

/**************************************************************************************/
// TestSpy design pattern use for this mock object to track calling of the reading and
// writing to disk of the cache
/**************************************************************************************/
class TestSpyAppServerEnumeration : public AppServerEnumeration
{
public:

    /*
     * Simple Constructor with defaults 
     * that initializes the TestSpy counters
     */
    TestSpyAppServerEnumeration() : 
        AppServerEnumeration(),
        m_ReadInstancesCalledCounter(0),
        m_WriteInstancesCalledCounter(0),
        m_NumberOfCallsToUpdateInstances(0)
    {
    }
 
    /*
     * Constructor that can control the PAL dependencies
     */
    TestSpyAppServerEnumeration(SCXHandle<AppServerPALDependencies> deps) :
        AppServerEnumeration(deps),
        m_ReadInstancesCalledCounter(0),
        m_WriteInstancesCalledCounter(0),
        m_NumberOfCallsToUpdateInstances(0)
    {
    }
    
    /*----------------------------------------------------------------------------*/
    /**
       Update all AppServer data

    */
    void UpdateInstances()
    {
        ++m_NumberOfCallsToUpdateInstances;
        AppServerEnumeration::UpdateInstances();
    }

    int m_ReadInstancesCalledCounter;

    int m_WriteInstancesCalledCounter;
    
    /*
     * Returns back number of times the Update() method
     * has been called.
     */
    int GetNumberOfCallsToUpdateInstances()
    {
        return m_NumberOfCallsToUpdateInstances;
    }
    
protected:
    
    /*
     * Overridden base class method to keep track of how many times
     * the method for reading the cache was called.
     */
    void ReadInstancesFromDisk()
    {
        ++m_ReadInstancesCalledCounter;
    }
    
    /*
     * Overridden base class method to keep track of how many times
     * the method for writing the cache was called.
     */
    void WriteInstancesToDisk()
    {
        ++m_WriteInstancesCalledCounter;
    }

private:
    /*
     * Counter to track the number of times Update is called
     */
    int m_NumberOfCallsToUpdateInstances;
    
};


/**************************************************************************************/
// Mock ProcessInstance Class to simulate a ProcessInstance, the 
// GetParameters method will return a set of test parameters
// 
/**************************************************************************************/
class MockProcessInstance : public ProcessInstance
{
public:
#if defined(hpux)
    MockProcessInstance(scxpid_t pid, struct pst_status *pstatus) : ProcessInstance(pid,pstatus) {}
#elif defined(aix)
    MockProcessInstance(scxpid_t pid, struct procentry64 *pentry) : ProcessInstance(pid,pentry) {}
#else
    MockProcessInstance(scxpid_t pid, const char* basename) : ProcessInstance(pid,basename) {}
#endif

    /**************************************************************************************/
    // Mock GetParameters method to return the parameters required to test the  ProcessInstance
    // 
    /**************************************************************************************/
    bool GetTheParameters(std::vector<std::string>& params)
    {
        for(std::vector<std::string>::iterator pos = m_params.begin(); pos != m_params.end(); ++pos) 
        {
           params.push_back(*pos);
        }
        return true;
    }
    
    /**************************************************************************************/
    // Helper method used to add/create process parameters that are returned by
    // GetParameters
    /**************************************************************************************/
    void AddParameter(std::string const val)
    {
        m_params.push_back(val);
    }

private:
    std::vector<std::string> m_params;
};

/**************************************************************************************/
// Mock AppServerPALDependencies Class, this class is used as a proxy  between the 
// AppSServerEnumeration class and the ProcessInstance class. It is meant to injected
// into AppSServerEnumeration class for testing purposes.
/**************************************************************************************/
class MockAppServerPALDependencies : public AppServerPALDependencies
{
public:
    
    /**************************************************************************************/
    // Mock Find method which emulated the ProcessEnumeration.Find method
    /**************************************************************************************/
    std::vector<SCXCoreLib::SCXHandle<ProcessInstance> > Find(const std::wstring& name)
    {
        std::wstring x = name;
        return m_Inst;
    }
    
    /**************************************************************************************/
    // Helper method to populate ProcessInstances so that the 'Find' method can retrieve 
    // good test values.
    /**************************************************************************************/
    SCXCoreLib::SCXHandle<MockProcessInstance> CreateProcessInstance(scxpid_t pid, const char* basename)
    {
#if defined(hpux)
        struct pst_status stat;
        strcpy(stat.pst_ucomm, basename);
        SCXCoreLib::SCXHandle<MockProcessInstance> inst(new MockProcessInstance(pid, &stat));
#elif defined(aix)
        struct procentry64 entry;
        strcpy(entry.pi_comm, basename);
        SCXCoreLib::SCXHandle<MockProcessInstance> inst(new MockProcessInstance(pid, &entry));
#else
        SCXCoreLib::SCXHandle<MockProcessInstance> inst(new MockProcessInstance(pid, basename));
#endif
        m_Inst.push_back(inst);
        m_InstTest.push_back(inst);
        return inst;
    }
    
    /**************************************************************************************/
    // Mock PAL GetParameters method. This method get the paramerters for a specific 
    // ProcessInstance.
    /**************************************************************************************/
    bool GetParameters(SCXCoreLib::SCXHandle<ProcessInstance> inst, std::vector<std::string>& params)
    {
        for (std::vector<SCXCoreLib::SCXHandle<MockProcessInstance> >::iterator it = m_InstTest.begin(); it != m_InstTest.end(); it++)
        {
            if((SCXCoreLib::SCXHandle<ProcessInstance>)(*it) == inst)
            {
               (*it)->GetTheParameters(params);
               return true;
            }
        }
        return false;
    }
    
    /**************************************************************************************/
    // Mock PAL GetWeblogicInstances method. This method creates WeblogicAppserverinstances 
    // 
    /**************************************************************************************/
    void GetWeblogicInstances(vector<wstring> weblogicProcesses, vector<SCXHandle<AppServerInstance> >& newInst)
    {
        wstring wideHttpPort = L"7001";
        wstring wideHttpsPort = L"7002";
        wstring wideVersion = L"10.3.2.0";

        vector<wstring>::iterator tmp = 
                unique(weblogicProcesses.begin(), weblogicProcesses.end());
        weblogicProcesses.resize(tmp-weblogicProcesses.begin());

        for(tmp=weblogicProcesses.begin();tmp !=weblogicProcesses.end(); ++tmp)
        {
            SCXCoreLib::SCXHandle<AppServerInstance> instance(
                new AppServerInstance (*tmp,L"Weblogic") );
            newInst.push_back(instance);
        }
    }
    
private:
    std::vector<SCXCoreLib::SCXHandle<ProcessInstance> > m_Inst;
    std::vector<SCXCoreLib::SCXHandle<MockProcessInstance> > m_InstTest;
};

/**************************************************************************************/
// The Unit Test class for AppServerEnumeration.
/**************************************************************************************/
class AppServerEnumeration_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( AppServerEnumeration_Test  );

    CPPUNIT_TEST( JBoss_Process_Good_Params_space );
    CPPUNIT_TEST( JBoss_Process_Good_Params_equal );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_Main );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_ClassPath_long );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_ClassPath_short );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_ClassPath_no_value );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_ClassPath_no_value_equal );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_RunJar_in_ClassPath );
    CPPUNIT_TEST( JBoss_Process_Bad_Params__No_RunJar_in_longer_ClassPath );
    CPPUNIT_TEST( JBoss_Process_Good_Params_Using_ServerNameProperty );
    CPPUNIT_TEST( JBoss_Process_Good_Params_3_Running );
    CPPUNIT_TEST( JBoss_Process_Good_Params_22_Running );
    CPPUNIT_TEST( JBoss_Domain_Process_Good_Params );
    CPPUNIT_TEST( testReadInstancesMethodCalledAtInit );
    CPPUNIT_TEST( testWriteInstancesMethodCalledAtCleanup );
    CPPUNIT_TEST( Tomcat_Process_Good_Params );
    CPPUNIT_TEST( Tomcat_Process_Bad_Params_missing_Catalina_home );
    CPPUNIT_TEST( Tomcat_Process_Bad_Params_missing_Catalina_base );
    CPPUNIT_TEST( JBoss_Tomcat_Process_Good_params );
    CPPUNIT_TEST( JBoss_Tomcat_Process_Bad_Good_params );
    CPPUNIT_TEST( JBoss_Tomcat_Process_MixedGoodBad );
    
    CPPUNIT_TEST( WebSphere_Process_NonDefaultProfile );
    CPPUNIT_TEST( WebSphere_Process_Good_Params );
    CPPUNIT_TEST( WebSphere_Process_Fixing_Incorrect_Enumerations );
    CPPUNIT_TEST( WebSphere_Process_Bad_Params_TooFewArgs_Missing_Server );
    CPPUNIT_TEST( WebSphere_Process_Bad_Params_TooFewArgs_Missing_Node );
    CPPUNIT_TEST( WebSphere_Process_Bad_Params_TooFewArgs_Missing_ServerRoot );
    CPPUNIT_TEST( WebSphere_JBoss_Tomcat_Process_MixedGoodBad );
    
    CPPUNIT_TEST( Weblogic_Process_Good_Params );
	CPPUNIT_TEST( Weblogic_12cR1_Process_Good_Params );
    CPPUNIT_TEST( Weblogic_Process_Good_Params_NodeManager );
    CPPUNIT_TEST( Weblogic_Process_Bad_Params );
    CPPUNIT_TEST( Weblogic_Process_Good_Params_Two_Instances );
    CPPUNIT_TEST( Weblogic_Process_Good_Params_Two_Instances_One_Home );
    CPPUNIT_TEST( Weblogic_WebSphere_JBoss_Tomcat_Process_MixedGoodBad );
    
    CPPUNIT_TEST( UpdateInstances_Is_Not_Called );
    
    
    CPPUNIT_TEST_SUITE_END();

public:

    /**************************************************************************************/
    //
    // Unit Test Setup: run before each test
    //
    /**************************************************************************************/
    void setUp(void)
    {
    }

    /**************************************************************************************/
    //
    // Unit Test Teardown: run after each test
    //
    /**************************************************************************************/
    void tearDown(void)
    {
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters. The classpath key and value are space seperated
    // -classpath classpathvalue:classpathvalue. The values should be corectly parsed out
    // 
    /**************************************************************************************/
    void JBoss_Process_Good_Params_space()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-server");
        inst->AddParameter("-Xms128m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:MaxPermSize=256m");
        inst->AddParameter("-Dorg.jboss.resolver.warning=true");
        inst->AddParameter("-Dsun.rmi.dgc.client.gcInterval=3600000");
        inst->AddParameter("-Djava.net.preferIPv4Stack=true");
        inst->AddParameter("-Dprogram.name=run.sh");
        inst->AddParameter("-Djava.library.path=/opt/jboss-6.0/bin/native/lib");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/jboss-6.0/lib/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/optjboss-6.0/:/opt/jboss-6.0/bin/run.jar:/usr/lib");
        inst->AddParameter("org.jboss.Main");
        inst->AddParameter("-Djboss.service.binding.set=ports-01");
        inst->AddParameter("-b");
        inst->AddParameter("0.0.0.0");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/jboss-6.0/server/default/" == (*it)->GetId());
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters. The classpath key and value are seperated by an '='
    // -classpath=classpathvalue:classpathvalue. The values should be corectly parsed out
    // 
    /**************************************************************************************/
    void JBoss_Process_Good_Params_equal()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/opt/jboss-6.2/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();

        CPPUNIT_ASSERT(L"/opt/jboss-6.2/server/default/" == (*it)->GetId());
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter 'org.jboss.main' must exist
    // in the parameter list for this to be a valid JBoss instance.
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_Main()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss_Main"); //FAIL
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list for this to be a valid JBoss instance.
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_ClassPath_long()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpathx"); //FAIL
        inst->AddParameter("/opt/jboss-6.5/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list for this to be a valid JBoss instance.
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_ClassPath_short()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("Classpath"); //FAIL
        inst->AddParameter("/opt/jboss-6.5/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list and must be followed by the classpath value .
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_ClassPath_no_value()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");
        inst->AddParameter("-classpath"); // missing value

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list and must be followed by the classpath value .
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_ClassPath_no_value_equal()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-classpath="); // missing value
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }
    
    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list. The classpath value must contain a path entry for 'bin/run.jar'
    // this is the entry used to identify the home directory.
    // This test is for a single classpath jar file entry.
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_RunJar_in_ClassPath()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath"); 
        inst->AddParameter("/opt/jboss-6.6/bin/run.jam"); //FAIL
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with incorrect parameters. The parameter key '-classpath' must exist
    // in the parameter list. The classpath value must contain a path entry for 'bin/run.jar'
    // this is the entry used to identify the home directory.
    // This test is for a more complex classpath entry containg multiple paths.
    // 
    /**************************************************************************************/
    void JBoss_Process_Bad_Params__No_RunJar_in_longer_ClassPath()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath");   
        inst->AddParameter("/opt/jboss-6.6/bin:/usr/lib:/opt/jboss-6.6/bin/run.ja:/opt/jboss-6.6/lib"); //FAIL
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        asEnum.Update(false);
        
        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Bug #42733:
    // JBoss5 process discovery fails when specifying profile using -Djboss.server.name property
    //
    // For a JBoss application server started with the -Djboss.server.name property, verify that
    // this switch is correctly parsed from the command-line.
    // 
    /**************************************************************************************/
    void JBoss_Process_Good_Params_Using_ServerNameProperty()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        // java -Dprogram.name=run.sh -server -Xms128m -Xmx512m -XX:MaxPermSize=256m 
        //      -Dorg.jboss.resolver.warning=true -Dsun.rmi.dgc.client.gcInterval=3600000 
        //      -Dsun.rmi.dgc.server.gcInterval=3600000 -Djava.net.preferIPv4Stack=true 
        //      -Djava.endorsed.dirs=/home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/lib/endorsed 
        //      -classpath /home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/bin/run.jar 
        //       org.jboss.Main -b 0.0.0.0
        //
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/b/jboss-1234/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        // java -Dprogram.name=run.sh -server -Xms128m -Xmx512m -XX:MaxPermSize=256m 
        //      -Dorg.jboss.resolver.warning=true -Dsun.rmi.dgc.client.gcInterval=3600000 
        //      -Dsun.rmi.dgc.server.gcInterval=3600000 -Djava.net.preferIPv4Stack=true 
        //      -Djava.endorsed.dirs=/home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/lib/endorsed
        //      -classpath /home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/bin/run.jar org.jboss.Main
        //      -Djboss.service.binding.set=ports-01 -Djboss.server.name=profile2
        inst = pal->CreateProcessInstance(5678, "5678");
        inst->AddParameter("-classpath=/a/jboss-5678/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");
        inst->AddParameter("-Djboss.server.name=profile2");

        // java -Dprogram.name=run.sh -server -Xms128m -Xmx512m -XX:MaxPermSize=256m
        //      -Dorg.jboss.resolver.warning=true -Dsun.rmi.dgc.client.gcInterval=3600000
        //      -Dsun.rmi.dgc.server.gcInterval=3600000 -Djava.net.preferIPv4Stack=true
        //      -Djava.endorsed.dirs=/home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/lib/endorsed
        //      -classpath /home/ccrammo/AppServers/jboss/jboss-5.1.0.GA/bin/run.jar org.jboss.Main
        //      -Djboss.service.binding.set=ports-02 -Djboss.server.name=profile 3
        inst = pal->CreateProcessInstance(90, "90");
        inst->AddParameter("-classpath=/c/jboss-90/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-Djboss.server.name=profile 3");

        asEnum.Update(false);
        CPPUNIT_ASSERT(asEnum.Size() == 3);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/a/jboss-5678/server/profile2/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"/b/jboss-1234/server/default/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"/c/jboss-90/server/profile 3/" == (*(++it))->GetId());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with correct parameters. Multiple ProcessInstances are created and the 
    // AppServerEnumeration adds the correct entries to its list of AppServerInstances.
    // 
    /**************************************************************************************/
    void JBoss_Process_Good_Params_3_Running()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/opt/jboss-6.2/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-01");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/jboss-6.4/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c");
        inst->AddParameter("My profile");

        asEnum.Update(false);
        CPPUNIT_ASSERT(asEnum.Size() == 3);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"/jboss-6.4/server/My profile/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"/opt/jboss-6.2/server/default/" == (*(++it))->GetId());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with correct parameters. Multiple ProcessInstances are created and the 
    // AppServerEnumeration adds the correct entries to its list of 
    // AppServerInstances as running.
    //
    // This unit test is needed for Bug #49459, which was a bug in the
    // sorting algorithm.
    // 
    /**************************************************************************************/
    void JBoss_Process_Good_Params_22_Running()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/adminrx/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c adminrx");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/contextagent/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c contextagent");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/ha/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c ha");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hcservice/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hcservice");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hdm/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hdm");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hdv/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hdv");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hec/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hec");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hed/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hed");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hen/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hen");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hep/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hep");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hep_author/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hep_author");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hhs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hhs");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hmrcs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hmrcs");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hocs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hocs");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hot/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hot");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hpcs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hpcs");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hqmct/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hqmct");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hscs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hscs");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/hwc/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c hwc");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/security/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c security");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/updatemgr/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c updatemgr");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-classpath=/u/hcswl1030/apps/vfs/jboss/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-c vfs");

        asEnum.Update(false);
        CPPUNIT_ASSERT(asEnum.Size() == 22);

        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it;
        for (it = asEnum.Begin(); it != asEnum.End(); ++it)
        {
            CPPUNIT_ASSERT((*it)->GetIsRunning());
        }

        // Call update again
        asEnum.Update(false);
        CPPUNIT_ASSERT(asEnum.Size() == 22);

        for (it = asEnum.Begin(); it != asEnum.End(); ++it)
        {
            CPPUNIT_ASSERT((*it)->GetIsRunning());
        }

        asEnum.CleanUp();
    }
    
    void JBoss_Domain_Process_Good_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/lib/jvm/java-7-openjdk-amd64/jre/bin/java");
        inst->AddParameter("-D[Server:server-one]");
        inst->AddParameter("-XX:PermSize=256m");
        inst->AddParameter("-XX:MaxPermSize=256m");
        inst->AddParameter("-Xms64m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-server");
        inst->AddParameter("-Djava.awt.headless=true");
        inst->AddParameter("-Djava.net.preferIPv4Stack=true");
        inst->AddParameter("-Djboss.bind.address=0.0.0.0");
        inst->AddParameter("-Djboss.home.dir=/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2");
        inst->AddParameter("-Djboss.modules.system.pkgs=org.jboss.byteman");
        inst->AddParameter("-Djboss.server.log.dir=/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/domain/servers/server-one/log");
        inst->AddParameter("-Djboss.server.temp.dir=/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/domain/servers/server-one/tmp");
        inst->AddParameter("-Djboss.server.data.dir=/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/domain/servers/server-one/data");
        inst->AddParameter("-Dlogging.configuration=file:/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/domain/servers/server-one/data/logging.properties");
        inst->AddParameter("-jar");
        inst->AddParameter("/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/jboss-modules.jar");
        inst->AddParameter("-mp");
        inst->AddParameter("/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/modules");
        inst->AddParameter("org.jboss.as.server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        
        CPPUNIT_ASSERT_EQUAL(L"/root/wildfly-8.1.0.CR2/wildfly-8.1.0.CR2/domain/servers/server-one/",(*it)->GetId());
        
        asEnum.CleanUp();
    }

    /*
     * The actual reading and writing to the cache has been mocked out.
     * This test utilizes the test spy pattern because all that we want
     * to verify is that the method to read from the cache was called
     * at initialization. 
     */
    void testReadInstancesMethodCalledAtInit()
    {
        TestSpyAppServerEnumeration asEnum;

        CPPUNIT_ASSERT_EQUAL(0, asEnum.m_ReadInstancesCalledCounter);
        asEnum.Init();
        CPPUNIT_ASSERT_EQUAL(1, asEnum.m_ReadInstancesCalledCounter);
    }
    
    /*
     * The actual reading and writing to the cache has been mocked out.
     * This test utilizes the test spy pattern because all that we want
     * to verify is that the method to write to the cache was called
     * at clean-up. 
     */
    void testWriteInstancesMethodCalledAtCleanup()
    {
        TestSpyAppServerEnumeration asEnum;

        CPPUNIT_ASSERT_EQUAL(0, asEnum.m_WriteInstancesCalledCounter);
        asEnum.CleanUp();
        CPPUNIT_ASSERT_EQUAL(1, asEnum.m_WriteInstancesCalledCounter);
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid Tomcat instance should be created.
    // 
    /**************************************************************************************/
    void Tomcat_Process_Good_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/profile1");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/profile1/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the incorrect parameters works correctly. 
    // No valid Tomcat instances should be created.
    // 
    /**************************************************************************************/
    void Tomcat_Process_Bad_Params_missing_Catalina_home()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid Tomcat instances should be created.
    // This specific test is for when the Catalina.base is not specified.
    // 
    /**************************************************************************************/
    void Tomcat_Process_Bad_Params_missing_Catalina_base()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*it)->GetDiskPath());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid JBoss and Tomcat instance should be created.
    // This specific test is for a combination of both JBoss and Tomcat.
    // 
    /**************************************************************************************/
    void JBoss_Tomcat_Process_Good_params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 2);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());

        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());

        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid JBoss instance should be created and the invalid Tomcat 
    // should be ignored.
    // This specific test is for a combination of both JBoss and Tomcat.
    // 
    /**************************************************************************************/
    void JBoss_Tomcat_Process_Good_Bad_params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid Tomcat instance should be created and the invalid JBoss 
    // should be ignored.
    // This specific test is for a combination of both JBoss and Tomcat.
    // 
    /**************************************************************************************/
    void JBoss_Tomcat_Process_Bad_Good_params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*(it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // Two valid Tomcat instance should be created and two valid JBoss 
    // instances should be created. There is one invalid Tomcat and JBoss entry that should be ignored.
    // This specific test is for a combination of both JBoss and Tomcat.
    // 
    /**************************************************************************************/
    void JBoss_Tomcat_Process_MixedGoodBad()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.30/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal1");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal2");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 4);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal1/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.31/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());

        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the corret parameters, and non default 'Profiles' path 
    // A valid WebSphere instance should be created.
    // 
    /**************************************************************************************/
    void WebSphere_Process_NonDefaultProfile()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/java/bin/java");
        inst->AddParameter("-Declipse.security");
        inst->AddParameter("-Dwas.status.socket=56994");
        inst->AddParameter("-Dosgi.install.area=/opt/IBM/WebSphere/AppServer");
        inst->AddParameter("-Dosgi.configuration.area=/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/configuration");
        inst->AddParameter("-Djava.awt.headless=true");
        inst->AddParameter("-Dosgi.framework.extensions=com.ibm.cds");
        inst->AddParameter("-Xshareclasses:name=webspherev61_%g,groupAccess,nonFatal");
        inst->AddParameter("-Xscmx50M");
        inst->AddParameter("-Xbootclasspath/p:/opt/IBM/WebSphere/AppServer/java/jre/lib/ext/ibmorb.jar:/opt/IBM/WebSphere/AppServer/java/jre/lib/ext/ibmext.jar");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/properties:/opt/IBM/WebSphere/AppServer/properties:/opt/IBM/WebSphere/AppServer/lib/startup.jar:/opt/IBM/WebSphere/AppServer/lib/bootstrap.jar:/opt/IBM/WebSphere/AppServer/lib/j2ee.jar:/opt/IBM/WebSphere/AppServer/lib/lmproxy.jar:/opt/IBM/WebSphere/AppServer/lib/urlprotocols.jar:/opt/IBM/WebSphere/AppServer/deploytool/itp/batchboot.jar:/opt/IBM/WebSphere/AppServer/deploytool/itp/batch2.jar:/opt/IBM/WebSphere/AppServer/java/lib/tools.jar");
        inst->AddParameter("-Dibm.websphere.internalClassAccessMode=allow");
        inst->AddParameter("-Xms50m");
        inst->AddParameter("-Xmx256m"); 
        inst->AddParameter("-Dws.ext.dirs=/opt/IBM/WebSphere/AppServer/java/lib:/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/classes:/opt/IBM/WebSphere/AppServer/classes:/opt/IBM/WebSphere/AppServer/lib:/opt/IBM/WebSphere/AppServer/installedChannels:/opt/IBM/WebSphere/AppServer/lib/ext:/opt/IBM/WebSphere/AppServer/web/help:/opt/IBM/WebSphere/AppServer/deploytool/itp/plugins/com.ibm.etools.ejbdeploy/runtime"); 
        inst->AddParameter("-Dderby.system.home=/opt/IBM/WebSphere/AppServer/derby"); 
        inst->AddParameter("-Dcom.ibm.itp.location=/opt/IBM/WebSphere/AppServer/bin"); 
        inst->AddParameter("-Djava.util.logging.configureByServer=true"); 
        inst->AddParameter("-Duser.install.root=/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01");
        inst->AddParameter("-Djavax.management.builder.initial=com.ibm.ws.management.PlatformMBeanServerBuilder"); 
        inst->AddParameter("-Dwas.install.root=/opt/IBM/WebSphere/AppServer"); 
        inst->AddParameter("-Dpython.cachedir=/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/temp/cachedir"); 
        inst->AddParameter("-Djava.util.logging.manager=com.ibm.ws.bootstrap.WsLogManager"); 
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("-Djava.security.auth.login.config=/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/properties/wsjaas.conf"); 
        inst->AddParameter("-Djava.security.policy=/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/properties/server.policy"); 
        inst->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher"); 
        inst->AddParameter("-nosplash"); 
        inst->AddParameter("-application"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("server1");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT_EQUAL(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-server1",(*it)->GetId());
        CPPUNIT_ASSERT_EQUAL(L"WebSphere",(*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // A valid WebSphere instance should be created.
    // 
    /**************************************************************************************/
    void WebSphere_Process_Good_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/java/bin/java");
        inst->AddParameter("-Declipse.security");
        inst->AddParameter("-Dwas.status.socket=56994");
        inst->AddParameter("-Dosgi.install.area=/opt/IBM/WebSphere/AppServer");
        inst->AddParameter("-Dosgi.configuration.area=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/configuration");
        inst->AddParameter("-Djava.awt.headless=true");
        inst->AddParameter("-Dosgi.framework.extensions=com.ibm.cds");
        inst->AddParameter("-Xshareclasses:name=webspherev61_%g,groupAccess,nonFatal");
        inst->AddParameter("-Xscmx50M");
        inst->AddParameter("-Xbootclasspath/p:/opt/IBM/WebSphere/AppServer/java/jre/lib/ext/ibmorb.jar:/opt/IBM/WebSphere/AppServer/java/jre/lib/ext/ibmext.jar");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/properties:/opt/IBM/WebSphere/AppServer/properties:/opt/IBM/WebSphere/AppServer/lib/startup.jar:/opt/IBM/WebSphere/AppServer/lib/bootstrap.jar:/opt/IBM/WebSphere/AppServer/lib/j2ee.jar:/opt/IBM/WebSphere/AppServer/lib/lmproxy.jar:/opt/IBM/WebSphere/AppServer/lib/urlprotocols.jar:/opt/IBM/WebSphere/AppServer/deploytool/itp/batchboot.jar:/opt/IBM/WebSphere/AppServer/deploytool/itp/batch2.jar:/opt/IBM/WebSphere/AppServer/java/lib/tools.jar");
        inst->AddParameter("-Dibm.websphere.internalClassAccessMode=allow");
        inst->AddParameter("-Xms50m");
        inst->AddParameter("-Xmx256m"); 
        inst->AddParameter("-Dws.ext.dirs=/opt/IBM/WebSphere/AppServer/java/lib:/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/classes:/opt/IBM/WebSphere/AppServer/classes:/opt/IBM/WebSphere/AppServer/lib:/opt/IBM/WebSphere/AppServer/installedChannels:/opt/IBM/WebSphere/AppServer/lib/ext:/opt/IBM/WebSphere/AppServer/web/help:/opt/IBM/WebSphere/AppServer/deploytool/itp/plugins/com.ibm.etools.ejbdeploy/runtime"); 
        inst->AddParameter("-Dderby.system.home=/opt/IBM/WebSphere/AppServer/derby"); 
        inst->AddParameter("-Dcom.ibm.itp.location=/opt/IBM/WebSphere/AppServer/bin"); 
        inst->AddParameter("-Djava.util.logging.configureByServer=true"); 
        inst->AddParameter("-Duser.install.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01");
        inst->AddParameter("-Djavax.management.builder.initial=com.ibm.ws.management.PlatformMBeanServerBuilder"); 
        inst->AddParameter("-Dwas.install.root=/opt/IBM/WebSphere/AppServer"); 
        inst->AddParameter("-Dpython.cachedir=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/temp/cachedir"); 
        inst->AddParameter("-Djava.util.logging.manager=com.ibm.ws.bootstrap.WsLogManager"); 
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("-Djava.security.auth.login.config=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/properties/wsjaas.conf"); 
        inst->AddParameter("-Djava.security.policy=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/properties/server.policy"); 
        inst->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher"); 
        inst->AddParameter("-nosplash"); 
        inst->AddParameter("-application"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("server1");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT_EQUAL(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-server1",(*it)->GetId());
        CPPUNIT_ASSERT_EQUAL(L"WebSphere",(*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the incorrect parameters works correctly. 
    // No valid WebSphere instance should be created.
    // 
    /**************************************************************************************/
    void WebSphere_Process_Bad_Params_TooFewArgs_Missing_Server()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/java/bin/java");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher"); 
        inst->AddParameter("-application"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the incorrect parameters works correctly. 
    // No valid WebSphere instance should be created.
    // 
    /**************************************************************************************/
    void WebSphere_Process_Bad_Params_TooFewArgs_Missing_Node()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/java/bin/java");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher"); 
        inst->AddParameter("-application"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("server1");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the incorrect parameters works correctly. 
    // No valid WebSphere instance should be created.
    // 
    /**************************************************************************************/
    void WebSphere_Process_Bad_Params_TooFewArgs_Missing_ServerRoot()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/java/bin/java");
        inst->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher"); 
        inst->AddParameter("-application"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("server1");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // Two valid Tomcat instance , two valid JBoss 
    // instances and two valid WebSphere instances should be created. 
    // There is one invalid Tomcat, JBoss and WebSphere entry that should be ignored.
    // This specific test is for a combination of both JBoss, Tomcat and WebSphere.
    // 
    /**************************************************************************************/
    void WebSphere_JBoss_Tomcat_Process_MixedGoodBad()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("Server1"); 

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.30/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal1");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal2");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM1/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("Server3"); 

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 6);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal1/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-Server1" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"WebSphere" == (*it)->GetType());
        CPPUNIT_ASSERT(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-Server3" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"WebSphere" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.31/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());

        asEnum.CleanUp();
    }


    /**************************************************************************************/
    //
    // Verify that a valid instance of WebLogic is discovered, this perticular
    // instance is started via the NodeManager.
    // A valid Weblogic instance should be created.
    // 
    /**************************************************************************************/
    void Weblogic_Process_Good_Params_NodeManager()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        
        inst->AddParameter("/opt/weblogic/jrockit_160_14_R27.6.5-32/jre/bin/java");
        inst->AddParameter("-Dweblogic.Name=Managed1");
        inst->AddParameter("-Djava.security.policy=/opt/weblogic/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Dweblogic.management.server=http://[2001:4898:e0:3207:226:55ff:feb7:b42b]:7001");
        inst->AddParameter("-Djava.library.path=\"/opt/weblogic/jrockit_160_14_R27.6.5-32/jre/lib/i386/jrockit\"" );
        inst->AddParameter("-Djava.class.path=/opt/weblogic/patch_wls1032/profiles/default/sys_manifest_classpath/weblogic_patch.jar"); 
        inst->AddParameter("-Dweblogic.system.BootIdentityFile=/opt/weblogic/user_projects/domains/base_domain/servers/Managed1/data/nodemanager/boot.properties"); 
        inst->AddParameter("-Dweblogic.nodemanager.ServiceEnabled=true"); 
        inst->AddParameter("-Dweblogic.security.SSL.ignoreHostnameVerification=false"); 
        inst->AddParameter("-Dweblogic.ReverseDNSAllowed=false"); 
        inst->AddParameter("weblogic.Server");
        
        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/weblogic" == (*it)->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that a valid instance of WebLogic is discovered, this perticular
    // instance is started using the command line scripts.
    // A valid Weblogic instance should be created.
    // 
    /**************************************************************************************/
    void Weblogic_Process_Good_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-client");
        inst->AddParameter("-Xms256m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:CompileThreshold=8000");
        inst->AddParameter("-XX:PermSize=48m");
        inst->AddParameter("-XX:MaxPermSize=128m");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Xverify:none");
        inst->AddParameter("-da");
        inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.management.discover=true");
        inst->AddParameter("-Dwlw.iterativeDev=");
        inst->AddParameter("-Dwlw.testConsole=");
        inst->AddParameter("-Dwlw.logErrorsToConsole=");
        inst->AddParameter("-Dweblogic.ext.dirs=/opt/Oracle/Middleware/patch_wls1032/profiles/default/sysext_manifest_classpath");
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/Oracle/Middleware" == (*it)->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

	/**************************************************************************************/
    //
    // Verify that a valid instance of WebLogic 12.1.3 is discovered, this perticular
    // instance is started using the command line scripts.
    // A valid Weblogic instance should be created.
	// 
	// WebLogic 12.1.2 and 12.1.3 remove the following command line parameters
	// -Dbea.home, -Dplatform.home, and -Dweblogic.system.BootIdentityFile
	// This test makes sure that using -Dweblogic.home is sufficient
    // 
    /**************************************************************************************/
    void Weblogic_12cR1_Process_Good_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/lib/jvm/java-7-openjdk-amd64/bin/java");
        inst->AddParameter("-Xms512m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-Dweblogic.Name=myserver");
        inst->AddParameter("-Djava.security.policy=/root/WebLogic/wls12120/wlserver/server/lib/weblogic.policy");
        inst->AddParameter("/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/endorsed:/root/WebLogic/wls12120/wlserver/../oracle_common/modules/endorsed");
		inst->AddParameter("-da");
        inst->AddParameter("-Dwls.home=/root/WebLogic/wls12120/wlserver/server");
        inst->AddParameter("-Dweblogic.home=/root/WebLogic/wls12120/wlserver/server");
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Assert correct diskpath/id returned from WebLogic 12.1.3 Instance", L"/root/WebLogic/wls12120", (*it)->GetId());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Assert type of AppServer returned", L"Weblogic", (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that no instance of WebLogic is discovered, this perticular
    // instance is started without the 'platform.home' variable set.
    // No valid Weblogic instance should be created.
    // 
    /**************************************************************************************/
    void Weblogic_Process_Bad_Params()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-client");
        inst->AddParameter("-Xms256m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:CompileThreshold=8000");
        inst->AddParameter("-XX:PermSize=48m");
        inst->AddParameter("-XX:MaxPermSize=128m");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Xverify:none");
        inst->AddParameter("-da");
        // Without setting the platform.home will cause the failure
        // inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        // With addition for -Dweblogic.home as a supported parameter to determine installation directory we 
		// need to remove this in unit test
		// inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.management.discover=true");
        inst->AddParameter("-Dwlw.iterativeDev=");
        inst->AddParameter("-Dwlw.testConsole=");
        inst->AddParameter("-Dwlw.logErrorsToConsole=");
        inst->AddParameter("-Dweblogic.ext.dirs=/opt/Oracle/Middleware/patch_wls1032/profiles/default/sysext_manifest_classpath");
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that 2 valid instance of WebLogic are discovered, this perticular
    // scenario a nstance is started using the command line scripts and another
    // is started via the NodeManager.
    // 2 valid Weblogic instances should be created.
    // 
    /**************************************************************************************/
    void Weblogic_Process_Good_Params_Two_Instances()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-client");
        inst->AddParameter("-Xms256m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:CompileThreshold=8000");
        inst->AddParameter("-XX:PermSize=48m");
        inst->AddParameter("-XX:MaxPermSize=128m");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Xverify:none");
        inst->AddParameter("-da");
        inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.management.discover=true");
        inst->AddParameter("-Dwlw.iterativeDev=");
        inst->AddParameter("-Dwlw.testConsole=");
        inst->AddParameter("-Dwlw.logErrorsToConsole=");
        inst->AddParameter("-Dweblogic.ext.dirs=/opt/Oracle/Middleware/patch_wls1032/profiles/default/sysext_manifest_classpath");
        inst->AddParameter("weblogic.Server");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/weblogic/jrockit_160_14_R27.6.5-32/jre/bin/java");
        inst->AddParameter("-Dweblogic.Name=Managed1");
        inst->AddParameter("-Djava.security.policy=/opt/weblogic/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Dweblogic.management.server=http://[2001:4898:e0:3207:226:55ff:feb7:b42b]:7001");
        inst->AddParameter("-Djava.library.path=\"/opt/weblogic/jrockit_160_14_R27.6.5-32/jre/lib/i386/jrockit\"" );
        inst->AddParameter("-Djava.class.path=/opt/weblogic/patch_wls1032/profiles/default/sys_manifest_classpath/weblogic_patch.jar"); 
        inst->AddParameter("-Dweblogic.system.BootIdentityFile=/opt/weblogic/user_projects/domains/base_domain/servers/Managed1/data/nodemanager/boot.properties"); 
        inst->AddParameter("-Dweblogic.nodemanager.ServiceEnabled=true"); 
        inst->AddParameter("-Dweblogic.security.SSL.ignoreHostnameVerification=false"); 
        inst->AddParameter("-Dweblogic.ReverseDNSAllowed=false"); 
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 2);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/Oracle/Middleware" == (*it)->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"/opt/weblogic" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that 1 valid instance of WebLogic is discovered, this perticular
    // scenario two process instances are started using the command.
    // As they have the same home directory only one valid Weblogic instances should be created.
    // 
    /**************************************************************************************/
    void Weblogic_Process_Good_Params_Two_Instances_One_Home()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-client");
        inst->AddParameter("-Xms256m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:CompileThreshold=8000");
        inst->AddParameter("-XX:PermSize=48m");
        inst->AddParameter("-XX:MaxPermSize=128m");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Xverify:none");
        inst->AddParameter("-da");
        inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.management.discover=true");
        inst->AddParameter("-Dwlw.iterativeDev=");
        inst->AddParameter("-Dwlw.testConsole=");
        inst->AddParameter("-Dwlw.logErrorsToConsole=");
        inst->AddParameter("-Dweblogic.ext.dirs=/opt/Oracle/Middleware/patch_wls1032/profiles/default/sysext_manifest_classpath");
        inst->AddParameter("weblogic.Server");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-client");
        inst->AddParameter("-Xms256m");
        inst->AddParameter("-Xmx512m");
        inst->AddParameter("-XX:CompileThreshold=8000");
        inst->AddParameter("-XX:PermSize=48m");
        inst->AddParameter("-XX:MaxPermSize=128m");
        inst->AddParameter("-Dweblogic.Name=ManagedServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Xverify:none");
        inst->AddParameter("-da");
        inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.management.discover=true");
        inst->AddParameter("-Dwlw.iterativeDev=");
        inst->AddParameter("-Dwlw.testConsole=");
        inst->AddParameter("-Dwlw.logErrorsToConsole=");
        inst->AddParameter("-Dweblogic.ext.dirs=/opt/Oracle/Middleware/patch_wls1032/profiles/default/sysext_manifest_classpath");
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/opt/Oracle/Middleware" == (*it)->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        asEnum.CleanUp();
    }

    /**************************************************************************************/
    //
    // Verify that correct number of enumerations is being calculated with WebSphere V8
    // using Customer Log to populate data 
    // 
    /**************************************************************************************/
    void WebSphere_Process_Fixing_Incorrect_Enumerations()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst1;
               
        inst1 = pal->CreateProcessInstance(1234, "1234");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/java/bin/java");
        inst1->AddParameter("-Declipse.security");
        inst1->AddParameter("-Dwas.status.socket=36244");
        inst1->AddParameter("-Dosgi.install.area=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Dosgi.configuration.area=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/servers/StatementService_lsys401c/configuration");
        inst1->AddParameter("-Djava.awt.headless=true");
        inst1->AddParameter("-Dosgi.framework.extensions=com.ibm.cds,com.ibm.ws.eclipse.adaptors");
        inst1->AddParameter("-Xshareclasses:name=webspherev80_%g,groupAccess,nonFatal");
        inst1->AddParameter("-Dcom.ibm.xtq.processor.overrideSecureProcessing=true");
        inst1->AddParameter("-Xbootclasspath/p:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ibmorb.jar");
        inst1->AddParameter("-classpath");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties:/usr/WebSphere/WAS8/AppServer/properties:/usr/WebSphere/WAS8/AppServer/lib/startup.jar:/usr/WebSphere/WAS8/AppServer/lib/bootstrap.jar:/usr/WebSphere/WAS8/AppServer/lib/jsf-nls.jar:/usr/WebSphere/WAS8/AppServer/lib/lmproxy.jar:/usr/WebSphere/WAS8/AppServer/lib/urlprotocols.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batchboot.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batch2.jar:/usr/WebSphere/WAS8/AppServer/java/lib/tools.jar");
        inst1->AddParameter("-Dibm.websphere.internalClassAccessMode=allow");
        inst1->AddParameter("-Xms64m");
        inst1->AddParameter("-Xmx128m");
        inst1->AddParameter("-Xcompressedrefs");
        inst1->AddParameter("-Xscmaxaot4M");
        inst1->AddParameter("-Xscmx90M");
        inst1->AddParameter("-Dws.ext.dirs=/usr/WebSphere/WAS8/AppServer/java/lib:/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/classes:/usr/WebSphere/WAS8/AppServer/classes:/usr/WebSphere/WAS8/AppServer/lib:/usr/WebSphere/WAS8/AppServer/installedChannels:/usr/WebSphere/WAS8/AppServer/lib/ext:/usr/WebSphere/WAS8/AppServer/web/help:/usr/WebSphere/WAS8/AppServer/deploytool/itp/plugins/com.ibm.etools.ejbdeploy/runtime");
        inst1->AddParameter("-Xdump:java+heap:events=user");
        inst1->AddParameter("-Dderby.system.home=/usr/WebSphere/WAS8/AppServer/derby");
        inst1->AddParameter("-Dcom.ibm.itp.location=/usr/WebSphere/WAS8/AppServer/bin");
        inst1->AddParameter("-Djava.util.logging.configureByServer=true");
        inst1->AddParameter("-Duser.install.root=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01");
        inst1->AddParameter("-Djava.ext.dirs=/usr/WebSphere/WAS8/AppServer/tivoli/tam:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ext");
        inst1->AddParameter("-Djavax.management.builder.initial=com.ibm.ws.management.PlatformMBeanServerBuilder");
        inst1->AddParameter("-Dpython.cachedir=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/temp/cachedir");
        inst1->AddParameter("-Dwas.install.root=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Djava.util.logging.manager=com.ibm.ws.bootstrap.WsLogManager");
        inst1->AddParameter("-Dserver.root=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01");
        inst1->AddParameter("-Dcom.ibm.security.jgss.debug=off");
        inst1->AddParameter("-Dcom.ibm.security.krb5.Krb5Debug=off");
        inst1->AddParameter("-DWAS_LOG4J=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/log4j/STATEMENTSERVICE");
        inst1->AddParameter("-Xgcpolicy:gencon");
        inst1->AddParameter("-Djava.library.path=/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd64/compressedrefs:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/bin:/usr/lib:");
        inst1->AddParameter("-Djava.endorsed.dirs=/usr/WebSphere/WAS8/AppServer/endorsed_apis:/usr/WebSphere/WAS8/AppServer/java/jre/lib/endorsed");
        inst1->AddParameter("-Djava.security.auth.login.config=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties/wsjaas.conf");
        inst1->AddParameter("-Djava.security.policy=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties/server.policy");
        inst1->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher");
        inst1->AddParameter("-nosplash");
        inst1->AddParameter("-application");
        inst1->AddParameter("com.ibm.ws.bootstrap.WSLauncher");
        inst1->AddParameter("com.ibm.ws.runtime.WsServer");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/config");
        inst1->AddParameter("DEV");
        inst1->AddParameter("lsys401cNode01");
        inst1->AddParameter("StatementService_lsys401c");
        
        //Second Instance of WebSphere V8 with different server
        inst1 = pal->CreateProcessInstance(1235, "1235");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/java/bin/java");
        inst1->AddParameter("-Declipse.security");
        inst1->AddParameter("-Dwas.status.socket=45529");
        inst1->AddParameter("-Dosgi.install.area=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Dosgi.configuration.area=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/servers/dmgr/configuration");
        inst1->AddParameter("-Djava.awt.headless=true");
        inst1->AddParameter("-Dosgi.framework.extensions=com.ibm.cds,com.ibm.ws.eclipse.adaptors");
        inst1->AddParameter("-Xshareclasses:name=webspherev80_%g,groupAccess,nonFatal");
        inst1->AddParameter("-Xscmx50M");
        inst1->AddParameter("-Dcom.ibm.xtq.processor.overrideSecureProcessing=true");
        inst1->AddParameter("-Xbootclasspath/p:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ibmorb.jar");
        inst1->AddParameter("-classpath");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/properties:/usr/WebSphere/WAS8/AppServer/properties:/usr/WebSphere/WAS8/AppServer/lib/startup.jar:/usr/WebSphere/WAS8/AppServer/lib/bootstrap.jar:/usr/WebSphere/WAS8/AppServer/lib/jsf-nls.jar:/usr/WebSphere/WAS8/AppServer/lib/lmproxy.jar:/usr/WebSphere/WAS8/AppServer/lib/urlprotocols.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batchboot.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batch2.jar:/usr/WebSphere/WAS8/AppServer/java/lib/tools.jar");
        inst1->AddParameter("-Dibm.websphere.internalClassAccessMode=allow");
        inst1->AddParameter("-Xms256m");
        inst1->AddParameter("-Xmx512m");
        inst1->AddParameter("-Xcompressedrefs");
        inst1->AddParameter("-Dws.ext.dirs=/usr/WebSphere/WAS8/AppServer/java/lib:/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/classes:/usr/WebSphere/WAS8/AppServer/classes:/usr/WebSphere/WAS8/AppServer/lib:/usr/WebSphere/WAS8/AppServer/installedChannels:/usr/WebSphere/WAS8/AppServer/lib/ext:/usr/WebSphere/WAS8/AppServer/web/help:/usr/WebSphere/WAS8/AppServer/deploytool/itp/plugins/com.ibm.etools.ejbdeploy/runtime");
        inst1->AddParameter("-Dderby.system.home=/usr/WebSphere/WAS8/AppServer/derby");
        inst1->AddParameter("-Dcom.ibm.itp.location=/usr/WebSphere/WAS8/AppServer/bin");
        inst1->AddParameter("-Djava.util.logging.configureByServer=true");
        inst1->AddParameter("-Duser.install.root=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01");
        inst1->AddParameter("-Djava.ext.dirs=/usr/WebSphere/WAS8/AppServer/tivoli/tam:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ext");
        inst1->AddParameter("-Djavax.management.builder.initial=com.ibm.ws.management.PlatformMBeanServerBuilder");
        inst1->AddParameter("-Dpython.cachedir=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/temp/cachedir");
        inst1->AddParameter("-Dwas.install.root=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Djava.util.logging.manager=com.ibm.ws.bootstrap.WsLogManager");
        inst1->AddParameter("-Dserver.root=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01");
        inst1->AddParameter("-Dcom.ibm.security.jgss.debug=off");
        inst1->AddParameter("-Dcom.ibm.security.krb5.Krb5Debug=off");
        inst1->AddParameter("-Djava.library.path=/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd64/compressedrefs:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd64:/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/bin:/usr/lib:");
        inst1->AddParameter("-Djava.endorsed.dirs=/usr/WebSphere/WAS8/AppServer/endorsed_apis:/usr/WebSphere/WAS8/AppServer/java/jre/lib/endorsed");
        inst1->AddParameter("-Djava.security.auth.login.config=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/properties/wsjaas.conf");
        inst1->AddParameter("-Djava.security.policy=/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/properties/server.policy");
        inst1->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher");
        inst1->AddParameter("-nosplash");
        inst1->AddParameter("-application");
        inst1->AddParameter("com.ibm.ws.bootstrap.WSLauncher");
        inst1->AddParameter("com.ibm.ws.runtime.WsServer");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/Dmgr01/config");
        inst1->AddParameter("DEV");
        inst1->AddParameter("lsys401cDmgr01");
        inst1->AddParameter("dmgr");
        
        
        //Third instance of WebSphere Server
        inst1 = pal->CreateProcessInstance(1236, "1236");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/java/bin/java");
        inst1->AddParameter("-Xmaxt0.5");
        inst1->AddParameter("-Dwas.status.socket=38696");
        inst1->AddParameter("-Declipse.security");
        inst1->AddParameter("-Dosgi.install.area=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Dosgi.configuration.area=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/servers/nodeagent/configuration");
        inst1->AddParameter("-Dosgi.framework.extensions=com.ibm.cds,com.ibm.ws.eclipse.adaptors");
        inst1->AddParameter("-Xshareclasses:name=webspherev80_%g,groupAccess,nonFatal");
        inst1->AddParameter("-Dcom.ibm.xtq.processor.overrideSecureProcessing=true");
        inst1->AddParameter("-Xbootclasspath/p:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ibmorb.jar");
        inst1->AddParameter("-Dorg.osgi.framework.bootdelegation=*");
        inst1->AddParameter("-classpath");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties:/usr/WebSphere/WAS8/AppServer/properties:/usr/WebSphere/WAS8/AppServer/lib/startup.jar:/usr/WebSphere/WAS8/AppServer/lib/bootstrap.jar:/usr/WebSphere/WAS8/AppServer/lib/jsf-nls.jar:/usr/WebSphere/WAS8/AppServer/lib/lmproxy.jar:/usr/WebSphere/WAS8/AppServer/lib/urlprotocols.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batchboot.jar:/usr/WebSphere/WAS8/AppServer/deploytool/itp/batch2.jar:/usr/WebSphere/WAS8/AppServer/java/lib/tools.jar");
        inst1->AddParameter("-Dorg.osgi.framework.bootdelegation=*");
        inst1->AddParameter("-Dibm.websphere.internalClassAccessMode=allow");
        inst1->AddParameter("-Xms50m");
        inst1->AddParameter("-Xmx256m");
        inst1->AddParameter("-Xcompressedrefs");
        inst1->AddParameter("-Xscmaxaot4M");
        inst1->AddParameter("-Xnoaot");
        inst1->AddParameter("-Xscmx90M");
        inst1->AddParameter("-Dws.ext.dirs=/usr/WebSphere/WAS8/AppServer/java/lib:/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/classes:/usr/WebSphere/WAS8/AppServer/classes:/usr/WebSphere/WAS8/AppServer/lib:/usr/WebSphere/WAS8/AppServer/installedChannels:/usr/WebSphere/WAS8/AppServer/lib/ext:/usr/WebSphere/WAS8/AppServer/web/help:/usr/WebSphere/WAS8/AppServer/deploytool/itp/plugins/com.ibm.etools.ejbdeploy/runtime");
        inst1->AddParameter("-Dderby.system.home=/usr/WebSphere/WAS8/AppServer/derby");
        inst1->AddParameter("-Dcom.ibm.itp.location=/usr/WebSphere/WAS8/AppServer/bin");
        inst1->AddParameter("-Djava.util.logging.configureByServer=true");
        inst1->AddParameter("-Duser.install.root=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01");
        inst1->AddParameter("-Djava.ext.dirs=/usr/WebSphere/WAS8/AppServer/tivoli/tam:/usr/WebSphere/WAS8/AppServer/java/jre/lib/ext");
        inst1->AddParameter("-Djavax.management.builder.initial=com.ibm.ws.management.PlatformMBeanServerBuilder");
        inst1->AddParameter("-Dpython.cachedir=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/temp/cachedir");
        inst1->AddParameter("-Dwas.install.root=/usr/WebSphere/WAS8/AppServer");
        inst1->AddParameter("-Djava.util.logging.manager=com.ibm.ws.bootstrap.WsLogManager");
        inst1->AddParameter("-Dserver.root=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01");
        inst1->AddParameter("-Dcom.ibm.security.jgss.debug=off");
        inst1->AddParameter("-Dcom.ibm.security.krb5.Krb5Debug=off");
        inst1->AddParameter("-Djava.awt.headless=true");
        inst1->AddParameter("-Djava.library.path=/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd64/compressedrefs:/usr/WebSphere/WAS8/AppServer/java/jre/lib/amd64:/usr/WebSphere/WAS8/AppServer/lib/native/linux/x86_64/:/usr/WebSphere/WAS8/AppServer/bin:/usr/lib:");
        inst1->AddParameter("-Djava.endorsed.dirs=/usr/WebSphere/WAS8/AppServer/endorsed_apis:/usr/WebSphere/WAS8/AppServer/java/jre/lib/endorsed");
        inst1->AddParameter("-Djava.security.auth.login.config=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties/wsjaas.conf");
        inst1->AddParameter("-Djava.security.policy=/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/properties/server.policy");
        inst1->AddParameter("com.ibm.wsspi.bootstrap.WSPreLauncher");
        inst1->AddParameter("-nosplash");
        inst1->AddParameter("-application");
        inst1->AddParameter("com.ibm.ws.bootstrap.WSLauncher");
        inst1->AddParameter("com.ibm.ws.runtime.WsServer");
        inst1->AddParameter("/usr/WebSphere/WAS8/AppServer/profiles/AppSrv01/config");
        inst1->AddParameter("DEV");
        inst1->AddParameter("lsys401cNode01");
        inst1->AddParameter("nodeagent");
        
        asEnum.Update(false);
        //We have 3 different WebSphere enumerations
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t>(3),asEnum.Size());

        asEnum.CleanUp();
    }


    /**************************************************************************************/
    //
    // Verify that the mocked out implementation of the ProcessInstance
    // with the correct parameters works correctly. 
    // Two valid Tomcat instance , two valid JBoss. two valid Weblogic  
    // instances and two valid WebSphere instances should be created. 
    // There is one invalid Tomcat, JBoss, Weblogic and WebSphere entry that should be ignored.
    // This specific test is for a combination of both JBoss, Tomcat, Weblogic and WebSphere.
    // 
    /**************************************************************************************/
    void Weblogic_WebSphere_JBoss_Tomcat_Process_MixedGoodBad()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("Server1"); 

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.30/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("-classpath=/jboss-6.3/bin/run.jar");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal1");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3");
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("weblogic.Server");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.31/");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");

        inst = pal->CreateProcessInstance(1235, "1235");
        inst->AddParameter("org.jboss.Main"); 
        inst->AddParameter("-Djboss.service.binding.set=ports-02");
        inst->AddParameter("-c minimal2");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Dwls.home=/opt/Oracle1/Middleware/wlserver_10.3/server");
        inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("weblogic.Server");

        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("-Dserver.root=/opt/IBM1/WebSphere/AppServer/profiles/AppSrv01"); 
        inst->AddParameter("com.ibm.ws.bootstrap.WSLauncher"); 
        inst->AddParameter("com.ibm.ws.runtime.WsServer"); 
        inst->AddParameter("/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/config"); 
        inst->AddParameter("scxjet-rhel5-04Node01Cell"); 
        inst->AddParameter("Node01"); 
        inst->AddParameter("Server3"); 


        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/opt/jdk1.6.0_24/bin/java");
        inst->AddParameter("-Dweblogic.Name=AdminServer");
        inst->AddParameter("-Djava.security.policy=/opt/Oracle/Middleware/wlserver_10.3/server/lib/weblogic.policy");
        inst->AddParameter("-Dweblogic.system.BootIdentityFile=/opt/Oracle2/user_projects/domains/base_domain/servers/Managed1/data/nodemanager/boot.properties"); 
        inst->AddParameter("-Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server");
		// Remove the -Dweblogic.home to complete bad process
        // inst->AddParameter("-Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server");
        inst->AddParameter("weblogic.Server");

        asEnum.Update(false);

        CPPUNIT_ASSERT(asEnum.Size() == 8);
        
        std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = asEnum.Begin();
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal/" == (*it)->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/jboss-6.3/server/minimal1/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"JBoss" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-Server1" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"WebSphere" == (*it)->GetType());
        CPPUNIT_ASSERT(L"AppSrv01-scxjet-rhel5-04Node01Cell-Node01-Server3" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"WebSphere" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"/opt/Oracle/Middleware" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/opt/Oracle2" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Weblogic" == (*it)->GetType());
        
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.29/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());
        CPPUNIT_ASSERT(L"/opt/apache-tomcat-5.5.31/" == (*(++it))->GetId());
        CPPUNIT_ASSERT(L"Tomcat" == (*it)->GetType());

        asEnum.CleanUp();
    }

    /*************************************************************/
    //
    // Verification of Bug Fix #51490
    //
    // UpdateInstances should not be called when Update() is called.
    // 
    /*************************************************************/
    void UpdateInstances_Is_Not_Called()
    {
        SCXCoreLib::SCXHandle<MockAppServerPALDependencies> pal = SCXCoreLib::SCXHandle<MockAppServerPALDependencies>(new MockAppServerPALDependencies());
        TestSpyAppServerEnumeration asEnum(pal);

        CPPUNIT_ASSERT(asEnum.Size() == 0);
        CPPUNIT_ASSERT(asEnum.GetNumberOfCallsToUpdateInstances()== 0);

        SCXCoreLib::SCXHandle<MockProcessInstance> inst;
        
        inst = pal->CreateProcessInstance(1234, "1234");
        inst->AddParameter("/usr/java/jre1.6.0_10//bin/java");
        inst->AddParameter("-Djava.util.logging.config.file=/opt/apache-tomcat-5.5.29//conf/logging.properties");
        inst->AddParameter("-Djava.util.logging.manager=org.apache.juli.ClassLoaderLogManager");
        inst->AddParameter("-Djava.endorsed.dirs=/opt/apache-tomcat-5.5.29//common/endorsed");
        inst->AddParameter("-classpath");
        inst->AddParameter("/opt/apache-tomcat-5.5.29//bin/bootstrap.jar");
        inst->AddParameter("-Dcatalina.base=/opt/apache-tomcat-5.5.29/profile1");
        inst->AddParameter("-Dcatalina.home=/opt/apache-tomcat-5.5.29/");
        inst->AddParameter("-Djava.io.tmpdir=/opt/apache-tomcat-5.5.29//temp");
        inst->AddParameter("org.apache.catalina.startup.Bootstrap");
        inst->AddParameter("start");

        CPPUNIT_ASSERT(asEnum.GetNumberOfCallsToUpdateInstances()== 0);

        asEnum.Update(true);

        CPPUNIT_ASSERT(asEnum.Size() == 1);
        CPPUNIT_ASSERT(asEnum.GetNumberOfCallsToUpdateInstances()== 0);

        asEnum.CleanUp();
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( AppServerEnumeration_Test );

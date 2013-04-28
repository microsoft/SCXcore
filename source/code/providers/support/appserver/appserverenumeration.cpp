  /*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file        appserverenumeration.cpp

   \brief       Enumeration of Application Server

   \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxlog.h>

#include <scxcorelib/scxcondition.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilepath.h>

#include <scxsystemlib/processenumeration.h>
#include <scxsystemlib/processinstance.h>

#include "appserverenumeration.h"
#include "jbossappserverinstance.h"
#include "tomcatappserverinstance.h"
#include "weblogicappserverenumeration.h"
#include "websphereappserverinstance.h"
#include "manipulateappserverinstances.h"
#include "persistappserverinstances.h"

#include <string>
#include <vector>

using namespace std;
using namespace SCXCoreLib;
           
namespace SCXSystemLib
{
    /**
       Returns a vector containing all running processes with the name matching the criteria.
    */
    vector<SCXHandle<ProcessInstance> > AppServerPALDependencies::Find(const wstring& name)
    {
        SCXHandle<ProcessEnumeration> enumProc =  SCXHandle<ProcessEnumeration>(new ProcessEnumeration());
        enumProc->SampleData();
        return enumProc->Find(name);
    }
    
    /**
       Populates the params with the process parameters.
    */
    bool AppServerPALDependencies::GetParameters(SCXHandle<ProcessInstance> inst, vector<string>& params)
    {
        return inst->GetParameters(params);
    }

    /**
       Populates the newInst with the newly created Weblogic AppServerInstances.
       
       \param[in] weblogicProcesses Vector containing the home peth of all running Weblogic processes.
       \param[out] newInst           Vector containing newly created AppServerInstances.
    */
    void AppServerPALDependencies::GetWeblogicInstances(vector<wstring> weblogicProcesses, vector<SCXHandle<AppServerInstance> >& newInst)
    {
        WebLogicAppServerEnumeration weblogicEnum(
                SCXCoreLib::SCXHandle<IWebLogicFileReader> (new WebLogicFileReader()));
        
        weblogicEnum.GetInstances(weblogicProcesses,newInst);
    }

    /*----------------------------------------------------------------------------*/
    /**
       Default constructor

       \param[in] deps Dependencies for the AppServer Enumeration.
    */
    AppServerEnumeration::AppServerEnumeration(SCXCoreLib::SCXHandle<AppServerPALDependencies> deps) :
        EntityEnumeration<AppServerInstance>(),
        m_deps(deps)
    {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.appserverenumeration");

        SCX_LOGTRACE(m_log, L"AppServerEnumeration default constructor");
    }

    /*----------------------------------------------------------------------------*/
    /**
       Destructor

    */
    AppServerEnumeration::~AppServerEnumeration()
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration destructor");
    }

    /*----------------------------------------------------------------------------*/
    /**
       Create AppServer instances

    */
    void AppServerEnumeration::Init()
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration Init()");
        ReadInstancesFromDisk();
        Update(false);
    }

    /*----------------------------------------------------------------------------*/
    /**
       Deserialize Instances from disk

    */
    void AppServerEnumeration::ReadInstancesFromDisk()
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration ReadInstancesFromDisk()");

        SCXHandle<PersistAppServerInstances> cache( 
                new PersistAppServerInstances() );
        vector<SCXHandle<AppServerInstance> > readInstances;
        cache->ReadFromDisk(readInstances);

        for (EntityIterator i = readInstances.begin();
                readInstances.end() != i;
                ++i)
        {
            SCX_LOGTRACE(m_log, L"adding an instance from cache read");
            AddInstance(*i);
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get JBoss parameters and from the commandline and create an AppServerInstance

    */
    void AppServerEnumeration::CreateJBossInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params)
    {
        bool gotInstPath=false;
        wstring instDir;
        string config;
        string configFromDashC;
        string configFromJBossProperty;
        string ports;
        
        
        // We have a 'JBoss' instance, now get the base directory from the 'classpath' commandline argument
        string arg = ParseOutCommandLineArg(params, "-classpath",true,true);
        if ( arg.length() > 0 )
        {
           instDir = GetJBossPathFromClassPath(StrFromUTF8(arg));
           if(instDir.length() > 0)
           {
               gotInstPath=true;
           }
        }

        configFromDashC = ParseOutCommandLineArg(params, "-c",false,true);
        configFromJBossProperty = ParseOutCommandLineArg(params, "-Djboss.server.name",true,false);
        if ( configFromDashC.length() != 0 )
        {
            config = configFromDashC;
        }
        else if ( configFromJBossProperty.length() != 0 )
        {
            config = configFromJBossProperty;
        }
        else // ( configFromDashC.length() == 0 ) && ( configFromJBossProperty.length() == 0 )
        {
            config = "default";
        }

        ports = ParseOutCommandLineArg(params, "-Djboss.service.binding.set",true,false);

        if(gotInstPath)
        {
            SCXCoreLib::SCXHandle<JBossAppServerInstance> inst ( 
                       new JBossAppServerInstance(instDir,StrFromUTF8(config),StrFromUTF8(ports)) );
            inst->Update();
            
            SCX_LOGTRACE(m_log, L"Found a running app server process");
            inst->SetIsRunning(true);
            ASInstances->push_back(inst);
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get Tomcat parameters from the commandline and create an AppServerInstance

    */
    void AppServerEnumeration::CreateTomcatInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params)
    {
        bool gotInstPath=false;
        string instDir;
        string config;
        
        instDir = ParseOutCommandLineArg(params, "-Dcatalina.home",true,true);
        if ( !instDir.empty() )
        {
             gotInstPath=true;
        }

        // We have a 'Tomcat' instance, now get the base directory from the '-Dcatalina.home' commandline argument
        config = ParseOutCommandLineArg(params, "-Dcatalina.base",true,true);
        if ( config.empty() )
        {
             config = instDir;
        }
        
        if(gotInstPath)
        {
            SCXCoreLib::SCXHandle<TomcatAppServerInstance> inst ( 
                new TomcatAppServerInstance(StrFromUTF8(config), StrFromUTF8(instDir)) );
            inst->Update();
            
            SCX_LOGTRACE(m_log, L"Found a running instance of Tomcat");
            inst->SetIsRunning(true);
            ASInstances->push_back(inst);
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get WebSphere parameters from the commandline and create an AppServerInstance
       
       The commandline has the "-Dserver.root" key which contains the disk path to the instance
       The WebSphere startup script runs websphere with the following arguments after the "com.ibm.ws.runtime.WsServer" class
            "%CONFIG_ROOT%" "%WAS_CELL%" "%WAS_NODE%" %* %WORKSPACE_ROOT_PROP%
       
    */
    void AppServerEnumeration::CreateWebSphereInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params)
    {
        int argNumberForRuntimeClass;
        string configRoot;
        string instDir;
        string wasCell;
        string wasNode;
        string wasServer;
        wstring wasProfile;
        bool gotInstPath = false;
        bool gotParams = false;
        

        argNumberForRuntimeClass = GetArgNumber(params, WEBSPHERE_RUNTIME_CLASS);
        if(argNumberForRuntimeClass >= 0)
        {
           // parse out the "%CONFIG_ROOT%" "%WAS_CELL%" "%WAS_NODE%" %* %WORKSPACE_ROOT_PROP%
           // The +5 is for the 4 arguments and and extra 1 for the zero based offset of the 
           // argNumberForRuntimeClass.
           if(params.size() >= (unsigned int)argNumberForRuntimeClass+5)
           {
              configRoot = params[argNumberForRuntimeClass+1];
              wasCell = params[argNumberForRuntimeClass+2];
              wasNode = params[argNumberForRuntimeClass+3];
              wasServer = params[argNumberForRuntimeClass+4];
              gotParams = true;
           }
        }
        instDir = ParseOutCommandLineArg(params, "-Dserver.root",true,true);
        if ( !instDir.empty() )
        {
             SCXFilePath sf(StrFromUTF8(instDir));
             wasProfile = sf.GetFilename();
             gotInstPath=true;
        }
        
        if(gotInstPath && gotParams)
        {
            SCXCoreLib::SCXHandle<WebSphereAppServerInstance> inst ( 
                        new WebSphereAppServerInstance(StrFromUTF8(instDir),StrFromUTF8(wasCell),StrFromUTF8(wasNode),wasProfile,StrFromUTF8(wasServer)) );
            inst->Update();
            
            SCX_LOGTRACE(m_log, L"Found a running instance of WebSphere");
            inst->SetIsRunning(true);
            ASInstances->push_back(inst);
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get Weblogic parameters from the commandline and find the base directory
        -Dweblogic.Name=AdminServer 
        -Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3
        -Dwls.home=/opt/Oracle/Middleware/wlserver_10.3/server 
        -Dweblogic.home=/opt/Oracle/Middleware/wlserver_10.3/server 
    */
    wstring AppServerEnumeration::GetWeblogicHome(vector<string> params)
    {
        string wlPlatformHome;
        wstring PlatformHome;
        
        wlPlatformHome = ParseOutCommandLineArg(params, "-Dplatform.home",true,true);
        if ( !wlPlatformHome.empty() )
        {
             // Commandline entry for "-Dplatform.home" looks like this
             // "-Dplatform.home=/opt/Oracle/Middleware/wlserver_10.3"
             // remove the "wlserver_10.3" portion to return the platform
             // home directory.
             // There is the possibility that the wlPlatformHome ends with a
             // trailing '/', we need to strip it off.
             PlatformHome = StrFromUTF8(GetParentDirectory(wlPlatformHome));
             SCX_LOGTRACE(m_log, L"Found a running instance of Weblogic");
        }
        else
        {
            //-Dweblogic.system.BootIdentityFile=/opt/Oracle/Middleware/user_projects/domains/base_domain/servers/Managed1/data/nodemanager/boot.properties 
            string wlBootId = ParseOutCommandLineArg(params, "-Dweblogic.system.BootIdentityFile",true,true);
            if ( !wlBootId.empty() )
            {
                PlatformHome = StrFromUTF8(GetParentDirectory(wlBootId,8)); // remove '/user_projects/domains/base_domain/servers/Managed1/data/nodemanager/boot.properties' 
            }
            else
            {
                SCX_LOGTRACE(m_log, L"Weblogic process does not contain the 'platform.home' or 'weblogic.system.BootIdentityFile' commandline argument.");
            }
        }
        return PlatformHome;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Update all AppServer data

    */
    void AppServerEnumeration::Update(bool /*updateInstances*/)
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration Update()");
        vector<SCXCoreLib::SCXHandle<AppServerInstance> > ASInstances;
        bool gotWeblogicProcesses = false;
        vector<wstring> weblogicProcesses;

        // Find all Java processes running
        vector<SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> > procList = m_deps->Find(L"java");
        for (vector<SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> >::iterator it = procList.begin(); it != procList.end(); it++)
        {
          vector<string> params;

          if (m_deps->GetParameters((*it),params)) 
          {

             // Loop through each 'java' process and check for 'JBoss' argument on the commandline
             if(CheckProcessCmdLineArgExists(params,"org.jboss.Main"))
             {
                CreateJBossInstance(&ASInstances, params);
             }
             
             // Loop through each 'java' process and check for Tomcat i.e. 'Catalina' argument on the commandline
             if(CheckProcessCmdLineArgExists(params,"org.apache.catalina.startup.Bootstrap"))
             {
                CreateTomcatInstance(&ASInstances, params);
             }
             
             // Loop through each 'java' process and check for Weblogic i.e. 'weblogic.Server' argument on the commandline
             if(CheckProcessCmdLineArgExists(params,"weblogic.Server"))
             {
                wstring wlHome = GetWeblogicHome(params);
                if(!wlHome.empty())
                {
                    weblogicProcesses.push_back(wlHome);
                    gotWeblogicProcesses = true;
                }
             }

             // Loop through each 'java' process and check for WebSphere i.e. 
             // com.ibm.ws.bootstrap.WSLauncher com.ibm.ws.runtime.WsServer argument on the commandline
             if(CheckProcessCmdLineArgExists(params,"com.ibm.ws.bootstrap.WSLauncher") &&
                CheckProcessCmdLineArgExists(params,WEBSPHERE_RUNTIME_CLASS))
             {
                CreateWebSphereInstance(&ASInstances, params);
             }
          }
        }

        // Get the list of Weblogic Instances and add them to the enumerator
        if(gotWeblogicProcesses)
        {
            vector<SCXHandle<AppServerInstance> > newInst;
            m_deps->GetWeblogicInstances(weblogicProcesses, newInst);

            for (
                 vector<SCXCoreLib::SCXHandle<AppServerInstance> >::iterator it = newInst.begin(); 
                    it != newInst.end();
                    ++it)
            {
                SCX_LOGTRACE(m_log, L"Adding a Weblogic instance");
                ASInstances.push_back(*it);
            }
        }

        //Get the current instances and place them in a vector
        vector<SCXCoreLib::SCXHandle<AppServerInstance> > knownInstances;
        for (EntityIterator iter = Begin(); iter != End(); ++iter) 
        {
            knownInstances.push_back(*iter);
        }

        SCX_LOGTRACE(m_log, L"Merging previously known instances with current running processes");
        SCX_LOGTRACE(m_log,
                StrAppend(L"size of previously known instances: ",
                        knownInstances.size()));
        SCX_LOGTRACE(m_log,
                StrAppend(L"size of running processes : ", ASInstances.size()));

        ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(knownInstances, ASInstances);

        SCX_LOGTRACE(m_log,
                StrAppend(L"size of merged list : ",
                        knownInstances.size()));
                        
        SCX_LOGTRACE(m_log, L"delete all instances");
        RemoveInstances() ;
        for (vector<SCXHandle<AppServerInstance> >::iterator it = knownInstances.begin(); 
                it != knownInstances.end(); 
                ++it)
        {
            SCX_LOGTRACE(m_log, L"adding an instance from processes");
           AddInstance(*it);
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Wrapper to EntityEnumeration's UpdateInstances()

    */
    void AppServerEnumeration::UpdateInstances()
    {
        EntityEnumeration<AppServerInstance>::UpdateInstances();
    }
    
    /*----------------------------------------------------------------------------*/
    /**
       Serialize Instances to disk

    */
    void AppServerEnumeration::WriteInstancesToDisk()
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration WriteInstancesToDisk()");

        SCXHandle<PersistAppServerInstances> cache( 
                new PersistAppServerInstances() );
        vector<SCXHandle<AppServerInstance> > instancesToWrite;
        instancesToWrite.insert(instancesToWrite.end(), Begin(), End() );
        cache->EraseFromDisk();
        cache->WriteToDisk(instancesToWrite);
    }

    /*----------------------------------------------------------------------------*/
    /**
       Cleanup

    */
    void AppServerEnumeration::CleanUp()
    {
        SCX_LOGTRACE(m_log, L"AppServerEnumeration CleanUp()");
        WriteInstancesToDisk();
    }

   /*----------------------------------------------------------------------------
    * Check the process command line arguments looking 
    * for a specific entry.
    *
    * \param    params    List of commandline arguments
    * \param    value     argument value to look for
    * \returns  true if the argument is found otherwise false
    */
    bool AppServerEnumeration::CheckProcessCmdLineArgExists(vector<string>& params, const string& value)
    {
        vector<string>::iterator pos;
        bool retval = false;

        for(pos = params.begin(); pos != params.end(); ++pos) 
        {
            if(value == *pos)
            {
                retval = true;
                break;
            }
        }
        return retval;
    }
    
   /*----------------------------------------------------------------------------
    * Check the process command line arguments looking 
    * for a specific entry and return the argument number of the entry.
    *
    * \param    params    List of commandline arguments
    * \param    value     argument value to look for
    * \returns  the argument number of the matching argument
    */
    int AppServerEnumeration::GetArgNumber(vector<string>& params, const string& value)
    {
        vector<string>::iterator pos;
        int retval = -1;
        bool found = false;

        for(pos = params.begin(); (pos != params.end() )&&(!found); ++pos) 
        {
            retval++;
            if(value == *pos)
            {
                found = true;
            }
        }
        return !found?-1:retval;
    }
    
   /*----------------------------------------------------------------------------
    * Remove the last folder entry from the input folder
    *
    * \param    directoryPath   Directory path
    * \param    levels          number of directories to fall back
    * \returns  the parent directory
    */
    string AppServerEnumeration::GetParentDirectory(const string& directoryPath,int levels)
    {
        string thePath;
        size_t pos;


        if( '/' == directoryPath[directoryPath.length()-1] )
        {
            thePath = directoryPath.substr(directoryPath.length()-1);
        }
        else
        {
            thePath = directoryPath;
        }

        for(int i=0;i<levels;i++)
        {
            pos = thePath.find_last_of("/");
            thePath = thePath.substr(0,pos);
        }

        return thePath;
    }
    
   /*----------------------------------------------------------------------------
    * Parse the commandline arguments looking for a specific "key"
    * when the "key" is found the associated value is returned.
    * The commandline arguments have different formats
    *    arg0 -D abc;def ("-D" is the key and "abc;def" is the associated value)
    *    arg0 name=bill  ("name" is the key and "bill" is the value)
    *
    * \param    params           List of commandline arguments
    * \param    key              The "key" whose associated value must be retrieved
    * \param    EqualsDelimited  Must the "key" be seperated from the "value" by an '=' sign
    * \param    SpaceDelimited   Must the "key" be seperated from the "value" by a space
    * \returns  the associated value for the "key" or an empty string if not found.
    */
    string AppServerEnumeration::ParseOutCommandLineArg(vector<string>& params, 
                                                             const string& key,
                                                             const bool EqualsDelimited,
                                                             const bool SpaceDelimited ) const
    {
        vector<string>::iterator pos;
        const string emptyString = ""; 
        string result = emptyString;
        bool returnTheNextArgAsValue = false;
 
        for(pos = params.begin(); pos != params.end(); ++pos) 
        {
            string arg = static_cast<string>(*pos);
           
            if(returnTheNextArgAsValue)
            {
                result = arg;
                break;
            }
           
            if((key == arg) && SpaceDelimited)
            {
                /* 
                 * Some parameters are in the form key=value while some are "key value" 
                 * If the parameter length is the same size as the key then the value is 
                 * in the next arg.
                 */
                returnTheNextArgAsValue = true;
            }
            else
            {
                /*
                 * The following 2 scenarios still apply
                 * key=value
                 * key value - (this is done if the arg specified is a single arg "key value"
                 */
                if(arg.length() > key.length()+1) 
                {
                    if(arg.substr(0,key.length()) == key)
                    {
                       if((EqualsDelimited && (arg[key.length()] == '=')) ||
                          (SpaceDelimited  && (arg[key.length()] == ' ')) )
                       {
                           result = arg.substr(key.length()+1);
                           break;
                       }
                    }
                }
            }
        }
        return result;
    }

    
   /*----------------------------------------------------------------------------
    * Parse a given classpath string and find the item that ends with 
    * "/bin/run.jar" the classpath item would typically be
    * "/opt/JBoss-4.2.1/bin/run.jar" and the return value should be 
    * "/opt/JBoss-4.2.1". 
    *
    * \param    classpath    The entire classpath for an application serve
    * \returns  the application server base directory.
    */
    wstring AppServerEnumeration::GetJBossPathFromClassPath(const wstring& classpath) const
    {
        const wstring emptyString = L""; 
        wstring result = emptyString; 
        vector<wstring> parts;
        vector<wstring>::iterator part;

        /* Search through the string checking each path element for '/bin/run.jar' */
        StrTokenize(classpath, parts, PATH_SEPERATOR);

        for(part = parts.begin(); part != parts.end(); ++part) 
        {
            size_t pos = part->find(JBOSS_RUN_JAR);
            if(pos!=wstring::npos)
            {
                result = part->substr(0,pos+1); //include the trailing '/'
                break;
            }
        } 
        return result;
    }   

}
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

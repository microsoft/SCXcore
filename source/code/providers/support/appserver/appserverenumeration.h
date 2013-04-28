/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Enumeration of application servers

   \date        11-05-18 12:00:00

*/
/*----------------------------------------------------------------------------*/
#ifndef APPSERVERENUMERATION_H
#define APPSERVERENUMERATION_H

#include <vector>

#include <scxsystemlib/entityenumeration.h>
#include <scxsystemlib/processenumeration.h>
#include "appserverinstance.h"
#include <scxcorelib/scxlog.h>

namespace SCXSystemLib
{

    const static std::wstring PATH_SEPERATOR = L":";
    const static std::string WEBSPHERE_RUNTIME_CLASS = "com.ibm.ws.runtime.WsServer";
    const static std::wstring JBOSS_RUN_JAR = L"/bin/run.jar";
    /*----------------------------------------------------------------------------*/
    /**
       Class representing all external dependencies from the AppServer PAL.

    */
    class AppServerPALDependencies
    {
    public:
        virtual ~AppServerPALDependencies() {};
        virtual std::vector<SCXCoreLib::SCXHandle<ProcessInstance> > Find(const std::wstring& name);
        virtual bool GetParameters(SCXCoreLib::SCXHandle<ProcessInstance> inst, std::vector<std::string>& params);
        virtual void GetWeblogicInstances(vector<wstring> weblogicProcesses, vector<SCXCoreLib::SCXHandle<AppServerInstance> >& newInst);
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class that represents a colletion of application servers.

       PAL Holding collection of application servers.

    */
    class AppServerEnumeration : public EntityEnumeration<AppServerInstance>
    {
    public:
        explicit AppServerEnumeration(SCXCoreLib::SCXHandle<AppServerPALDependencies> = SCXCoreLib::SCXHandle<AppServerPALDependencies>(new AppServerPALDependencies()));
        virtual ~AppServerEnumeration();
        virtual void Init();
        virtual void Update(bool updateInstances=true);
        virtual void UpdateInstances();
        virtual void CleanUp();
        
    protected:
        /*
         * De-serialize instances from disk
         */
        virtual void ReadInstancesFromDisk();

        /*
         * Serialize instances to disk
         */
        virtual void WriteInstancesToDisk();

    private:
        SCXCoreLib::SCXHandle<AppServerPALDependencies> m_deps; //!< Collects external dependencies of this class.
        SCXCoreLib::SCXLogHandle m_log;         //!< Log handle.
        bool CheckProcessCmdLineArgExists(std::vector<std::string>& params, const std::string& value);
        std::string ParseOutCommandLineArg(std::vector<std::string>& params, 
                                           const std::string& key,
                                           const bool EqualsDelimited,
                                           const bool SpaceDelimited ) const;
        std::wstring GetJBossPathFromClassPath(const std::wstring& classpath) const;
        int  GetArgNumber(vector<string>& params, const string& value); 
        void CreateTomcatInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params);
        void CreateJBossInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params);
        std::wstring GetWeblogicHome(vector<string> params);
        string GetParentDirectory(const string& directoryPath,int levels=1);
        void CreateWebSphereInstance(vector<SCXCoreLib::SCXHandle<AppServerInstance> > *ASInstances, vector<string> params); 
    };

}

#endif /* APPSERVERENUMERATION_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

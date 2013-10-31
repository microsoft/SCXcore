/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        websphereappserverinstance.h

   \brief       PAL representation of a WebSphere Application Server

   \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/
#ifndef WEBSPHEREAPPSERVERINSTANCE_H
#define WEBSPHEREAPPSERVERINSTANCE_H

#include <string>
#include <util/XElement.h>

#include "appserverinstance.h"

namespace SCXSystemLib
{
    /*----------------------------------------------------------------------------*/
    /**
       Class representing all external dependencies from the AppServer PAL.

    */
    class WebSphereAppServerInstancePALDependencies
    {
    public:
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlServerFile(const std::wstring& filename);
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlVersionFile(const std::wstring& filename);
        virtual ~WebSphereAppServerInstancePALDependencies() {};
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class that represents an instances.

       Concrete implementation of an instance of a WebSphere Application Server

    */
    class WebSphereAppServerInstance : public AppServerInstance
    {
        friend class AppServerEnumeration;

    public:

        WebSphereAppServerInstance(
            std::wstring cell, std::wstring node, std::wstring profile, std::wstring installDir, std::wstring server,
            SCXCoreLib::SCXHandle<WebSphereAppServerInstancePALDependencies> deps = SCXCoreLib::SCXHandle<WebSphereAppServerInstancePALDependencies>(new WebSphereAppServerInstancePALDependencies()));
        virtual ~WebSphereAppServerInstance();

        virtual bool IsStillInstalled();

        virtual void Update();

    private:

        void UpdateVersion();
        void UpdatePorts();
        void GetStringFromStream(SCXCoreLib::SCXHandle<std::istream> mystream, std::string& content);
        void GetPortFromXml(const SCX::Util::Xml::XElementPtr& node, bool& found, std::wstring& port);

        SCXCoreLib::SCXFilePath GetProfileVersionXml() const;

        SCXCoreLib::SCXHandle<WebSphereAppServerInstancePALDependencies> m_deps;
    };

}

#endif /* WEBSPHEREAPPSERVERINSTANCE_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

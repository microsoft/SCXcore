/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        jbossappserverinstance.cpp

    \brief       PAL representation of a JBoss application server

    \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <string>
#include <iostream>
#include <fstream>

#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxprocess.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxregex.h>
#include <util/XElement.h>

#include "appserverconstants.h"
#include "jbossappserverinstance.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCX::Util::Xml;

namespace SCXSystemLib
{

    /**
       Returns a stream for reading from jar-versions.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> JBossAppServerInstancePALDependencies::OpenXmlVersionFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from bindings-jboss-beans.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> JBossAppServerInstancePALDependencies::OpenXmlPortsFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from jboss-service.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> JBossAppServerInstancePALDependencies::OpenXmlServiceFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from server.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> JBossAppServerInstancePALDependencies::OpenXmlServerFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from the service binder XML file

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> JBossAppServerInstancePALDependencies::OpenXmlBindingFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a command to run

       \param[in] filename Name of file to use
    */
    wstring JBossAppServerInstancePALDependencies::GetJboss7Command(SCXCoreLib::SCXFilePath filepath)
    {
        SCXCoreLib::SCXFilePath filename(filepath);
        filename.Append(L"standalone.sh --version");
        return filename.Get();
    }
    
    /*----------------------------------------------------------------------------*/
    /**
       Constructor

       \param[in]  id            Identifier for the appserver (= install path for the appserver)
       \param[in]  config        Configuration name used
       \param[in]  portsBinding  ports binding configuration used
       \param[in]  deps          Dependency instance to use
    */
    JBossAppServerInstance::JBossAppServerInstance(
        wstring id, wstring config, wstring portsBinding,
        SCXHandle<JBossAppServerInstancePALDependencies> deps) : 
        AppServerInstance(id, APP_SERVER_TYPE_JBOSS), 
        m_config(config), m_portsBinding(portsBinding), m_deps(deps)
    {
        bool fJboss7check = false;
        SCXRegex re(L"/standalone/configuration");
        vector<wstring> v_config;
        // If no config is given, use default
        if (L"" == config)
        {
            m_config = L"default";
        }
        //In the case of JBoss AS 7 the configuration files
        //include the diskPath and also a properties file
        //This logging.properties is not necesary
        //From docs.jboss.org "In the future file may go away"
        else if(re.ReturnMatch(config,v_config,0 ))
        {
            fJboss7check = true;
            m_config = (v_config[0]);
        }

        SCXFilePath installPath;

        installPath.SetDirectory(id);

        m_basePath = installPath.Get();
        
        if(!fJboss7check)
        {
            installPath.AppendDirectory(L"server");
        }
        installPath.AppendDirectory(m_config);

        SetId(installPath.Get());
        m_diskPath = GetId();

        SCX_LOGTRACE(m_log, wstring(L"JBossAppServerInstance default constructor - ").append(GetId()));
    }


    /*----------------------------------------------------------------------------*/
    /**
        Constructor used to created from cached entry

       \param[in]  diskPath      Path for the configuration
       \param[in]  deps          Dependency instance to use
    */
    JBossAppServerInstance::JBossAppServerInstance(
        wstring diskPath,
        SCXHandle<JBossAppServerInstancePALDependencies> deps) : 
        AppServerInstance(diskPath, APP_SERVER_TYPE_JBOSS), 
        m_config(L""), m_portsBinding(L""), m_deps(deps)
    {
        SCX_LOGTRACE(m_log, wstring(L"JBossAppServerInstance cache constructor - ").append(GetId()));
    }

    /*----------------------------------------------------------------------------*/
    /**
        Destructor
    */
    JBossAppServerInstance::~JBossAppServerInstance()
    {
        SCX_LOGTRACE(m_log, wstring(L"JBossAppServerInstance destructor - ").append(GetId()));
    }

    /*----------------------------------------------------------------------------*/
    /**
        Try to read an integer from a string

       \param[in]  result      Variable to assign the parsed integer to
       \param[in]  found       Set to true if successful
       \param[in]  value       string to read from
       \param[in]  erroText    Text to log if fails
    */
    void JBossAppServerInstance::TryReadInteger(unsigned int& result, bool& found, const wstring& value, const wstring& errorText)
    {
        try
        {
            result = StrToUInt(value);
            found = true;
        }
        catch (SCXNotSupportedException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::TryReadInteger() - ").append(GetId()).append(L" - ").append(errorText).append(L": ").append(value));
        }
    }


    /*----------------------------------------------------------------------------*/
    /**
        Update ports for JBoss 4 from the service binding configuration

        Load the given XML file
        Get node /service-bindings/server where name property is <sererName> 
        Get node service-config where name propety is jboss.web:service=WebServer
        Get node binding
        Get attribute port as HTTP Port
        Set HTTPS port as HTTP port + 363

       \param[in]  filename      Name of XML file to load
       \param[in]  servername    Name of server to use from the XML file
    */
    void JBossAppServerInstance::UpdateJBoss4PortsFromServiceBinding(wstring filename, string servername)
    {
        const string cServiceBindingNodeName("service-bindings");
        const string cServerNodeName("server");
        const string cServiceNodeName("service-config");
        const string cNameAttributeName("name");
        const string cPortAttributeName("port");
        const string cWebServerName("jboss.web:service=WebServer");
        const string cBindingNodeName("binding");
        const unsigned int HTTPSOffset = 363;

        try {
            string xmlcontent;
            SCXHandle<istream> mystream = m_deps->OpenXmlBindingFile(filename);
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr serviceBindNode;
            XElement::Load(xmlcontent, serviceBindNode);
            if (serviceBindNode->GetName() == cServiceBindingNodeName)
            {
                XElementList serverNodes;
                bool foundnode = false;

                serviceBindNode->GetChildren(serverNodes);
                for (size_t serverNodeIdx = 0; !foundnode && serverNodeIdx < serverNodes.size(); ++serverNodeIdx)
                {
                    string nameprop;

                    if (serverNodes[serverNodeIdx]->GetName() == cServerNodeName && 
                        serverNodes[serverNodeIdx]->GetAttributeValue(cNameAttributeName, nameprop) && 
                        servername == nameprop)
                    {
                        foundnode = true;

                        XElementList serviceNodes;
                        bool foundservicenode = false;

                        serverNodes[serverNodeIdx]->GetChildren(serviceNodes);
                        for (size_t serviceNodeIdx = 0; !foundservicenode && serviceNodeIdx < serviceNodes.size(); ++serviceNodeIdx)
                        {
                            if (serviceNodes[serviceNodeIdx]->GetName() == cServiceNodeName && 
                                serviceNodes[serviceNodeIdx]->GetAttributeValue(cNameAttributeName, nameprop) && 
                                cWebServerName == nameprop)
                            {
                                foundservicenode = true;
                                XElementPtr bindingNode;

                                if (serviceNodes[serviceNodeIdx]->GetChild(cBindingNodeName, bindingNode))
                                {
                                    string portprop;

                                    if (bindingNode->GetAttributeValue(cPortAttributeName, portprop))
                                    {
                                        unsigned int httpPort;
                                        bool foundport;
                                        TryReadInteger(httpPort, foundport, StrFromUTF8(portprop), L"Failed to parse HTTP port");
                                        if (foundport)
                                        {
                                            m_httpPort = StrFrom(httpPort);
                                            m_httpsPort = StrFrom(httpPort + HTTPSOffset);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServiceBinding() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServiceBinding() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServiceBinding() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update ports for JBoss 4 from the serve configuration

        Load XML file <ConfigPath>\deploy\jboss-web.deployer\server.xml
        Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and secure is true
        Get attribute named port for HTTPS Port
        Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and no attribute named secure exist
        Get attribute named port for HTTP Port
    */
    void JBossAppServerInstance::UpdateJBoss4PortsFromServerConfiguration()
    {
        const string cServerNodeName("Server");
        const string cServiceNodeName("Service");
        const string cConnectorNodeName("Connector");
        const string cProtocolAttributeName("protocol");
        const string cSecureAttributeName("secure");
        const string cPortAttributeName("port");
        const string cHTTP11Name("HTTP/1.1");
        const string cTrueName("true");

        SCXFilePath filename(m_diskPath);

        string xmlcontent;
        filename.Append(L"/deploy/jboss-web.deployer/server.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlServerFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr serverNode;
            XElement::Load(xmlcontent, serverNode);
            if (serverNode->GetName() == cServerNodeName)
            {
                XElementPtr serviceNode;

                if (serverNode->GetChild(cServiceNodeName, serviceNode))
                {
                    XElementList connectorNodes;
                    bool foundHTTPnode = false;
                    bool foundHTTPSnode = false;

                    serviceNode->GetChildren(connectorNodes);
                    for (size_t idx = 0; !(foundHTTPnode && foundHTTPSnode) && idx < connectorNodes.size(); ++idx)
                    {
                        string protocolprop;

                        if (connectorNodes[idx]->GetName() == cConnectorNodeName && 
                            connectorNodes[idx]->GetAttributeValue(cProtocolAttributeName, protocolprop) && 
                            cHTTP11Name == protocolprop)
                        {
                            string secureprop;
                            string portprop;

                            if (connectorNodes[idx]->GetAttributeValue(cPortAttributeName, portprop))
                            {
                                if (connectorNodes[idx]->GetAttributeValue(cSecureAttributeName, secureprop) && 
                                    cTrueName == secureprop)
                                {
                                    m_httpsPort = StrFromUTF8(portprop);
                                    foundHTTPSnode = true;
                                }
                                else
                                {
                                    m_httpPort = StrFromUTF8(portprop);
                                    foundHTTPnode = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServerConfiguration() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServerConfiguration() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4PortsFromServerConfiguration() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update ports for JBoss 4

        Load XML file <ConfigPath>/conf/jboss-service.xml

        Get node /server/mbean where code property is org.jboss.services.binding.ServiceBindingManager
        if that exist
          Get node attribute where name property is ServerName and save as port name
          Get node attribute where name property is StoreURL
          Replace ${jboss.home.url} with ConfigPath and load the XML file
          Get node /service-bindings/server where name property is <port name> 
          Get node service-config where name propety is jboss.web:service=WebServer
          Get node binding
          Get attribute port as HTTP Port
          Set HTTPS port as HTTP port + 363
        If not exists
          Load XML file <ConfigPath>\deploy\jboss-web.deployer\server.xml
          Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and secure is true
          Get attribute named port for HTTPS Port
          Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and no attribute named secure exist
          Get attribute named port for HTTP Port
    */
    void JBossAppServerInstance::UpdateJBoss4Ports()
    {
        const string cServerNodeName("server");
        const string cMbeanNodeName("mbean");
        const string cCodeAttributeName("code");
        const string cServiceBindingManagerName("org.jboss.services.binding.ServiceBindingManager");
        const string cAttributeNodeName("attribute");
        const string cNameAttributeName("name");
        const string cServerNameName("ServerName");
        const string cStoreUrlName("StoreURL");
        const wstring cHomeUrlName(L"${jboss.home.url}/");

        SCXFilePath filename(m_diskPath);

        string xmlcontent;
        filename.Append(L"/conf/jboss-service.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlServiceFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr serverNode;
            XElement::Load(xmlcontent, serverNode);
            if (serverNode->GetName() == cServerNodeName)
            {
                XElementList mbeanNodes;
                bool foundnode = false;

                serverNode->GetChildren(mbeanNodes);
                for (size_t mbeanNodeIdx = 0; !foundnode && mbeanNodeIdx < mbeanNodes.size(); ++mbeanNodeIdx)
                {
                    string codeprop;

                    if (mbeanNodes[mbeanNodeIdx]->GetName() == cMbeanNodeName && 
                        mbeanNodes[mbeanNodeIdx]->GetAttributeValue(cCodeAttributeName, codeprop) && 
                        cServiceBindingManagerName == codeprop)
                    {
                        XElementList attrNodes;
                        bool foundname = false;
                        bool foundurl = false;
                        string serverName("");
                        wstring storeUrl(L"");

                        foundnode = true;

                        mbeanNodes[mbeanNodeIdx]->GetChildren(attrNodes);
                        for (size_t attrNodeIdx = 0; !(foundname && foundurl) && attrNodeIdx < attrNodes.size(); ++attrNodeIdx)
                        {
                            string nameprop;

                            if (attrNodes[attrNodeIdx]->GetName() == cAttributeNodeName && 
                                attrNodes[attrNodeIdx]->GetAttributeValue(cNameAttributeName, nameprop))
                            {
                                if (cServerNameName == nameprop)
                                {
                                    foundname = true;
                                    attrNodes[attrNodeIdx]->GetContent(serverName);
                                }
                                else if (cStoreUrlName == nameprop)
                                {
                                    foundurl = true;
                                    attrNodes[attrNodeIdx]->GetContent(storeUrl);
                                }
                            }
                        }

                        if (foundname && foundurl)
                        {
                            size_t homePos = storeUrl.find(cHomeUrlName);
                            if (homePos != wstring::npos)
                            {
                                storeUrl.replace(homePos, cHomeUrlName.length(), m_basePath);
                            }
                            UpdateJBoss4PortsFromServiceBinding(storeUrl, serverName);
                        }
                    }
                }

                if (!foundnode)
                {
                    UpdateJBoss4PortsFromServerConfiguration();
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4Ports() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4Ports() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss4Ports() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Given a XML element list find the element containing "${jboss.service.binding.set:xxx}"
        in it value and return the associated part e.g. "xxx"
    */
    bool GetPortsBinding (XElementList paramNodes, wstring & portsBinding)
    {
        const string cBindingObjectDefaultSet ("${jboss.service.binding.set:");
        bool foundBinding = false;
        
        for (size_t idx = 0; !(foundBinding) && idx < paramNodes.size(); ++idx)
        {
            string content;
            paramNodes[0]->GetContent(content);
            if(content.length() > cBindingObjectDefaultSet.length())
            {
               if (content.compare(0,cBindingObjectDefaultSet.length(),cBindingObjectDefaultSet) == 0) 
               {
                  portsBinding = StrFromUTF8(content.substr(cBindingObjectDefaultSet.length(),content.length() - cBindingObjectDefaultSet.length() - 1) );
                  foundBinding = true;
               }
            }
        }
        return foundBinding;
    }
    
    /*----------------------------------------------------------------------------*/
    /**
        Update ports for JBoss 5

        Load XML file <ConfigPath>/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml

        If no portsBinding has been set (no command line option specified) we get the 
        assiciated factory from the "ServiceBindingManager". Once we have got the factory we use its value to
        to get the default portsBinding. This is done by getting the properties for the factory and looking for the 
        "${jboss.service.binding.set:XXX" value. If we still do not have a portsBinding value we use "ports-default"
        as the value.
        
        Get nodes /deployment/bean where class property is org.jboss.services.binding.impl.ServiceBindingSet
        For each of those nodes get the nodes constructor/parameter
        If the first of those nodes has the text equal to the portsBinding, set the offset to the text from the third node

        Get node /deployment/bean where name property is StandardBindings
        For that node get all nodes constructor/parameter/set/bean
        Find the one node among those that have a subnode property where 
        name property is serviceName and text is jboss.web:service=WebServer
        Then get text of subnode property where name property is port
        Then get text of subnode property where name property is bindingName
        If no node exist with name property being bindingName, use port for HttpPort
        If node with name property being bindingNamehas text HttpConnector, use port for HttpPort
        If node with name property being bindingNamehas text HttpsConnector, use port for HttpsPort
        
    */
    void JBossAppServerInstance::UpdateJBoss5Ports()
    {
        const string cDeploymentNodeName("deployment");
        const string cBeanNodeName("bean");
        const string cSetNodeName("set");
        const string cPropertyNodeName("property");
        const string cClassAttributeName("class");
        const string cConstructorNodeName("constructor");
        const string cServiceBindingSetName("org.jboss.services.binding.impl.ServiceBindingSet");
        const string cParameterNodeName("parameter");
        const string cNameAttributeName("name");
        const string cStandardBindingsName("StandardBindings");
        const string cServiceName("serviceName");
        const string cWebServerName("jboss.web:service=WebServer");
        const string cBindingName("bindingName");
        const string cPortName("port");
        const string cHttpConnectorName("HttpConnector");
        const string cHttpsConnectorName("HttpsConnector");
        const string cServiceBindingManagerAttributeName("ServiceBindingManager");
        const string cFactoryNodeName("factory");
        const string cBeanAttributeName("bean");
        const wstring cPortsDefault(L"ports-default");

        string xmlcontent;
        SCXFilePath filename(m_diskPath);

        filename.Append(L"/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlPortsFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr depNode;
            XElement::Load(xmlcontent, depNode);
            if (depNode->GetName() == cDeploymentNodeName)
            {
                XElementList beanNodes;
                depNode->GetChildren(beanNodes);
                bool foundset = false;
                bool foundbase = false;
                unsigned int portOffset = 0; // Use offset 0 if no offset can be found
                XElementPtr baseNode;
                string bindingManager;
                bool foundBinding = false;

                // No PortsBinding has been specified on the commandline, check for the default value set in the XML file. 
                // We start by finding the factory used by the "ServiceBindingManager"
                //
                // <bean name="ServiceBindingManager" class="org.jboss.services.binding.ServiceBindingManager">
                //    <annotation>@org.jboss.aop.microcontainer.aspects.jmx.JMX(name="jboss.system:service=ServiceBindingManager", exposedInterface=org.jboss.services.binding.ServiceBindingManagerMBean.class, registerDirectly=true)</annotation>
                //    <constructor factoryMethod="getServiceBindingManager">
                //       <factory bean="ServiceBindingManagementObject"/>
                //    </constructor>
                // </bean>

                if ( m_portsBinding.empty() )
                {
                    for (size_t idx = 0; !(foundBinding) && idx < beanNodes.size(); ++idx)
                    {
                        string nameprop;
                        string classprop;

                        // Get the "ServiceBindingManager" from the XML file
                        if (beanNodes[idx]->GetName() == cBeanNodeName && 
                            beanNodes[idx]->GetAttributeValue(cNameAttributeName, classprop) && 
                            cServiceBindingManagerAttributeName == classprop)
                        {
                            XElementPtr constrNode;
                            if (beanNodes[idx]->GetChild(cConstructorNodeName, constrNode))
                            {
                                XElementPtr factoryNode;
                                if (constrNode->GetChild(cFactoryNodeName, factoryNode))
                                {
                                    factoryNode->GetAttributeValue(cBeanAttributeName, bindingManager);
                                }        
                            }
                        }
                        
                        // Once we have the factory associated with the "ServiceBindingManager" we need to find the 
                        // parameter containing the default value "${jboss.service.binding.set:ports-01}" and get the configuration option
                        // specified e.g. "ports-01"
                        //
                        // <bean name="ServiceBindingManagementObject" class="org.jboss.services.binding.managed.ServiceBindingManagementObject">
                        //   <constructor>
                        //      <parameter>${jboss.service.binding.set:ports-01}</parameter>
                        //      <parameter>
                        //         <set>
                        //            <inject bean="PortsDefaultBindings"/>
                        //            <inject bean="Ports01Bindings"/>
                        //            <inject bean="Ports02Bindings"/>
                        //            <inject bean="Ports03Bindings"/>
                        //         </set>
                        //      </parameter>
                        //      <parameter>
                        //         <inject bean="StandardBindings"/>
                        //      </parameter>
                        //   </constructor>
                        // </bean>
                        if(bindingManager.length() > 0)
                        {
                            if (beanNodes[idx]->GetName() == cBeanNodeName && 
                                beanNodes[idx]->GetAttributeValue(cNameAttributeName, classprop) && 
                                bindingManager == classprop)
                            {
                                XElementPtr constrNode;
                                if (beanNodes[idx]->GetChild(cConstructorNodeName, constrNode))
                                {
                                    XElementList paramNodes;
                                    
                                    constrNode->GetChildren(paramNodes);
                                    foundBinding = GetPortsBinding (paramNodes, m_portsBinding);
                                }
                            }
                        }
                    }
                }

                // No PortsBinding has been specified on the commandline and we never found the
                // default setting in the ServiceBindingManager so we will atempt to use the default
                if ( m_portsBinding.empty() )
                {
                    m_portsBinding = cPortsDefault;
                }

                for (size_t idx = 0; !(foundset && foundbase) && idx < beanNodes.size(); ++idx)
                {
                    string nameprop;
                    string classprop;

                    if (beanNodes[idx]->GetName() == cBeanNodeName && 
                        beanNodes[idx]->GetAttributeValue(cClassAttributeName, classprop) && 
                        cServiceBindingSetName == classprop)
                    {
                        XElementPtr constrNode;
                        if (beanNodes[idx]->GetChild(cConstructorNodeName, constrNode))
                        {
                            XElementList paramNodes;
                            constrNode->GetChildren(paramNodes);
                            if (paramNodes.size() >= 3 &&
                                paramNodes[0]->GetName() == cParameterNodeName &&
                                paramNodes[0]->GetContent() == StrToUTF8(m_portsBinding))
                            {
                                std::wstring content;
                                paramNodes[2]->GetContent(content);

                                TryReadInteger(portOffset, foundset, content, L"Failed to parse port offset");
                            }
                        }
                    }

                    if (beanNodes[idx]->GetName() == cBeanNodeName && 
                        beanNodes[idx]->GetAttributeValue(cNameAttributeName, nameprop) && 
                        cStandardBindingsName == nameprop)
                    {
                        baseNode = beanNodes[idx];
                        foundbase = true;
                    }
                }

                // use baseNode to figure out base HTTP & HTTPS ports
                // add portOffset to that
                XElementPtr constrNode;
                XElementPtr paramNode;
                XElementPtr setNode;
                if (foundbase && 
                    baseNode->GetChild(cConstructorNodeName, constrNode) && 
                    constrNode->GetChild(cParameterNodeName, paramNode) &&
                    paramNode->GetChild(cSetNodeName, setNode))
                {
                    XElementList setBeanNodes;
                    setNode->GetChildren(setBeanNodes);
                    bool foundHttp = false;
                    bool foundHttps = false;
                    unsigned int baseHttpPort = 0;
                    unsigned int baseHttpsPort = 0;
                    for (size_t idx = 0; !(foundHttp && foundHttps) && idx < setBeanNodes.size(); ++idx)
                    {
                        XElementList propNodes;
                        string nameprop;
                        std::wstring content;

                        setBeanNodes[idx]->GetChildren(propNodes);
                        if (propNodes.size() >= 2 &&
                            propNodes[0]->GetName() == cPropertyNodeName &&
                            propNodes[0]->GetAttributeValue(cNameAttributeName, nameprop) &&
                            cServiceName == nameprop &&
                            propNodes[0]->GetContent() == cWebServerName)
                        {
                            if (propNodes.size() >= 3 &&
                                propNodes[1]->GetName() == cPropertyNodeName &&
                                propNodes[1]->GetAttributeValue(cNameAttributeName, nameprop) &&
                                cBindingName == nameprop &&
                                propNodes[2]->GetName() == cPropertyNodeName &&
                                propNodes[2]->GetAttributeValue(cNameAttributeName, nameprop) &&
                                cPortName == nameprop)
                            {
                                if (propNodes[1]->GetContent() == cHttpConnectorName)
                                {
                                    propNodes[2]->GetContent(content);
                                    TryReadInteger(baseHttpPort, foundHttp, content, L"Failed to parse HTTP port");
                                }
                                else if (propNodes[1]->GetContent() == cHttpsConnectorName)
                                {
                                    propNodes[2]->GetContent(content);
                                    TryReadInteger(baseHttpsPort, foundHttps, content, L"Failed to parse HTTPS port");
                                }
                            }
                            else if (propNodes[1]->GetName() == cPropertyNodeName &&
                                     propNodes[1]->GetAttributeValue(cNameAttributeName, nameprop) &&
                                     cPortName == nameprop)
                            {
                                propNodes[1]->GetContent(content);
                                TryReadInteger(baseHttpPort, foundHttp, content, L"Failed to parse HTTP port");
                            }
                        }
                    }
                    // calculate ports if found
                    if (foundHttp)
                    {
                        m_httpPort = StrFrom(baseHttpPort + portOffset);
                    }
                    if (foundHttps)
                    {
                        m_httpsPort = StrFrom(baseHttpsPort + portOffset);
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss5Ports() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss5Ports() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss5Ports() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }
    /*----------------------------------------------------------------------------*/
    /**
       Update ports for JBoss 7

       Load XML file <disk_path>/standalone/standalone.xml
       No need for bindings file, All located in standalone.xml
        
       In Standalon.xml navigate to socket-binding group and check for port-offset
       attribute. if not found set to 0. Get list of all socket-binding group's children
       and traverse to retrieve http and https. If modifications are to be made in the future
       for inclusion of osgi applications, traverse same file.
        
        
    */
    void JBossAppServerInstance::UpdateJBoss7Ports()
    {
        const string cServerNodeName("server");
        const string cSocketBindingGroupNodeName("socket-binding-group");
        const string cPortOffsetAttributeName("port-offset");
        const string cSocketBindingNodeName("socket-binding");
        const string cNameAttributeName("name");
        const string cHttpName("http");
        const string cHttpsName("https");
        const string cPortAttributeName("port");

        string xmlcontent;
        SCXFilePath filename(m_basePath);
    
        filename.Append(L"standalone/configuration/standalone.xml");
      
        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlPortsFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr topNode;
            XElement::Load(xmlcontent, topNode);
            if (topNode->GetName() == cServerNodeName)
            {
                XElementPtr socketBindingGroupNode;
                if(topNode->GetChild(cSocketBindingGroupNodeName, socketBindingGroupNode))
                {
                    bool httpPortFound = false;
                    bool httpsPortFound = false;
                    bool portsFound = false;
                    bool portOffsetFound = false;
                    unsigned int baseHttpPort = 0;
                    unsigned int baseHttpsPort = 0;
                    unsigned int portOffset = 0;
                    string HttpPort;
                    string HttpsPort;
                    string offset;
             
                    //chek if port-offset attribute, if not then value is preset to 0
                    if(socketBindingGroupNode->GetAttributeValue(cPortOffsetAttributeName,offset))
                    {
                        //There are two ways to set port-offset, one with port-offset="100",
                        //and the second with port-offset="${jboss.socket.binding.port-offset:100}";
                        //check if it includes jboss.socket.bind.port-offset beginning and parse accordingly
                        wstring wPortOffset = SCXCoreLib::StrFromUTF8(offset);
                        std::vector<std::wstring> v_offset;
                        SCXRegex re(L"([0-9]*)");
                        if(re.ReturnMatch(wPortOffset,v_offset,0))
                        {
                            wPortOffset = v_offset[1];
                        }
                        TryReadInteger(portOffset, portOffsetFound, wPortOffset, L"Failed to Parse port offset");
                    }
                    //XMl Document Example for Standalone.xml
                    //<socket-binding-group name="standard sockets>
                    //  <socket-binding name="http" port="8080"/>
                    //  <socket-binding name="https" port="8443"/>
                    //  <socket-binding name="....." port="...."/>
                    //</socket-binding group>
                    XElementList socketBindings;
                    socketBindingGroupNode->GetChildren(socketBindings);
            
                    for(size_t idx = 0; !portsFound && idx <socketBindings.size();++idx)
                    {
                        string name;
                        if(socketBindings[idx]->GetName() == cSocketBindingNodeName &&
                           socketBindings[idx]->GetAttributeValue(cNameAttributeName, name))
                        {
                            if(cHttpName == name &&
                               socketBindings[idx]->GetAttributeValue(cPortAttributeName, HttpPort))
                            {
                                wstring wHttpPort;
                                wHttpPort = SCXCoreLib::StrFromUTF8(HttpPort);
                                TryReadInteger(baseHttpPort, httpPortFound, wHttpPort, L"Failed to parse HTTP port");
                            }
                            else if(cHttpsName == name &&
                                    socketBindings[idx]->GetAttributeValue(cPortAttributeName, HttpsPort))
                            {
                                wstring wHttpsPort;
                                wHttpsPort = SCXCoreLib::StrFromUTF8(HttpsPort);
                                TryReadInteger(baseHttpsPort, httpsPortFound, wHttpsPort, L"Failed to parse HTTPS port");
                            }

                            if(httpPortFound && httpsPortFound) portsFound = true;
                        }
                    }
                    if(httpPortFound)
                    {
                        m_httpPort = StrFrom(baseHttpPort + portOffset);
                    }
                    if(httpsPortFound)
                    {
                        m_httpsPort = StrFrom(baseHttpsPort + portOffset);
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss7Ports() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss7Ports() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateJBoss7Ports() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }
    /*----------------------------------------------------------------------------*/
    /**
       Update version

       Load XML file <DiskPath>/jar-versions.xml
       Get node /jar-versions/jar where name property is jboss.jar
       Read specVersion property for that node
    */
    void JBossAppServerInstance::UpdateVersion()
    {
        const string cJarVersionsNodeName("jar-versions");
        const string cJarNodeName("jar");
        const string cNameAttributeName("name");
        const string cJbossJarName("jboss.jar");
        const string cSpecVersionAttributeName("specVersion");
        
        bool fJboss7Check = false;

        string xmlcontent;
        SCXFilePath filename(m_basePath);
        SCXFilePath filename2(m_basePath);

        filename.Append(L"jar-versions.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlVersionFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr topNode;
            XElement::Load(xmlcontent, topNode);
            if (topNode->GetName() == cJarVersionsNodeName)
            {
                XElementList versionNodes;
                topNode->GetChildren(versionNodes);
                bool found = false;
                for (size_t idx = 0; !found && idx < versionNodes.size(); ++idx)
                {
                    string name;
                    if (versionNodes[idx]->GetName() == cJarNodeName && 
                        versionNodes[idx]->GetAttributeValue(cNameAttributeName, name) && 
                        cJbossJarName == name)
                    {
                        string version;
                        if (versionNodes[idx]->GetAttributeValue(cSpecVersionAttributeName, version))
                        {
                            SetVersion(StrFromUTF8(version));
                            found = true;
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            fJboss7Check = true;
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
        
        if(fJboss7Check)
        {            
            try {
                
                filename2.Append(L"bin/");
                
                std::istringstream in;
                std::ostringstream out;
                std::ostringstream err;
                
                // Get command line from function
                // Determine parse full string to only get filepath/standalone.sh
                // Determine if SCXFileExists(..filepath/standalone.sh)
                // Only use SCXProcess::Run If standalone.sh exists

                wstring cli = m_deps->GetJboss7Command(filename2);

                std::size_t found = cli.find( L" --version");
                bool jboss7StandaloneFilePathExist = false;
                
                if(found!=std::wstring::npos)
                {
                    SCXFilePath standaloneFileInJB7(cli.substr(0,found));
                    jboss7StandaloneFilePathExist = SCXFile::Exists(standaloneFileInJB7); 
                }

                if(cli.length() && jboss7StandaloneFilePathExist)
                {
                    int exitStatus = SCXCoreLib::SCXProcess::Run(cli,in,out,err,10000);
            
                    if(exitStatus != 0 || err.str().length())
                    {
                        wstring werr = SCXCoreLib::StrFromUTF8(err.str());
                        SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - error in command line: ").append(werr));
                    }
                    else
                    {
                        wstring commandOutput = SCXCoreLib::StrFromUTF8(out.str());
                        vector<wstring> v_version;
                         
                        SCXRegex re(L"JBoss (Application Server|AS) ([^ ?]*)");
                        if(re.ReturnMatch(commandOutput,v_version,0))
                        {
                            SetVersion(v_version[2]);
                        }
                    }
                }
            }
            catch (SCXFilePathNotFoundException&)
            {
                SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not find file: ").append(filename).append(L"- Or find file: ").append(filename2));
            }
            catch (SCXUnauthorizedFileSystemAccessException&)
            {
                SCX_LOGERROR(m_log, wstring(L"JBossAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename2));
            }
        }
    }
    
    /*----------------------------------------------------------------------------*/
    /**
       Update values

    */
    void JBossAppServerInstance::Update()
    {
        SCX_LOGTRACE(m_log, wstring(L"JBossAppServerInstance::Update() - ").append(GetId()));

        UpdateVersion();

        if (m_majorVersion.length() > 0)
        {
            if(StrToLong(m_majorVersion) >= 7)
            {
                UpdateJBoss7Ports();      //JBoss is version 7 or higher
            }
            else if (StrToLong(m_majorVersion) >= 5)  //JBoss is version 5 or 6
            {
                UpdateJBoss5Ports();
            }
            else
            {
                UpdateJBoss4Ports();
            }
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Read all lines from a stream and save in a string

       \param[in]  mystream   Stream to read from
       \param[out] content    String to return content in
    */
    void JBossAppServerInstance::GetStringFromStream(SCXHandle<istream> mystream, string& content)
    {
        content = "";
        while (SCXStream::IsGood(*mystream))
        {
            string tmp;
            getline(*mystream, tmp);
            content.append(tmp);
            content.append("\n");
        }
    }

}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Created date    2011-05-18

  jboss appserver data colletion test class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilesystem.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxprocess.h>

#include <jbossappserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

// Test dependencies used to get the XML content from string constants instead of from files
// Also has the ability to control some aspects of the XML to supply, to simulate different problems
class JBossAppServerInstanceTestPALDependencies : public JBossAppServerInstancePALDependencies
{
public:
    JBossAppServerInstanceTestPALDependencies() : 
        m_xmlVersionFilename(L""), m_xmlPortsFilename(L""), m_httpBindingProperty(false), 
        m_includeJbossJar(true), m_version5(true),m_hasJboss7File(true), m_hasBadJboss7File(false), m_version7(false), m_httpBinding(true), m_httpsBinding(true),
        m_noPortsFile(false), m_noVersionFile(false), m_noServiceFile(false), m_noServerFile(false), 
        m_noBindingFile(false), m_emptyPortsFile(false), m_emptyVersionFile(false), m_emptyServiceFile(false), 
        m_emptyServerFile(false), m_emptyBindingFile(false), m_badPortsXml(false), m_badVersionXml(false), 
        m_badHttpPortValue(false), m_badPortOffsetValue(false), m_serviceBinding(true),
        m_noPortOffsetValue(false), m_badPortOffsetValueWithSocket(false),
        m_portBindingName("${jboss.service.binding.set:ports-default}")
    {}

    // Should there be an Port Offset Value attribute in socket-binding-group tag(JBoss 7)
    void SetNoPortOffsetValue(bool noPortOffsetValue)
    {
        m_noPortOffsetValue = noPortOffsetValue;
    }

    // Should there be an invalid Port Offset Value attribute in socket-binding-group for secondary option i.e using jboss.socket (JBoss 7)
    void SetBadPortOffsetValueWithSocket(bool badPortOffsetValueWithSocket)
    {
        m_badPortOffsetValueWithSocket = badPortOffsetValueWithSocket;
    }

    // Should the XML contain a serviceBindingManager tag
    void SetServiceBinding(bool serviceBinding)
    {
        m_serviceBinding = serviceBinding;
    }

    // Should the XML contain a property tag with a name attribute with the value bindingName that contains the string HttpConnector
    void SetHttpBindingProperty(bool httpBindingProperty)
    {
        m_httpBindingProperty = httpBindingProperty;
    }

    // Should the XML contain a section describign the HTTPS binding
    void SetHttpsBinding(bool httpsBinding)
    {
        m_httpsBinding = httpsBinding;
    }

    // Should the XML contain a section describign the HTTP binding
    void SetHttpBinding(bool httpBinding)
    {
        m_httpBinding = httpBinding;
    }

    // Should the XML contain an entry for jboss.jar 
    void SetIncludeJbossJar(bool includeJbossJar)
    {
        m_includeJbossJar = includeJbossJar;
    }

    // Should the XML contain version 5 or 4
    void SetVersion5(bool version5)
    {
        m_version5 = version5;
    }

    //should this File execute the standalone.sh script
    void SetHasJboss7File(bool hasJboss7File)
    {
        m_hasJboss7File = hasJboss7File;
    }

    // Should we use XML from JBoss 7 or JBoss 4 or 5
    void SetVersion7(bool version7)
    {
        m_version7 = version7;
    }

    //Should the Run command return something without the versoin
    void SetHasBadJboss7VersionFile(bool hasBadJboss7VersionFile)
    {
        m_hasBadJboss7File = hasBadJboss7VersionFile;
    }

    // Should the we throw an exception when opening the ports file
    void SetNoPortsFile(bool noPortsFile)
    {
        m_noPortsFile = noPortsFile;
    }

    // Should the we throw an exception when opening the version file
    void SetNoVersionFile(bool noVersionFile)
    {
        m_noVersionFile = noVersionFile;
    }

    // Should the we throw an exception when opening the service file
    void SetNoServiceFile(bool noServiceFile)
    {
        m_noServiceFile = noServiceFile;
    }

    // Should the we throw an exception when opening the server file
    void SetNoServerFile(bool noServerFile)
    {
        m_noServerFile = noServerFile;
    }

    // Should the we throw an exception when opening the binding file
    void SetNoBindingFile(bool noBindingFile)
    {
        m_noBindingFile = noBindingFile;
    }

    // Should the we return an empty string for the content of the ports file
    void SetEmptyPortsFile(bool emptyPortsFile)
    {
        m_emptyPortsFile = emptyPortsFile;
    }

    // Should the we return an empty string for the content of the version file
    void SetEmptyVersionFile(bool emptyVersionFile)
    {
        m_emptyVersionFile = emptyVersionFile;
    }

    // Should the we return an empty string for the content of the service file
    void SetEmptyServiceFile(bool emptyServiceFile)
    {
        m_emptyServiceFile = emptyServiceFile;
    }

    // Should the we return an empty string for the content of the server file
    void SetEmptyServerFile(bool emptyServerFile)
    {
        m_emptyServerFile = emptyServerFile;
    }

    // Should the we return an empty string for the content of the binding file
    void SetEmptyBindingFile(bool emptyBindingFile)
    {
        m_emptyBindingFile = emptyBindingFile;
    }

    // Should the we return invalid XML for the content of the ports file
    void SetBadPortsXml(bool badPortsXml)
    {
        m_badPortsXml = badPortsXml;
    }

    // Should the we return invalid XML for the content of the version file
    void SetBadVersionXml(bool badVersionXml)
    {
        m_badVersionXml = badVersionXml;
    }

    // Should the XML contain a non-numeric value for the HTTP port
    void SetBadHttpPortValue(bool badHttpPortValue)
    {
        m_badHttpPortValue = badHttpPortValue;
    }

    // Should the XML contain a non-numeric value for the port offset
    void SetBadPortOffsetValue(bool badPortOffsetValue)
    {
        m_badPortOffsetValue = badPortOffsetValue;
    }

    virtual SCXHandle<std::istream> OpenXmlVersionFile(wstring filename)
    {
        m_xmlVersionFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noVersionFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyVersionFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<jar-versions>" << endl;
        *xmlcontent << "<jar name=\"FastInfoset.jar\" specVersion=\"1.0\" specVendor=\"JBoss (http://www.jboss.org/)\" specTitle=\"ITU-T Rec. X.891 | ISO/IEC 24824-1 (Fast Infoset)\" implVersion=\"1.2.2\" implVendor=\"Sun Microsystems, Inc.\" implTitle=\"Fast Infoset Implementation \" implVendorID=\"com.sun\" implURL=\"http://www.jboss.org/\" sealed=\"false\" md5Digest=\"aaa3ac05dbedcbd8c4d62e11e68a4b7e\"/>" << endl;
        *xmlcontent << "<jar name=\"activation.jar\" specVersion=\"1.1\" specVendor=\"Sun Microsystems, Inc.\" specTitle=\"JavaBeans(TM) Activation Framework Specification\" implVersion=\"1.1\" implVendor=\"Sun Microsystems, Inc.\" implTitle=\"Sun Java System Application Server\" implVendorID=\"com.sun\" implURL=\"http://www.jboss.org/\" sealed=\"false\" md5Digest=\"2dc066d4c6fda44c8e32ea95ad267b2a\"/>" << endl;

        if (m_includeJbossJar)
        {
            if (m_version5)
            {
                *xmlcontent << "<jar name=\"jboss.jar\" specVersion=\"5.1.0.GA\" specVendor=\"JBoss (http://www.jboss.org/)\" specTitle=\"JBoss\" implVersion=\"5.1.0.GA (build: SVNTag=JBoss_5_1_0_GA date=200905221634)\" implVendor=\"JBoss Inc.\" implTitle=\"JBoss [The Oracle]\" implVendorID=\"http://www.jboss.org/\" implURL=\"http://www.jboss.org/\" sealed=\"false\" md5Digest=\"4080a2cc0e907c386fb78247f97139de\"/>" << endl;
            }
            else
            {
                *xmlcontent << "<jar name=\"jboss.jar\" specVersion=\"4.2.1.GA\" specVendor=\"JBoss (http://www.jboss.org/)\" specTitle=\"JBoss\" implVersion=\"4.2.1.GA (build: SVNTag=JBoss_4_2_1_GA date=200707131605)\" implVendor=\"JBoss Inc.\" implTitle=\"JBoss [Trinity]\" implVendorID=\"http://www.jboss.org/\" implURL=\"http://www.jboss.org/\" sealed=\"false\" md5Digest=\"d52311010c99823da360b6c3db8bcdcd\"/>" << endl;
            }
        }

        *xmlcontent << "<jar name=\"xnio-nio.jar\" specVersion=\"1.2.1.GA\" specVendor=\"JBoss, a division of Red Hat, Inc.\" specTitle=\"XNIO NIO Implementation\" implVersion=\"1.2.1.GA\" implVendor=\"JBoss, a division of Red Hat, Inc.\" implTitle=\"XNIO NIO Implementation\" implVendorID=\"http://www.jboss.org/\" implURL=\"http://www.jboss.com/xnio\" sealed=\"false\" md5Digest=\"232167be18917246e62c64b75d7922fb\"/>" << endl;

        if (!m_badVersionXml)
        {
            *xmlcontent << "</jar-versions>" << endl;
        }

        return xmlcontent;
    }

    virtual wstring GetJboss7Command(SCXCoreLib::SCXFilePath filepath)
    {
        wstring cli;
        if(m_hasBadJboss7File)
        {
            cli = L"./testfiles/Jboss7VersionCheck.sh --version -b";
        }
        else if(m_hasJboss7File)
        {
            cli = L"./testfiles/Jboss7VersionCheck.sh --version";
        }
        else
        {
            cli = L"";
        }
        return cli;
    }

    virtual SCXHandle<std::istream> OpenXmlPortsFile(wstring filename)
    {
        m_xmlPortsFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noPortsFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyPortsFile)
        {
            return xmlcontent;
        }
        
        if(!m_version5 && m_version7)
        {
            *xmlcontent << " <server xmlns=\"urn:jboss:domain:1.0\">"<<endl;
          
            if(m_noPortOffsetValue)
            {
                *xmlcontent << "   <socket-binding-group name=\"standard-sockets\" default-interface=\"public\">"<<endl;
            }
            else if(m_badPortOffsetValue)
            {
                *xmlcontent <<"  <socket-binding-group name=\"standard-sockets\" default-interface=\"public\" port-offset=\"xyz\">"<<endl;
            }
            else if(m_badPortOffsetValueWithSocket)
            {
                *xmlcontent <<"  <socket-binding-group name=\"standard-sockets\" default-interface=\"public\" port-offset=\"${jboss.socket.binding.port-offset:xyz}\">"<<endl;
            }
            else
            {
                *xmlcontent <<"  <socket-binding-group name=\"standard-sockets\" default-interface=\"public\">"<<endl;
            }

            if(m_badHttpPortValue)
            {
                *xmlcontent <<"     <socket-binding name=\"http\" port=\"xyz\"/>"<<endl; 
            }
            else
            {  
                *xmlcontent <<"     <socket-binding name=\"http\" port=\"8080\"/>"<<endl;
            }

            *xmlcontent <<"     <socket-binding name=\"https\" port=\"8443\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"jmx-connector-registry\" port=\"1090\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"jmx-connector-server\" port=\"1091\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"jndi\" port=\"1099\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"osgi-http\" port=\"8090\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"remoting\" port=\"4447\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"txn-recovery-environment\" port=\"4712\"/>"<<endl;
            *xmlcontent <<"     <socket-binding name=\"txn-status-manager\" port=\"4713\"/>"<<endl;
            *xmlcontent <<"   </socket-binding-group>"<<endl;
            *xmlcontent <<"  </server>"<<endl;

            return xmlcontent;
        }
        
        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<deployment kalle=\"urn:jboss:bean-deployer:2.0\">" << endl;
        *xmlcontent << "  <bean name=\"ServiceBindingManager\" class=\"org.jboss.services.binding.ServiceBindingManager\">" << endl;
        *xmlcontent << "     <annotation>@org.jboss.aop.microcontainer.aspects.jmx.JMX(name=\"jboss.system:service=ServiceBindingManager\", exposedInterface=org.jboss.services.binding.ServiceBindingManagerMBean.class, registerDirectly=true)</annotation>" << endl;
        *xmlcontent << "     <constructor factoryMethod=\"getServiceBindingManager\">" << endl;
        *xmlcontent << "        <factory bean=\"ServiceBindingManagementObject\"/>" << endl;
        *xmlcontent << "     </constructor>" << endl;
        *xmlcontent << "  </bean>" << endl;
        *xmlcontent << "  <bean name=\"ServiceBindingManagementObject\" class=\"org.jboss.services.binding.managed.ServiceBindingManagementObject\">" << endl;
        *xmlcontent << "     <constructor>" << endl;
        *xmlcontent << "        <parameter>" << m_portBindingName << "</parameter>" << endl;
        *xmlcontent << "        <parameter>" << endl;
        *xmlcontent << "           <set>" << endl;
        *xmlcontent << "              <inject bean=\"PortsDefaultBindings\"/>" << endl;
        *xmlcontent << "              <inject bean=\"Ports01Bindings\"/>" << endl;
        *xmlcontent << "              <inject bean=\"Ports02Bindings\"/>" << endl;
        *xmlcontent << "              <inject bean=\"Ports03Bindings\"/>" << endl;
        *xmlcontent << "           </set>" << endl;
        *xmlcontent << "        </parameter>" << endl;
        *xmlcontent << "        <parameter><inject bean=\"StandardBindings\"/></parameter> " << endl;
        *xmlcontent << "     </constructor>" << endl;
        *xmlcontent << "  </bean>" << endl;
        *xmlcontent << "  <bean name=\"PortsDefaultBindings\"  class=\"org.jboss.services.binding.impl.ServiceBindingSet\">" << endl;
        *xmlcontent << "    <constructor>" << endl;
        *xmlcontent << "      <parameter>ports-default</parameter>" << endl;
        *xmlcontent << "      <parameter>${jboss.bind.address}</parameter>" << endl;
        *xmlcontent << "      <parameter>0</parameter>" << endl;
        *xmlcontent << "      <parameter><null/></parameter>" << endl;
        *xmlcontent << "    </constructor>" << endl;
        *xmlcontent << "  </bean>" << endl;
        *xmlcontent << "  <bean name=\"Ports01Bindings\" class=\"org.jboss.services.binding.impl.ServiceBindingSet\">" << endl;
        *xmlcontent << "    <constructor>" << endl;
        *xmlcontent << "      <parameter>ports-01</parameter>" << endl;
        *xmlcontent << "      <parameter>${jboss.bind.address}</parameter>" << endl;

        if (m_badPortOffsetValue)
        {
            *xmlcontent << "      <parameter>xyz</parameter>" << endl;
        }
        else
        {
            *xmlcontent << "      <parameter>100</parameter>" << endl;
        }

        *xmlcontent << "      <parameter><null/></parameter>" << endl;
        *xmlcontent << "    </constructor>" << endl;
        *xmlcontent << "  </bean>" << endl;
        *xmlcontent << "  <bean name=\"StandardBindings\" class=\"java.util.HashSet\">" << endl;
        *xmlcontent << "    <constructor>" << endl;
        *xmlcontent << "      <parameter class=\"java.util.Collection\">" << endl;
        *xmlcontent << "        <set elementClass=\"org.jboss.services.binding.ServiceBindingMetadata\">" << endl;

        if (m_httpBinding)
        {
            *xmlcontent << "          <bean class=\"org.jboss.services.binding.ServiceBindingMetadata\">" << endl;
            *xmlcontent << "            <property name=\"serviceName\">jboss.web:service=WebServer</property>" << endl;

            if (m_httpBindingProperty)
            {
                *xmlcontent << "         <property name=\"bindingName\">HttpConnector</property>" << endl;
            }

            if (m_badHttpPortValue)
            {
                *xmlcontent << "            <property name=\"port\">xyz</property>" << endl;
            }
            else
            {
                *xmlcontent << "            <property name=\"port\">8080</property>" << endl;
            }

            *xmlcontent << "            <property name=\"description\">JBoss Web HTTP connector socket; also drives the values for the HTTPS and AJP sockets</property>" << endl;
            *xmlcontent << "            <property name=\"serviceBindingValueSourceConfig\"><inject bean=\"JBossWebConnectorXSLTConfig\"/></property>" << endl;
            *xmlcontent << "          </bean>" << endl;
        }

        if (m_httpsBinding)
        {
            *xmlcontent << "          <bean class=\"org.jboss.services.binding.ServiceBindingMetadata\">" << endl;
            *xmlcontent << "            <property name=\"serviceName\">jboss.web:service=WebServer</property>" << endl;
            *xmlcontent << "            <property name=\"bindingName\">HttpsConnector</property>" << endl;
            *xmlcontent << "            <property name=\"port\">8443</property>" << endl;
            *xmlcontent << "            <property name=\"description\">JBoss Web HTTPS connector socket</property>" << endl;
            *xmlcontent << "          </bean>" << endl;
        }

        *xmlcontent << "        </set>" << endl;
        *xmlcontent << "      </parameter>" << endl;
        *xmlcontent << "    </constructor>" << endl;
        *xmlcontent << "  </bean>" << endl;

        if (!m_badPortsXml)
        {
            *xmlcontent << "</deployment>" << endl;
        }

        return xmlcontent;    
    }

    virtual SCXHandle<std::istream> OpenXmlServiceFile(wstring filename)
    {
        m_xmlServiceFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noServiceFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyServiceFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<server>" << endl;
        *xmlcontent << "   <classpath codebase=\"${jboss.server.lib.url:lib}\" archives=\"*\"/>" << endl;
        *xmlcontent << "   <mbean code=\"org.jboss.system.pm.AttributePersistenceService\"" << endl;
        *xmlcontent << "      name=\"jboss:service=AttributePersistenceService\"" << endl;
        *xmlcontent << "      xmbean-dd=\"resource:xmdesc/AttributePersistenceService-xmbean.xml\">" << endl;
        *xmlcontent << "   </mbean>" << endl;

        if (m_serviceBinding)
        {
            *xmlcontent << "   <mbean code=\"org.jboss.services.binding.ServiceBindingManager\"" << endl;
            *xmlcontent << "     name=\"jboss.system:service=ServiceBindingManager\">" << endl;
            *xmlcontent << "     <attribute name=\"ServerName\">ports-01</attribute>" << endl;
            *xmlcontent << "      <attribute name=\"StoreURL\">${jboss.home.url}/docs/examples/binding-manager/sample-bindings.xml</attribute>" << endl;
            *xmlcontent << "     <attribute name=\"StoreFactoryClassName\">" << endl;
            *xmlcontent << "       org.jboss.services.binding.XMLServicesStoreFactory" << endl;
            *xmlcontent << "     </attribute>" << endl;
            *xmlcontent << "   </mbean>" << endl;
        }

        *xmlcontent << "   <mbean code=\"org.jnp.server.NamingBeanImpl\"" << endl;
        *xmlcontent << "      name=\"jboss:service=NamingBeanImpl\"" << endl;
        *xmlcontent << "      xmbean-dd=\"resource:xmdesc/NamingBean-xmbean.xml\">" << endl;
        *xmlcontent << "   </mbean>" << endl;
        *xmlcontent << "</server>" << endl;

        return xmlcontent;
    }

    virtual SCXHandle<std::istream> OpenXmlServerFile(wstring filename)
    {
        m_xmlServerFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noServerFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyServerFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<Server>" << endl;
        *xmlcontent << "  <Listener className=\"org.apache.catalina.core.AprLifecycleListener\" SSLEngine=\"on\" />" << endl;
        *xmlcontent << "  <Listener className=\"org.apache.catalina.core.JasperListener\" />" << endl;
        *xmlcontent << "  <Service name=\"jboss.web\">" << endl;
        *xmlcontent << "    <Connector port=\"8080\" address=\"${jboss.bind.address}\"" << endl;
        *xmlcontent << "         maxThreads=\"250\" maxHttpHeaderSize=\"8192\"" << endl;
        *xmlcontent << "         emptySessionPath=\"true\" protocol=\"HTTP/1.1\"" << endl;
        *xmlcontent << "         enableLookups=\"false\" redirectPort=\"8443\" acceptCount=\"100\"" << endl;
        *xmlcontent << "         connectionTimeout=\"20000\" disableUploadTimeout=\"true\" />" << endl;
        *xmlcontent << "    <Connector port=\"8443\" protocol=\"HTTP/1.1\" SSLEnabled=\"true\"" << endl;
        *xmlcontent << "         maxThreads=\"150\" scheme=\"https\" secure=\"true\"" << endl;
        *xmlcontent << "         clientAuth=\"false\" sslProtocol=\"TLS\" />" << endl;
        *xmlcontent << "    <Connector port=\"8009\" address=\"${jboss.bind.address}\" protocol=\"AJP/1.3\"" << endl;
        *xmlcontent << "         emptySessionPath=\"true\" enableLookups=\"false\" redirectPort=\"8443\" />" << endl;
        *xmlcontent << "    <Engine name=\"jboss.web\" defaultHost=\"localhost\">" << endl;
        *xmlcontent << "      <Realm className=\"org.jboss.web.tomcat.security.JBossSecurityMgrRealm\"" << endl;
        *xmlcontent << "            certificatePrincipal=\"org.jboss.security.auth.certs.SubjectDNMapping\"" << endl;
        *xmlcontent << "            allRolesMode=\"authOnly\"/>" << endl;
        *xmlcontent << "      <Host name=\"localhost\"" << endl;
        *xmlcontent << "           autoDeploy=\"false\" deployOnStartup=\"false\" deployXML=\"false\"" << endl;
        *xmlcontent << "           configClass=\"org.jboss.web.tomcat.security.config.JBossContextConfig\">" << endl;
        *xmlcontent << "        <Valve className=\"org.jboss.web.tomcat.service.jca.CachedConnectionValve\"" << endl;
        *xmlcontent << "                cachedConnectionManagerObjectName=\"jboss.jca:service=CachedConnectionManager\"" << endl;
        *xmlcontent << "                transactionManagerObjectName=\"jboss:service=TransactionManager\" />" << endl;
        *xmlcontent << "      </Host>" << endl;
        *xmlcontent << "    </Engine>" << endl;
        *xmlcontent << "  </Service>" << endl;
        *xmlcontent << "</Server>" << endl;

        return xmlcontent;
    }

  virtual SCXHandle<std::istream> OpenXmlBindingFile(wstring filename)
    {
        m_xmlBindingFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noBindingFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyBindingFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<service-bindings>" << endl;
        *xmlcontent << "   <server name=\"ports-default\">" << endl;
        *xmlcontent << "      <service-config name=\"jboss.remoting:type=Connector,name=DefaultEjb3Connector,handler=ejb3\"" << endl;
        *xmlcontent << "         delegateClass=\"org.jboss.services.binding.AttributeMappingDelegate\">" << endl;
        *xmlcontent << "        <delegate-config>" << endl;
        *xmlcontent << "     <attribute name=\"InvokerLocator\">socket://${jboss.bind.address}:3873</attribute>" << endl;
        *xmlcontent << "        </delegate-config>" << endl;
        *xmlcontent << "         <binding port=\"3873\"/>" << endl;
        *xmlcontent << "      </service-config>" << endl;
        *xmlcontent << "      <service-config name=\"jboss.web:service=WebServer\"" << endl;
        *xmlcontent << "         delegateClass=\"org.jboss.services.binding.XSLTFileDelegate\">" << endl;
        *xmlcontent << "         <delegate-config>" << endl;
        *xmlcontent << "         </delegate-config>" << endl;
        *xmlcontent << "         <binding port=\"8080\"/>" << endl;
        *xmlcontent << "      </service-config>" << endl;
        *xmlcontent << "   </server>" << endl;
        *xmlcontent << "   <server name=\"ports-01\">" << endl;
        *xmlcontent << "      <service-config name=\"jboss.remoting:type=Connector,name=DefaultEjb3Connector,handler=ejb3\"" << endl;
        *xmlcontent << "         delegateClass=\"org.jboss.services.binding.AttributeMappingDelegate\">" << endl;
        *xmlcontent << "        <delegate-config>" << endl;
        *xmlcontent << "     <attribute name=\"InvokerLocator\">socket://${jboss.bind.address}:3973</attribute>" << endl;
        *xmlcontent << "        </delegate-config>" << endl;
        *xmlcontent << "         <binding port=\"3973\"/>" << endl;
        *xmlcontent << "      </service-config>" << endl;
        *xmlcontent << "      <service-config name=\"jboss.web:service=WebServer\"" << endl;
        *xmlcontent << "         delegateClass=\"org.jboss.services.binding.XSLTFileDelegate\">" << endl;
        *xmlcontent << "         <delegate-config>" << endl;
        *xmlcontent << "         </delegate-config>" << endl;
        *xmlcontent << "         <binding port=\"8180\"/>" << endl;
        *xmlcontent << "      </service-config>" << endl;
        *xmlcontent << "   </server>" << endl;
        *xmlcontent << "</service-bindings>" << endl;

        return xmlcontent;
    }
    
    // Set the Port Binding configuration string
    void SetPortBindingName(string portBindingName)
    {
        m_portBindingName = portBindingName;
    }

    wstring m_xmlVersionFilename;
    wstring m_xmlPortsFilename;
    wstring m_xmlServiceFilename;
    wstring m_xmlServerFilename;
    wstring m_xmlBindingFilename;
    bool m_httpBindingProperty;
    bool m_includeJbossJar;
    bool m_version5;
    bool m_hasJboss7File;
    bool m_hasBadJboss7File;
    bool m_version7;
    bool m_httpBinding;
    bool m_httpsBinding;
    bool m_noPortsFile;
    bool m_noVersionFile;
    bool m_noServiceFile;
    bool m_noServerFile;
    bool m_noBindingFile;
    bool m_emptyPortsFile;
    bool m_emptyVersionFile;
    bool m_emptyServiceFile;
    bool m_emptyServerFile;
    bool m_emptyBindingFile;
    bool m_badPortsXml;
    bool m_badVersionXml;
    bool m_badHttpPortValue;
    bool m_badPortOffsetValue;
    bool m_serviceBinding;
    bool m_noPortOffsetValue;
    bool m_badPortOffsetValueWithSocket;
  
    string m_portBindingName;
};

class JBossAppServerInstance_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( JBossAppServerInstance_Test );

    CPPUNIT_TEST( testJBoss4WithBinding );
    CPPUNIT_TEST( testJBoss4WithoutBinding );
    CPPUNIT_TEST( testJBoss4NoServiceFile );
    CPPUNIT_TEST( testJBoss4EmptyServiceFile );
    CPPUNIT_TEST( testJBoss4NoServerFile );
    CPPUNIT_TEST( testJBoss4EmptyServerFile );
    CPPUNIT_TEST( testJBoss4NoBindingFile );
    CPPUNIT_TEST( testJBoss4EmptyBindingFile );
    CPPUNIT_TEST( testWithoutHttpBindingProperty );
    CPPUNIT_TEST( testWithHttpBindingProperty );
    CPPUNIT_TEST( testNoVersion );
    CPPUNIT_TEST( testWithNoHttps );
    CPPUNIT_TEST( testWithNoHttp );
    CPPUNIT_TEST( testNoPortsFile );
    CPPUNIT_TEST( testNoVersionFile );
    CPPUNIT_TEST( testEmptyPortsFile );
    CPPUNIT_TEST( testEmptyVersionFile );
    CPPUNIT_TEST( testBadPortsXml );
    CPPUNIT_TEST( testBadVersionXml );
    CPPUNIT_TEST( testBadHttpPortValue );
    CPPUNIT_TEST( testBadPortOffsetValue );
    CPPUNIT_TEST( testPort_XMLSetTo_Junk_CommandLineSetTo_ports01 );
    CPPUNIT_TEST( testPort_XMLSetTo_Port01_CommandLineSetTo_Junk );
    CPPUNIT_TEST( testPort_XMLSetTo_Junk_NoCommandLineBinding );
    CPPUNIT_TEST( testPort_XMLSetTo_Ports01 );
    CPPUNIT_TEST( testJBoss7WithBadVersionFile );
    CPPUNIT_TEST( testJBoss7WithBadHttpProperty );
    CPPUNIT_TEST( testJBoss7WithBadPortOffsetValue );
    CPPUNIT_TEST( testJBoss7WithBadPortOffsetValueSocketBindingValue );
  
    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    // Test with command running a parse on a bad script
    void testJBoss7WithBadVersionFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);
        deps->SetIncludeJbossJar(false);
        deps->SetHttpBinding(false);
        deps->SetHttpsBinding(false);
        deps->SetVersion7(true);
        deps->SetNoVersionFile(true);
        deps->SetHasBadJboss7VersionFile(true);
        deps->SetBadHttpPortValue(true);
        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"id/standalone/configuration/logging.properties", L"", deps) );
 
        asInstance->Update();

        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetId());
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetDiskPath());
        CPPUNIT_ASSERT_EQUAL(L"JBoss", asInstance->GetType());
        CPPUNIT_ASSERT_EQUAL(L"", asInstance->GetVersion());
        CPPUNIT_ASSERT_EQUAL(L"", asInstance->GetMajorVersion());
        // Doesnt know Jboss 7, therefore cannot get standalone
        CPPUNIT_ASSERT_EQUAL(L"", asInstance->GetHttpPort());
        CPPUNIT_ASSERT_EQUAL(L"", asInstance->GetHttpsPort());
        // Will be empty because cannot get version
        CPPUNIT_ASSERT_EQUAL(L"", deps->m_xmlPortsFilename);
    }
    
    // Test with XML containing bad HTTP port attribute
    void testJBoss7WithBadHttpProperty()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);
        deps->SetIncludeJbossJar(false);
        deps->SetHttpBinding(false);
        deps->SetHttpsBinding(false);
        deps->SetVersion7(true);
        deps->SetNoVersionFile(true);
        
        deps->SetBadHttpPortValue(true);
        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"id/standalone/configuration/logging.properties", L"", deps) );
 
        asInstance->Update();
          
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetId());
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetDiskPath());
        CPPUNIT_ASSERT_EQUAL(L"JBoss", asInstance->GetType());
        CPPUNIT_ASSERT_EQUAL(L"7.0.0.Final",asInstance->GetVersion());
        CPPUNIT_ASSERT_EQUAL(L"7",asInstance->GetMajorVersion());
        // Http Ports will contain nonsense and return 0
        CPPUNIT_ASSERT_EQUAL(L"", asInstance->GetHttpPort());
        CPPUNIT_ASSERT_EQUAL(L"8443", asInstance->GetHttpsPort());

        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/standalone.xml", deps->m_xmlPortsFilename);
    }

    // Test with XML containing bad port-offset attribute
    void testJBoss7WithBadPortOffsetValue()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);
        deps->SetIncludeJbossJar(false);
        deps->SetHttpBinding(false);
        deps->SetHttpsBinding(false);
        deps->SetVersion7(true);
        deps->SetNoVersionFile(true);
        
        deps->SetBadPortOffsetValue(true);
          
        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"id/standalone/configuration/logging.properties", L"", deps) );
 
        asInstance->Update();
             
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetId());
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetDiskPath());
        CPPUNIT_ASSERT_EQUAL(L"JBoss", asInstance->GetType());
        CPPUNIT_ASSERT_EQUAL(L"7.0.0.Final",asInstance->GetVersion());
        CPPUNIT_ASSERT_EQUAL(L"7",asInstance->GetMajorVersion());
        // port offset will contain junk and return 0
        CPPUNIT_ASSERT_EQUAL(L"8080", asInstance->GetHttpPort());
        CPPUNIT_ASSERT_EQUAL(L"8443", asInstance->GetHttpsPort());
        
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/standalone.xml", deps->m_xmlPortsFilename);
    }

    // Test with XML containing bad port-offset attribute in binding socket
    void testJBoss7WithBadPortOffsetValueSocketBindingValue()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);
        deps->SetIncludeJbossJar(false);
        deps->SetHttpBinding(false);
        deps->SetHttpsBinding(false);
        deps->SetVersion7(true);
        deps->SetNoVersionFile(true);

        deps->SetBadPortOffsetValueWithSocket(true);
        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"id/standalone/configuration/logging.properties", L"", deps) );
 
        asInstance->Update();
             
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetId());
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/", asInstance->GetDiskPath());
        CPPUNIT_ASSERT_EQUAL(L"JBoss", asInstance->GetType());
        CPPUNIT_ASSERT_EQUAL(L"7.0.0.Final",asInstance->GetVersion());
        CPPUNIT_ASSERT_EQUAL(L"7",asInstance->GetMajorVersion());
        // port offset will contain junk and return 0
        CPPUNIT_ASSERT_EQUAL(L"8080", asInstance->GetHttpPort());
        CPPUNIT_ASSERT_EQUAL(L"8443", asInstance->GetHttpsPort());
        
        CPPUNIT_ASSERT_EQUAL( L"id/standalone/configuration/standalone.xml", deps->m_xmlPortsFilename);
    }

    // Test with XML not containing the HTTPBinding property, but which do contain the HTTP section
    void testJBoss4WithBinding()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"id/docs/examples/binding-manager/sample-bindings.xml");
    }

    // Test with XML not containing the HTTPBinding property, but which do contain the HTTP section
    void testJBoss4WithoutBinding()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        deps->SetVersion5(false);
        deps->SetServiceBinding(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/server/myconfig/deploy/jboss-web.deployer/server.xml");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"");
    }

    // Test with code that throw exception when we try to open the service file
    void testJBoss4NoServiceFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetNoServiceFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a service file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"");
    }

    // Test with code that returns an empty string from the service file
    void testJBoss4EmptyServiceFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetEmptyServiceFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a service file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"");
    }

    // Test with code that throw exception when we try to open the server file
    void testJBoss4NoServerFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetServiceBinding(false);
        deps->SetNoServerFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a server file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/server/myconfig/deploy/jboss-web.deployer/server.xml");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"");
    }

    // Test with code that returns an empty string from the server file
    void testJBoss4EmptyServerFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetServiceBinding(false);
        deps->SetEmptyServerFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a server file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/server/myconfig/deploy/jboss-web.deployer/server.xml");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"");
    }

    // Test with code that throw exception when we try to open the binding file
    void testJBoss4NoBindingFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetNoBindingFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a binding file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"");

        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"id/docs/examples/binding-manager/sample-bindings.xml");
    }

    // Test with code that returns an empty string from the binding file
    void testJBoss4EmptyBindingFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetVersion5(false);
        deps->SetEmptyBindingFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"4.2.1.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"4");
        // Without a binding file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlServiceFilename == L"id/server/myconfig/conf/jboss-service.xml");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"");
        CPPUNIT_ASSERT(deps->m_xmlBindingFilename == L"id/docs/examples/binding-manager/sample-bindings.xml");
    }

    // Test with XML not containing the HTTPBinding property, but which do contain the HTTP section
    void testWithoutHttpBindingProperty()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());
        
        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // We should still find the HTTP port even without the HTTPBinding property
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with XML containing the HTTPBinding property in the HTTP section
    void testWithHttpBindingProperty()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetHttpBindingProperty(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // We should ofcourse find the HTTP port witht the HTTPBinding property
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with XML not containing the HTTPS section 
   void testWithNoHttps()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetHttpsBinding(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        // No HTTPS section means no HTTPS port found
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with XML not containing the HTTP section 
    void testWithNoHttp()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetHttpBinding(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // No HTTP section means no HTTP port found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with XML not containing the section we get the version from 
    void testNoVersion()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetIncludeJbossJar(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        // Without version, we don't know that this is a JBoss 5, and cannot get the ports
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        // Without version, we don't know that this is a JBoss 5, and don't try to open the ports file
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
    }

    // Test with code that throw exception when we try to open the ports file
    void testNoPortsFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetNoPortsFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // Without a ports file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with code that throw exception when we try to open the version file
    void testNoVersionFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetNoVersionFile(true);
        deps->SetHasJboss7File(false);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        // Without version, we don't know that this is a JBoss 5, and cannot get the ports
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        // Without version, we don't know that this is a JBoss 5, and don't try to open the ports file
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
    }

    // Test with code that returns an empty string from the ports file
    void testEmptyPortsFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetEmptyPortsFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // Without the content of the ports file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with code that returns an empty string from the version file
    void testEmptyVersionFile()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetEmptyVersionFile(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        // Without version, we don't know that this is a JBoss 5, and cannot get the ports
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        // Without version, we don't know that this is a JBoss 5, and don't try to open the ports file
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
    }

    // Test with code that returns invalid XML from the ports file
    void testBadPortsXml()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetBadPortsXml(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // Without good content from the ports file, no ports will be found
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with code that returns invalid XML from the version file
    void testBadVersionXml()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetBadVersionXml(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        // Without version, we don't know that this is a JBoss 5, and cannot get the ports
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        // Without version, we don't know that this is a JBoss 5, and don't try to open the ports file
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"");
    }

    // Test with XML that has non-numeric value for the HTTP port
    void testBadHttpPortValue()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetBadHttpPortValue(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // If we cannot convert the HTTP base port to an integer, we cannot calculate the port value
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with XML that has non-numeric value for the port offset
    void testBadPortOffsetValue()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetBadPortOffsetValue(true);

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");
        // If we cannot convert the port offset to an integer, we fall back to assuming offset 0 (ports-default)
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with no commandline binding and the default in the XML set to "ports-01".
    // As the BindingPort in the XML doc is valid the correct port base + offset should be returned
    void testPort_XMLSetTo_Ports01()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetPortBindingName("${jboss.service.binding.set:ports-01}");

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with no commandline binding and the default in the XML set to be invalid.
    // As the BindingPort in the XML doc is invalid the default port base should be returned
    void testPort_XMLSetTo_Junk_NoCommandLineBinding()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetPortBindingName("${jboss.service.binding.set:junk}");

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with an invalid commandline binding and the default in the XML set to ports-01.
    // The command line setting will take precedence over the BindingPort in the XML doc,
    // the command line setting will fail and the default port base should be returned.
    void testPort_XMLSetTo_Port01_CommandLineSetTo_Junk()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetPortBindingName("${jboss.service.binding.set:ports-01}");

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"xxx", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

    // Test with a valid commandline binding and the default in the XML set to junk.
    // The command line setting will take precedence over the BindingPort in the XML doc
    // and the correct port base + offset should be returned
    void testPort_XMLSetTo_Junk_CommandLineSetTo_ports01()
    {
        SCXHandle<JBossAppServerInstanceTestPALDependencies> deps(new JBossAppServerInstanceTestPALDependencies());

        deps->SetPortBindingName("${jboss.service.binding.set:junk}");

        SCXHandle<JBossAppServerInstance> asInstance( new JBossAppServerInstance(L"id/", L"myconfig", L"ports-01", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/server/myconfig/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"JBoss");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"5.1.0.GA");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"5");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8180");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8543");

        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"id/jar-versions.xml");
        CPPUNIT_ASSERT(deps->m_xmlPortsFilename == L"id/server/myconfig/conf/bindingservice.beans/META-INF/bindings-jboss-beans.xml");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( JBossAppServerInstance_Test );

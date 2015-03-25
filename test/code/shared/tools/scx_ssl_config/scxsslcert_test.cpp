/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief      Tests for the ssl cert generation

   \date       2009-12-14 12:00

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <source/code/shared/tools/scx_ssl_config/scxsslcert.h> 
#include <testutils/scxunit.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxstream.h>
#include <scxcorelib/scxprocess.h>
#include <testutils/scxtestutils.h>
#include <scxcorelib/scxnameresolver.h>

#include <iostream>
#include <string>

#if defined(linux)
  static const bool s_fIsLinux = true;
#else
  static const bool s_fIsLinux = false;
#endif


using std::cout;
using std::wcout;
using std::endl;

class ScxSSLCertTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( ScxSSLCertTest );
    CPPUNIT_TEST( testLoadRndNumberWithGoodRandomFromAllFiles );
    CPPUNIT_TEST( testLoadRndNumberWithGoodRandomFromOnlyUserFile );
    CPPUNIT_TEST( testLoadRndNumberWithGoodRandomFromOnlyDevRandom );
    CPPUNIT_TEST( testLoadRndNumberWithGoodRandomFromUserFileAndDevRandom );
    CPPUNIT_TEST( testLoadRndNumberWithNotEnoughGoodRandom );
    CPPUNIT_TEST( testLoadRndNumberWithRandomFromOnlyDevURandom );
    CPPUNIT_TEST( testLoadRndNumberWithNoRandomAtAll );
    CPPUNIT_TEST( testCertGeneration7Bit );
    CPPUNIT_TEST( testCertGeneration8Bit );
    CPPUNIT_TEST( test7BitCertGenerationAndCheckFiles );
    CPPUNIT_TEST( test8BitCertGenerationAndCheckFiles );
    CPPUNIT_TEST( testNonRFCcompliantDomainFailure );
    CPPUNIT_TEST( testNonRFCcompliantHostnameFailure );
    CPPUNIT_TEST( testNonRFCcompliantDomainFallback );
    CPPUNIT_TEST( testNonRFCcompliantDomainNoRecovery );
    CPPUNIT_TEST_SUITE_END();

private:
    class SCXSSLCertificateTest : public SCXSSLCertificate
    {
    public:
        SCXSSLCertificateTest(size_t userrandom, size_t devrandom, size_t udevrandom) : 
            SCXSSLCertificate(L".", L".", 0, 0, L"hostname", L"domainname", 512), 
            m_userrandom(userrandom), m_devrandom(devrandom), m_udevrandom(udevrandom), m_warningdisplayed(false),
            m_readuserfile(false), m_readdevrandom(false), m_readdevurandom(false)
        {}
        size_t m_userrandom;
        size_t m_devrandom;
        size_t m_udevrandom;
        bool m_warningdisplayed;
        bool m_readuserfile;
        bool m_readdevrandom;
        bool m_readdevurandom;

    private:
        virtual size_t LoadRandomFromDevRandom(size_t /*randomNeeded*/)
        {
            m_readdevrandom = true;
            return m_devrandom;
        }
        virtual size_t LoadRandomFromDevUrandom(size_t /*randomNeeded*/)
        {
            m_readdevurandom = true;
            return m_udevrandom;
        }
        virtual size_t LoadRandomFromUserFile()
        {
            m_readuserfile = true;
            return m_userrandom;
        }
        virtual void DisplaySeedWarning(size_t /*goodRandomNeeded*/)
        {
            m_warningdisplayed = true;
        }
    };

    static const size_t m_randomneeded = 256;

public:

    void testLoadRndNumberWithGoodRandomFromAllFiles(void)
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(m_randomneeded, m_randomneeded, m_randomneeded);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did read data from dev/urandom when not neccesary", cert->m_readdevurandom == false);
        CPPUNIT_ASSERT_MESSAGE("Warning message displayed when it should not be", cert->m_warningdisplayed == false); 
        delete cert;
    }

    void testLoadRndNumberWithGoodRandomFromOnlyUserFile(void)
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(m_randomneeded, 0, 0);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did read data from dev/urandom when not neccesary", cert->m_readdevurandom == false);
        CPPUNIT_ASSERT_MESSAGE("Warning message displayed when it should not be", cert->m_warningdisplayed == false);
        delete cert;
    }
    
    void testLoadRndNumberWithGoodRandomFromOnlyDevRandom(void)
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(0, m_randomneeded, 0);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did read data from dev/urandom when not neccesary", cert->m_readdevurandom == false);
        CPPUNIT_ASSERT_MESSAGE("Warning message displayed when it should not be", cert->m_warningdisplayed == false);
        delete cert;
    }

    void testLoadRndNumberWithGoodRandomFromUserFileAndDevRandom()
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(m_randomneeded-64, 64, 0);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did read data from dev/urandom when not neccesary", cert->m_readdevurandom == false);
        CPPUNIT_ASSERT_MESSAGE("Warning message displayed when it should not be", cert->m_warningdisplayed == false);
        delete cert;
    }

    void testLoadRndNumberWithNotEnoughGoodRandom()
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(m_randomneeded-64, 32, m_randomneeded);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/urandom", cert->m_readdevurandom == true);
        CPPUNIT_ASSERT_MESSAGE("Warning message not displayed when it should be", cert->m_warningdisplayed == true);
        delete cert;
    }

    void testLoadRndNumberWithRandomFromOnlyDevURandom(void)
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(0, 0, m_randomneeded);
        CPPUNIT_ASSERT_NO_THROW(cert->LoadRndNumber());
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/urandom", cert->m_readdevurandom == true);
        CPPUNIT_ASSERT_MESSAGE("Warning message not displayed when it should be", cert->m_warningdisplayed == true);
        delete cert;
    }

    void testLoadRndNumberWithNoRandomAtAll(void)
    {
        SCXSSLCertificateTest* cert = new SCXSSLCertificateTest(0, 0, 0);
        CPPUNIT_ASSERT_THROW_MESSAGE("", cert->LoadRndNumber(), SCXCoreLib::SCXResourceExhaustedException);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from user rnd file", cert->m_readuserfile == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/random", cert->m_readdevrandom == true);
        CPPUNIT_ASSERT_MESSAGE("Did not read data from dev/urandom", cert->m_readdevurandom == true);
        CPPUNIT_ASSERT_MESSAGE("Warning message not displayed when it should be", cert->m_warningdisplayed == true);
        delete cert;
    }

public:
    void testCertGeneration7Bit(void)
    {
        // This should work on all platforms
        std::ostringstream debugChatter;
        
        // The class splices file names &c. so we will handle cleanup ourselves

        SCXCoreLib::SCXFilePath keyPath; 
        keyPath.SetDirectory(L"./testfiles"); 
        keyPath.SetFilename(L"scx-test-key.pem"); 

        SCXCoreLib::SCXFilePath certPath; 
        certPath.SetDirectory(L"./testfiles");  
        certPath.SetFilename(L"scx-test-cert.pem"); 

        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, L"hostname", L"domainname.com", 2048);

        std::wstring certKeyPath, certCertPath; 
        try
        {
            cert.Generate(debugChatter);
            
            // Will self delete to clean up 
            SCXCoreLib::SelfDeletingFilePath sdCertPath(cert.m_CertPath.Get());
            SCXCoreLib::SelfDeletingFilePath sdKeyPath(cert.m_KeyPath.Get());

            cout << debugChatter.str();

            CPPUNIT_ASSERT_MESSAGE("Output certificate file not found", SCXCoreLib::SCXFile::Exists(cert.m_CertPath));
            CPPUNIT_ASSERT_MESSAGE("Output key file not found", SCXCoreLib::SCXFile::Exists(cert.m_KeyPath));
        }
        catch(SCXSSLException &e)
        {
            std::string msg("Exception: " + debugChatter.str() + SCXCoreLib::StrToMultibyte(e.Where()) + std::string("\n") + SCXCoreLib::StrToMultibyte(e.What()));
            CPPUNIT_ASSERT_MESSAGE(msg, false);
        }
    }

    void testCertGeneration8Bit(void)
    {
        bool bConverted = false;
        std::ostringstream debugChatter;
 
        SCXCoreLib::SCXFilePath keyPath; 
        keyPath.SetDirectory(L"./testfiles"); 
        keyPath.SetFilename(L"scx-test-key.pem"); 

        SCXCoreLib::SCXFilePath certPath; 
        certPath.SetDirectory(L"./testfiles");  
        certPath.SetFilename(L"scx-test-cert.pem"); 
            
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, L"hostname", L"ümĺäüts.ïß.us", 2048);

        try
        {
            // Will self delete to clean up 
            SCXCoreLib::SelfDeletingFilePath sdCertPath(cert.m_CertPath.Get());
            SCXCoreLib::SelfDeletingFilePath sdKeyPath(cert.m_KeyPath.Get());
            cert.Generate(debugChatter);

            CPPUNIT_ASSERT_MESSAGE("Output certificate file not found", SCXCoreLib::SCXFile::Exists(cert.m_CertPath));
            CPPUNIT_ASSERT_MESSAGE("Output key file not found", SCXCoreLib::SCXFile::Exists(cert.m_KeyPath));

            cout << debugChatter.str();
            bConverted = true;
        }
        catch(SCXSSLException &e)
        {
            // All Linux platforms should have the IDN libraries installed
            if (s_fIsLinux)
            {
                std::string msg("Exception: " + debugChatter.str() + SCXCoreLib::StrToMultibyte(e.Where()) + std::string("\n") + SCXCoreLib::StrToMultibyte(e.What()));
                CPPUNIT_ASSERT_MESSAGE(msg, false);
            }

            // A unix platform can drop through here, we expect an exception .. 
        }

        // If the UNIX system doesn't have the libidn libraries, we shouldn't have worked ... verify that
        if( bConverted )
        {
            void * hLib = SCXSSLCertificateLocalizedDomain::GetLibIDN();
            SCXSSLCertificateLocalizedDomain::AutoClose aclib(hLib);

            CPPUNIT_ASSERT_MESSAGE("Expected a failure to convert on this platform, but it succeeded (" + debugChatter.str() + ")", hLib != NULL);
        }
    }


    bool CheckCertificate(std::wstring filePath, std::string domainname, std::string hostname)
    {
        std::istringstream in;
        std::ostringstream out, err;
        
        if (SCXCoreLib::SCXProcess::Run(std::wstring(L"openssl x509 -noout -subject -issuer -in " + filePath), in, out, err))
        {
            std::string msg("Not able to run openssl, error message is: " + err.str()); 
            CPPUNIT_ASSERT_MESSAGE(msg, false);
        }

        std::string strSubject("subject= /DC=com/DC=" + domainname + std::string("/CN=") + hostname + std::string("/CN=") + hostname + "." +  domainname + ".com");
        if(out.str().find(strSubject) == std::string::npos)
            return false; 

        std::string strIssuer("issuer= /DC=com/DC=" + domainname + std::string("/CN=") + hostname + std::string("/CN=") + hostname + "." +  domainname + ".com");
        if(out.str().find(strIssuer) == std::string::npos)
            return false; 
  
        return true;
    }
    
    void test7BitCertGenerationAndCheckFiles(void)
    {
        std::ostringstream debugChatter;
 
        SCXCoreLib::SCXFilePath keyPath; 
        keyPath.SetDirectory(L"./testfiles"); 
        keyPath.SetFilename(L"scx-test-key.pem"); 

        SCXCoreLib::SCXFilePath certPath; 
        certPath.SetDirectory(L"./testfiles");  
        certPath.SetFilename(L"scx-test-cert.pem"); 

        std::string hostname("myhostname");
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, SCXCoreLib::StrFromUTF8(hostname), L"vanilladomain.com", 2048);
            
        try
        {
            cert.Generate(debugChatter);

            // Will self delete to clean up 
            SCXCoreLib::SelfDeletingFilePath sdCertPath(cert.m_CertPath.Get());
            SCXCoreLib::SelfDeletingFilePath sdKeyPath(cert.m_KeyPath.Get());

            //xn--bcher-kva.com is what bücher.com should be in punycode
            CPPUNIT_ASSERT_MESSAGE("Punycode function produced incorrect output", 0 == cert.m_domainname.compare(L"vanilladomain.com"));
            CPPUNIT_ASSERT_MESSAGE("Output certificate file not found", SCXCoreLib::SCXFile::Exists(cert.m_CertPath));
            CPPUNIT_ASSERT_MESSAGE("Certificate mismatch or corruption", CheckCertificate(cert.m_CertPath.Get(), std::string("vanilladomain"), hostname)); 
            CPPUNIT_ASSERT_MESSAGE("Output key file not found", SCXCoreLib::SCXFile::Exists(cert.m_KeyPath));
            
            cout << debugChatter.str();
        }
        catch(SCXSSLException &e)
        {
            // Should succeed everywhere
            std::string msg("Exception: " + debugChatter.str() + SCXCoreLib::StrToMultibyte(e.Where()) + std::string("\n") + SCXCoreLib::StrToMultibyte(e.What()));
            CPPUNIT_ASSERT_MESSAGE(msg, false);
        }
    }

    void test8BitCertGenerationAndCheckFiles(void)
    {
        bool bConverted = false;
        std::ostringstream debugChatter;
 
        SCXCoreLib::SCXFilePath keyPath;
        keyPath.SetDirectory(L"./testfiles");
        keyPath.SetFilename(L"scx-test-key.pem");

        SCXCoreLib::SCXFilePath certPath;
        certPath.SetDirectory(L"./testfiles");
        certPath.SetFilename(L"scx-test-cert.pem");

        std::string hostname("myhostname");
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, SCXCoreLib::StrFromUTF8(hostname), L"bücher.com", 2048);

        try
        {
            cert.Generate(debugChatter);

            // Will self delete to clean up
            SCXCoreLib::SelfDeletingFilePath sdCertPath(cert.m_CertPath.Get());
            SCXCoreLib::SelfDeletingFilePath sdKeyPath(cert.m_KeyPath.Get());

            //xn--bcher-kva.com is what bücher.com should be in punycode
            CPPUNIT_ASSERT_MESSAGE("Punycode function produced incorrect output", 0 == cert.m_domainname.compare(L"xn--bcher-kva.com"));
            CPPUNIT_ASSERT_MESSAGE("Output certificate file not found", SCXCoreLib::SCXFile::Exists(cert.m_CertPath));
            CPPUNIT_ASSERT_MESSAGE("Certificate mismatch or corruption", CheckCertificate(cert.m_CertPath.Get(), std::string("xn--bcher-kva"), hostname));
            CPPUNIT_ASSERT_MESSAGE("Output key file not found", SCXCoreLib::SCXFile::Exists(cert.m_KeyPath));

            cout << debugChatter.str();
            bConverted = true;
        }
        catch(SCXSSLException &e)
        {
            // All Linux platforms should have the IDN libraries installed
            if (s_fIsLinux)
            {
                std::string msg("Exception: " + debugChatter.str() + SCXCoreLib::StrToMultibyte(e.Where()) + std::string("\n") + SCXCoreLib::StrToMultibyte(e.What()));
                CPPUNIT_ASSERT_MESSAGE(msg, false);
            }

            // A unix platform can drop through here, we expect an exception .. 
        }

        // If the UNIX system doesn't have the libidn libraries, we shouldn't have worked ... verify that
        if( bConverted )
        {
            void * hLib = SCXSSLCertificateLocalizedDomain::GetLibIDN();
            SCXSSLCertificateLocalizedDomain::AutoClose aclib(hLib);

            CPPUNIT_ASSERT_MESSAGE("Expected a failure to convert on this platform, but it succeeded (" + debugChatter.str() + ")", hLib != NULL);
        }
    }

    void testNonRFCcompliantDomainFailure()
    {
        std::ostringstream debugChatter;
 
        SCXCoreLib::SelfDeletingFilePath keyPath(L"./testfiles/scx-test-key.pem");
        SCXCoreLib::SelfDeletingFilePath certPath(L"./testfiles/scx-test-cert.pem");

        // This is an actual example we received.
        std::wstring hostname(L"Instance0-406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev");
        std::wstring domainname(L"406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev.d4.internal.cloudapp.net");
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, hostname, domainname, 2048);

        try
        {
            cert.Generate(debugChatter);
        }
        catch(SCXSSLException &e)
        {
            CPPUNIT_ASSERT_MESSAGE("Adding a non RFC compliant domain name did not produce the expected exception. Exception=" + SCXCoreLib::StrToMultibyte(e.What()),
                e.What().find(L"Unable to add the domain name to the subject.") != std::string::npos);
            return;
        }
        CPPUNIT_ASSERT_MESSAGE("Adding a non RFC compliant domain name did not produce an exception.", false);
    }

    void testNonRFCcompliantHostnameFailure()
    {
        std::ostringstream debugChatter;
 
        SCXCoreLib::SelfDeletingFilePath keyPath(L"./testfiles/scx-test-key.pem");
        SCXCoreLib::SelfDeletingFilePath certPath(L"./testfiles/scx-test-cert.pem");

        // This is an actual example we received.
        std::wstring hostname(L"Instance0-406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev-longer-than-64-bytes");
        std::wstring domainname(L"internal.cloudapp.net");
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, -365, 7300, hostname, domainname, 2048);

        try
        {
            cert.Generate(debugChatter);
        }
        catch(SCXSSLException &e)
        {
            CPPUNIT_ASSERT_MESSAGE("Adding a non RFC compliant domain name did not produce the expected exception. Exception=" + SCXCoreLib::StrToMultibyte(e.What()),
                e.What().find(L"Unable to add hostname to the subject.") != std::string::npos);
            return;
        }
        CPPUNIT_ASSERT_MESSAGE("Adding a non RFC compliant hostname did not produce an exception.", false);
    }

    void testNonRFCcompliantDomainFallback()
    {
        std::istringstream in;
        std::ostringstream out, err;
        
        std::wstring hostname(L"hostname");
        std::wstring domainname(L"406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev.d4.internal.cloudapp.net");

        SCXCoreLib::SelfDeletingFilePath sdCertPath(L"./testfiles/omi-host-localhost.pem");
        SCXCoreLib::SelfDeletingFilePath sdLinkPath(L"./testfiles/omi.pem");
        SCXCoreLib::SelfDeletingFilePath sdKeyPath(L"./testfiles/omikey.pem");
        
        std::wstring scxsslconfigPath(L"./scxsslconfig");
        if (SCXCoreLib::SCXFile::Exists(L"./openssl_1.0.0/scxsslconfig"))
        {
            scxsslconfigPath = L"./openssl_1.0.0/scxsslconfig";
        }

        // Because we pass the undocummented -t flag, scxsslconfig will try the fallback even though hostname and domain are specified.
        int ret = SCXCoreLib::SCXProcess::Run(scxsslconfigPath + L" -f -v -t -g testfiles/ -h " + hostname + L" -d " + domainname, in, out, err);

        std::ostringstream errorCodeMsg;
        errorCodeMsg << "Error running: " << SCXCoreLib::StrToUTF8(scxsslconfigPath) << ", error message is: " << err.str() 
            << ", error code is: " << ret;
        CPPUNIT_ASSERT_MESSAGE(errorCodeMsg.str(), ret == 0);

        CPPUNIT_ASSERT_MESSAGE("Fallback message was not detected in output:\n" + out.str(), out.str().find("trying fallback: \"localhost.local\"") != std::string::npos);
        CPPUNIT_ASSERT_MESSAGE("Output certificate file not found", SCXCoreLib::SCXFile::Exists(sdCertPath.Get()));
        CPPUNIT_ASSERT_MESSAGE("Output key file not found", SCXCoreLib::SCXFile::Exists(sdKeyPath.Get()));

        out.str("");
        err.str("");

        if (SCXCoreLib::SCXProcess::Run(L"openssl x509 -noout -subject -issuer -in " + sdCertPath.Get(), in, out, err))
        {
            std::string msg("Error running openssl, error message is: " + err.str()); 
            CPPUNIT_ASSERT_MESSAGE(msg, false);
        }

        CPPUNIT_ASSERT_MESSAGE("Cert subject not as expected. Received: " + out.str(), out.str().find("subject= /DC=local/CN=localhost/CN=localhost.local") != std::string::npos);
        CPPUNIT_ASSERT_MESSAGE("Cert issuer not as expected. Received: " + out.str(), out.str().find("issuer= /DC=local/CN=localhost/CN=localhost.local") != std::string::npos);
    }

    void testNonRFCcompliantDomainNoRecovery()
    {
        std::istringstream in;
        std::ostringstream out, err;
        
        std::wstring hostname(L"Instance0-406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev");
        std::wstring domainname(L"406484d6-6dba-46cb-b21f-93be8e2588b2-serresdev.d4.internal.cloudapp.net");

        SCXCoreLib::SelfDeletingFilePath sdCertPath(L"./testfiles/omi-host-" + hostname + L".pem");
        SCXCoreLib::SelfDeletingFilePath sdLinkPath(L"./testfiles/omi.pem");
        SCXCoreLib::SelfDeletingFilePath sdKeyPath(L"./testfiles/omikey.pem");
        
        std::wstring scxsslconfigPath(L"./scxsslconfig");
        if (SCXCoreLib::SCXFile::Exists(L"./openssl_1.0.0/scxsslconfig"))
        {
            scxsslconfigPath = L"./openssl_1.0.0/scxsslconfig";
        }

        // When we pass a non RFC compliant hostname or domain, scxsslconfig will not try to recover and should fail.
        int ret = SCXCoreLib::SCXProcess::Run(scxsslconfigPath + L" -f -v -g testfiles/ -h " + hostname + L" -d " + domainname, in, out, err);

        CPPUNIT_ASSERT_EQUAL_MESSAGE("scxsslconfig did not fail with a non RFC compliant domain name", 3, ret);
        CPPUNIT_ASSERT_MESSAGE("Adding a non RFC compliant domain name did not produce the expected error message: \"" + err.str() +"\"",
                err.str().find("Unable to add the domain name to the subject.") != std::string::npos);

        CPPUNIT_ASSERT_MESSAGE("Certificate found but it should not have been generated", SCXCoreLib::SCXFile::Exists(sdCertPath.Get()) == false);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( ScxSSLCertTest );

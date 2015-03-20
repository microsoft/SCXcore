/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      Generates SSL certificates for the SCX Installer.

   \date       1-17-2008

   Implementation of class SCXSSLCertificate.

*/

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxglob.h>

#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/objects.h>
#include <openssl/pem.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/engine.h>
#include <openssl/conf.h>

#include "scxsslcert.h"
#include "resourcehelper.h"

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fcntl.h>
#include <unistd.h>

#include <dlfcn.h>
#include <assert.h>
#include <locale.h>
#include <sys/utsname.h>
using std::wcout;
using std::wcerr;
using std::endl;
using std::ends;
using std::string;
using std::wstring;

using SCXCoreLib::SCXFile;
using SCXCoreLib::SCXNULLPointerException;
using SCXCoreLib::StrFromMultibyte;
using SCXCoreLib::StrToMultibyte;

// Define constant strings for the IDN library name based on platform:
//      For UNIX: libidn.so
//      For Linux: libcidn.so
// Take care that Universal Linux is counted as Linux

#if defined(aix) || defined(hpux) || defined(sun)
const char *s_idnLibraryName = "libidn.so";
#else
const char *s_idnLibraryName = "libcidn.so";
#endif


/******************************************************************************
 *  
 *  SCXSSLException Implementation 
 *  
 ******************************************************************************/

/*----------------------------------------------------------------------------*/
/* (overload)
   Format which pointer was NULL
   
*/
wstring SCXSSLException::What() const 
{ 
    return L"Error generating SSL certificate.  Use scxsslconfig to "
        L"generate a new certificate, specifying host and domain names if "
        L"necessary.  The error was: '" + m_Reason + L"'";
 }

/******************************************************************************
 *  
 *  SCXSSLCertificate Implementation 
 *  
 ******************************************************************************/

//------------------------------------------------------------------------------
// Public Methods
//------------------------------------------------------------------------------

/*----------------------------------------------------------------------------*/
/**
   Constructor - Instantiate a SCXSSLCertificate object.

   \param[in] keyPath  Full path to the key file.
   \param[in] certPath Full path to the certificate file.
   \param[in] startDays Days to offset valid start time with.
   \param[in] endDays Days to offset valid end time with.
   \param[in] hostname Hostname to use in the certificates.
   \param[in] domainname Domainname to use in the certificates.
   \param[in] bits Number of bits in key.

   \date   1-17-2008
*/
SCXSSLCertificate::SCXSSLCertificate(SCXCoreLib::SCXFilePath keyPath, SCXCoreLib::SCXFilePath certPath,
                                     int startDays, int endDays, const wstring & hostname,
                                     const wstring & domainname, int bits)
    : m_startDays(startDays),
      m_endDays(endDays),
      m_bits(bits),
      m_KeyPath(keyPath),
      m_CertPath(certPath),
      m_hostname(hostname),
      m_domainname(domainname)
{
}

/*----------------------------------------------------------------------------*/
/**
   Destructor

   \throws SCXSSLException
*/
SCXSSLCertificate::~SCXSSLCertificate()
{
}

/*----------------------------------------------------------------------------*/
/**
   Tries to seed random from a file. Will never block.

   \param file Path to file with radnom bytes.
   \param num Number of bytes to read from file. Zero means complete file.
   \returns Number of bytes actually read from random file.

   If the num parameter is zero the file is read until it blocks.
*/

size_t SCXSSLCertificate::LoadRandomFromFile(const char* file, size_t num)
{
    size_t remain = num;
    size_t result = 0;
    int fd = open(file, O_RDONLY);
    if (-1 == fd)
        goto cleanup;
    if (-1 == fcntl(fd, F_SETFL, O_NONBLOCK))
        goto cleanup;

    char buffer[1024];
    while (remain > 0 || 0 == num) {
        size_t r = read(fd, buffer, (remain>sizeof(buffer) || 0 == num)?sizeof(buffer):remain);
        if (static_cast<size_t>(-1) == r)
            goto cleanup;
        if (0 == r)
            break;
        result += r;
        RAND_seed(buffer, static_cast<int>(r));
        remain -= r;
    }

 cleanup:
    if (-1 != fd)
        close(fd);
    return result;
}
    

/*----------------------------------------------------------------------------*/
/**
   Load the random number seed from a file.

   \throws SCXResourceExhaustedException

*/
void SCXSSLCertificate::LoadRndNumber()
{
    size_t nLoadedBytes = 0;
    const size_t randomNeeded = 1024;
    const size_t goodRandomNeeded = 256;

    nLoadedBytes = LoadRandomFromUserFile();

    // Even if we got a lot of good data from the user rnd file we add extra entropy 
    // from /dev/random if we can to get an even better seed.
    // In the best case scenario this means we have 2048 bytes of random to seed with
    nLoadedBytes += LoadRandomFromDevRandom(randomNeeded);

    // we want to get at least 256 bytes good random data in total from either file or
    // 'random' (ideally both)
    // based on open-ssl man page, "file" is a "good" source of random data
    // in case if file is missing, we take it from "random" device,
    // which is blocking (on some platforms) if there is not enough entropy
    // in that case we log a warning to the user and try to read the rest from urandom device
    // that is not a "good" source. 
    if ( nLoadedBytes < goodRandomNeeded )
    {
        DisplaySeedWarning(goodRandomNeeded);
        nLoadedBytes += LoadRandomFromDevUrandom(randomNeeded);
        // Should not fail, but making sure
        if ( nLoadedBytes < goodRandomNeeded )
        {
            throw SCXCoreLib::SCXResourceExhaustedException(L"random data", L"Failed to get random data - not enough entropy", SCXSRCLOCATION);
        }
    }
}

/*----------------------------------------------------------------------------*/
/**
   Save the random number seed to a file.

   \throws SCXSSLException

*/
void SCXSSLCertificate::SaveRndNumber()
{
    char buffer[200];
    const char* file = RAND_file_name(buffer, sizeof buffer);
    if (!RAND_write_file(file))
    {
        ; //TODO: Only log that no random file was found. DO NOT FAIL!
    }
}


/*----------------------------------------------------------------------------*/
/**
   Generate the certificates.
  
   \throws SCXCoreLib::SCXInvalidArgumentException

   \date   1-17-2008

   \note The certificates are generated using the hostname and domain name, which
   is collected automatically.

*/
void SCXSSLCertificate::Generate()
{
        if (0 == m_KeyPath.Get().size())
        {
            throw SCXCoreLib::SCXInvalidArgumentException(L"keyPath",
                 L"Key path is not set.", SCXSRCLOCATION);
        }
        if (0 == m_CertPath.Get().size())
        {
            throw SCXCoreLib::SCXInvalidArgumentException(L"certPath",
                 L"Certificate path is not set.", SCXSRCLOCATION);
        }
        SCXCoreLib::SCXFileInfo keyInfo(m_KeyPath.GetDirectory());
        SCXCoreLib::SCXFileInfo certInfo(m_CertPath.GetDirectory());
        if( ! keyInfo.PathExists())
        {
            throw SCXCoreLib::SCXInvalidArgumentException(L"keyPath", L"Path does not exist.", SCXSRCLOCATION);
        }
        if( ! certInfo.PathExists())
        {
            throw SCXCoreLib::SCXInvalidArgumentException(L"certPath", L"Path does not exist.", SCXSRCLOCATION);
        }

        LoadRndNumber();
        DoGenerate();
        SaveRndNumber();
}

//------------------------------------------------------------------------------
// Private Methods
//------------------------------------------------------------------------------

// Resource helper classes.

/** Helper class to construct an ASN1_INTEGER */
struct LoadASN1 {
    X509V3_EXT_METHOD * m_Method;               ///< method function pointer.
    const char *        m_SerialNumber;         ///< serial number

    /** CTOR
        \param m Method function pointer.
        \param s Serial number.
    */
    LoadASN1( X509V3_EXT_METHOD * m, const char * s) : m_Method(m), m_SerialNumber(s) 
    {
    }

    /**
       Create an ASN1_INTEGER struct.
       \returns A pointer to a newly created ASN1_INTEGER struct encoding the serial
       number with the given method.
    */
    ASN1_INTEGER * operator()()
    {
        return s2i_ASN1_INTEGER(m_Method, const_cast<char*>(m_SerialNumber));
    }
};

// Resource helper functions.

/**
   Function to make a macro behave like a static function.

   OpenSSL_add_all_algorithms() is a macro so it could not be passed as a function pointer.
*/
static void SSL_OpenSSL_add_all_algorithms()
{
    // Call to a macro
    OpenSSL_add_all_algorithms();
}

/*----------------------------------------------------------------------------*/
/**
   Generate the SSL Certificates.

   \throws SCXSSLException
   \throws SCXCoreLib::SCXNULLPointerException
*/
void SCXSSLCertificate::DoGenerate()
{
    try
    {
        int newKeyLength = m_bits;

        // Arguments from the command line.
        string outfile(StrToMultibyte(m_CertPath));
        string keyout(StrToMultibyte(m_KeyPath));

        ManagedResource res1(ERR_load_crypto_strings,        ERR_free_strings);
        ManagedResource res2(SSL_OpenSSL_add_all_algorithms, EVP_cleanup);
        ManagedResource res3(ENGINE_load_builtin_engines,    ENGINE_cleanup);

        // Serial number is always set to "1". 
        // This is a self-signed certificate. Serial number is unimportant.
        char one[] = "1";
        ManagedValueResource<ASN1_INTEGER> serial(LoadASN1(NULL, one)(), ASN1_INTEGER_free);
        if (0 == serial.Get())
        {
            throw SCXNULLPointerException(L"Error generating serial number", SCXSRCLOCATION);
        }

        ManagedValueResource<BIO> out(BIO_new(BIO_s_file()), BIO_free_all);
        if (0 == out.Get()) 
        {
            throw SCXSSLException(L"Failed to open out file", SCXSRCLOCATION);
        }
    
        // Allocate an empty private key structure.
        ManagedValueResource<EVP_PKEY> pkey(EVP_PKEY_new(), EVP_PKEY_free);
        if (pkey.Get() == 0) 
        {
            throw SCXNULLPointerException(L"Unable to allocate empty private key structure.",
                                                      SCXSRCLOCATION);
        }
    
        {
            RSA * rsa = RSA_generate_key(newKeyLength, 0x10001, 0, 0);
            if ( ! rsa )
            {
                throw SCXCoreLib::SCXNULLPointerException(L"Error allocating RSA structure.",
                                                      SCXSRCLOCATION);
            }
            if ( ! EVP_PKEY_assign_RSA(pkey.Get(), rsa))
            {
                // Free rsa if the assign was unsuccessful. (If it was successful, then rsa
                // is owned by pkey.)
                RSA_free(rsa);
                throw SCXSSLException(L"Error generating RSA key pair..", SCXSRCLOCATION);
            }
        }

        if (BIO_write_filename(out.Get(),const_cast<char*>(keyout.c_str())) <= 0)
        {
            int e = errno;
            char * p = strerror(e);
            std::wostringstream ss;
            ss << keyout.c_str() << L": ";
            if (0 != p)
            {
                ss << p;
            }
            else
            {
                ss << L"errno=" << e;
            }
            throw SCXSSLException(ss.str(), SCXSRCLOCATION);
        }

        if ( ! PEM_write_bio_PrivateKey(out.Get(),pkey.Get(),NULL,NULL,0,NULL,NULL))
        {
            throw SCXSSLException(L"Error writing private key file", SCXSRCLOCATION);
        }
    
        // Allocate a new X509_REQ structure
        ManagedValueResource<X509_REQ> req(X509_REQ_new(), X509_REQ_free);
        if (0 == req.Get())
        {
            throw SCXNULLPointerException(L"Unable to allocate memory for an X509_REQ struct.",
                                          SCXSRCLOCATION);
        }
    
        // Set the properties in the req structure from the private key.
        SetX509Properties(req.Get(),pkey.Get());
    
        ManagedValueResource<X509> x509ss(X509_new(), X509_free);
        if (0 == x509ss.Get()) 
        {
            throw SCXNULLPointerException(L"Error allocating X509 structure x509ss.",
                                          SCXSRCLOCATION);
        }

        if (!X509_set_serialNumber(x509ss.Get(), serial.Get()))
        {
            throw SCXSSLException(L"Unable to set certificate serial nubmer.", SCXSRCLOCATION);
        }
   
        // Copy the issuer name from the request.
        if (!X509_set_issuer_name(x509ss.Get(), X509_REQ_get_subject_name(req.Get()))) 
        {
            throw SCXSSLException(L"Unable to set issuer name.", SCXSRCLOCATION);
        }

        // Ensure the time is not before the certificate time.
        if (!X509_gmtime_adj(X509_get_notBefore(x509ss.Get()),(long)60*60*24*m_startDays)) 
        {
            throw SCXSSLException(L"Invalid time range.", SCXSRCLOCATION);
        }

        // Ensure the time is not after the certificate time.
        if (!X509_gmtime_adj(X509_get_notAfter(x509ss.Get()), (long)60*60*24*m_endDays)) 
        {
            throw SCXSSLException(L"Invalid time range", SCXSRCLOCATION);
        }

        // Copy the subject name from the request.
        if (!X509_set_subject_name(x509ss.Get(), X509_REQ_get_subject_name(req.Get()))) 
        {
            throw SCXSSLException(L"Unable to set subject name.", SCXSRCLOCATION);
        }

        {
            // Get the public key from the request, and set it in our cert.
            ManagedValueResource<EVP_PKEY> tmppkey(X509_REQ_get_pubkey(req.Get()), EVP_PKEY_free);
            if (!tmppkey.Get() || !X509_set_pubkey(x509ss.Get(),tmppkey.Get())) 
            {
                throw SCXSSLException(L"Unable to set the public key in the certificate", SCXSRCLOCATION);
            }
        }

        /* Set up V3 context struct */
        
        X509V3_CTX ext_ctx;
        X509V3_set_ctx(&ext_ctx, x509ss.Get(), x509ss.Get(), NULL, NULL, 0);

        // Add serverAuth extension ... this magic OID is defined in RFC 3280, 
        // section 4.2.1.13 "Extended Key Usage", as "1.3.6.1.5.5.7.3.1"
        // We will access it the right way ... 
        // There is no need to free the pointer returned here, no memory is allocated
        ASN1_OBJECT * serverAuthOBJ = OBJ_nid2obj(NID_server_auth); 
        if(serverAuthOBJ == NULL)
        {
            throw SCXSSLException(L"Unable to get serverAuth ASN1_OBJECT pointer", SCXSRCLOCATION); 
        }

        // The oid is of known length, 17 bytes  ... pad it a little ... 
        char serverAuthOIDBuf[24] = {0};

        // The flag 1 denotes that the numeric form of the answer (not long or short name) will be used
        // The return is (apparently) the string length of the converted string (this is undocumented) .. 
        if(OBJ_obj2txt(serverAuthOIDBuf, static_cast<int> (sizeof(serverAuthOIDBuf)/sizeof(*serverAuthOIDBuf)), serverAuthOBJ, 1) <= 0)
        {
            throw SCXSSLException(L"Not able to convert OBJ_server_auth to text", SCXSRCLOCATION);
        }
 
        X509_EXTENSION * ext = X509V3_EXT_conf_nid(NULL, &ext_ctx, (int)NID_ext_key_usage, serverAuthOIDBuf); 
        if(!ext) 
        {
            throw SCXSSLException(L"Unable to get extension pointer for serverAuth extension", SCXSRCLOCATION);  
        }

        int ext_OK = X509_add_ext(x509ss.Get(), ext, -1); 
        X509_EXTENSION_free(ext); 
        if(!ext_OK)
        {
            throw SCXSSLException(L"Unable to add serverAuth extension", SCXSRCLOCATION);  
        }

        // Sign the certificate
        const EVP_MD * digest = EVP_sha1();
        int i = X509_sign(x509ss.Get(),pkey.Get(),digest);
        if (! i)
        {
            throw SCXSSLException(L"Error signing certificate.", SCXSRCLOCATION);
        }

        // Write the new certificate to a file.
        if ( ! BIO_write_filename(out.Get(),const_cast<char*>(outfile.c_str())))
        {
            throw SCXCoreLib::SCXInternalErrorException(L"Unable to open the cert file for writing.", SCXSRCLOCATION);
        }

        if ( ! PEM_write_bio_X509(out.Get(),x509ss.Get()))
        {
            throw SCXCoreLib::SCXInternalErrorException(L"Error writing the cert file.", SCXSRCLOCATION);
        }

        // Cleanup the rest of the resources that may have been allocated internally.
        OBJ_cleanup();
        CONF_modules_unload(1); 
        CRYPTO_cleanup_all_ex_data(); 
        ERR_remove_state(0);
    } 
    catch (SCXCoreLib::SCXException & e)
    {
        // Blunt force resource release functions.
        OBJ_cleanup();
        CONF_modules_free();
        CRYPTO_cleanup_all_ex_data(); 
        ERR_remove_state(0);
        
        throw;
    }
}

/*----------------------------------------------------------------------------*/
/**
   Set the properties in the X509_REQ object.
   
   \param req pointer to openSSL X509 request information object.
   \param pkey pointer to PEM Private Key object.
   \throws SCXSSLException if unsuccessful.

   The X509_REQ object replaces the need for a separate config file.

*/
void SCXSSLCertificate::SetX509Properties(X509_REQ *req, EVP_PKEY *pkey)
{
    // Set the version in the request.
    if ( ! X509_REQ_set_version(req,0L))
    {
        throw SCXSSLException(L"Unable to set the version number in the request.", SCXSRCLOCATION);
    }

    // Get the subject from the request.
    X509_NAME *subj = X509_REQ_get_subject_name(req);

    char dcPart[] = "DC";
    wstring tmp = m_domainname;
    wstring::size_type pos;
    while( ! tmp.empty())
    {
        if(wstring::npos != (pos = tmp.find_last_of(L'.')))
        {
            // Add the domain part to the subject.
            if ( ! X509_NAME_add_entry_by_txt(subj, dcPart, MBSTRING_ASC, 
                reinterpret_cast<unsigned char*>(const_cast<char*>(StrToMultibyte(tmp.substr(pos+1)).c_str())), -1, -1, 0))
            {
                throw SCXSSLException(L"Unable to add the domain to the subject.", SCXSRCLOCATION);
            }
            tmp.erase(pos);
        }
        else
        {
            // Add the domain part to the subject. 
            if ( ! X509_NAME_add_entry_by_txt(subj, dcPart, MBSTRING_ASC, 
                reinterpret_cast<unsigned char*>(const_cast<char*>(StrToMultibyte(tmp).c_str())), -1, -1, 0))
            {
                throw SCXSSLException(L"Unable to add the domain to the subject.", SCXSRCLOCATION);
            }
            tmp.erase();
        }
    }

    char cnPart[] = "CN";
    if ( ! X509_NAME_add_entry_by_txt(subj, cnPart, MBSTRING_ASC, 
        reinterpret_cast<unsigned char*>(const_cast<char*>(StrToMultibyte(m_hostname).c_str())), -1, -1, 0))
    {
        throw SCXSSLException(L"Unable to add hostname to the subject.", SCXSRCLOCATION);
    }
    wstring cn(m_hostname);
    // avoid putting the "." if there is no domain.
    if ( ! m_domainname.empty())
    {
        cn = SCXCoreLib::StrAppend(m_hostname,SCXCoreLib::StrAppend(L".",m_domainname));
    }
    if ( ! X509_NAME_add_entry_by_txt(subj, cnPart, MBSTRING_ASC, 
        reinterpret_cast<unsigned char*>(const_cast<char*>(StrToMultibyte(cn).c_str())), -1, -1, 0))
    {
        throw SCXSSLException(L"Unable to add the domain name to the subject.", SCXSRCLOCATION);
    }
    
    if ( ! X509_REQ_set_pubkey(req,pkey))
    {
        throw SCXSSLException(L"Unable to set the public key in the request.", SCXSRCLOCATION);
    }

}

/*----------------------------------------------------------------------------*/
/**
   Load random data from /dev/random
   
   \param randomNeeded Bytes of random data to read
   \returns Number of bytes read
   
*/
size_t SCXSSLCertificate::LoadRandomFromDevRandom(size_t randomNeeded)
{
    return LoadRandomFromFile("/dev/random", randomNeeded);
}

/*----------------------------------------------------------------------------*/
/**
   Load random data from /dev/urandom
   
   \param randomNeeded Bytes of random data to read
   \returns Number of bytes read
   
*/
size_t SCXSSLCertificate::LoadRandomFromDevUrandom(size_t randomNeeded)
{
    return LoadRandomFromFile("/dev/urandom", randomNeeded);
}

/*----------------------------------------------------------------------------*/
/**
   Load random data from user rnd file
   
   \returns Number of bytes read
   
*/
size_t SCXSSLCertificate::LoadRandomFromUserFile()
{
    char buffer[200];
    const char* file = RAND_file_name(buffer, sizeof buffer);
    if ( file != NULL )
    {
        // We load the entire user rnd file since:
        // 1. The default for OpenSSL is to create this file with 1024 bytes of data
        // 2. We will tell OpenSSL to replace this with new data when we are done
        return LoadRandomFromFile(file, 0);
    }
    return 0;
}

/*----------------------------------------------------------------------------*/
/**
   Display warning to the user that not enough good random data could be read
   
   \param goodRandomNeeded Bytes of random data that was needed
   
*/
void SCXSSLCertificate::DisplaySeedWarning(size_t goodRandomNeeded)
{
    wcout << endl << L"WARNING!" << endl;
    wcout << L"Could not read " << goodRandomNeeded << L" bytes of random data from /dev/random. ";
    wcout << L"Will revert to less secure /dev/urandom." << endl;
    wcout << L"See the security guide for how to regenerate certificates at a later time when more random data might be available." << endl << endl;
}



/*----------------------------------------------------------------------------*/
/**
   Constructor - Instantiate a SCXSSLCertificateLocalizedDomain object.

   \param[in] keyPath  Full path to the key file.
   \param[in] certPath Full path to the certificate file.
   \param[in] startDays Days to offset valid start time with.
   \param[in] endDays Days to offset valid end time with.
   \param[in] hostname Hostname to use in the certificates.
   \param[in] domainname Domainname to use in the certificates.
   \param[in] bits Number of bits in key.
   
   Note that it passes an empty string for the domain to the parent. It is expected that 
the user will call Generate() to create a punycode domain string after this is called. 
*/
SCXSSLCertificateLocalizedDomain::SCXSSLCertificateLocalizedDomain(SCXCoreLib::SCXFilePath keyPath, SCXCoreLib::SCXFilePath certPath,
                                     int startDays, int endDays, const wstring & hostname,
                                     const wstring & domainname_raw, int bits)
    :SCXSSLCertificate(keyPath, certPath, startDays, endDays, hostname, wstring(L""), bits), m_domainname_raw(domainname_raw)
{    
}

/*----------------------------------------------------------------------------*/
/**
   CleanupErrorOutput() - post processing of error strings returned by the system, 
   which can contain problematic characters. 

   \param[in] sErr  Returned by dlerror().
   \param[in] verbage Stringstream for error output.

*/
void SCXSSLCertificateLocalizedDomain::CleanupErrorOutput(const char * sErr, std::ostringstream& verbage)
{
    // AIX likes to return strings with an embedded linefeed, which is not convenient to us ....
#if defined(aix)
    if(sErr)
    {
        string strRaw = std::string(sErr);
        // Strip out linefeeds
        for(size_t offset = strRaw.find('\x0a'); offset != string::npos; offset = strRaw.find('\x0a'))
            strRaw.replace(offset, 1, string(" ")); 

        // Collapse all the doubled up spaces too ... 
        for(size_t offset = strRaw.find("  "); offset != string::npos; offset = strRaw.find("  "))
            strRaw.replace(offset, 2, string(" ")); 
                
        verbage << ", reason given: \'" << strRaw  << "\'";
    }
#else
    if(sErr)
        verbage << ", reason given: \'" << sErr  << "\'";
#endif
    verbage << "." << endl;
}

/*----------------------------------------------------------------------------*/
/**
   Generate() - Punycode-converts domain string, and calls base 
   class Generate() to create certificates.

   \param[in] verbage Stream to receive chatter when user chooses verbose output.

*/
void SCXSSLCertificateLocalizedDomain::Generate(std::ostringstream& verbage)
{
    std::wstring domainname_processed; 
    bool bConverted = false;
    const char * sErr = 0;

    // Get library handle if you can, but first clear errors  
    dlerror(); 
    void * hLib = GetLibIDN();

    if(hLib)
    {
        AutoClose aclib(hLib);
        
        // Get function pointer if you can
        IDNFuncPtr pCvt = GetIDNAToASCII(hLib);
 
        if(pCvt)
        {
            verbage << "Using punycode library for certificate generation" << endl;
 
            std::string domainname_raw_skinny = SCXCoreLib::StrToMultibyte(m_domainname_raw, true); 

            // Now we can convert, or try to ... 
            // Get locale, OK if it returns null
            const char * sLoc = setlocale(LC_CTYPE, "");
                    
            char * pout = 0; 
            int nSuccess = pCvt(domainname_raw_skinny.c_str(), &pout, 0); 
                            
            // Restore locale, harmless if sLoc is null
            setlocale(LC_CTYPE, sLoc); 
                
            // Zero means it worked ... a 7 bit string will pass through unchanged
            if(nSuccess == 0)
            {
                verbage << "Conversion succeeded" << endl; 

                domainname_processed = SCXCoreLib::StrFromMultibyte(pout, true);
                bConverted = true;
            }
            else
            {
                verbage << "Found library and function, but not able to convert string, returned value is " << nSuccess << endl;
                if(nSuccess == 1)
                    verbage << "Return code of 1 indicates a problem with locale. Consider using the LC_CTYPE environment variable to adjust locale settings." << endl; 
            }
        }
        else
        {
            sErr = dlerror();
            verbage << "Not using punycode because library does not have conversion function" << endl;
            CleanupErrorOutput(sErr, verbage);
        }
        // Library closes automagically through AutoClose
    }
    else
    {
        sErr = dlerror();
        verbage << "Not using punycode because library not found";
        CleanupErrorOutput(sErr, verbage); 
    }

    if(!bConverted)
    {
        // This in theory can produce an SCXCoreLib::SCXStringConversionException, 
        // which will have to be handled in client code. We can do nothing 
        // about converting this string if this fails
        verbage << "Converting string in raw form, \'" << SCXCoreLib::StrToMultibyte(m_domainname_raw, true) << "\'." << endl;
        domainname_processed = m_domainname_raw;
     }
  
    // Store processed domain name, ::Generate() will use it
    // Do not trap exception because we do not expect ever to see it .. if domainname were
    // unconvertible we would know it by now
    m_domainname = domainname_processed;
    verbage << "Domain name, after processing:" << SCXCoreLib::StrToMultibyte(m_domainname, true) << endl;

    try
    {
        SCXSSLCertificate::Generate();
        verbage << "Generated certificate" << endl; 
    }
    catch(SCXCoreLib::SCXStringConversionException)
    {
        verbage << "Caught an exception from base::Generate() " << endl;
    }
}

/*----------------------------------------------------------------------------*/
/**
   Loads and returns handle to libcidn library, if it is installed. 
   
   \return Opaque library handle, or null. 
*/
void * SCXSSLCertificateLocalizedDomain::GetLibIDN(void)
{
    void * pLib = NULL; 

    // Use dlopen() to look in the usual places ... this will
    // work if libcidn.so is a softlink chaining to a binary, 
    // which will be the case if the idn devel library is installed.
    pLib = dlopen(s_idnLibraryName, RTLD_LOCAL|RTLD_LAZY); 
    if(pLib)
        return pLib; 

    // Above did not work, look in directories for libcidn.so.<N>, 
    // taking the largest <N> preferentially.
    const char * sDir = NULL;

#if PF_WIDTH == 64
    sDir = "/lib64/";
#else
    sDir = "/lib/";
#endif

    pLib = GetLibIDNByDirectory(sDir);
    if(pLib)
        return pLib; 

    // Some systems (Ubuntu) put libraries into a directory of the form /lib/x86_64-linux-gnu. 
    // The leading part of the subdirectory is uname-derived, being obviously just the machine 
    // type. Rather than guess how it puts together the rest of the name, we will pass in a wild 
    // card and let glob() figure it out. 
    struct utsname uts; 
    if(uname(&uts) == 0)
    {
        std::stringstream sDirMachine; 
        sDirMachine << "/lib/" << uts.machine << "*/"; 
        pLib = GetLibIDNByDirectory(sDirMachine.str().c_str()); 
        if(pLib)
            return pLib;
    }
    // Fail ... 
    return NULL;
} 


/*----------------------------------------------------------------------------*/
/**
   Searches directory for libcidn.so.* library file, and loads library if it is found.
   Sorts on suffix as integer, preferring (for instance) libcidn.so.2 over libcidn.so.1. 
   This is to ensure getting the latest library. 
   
   \param sDir Name of directory in which to search, e.g. /usr/lib/ . Assumed
   to be non-null and to end with a '/' char. 
   \return Handle to library returned by dlopen().
*/
void * SCXSSLCertificateLocalizedDomain::GetLibIDNByDirectory(const char * sDir)
{
    SCXCoreLib::SCXFilePath file_path; 

    // Note that this is safe only because we know the dirs passed in will have no Unicode chars
    file_path.SetDirectory(SCXCoreLib::StrFromMultibyte(sDir));
    
    // It is tempting to get clever with globbing here but _caveat programmer_ : 
    // glob strings are not regular expressions and it is not trivial to write
    // one that will trap any positive integer of any length and exclude all
    // non-digits. So this is done the old fashioned way, with a trailing '*' and a 
    // validation routine. 
    std::wstring idnName(SCXCoreLib::StrFromUTF8(s_idnLibraryName));
    idnName += L".*";
    file_path.SetFilename(idnName);

    SCXCoreLib::SCXGlob glob(file_path.Get());
    SCXCoreLib::SCXFilePath path; 

    glob.DoGlob();
    glob.Next();

    // Sorts by trailing integer 
    SuffixSortedFileSet file_set; 
        
    do
    {
        path = glob.Current();                

        // Validate for nice file names .. 
        if(IntegerSuffixComparator::IsGoodFileName(path))
            file_set.insert(new SCXCoreLib::SCXFilePath(path));

    } while(glob.Next());

    void * pLib; 
    SuffixSortedFileSet::iterator si; 
    
    // Fetch top file name, should have biggest suffix value
    si = file_set.begin(); 
    if(si == file_set.end())
        pLib = NULL; 
    else
    {
        pLib = dlopen(SCXCoreLib::StrToMultibyte((*si)->Get()).c_str(), RTLD_LOCAL|RTLD_LAZY); 
        // Free alloc'd pointers here ...
        for(si = file_set.begin(); si != file_set.end(); ++si)
            delete (*si); 
    }

    // Clean up struct ...
    file_set.clear();

    return pLib;
}

/*----------------------------------------------------------------------------*/
/**
   Validates file path is of the form /dir/subdir/file.ext.<N>, with <N> being 
   a decimal integer. 
   This function does input validation for the convenience of 
   operator(), which is fussy about input by design. 
   
   \param path Path to file. 
   \return True/false for is/is not in correct form. 
*/
bool IntegerSuffixComparator::IsGoodFileName(const SCXCoreLib::SCXFilePath& path)
{
    std::wstring str_path = path.Get(); 
    
    if(str_path.length() == 0)
        return false; 

    size_t offset; 
    
    offset = str_path.find_last_of('.');

    // No dots, not a nice path
    if(offset == std::wstring::npos)
        return false;

    // Do not want dot at end of name
    if(offset == str_path.length() - 1)
        return false;
       
    // Must be all digits after the last dot
    static const wchar_t * sDigits = L"0123456789"; 
    if(str_path.find_first_not_of(sDigits, offset + 1) != std::wstring::npos)
        return false;

    return true;
}

/*----------------------------------------------------------------------------*/
/**
   Sort on integer file name suffix, e.g. libcidn.so.3 sorts before libcidn.so.2 . 
   
   \param pa, pb are pointers to SCXFilePath's that are pre-groomed and have nice 
   file names with trailing integer suffixes. 
   \return True/false to sort by descending order of suffixes. 
*/
bool IntegerSuffixComparator::operator()(const SCXCoreLib::SCXFilePath * pa, const SCXCoreLib::SCXFilePath * pb) const 
{
    // No checking is done for pa and pb because functor is called by set::insert() and they are known good
    // before insertion.
    // Also note that the file names are assumed to be OK because they passed through 
    // IntegerSuffixComparator::IsGoodFileName() to get here. 
    // Could do input validation here but this functor could be called many times during sorts / inserts
    // so it is more efficient to do it before insertion. 

    std::wstring file_a, file_b; // file names
    file_a = pa->Get(); 
    file_b = pb->Get(); 

    int sfx_a, sfx_b; // file name suffixes in integer form
    size_t offset_a, offset_b; 

    // Validation routine verified that the strings contain a '.' before insertion.
    // We will not be seeing npos here .... no check. 
    offset_a = file_a.find_last_of('.'); 
    offset_b = file_b.find_last_of('.'); 

    // Do not handle exceptions, we won't be getting any ... file and directory names are clean 7-bit strings.
    // We also already know that offsets do not point to last char in string ...  
    sfx_a = atoi(SCXCoreLib::StrToMultibyte(file_a.substr(offset_a + 1)).c_str());
    sfx_b = atoi(SCXCoreLib::StrToMultibyte(file_b.substr(offset_b + 1)).c_str());
    return sfx_a > sfx_b;
}

/*----------------------------------------------------------------------------*/
/**
   Closes handle returned by GetLibIDN().
   
   \param hLib Handle returned by GetLibIDN().
   \return Does not return.
*/
void SCXSSLCertificateLocalizedDomain::CloseLibIDN(void * hLib)
{
    assert(hLib); 
    dlclose(hLib);
}

/*----------------------------------------------------------------------------*/
/**
   Gets pointer to punycode string conversion function from libcidna library. 
   
   \param hLib Handle to libcidn library returned by GetLibIDN().
   \return Pointer to function idna_to_ascii_lz(), or null. 
*/
IDNFuncPtr SCXSSLCertificateLocalizedDomain::GetIDNAToASCII(void * hLib)
{
    void * p = dlsym(hLib, "idna_to_ascii_lz"); 
    if(!p)
        return NULL; 

// compilers on some platforms do not support the __extension__ keyword; 
// others require it. 
#if defined(sun) || defined(hpux)
    return (IDNFuncPtr)p;
#else
    return __extension__(IDNFuncPtr)p;
#endif 
}

/** Autoclose destructor **/
SCXSSLCertificateLocalizedDomain::AutoClose::~AutoClose()
{
    if(m_hLib != 0)
    {
        CloseLibIDN(m_hLib); 
    }
}

/*--------------------------E-N-D---O-F---F-I-L-E----------------------------*/

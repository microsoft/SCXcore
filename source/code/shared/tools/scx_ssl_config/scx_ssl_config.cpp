/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      openSSL configuration tool for SCX install tasks.

   \date       1-30-2008

*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/scxdefaultlogpolicyfactory.h> // Using the default log policy.

#include "scxsslcert.h"

#include <errno.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

using std::wcerr;
using std::cout;
using std::wcout;
using std::endl;
using std::string;
using std::wstring;
using SCXCoreLib::SCXFilePath;

static void usage(const char * name, int exitValue);
static int DoGenerate(const wstring & targetPath, int startDays, int endDays,
                      const wstring & hostname, const wstring & domainname, int bits, bool bDebug = false);
const int ERROR_CERT_GENERATE = 3;


/*----------------------------------------------------------------------------*/
/**
   main function.

   \param argc size of \a argv[]
   \param argv array of string pointers from the command line.
   \returns 0 on success, otherwise, 1 on error.

   Usage: scxgencert [-d domain]  [-h hostname] [-g targetpath] [-e days] [-s days]
   \n -v             toggle the debug flag.
   \n -?             print the help message and exit.
   \n -g targetpath  target path where certificates should be written
   \n -s days        days to offset valid start date with
   \n -e days        days to offset valid end date with
   \n -d domain      domain name
   \n -h host        hostname
   \n -b bits        number of key bits (defaults to 2048)

   Result Code
   \n -1  an exception has occured
   \n  0  success
   \n >1  an error occured while executing the command.

*/
int main(int argc, char *argv[])
{
    // commandline switches
    const string helpFlag       ("-?");
    const string bitsFlag       ("-b");
    const string domainFlag     ("-d");
    const string enddaysFlag    ("-e");
    const string forceFlag      ("-f");
    const string generateFlag   ("-g");
    const string hostFlag       ("-h");
    const string startdaysFlag  ("-s");
    const string debugFlag      ("-v");
    const string testFlag       ("-t"); // Undocummented, for testing only

    // Control variables built from command line arguments (defaulted as needed by SCX)
    bool debugMode = false;
    bool testMode = false;
    bool doGenerateCert = false;
    wstring targetPath = L"/etc/opt/microsoft/omi/ssl";
    int startDays = -365;
    int endDays = 7300;
#if defined(hpux) && defined(hppa)
    int bits = 1024;
#else
    int bits = 2048;
#endif

    SCXCoreLib::NameResolver mi;
    wstring hostname;
    wstring domainname;

    wstring specified_hostname;
    wstring specified_domainname;

    int i = 1;
    for (; i < argc; ++i)
    {
        if (debugFlag == argv[i])
        {
            debugMode = ! debugMode;
            wcout << L"Setting debugMode=" << (debugMode ? L"true" :L"false") << endl;
        }
        else if (helpFlag == argv[i])
        {
            usage(argv[0], 0);
        }
        else if (forceFlag == argv[i])
        {
            doGenerateCert = true;
        }
        else if(bitsFlag == argv[i])
        {
            if (++i >= argc)
            {
                wcout << L"Enter number of bits." << endl;
                usage(argv[0], 1);
            }
            bits = atoi(argv[i]);
            if (0 == bits || 0 != bits%512)
            {
                wcout << L"Bits must be non-zero dividable by 512." << endl;
                usage(argv[0], 1);
            }
        }
        else if(domainFlag == argv[i])
        {
            if (++i >= argc)
            {
                wcout << L"Enter a domain name." << endl;
                usage(argv[0], 1);
            }

            // Some platforms fail to convert if locale is not right (SLES 11 for instance).
            // Note we do not print domain name  because wcout will also fail to
            // properly convert, displaying a mangled string and further confusing
            // the user. Using cout is not an option because it will not print a
            // non-convertible string at all....
            try
            {
                specified_domainname = SCXCoreLib::StrFromMultibyte(argv[i], true);
            }
            catch(const SCXCoreLib::SCXStringConversionException &ex)
            {
                wcout << L"Not able to convert domain name. Consider adjusting your locale setting. Exiting." << endl;
                exit(3);
            }
        }
        else if(hostFlag == argv[i])
        {
            if (++i >= argc)
            {
                wcout << "Enter a hostname." << endl;
                usage(argv[0], 1);
            }

            // Host name is expected to be 7 bit so conversion is in most cases a no-op
            // If it fails prompt user and quit
            try
            {
                specified_hostname = SCXCoreLib::StrFromMultibyte(argv[i], true);
            }
            catch(const SCXCoreLib::SCXStringConversionException &e)
            {
                wcout << L"Not able to convert host name, \'" << argv[i] << "\'." << endl;
                wcout << L"Please specify a host name that uses only 7-bit ASCII characters." << endl;
                exit(4);
            }
        }
        else if (generateFlag == argv[i])
        {
            // Ensure the path argument exists.
            if (++i >= argc)
            {
                wcout << "Enter a target path to generate certificates." << endl;
                usage(argv[0], 1);
            }

            try
            {
                targetPath = SCXCoreLib::StrFromMultibyte(argv[i], true);
            }
            catch(SCXCoreLib::SCXStringConversionException)
            {
                wcout << L"Not able to convert target path, \'" << argv[i] << "\'." << endl;
                wcout << L"Consider adjusting your locale by changing the LC_CTYPE environment variable." << endl;
                exit(4);
            }
        }
        else if (startdaysFlag == argv[i])
        {
            // Ensure the value argument exists.
            if (++i >= argc)
            {
                wcout << "Enter a value for start days." << endl;
                usage(argv[0], 1);
            }
            startDays = atoi(argv[i]);
        }
        else if (enddaysFlag == argv[i])
        {
            // Ensure the value argument exists.
            if (++i >= argc || atoi(argv[i]) == 0)
            {
                wcout << "Enter a non-zero value for end days." << endl;
                usage(argv[0], 1);
            }
            endDays = atoi(argv[i]);
        }
        else if (testFlag == argv[i])
        {
            testMode = true;
        }
        else
        {
            break;
        }
    }

    // Fail if all arguments are not used.
    if (i < argc) {
        wcout << L"Unused arguments:" << endl;
        for (; i < argc; ++i)
        {
            wcout << L"\t" << argv[i] << endl;
        }
        wcout << endl;
        usage(argv[0], 1);
    }

    hostname = specified_hostname;
    domainname = specified_domainname;

    if(hostname.empty())
    {
        std::string hostname_raw = "";
        try
        {
            // This can fail because there are string conversions done in GetHostname()
            hostname = mi.GetHostname(&hostname_raw);
        }
        catch(SCXCoreLib::SCXStringConversionException)
        {
            // Note: We should never see this because host names are s'pose to be 7 bit ASCII
            // Can get away with conversion of stdout here because we are dying, and can do it exactly once ...
            fwide(stdout, -1);
            cout << "Unable to convert default host name \'" << hostname_raw << "\'." << endl;
            cout << "This might be caused by a host name that contains UTF-8 characters that are invalid given your current locale." << endl;
            // MUST exit here, due to fwide() call above ... cannot call fwide() more than once w/out closing/reopening handle
            exit(3);
        }
    }

    // If the user did not supply a domain name, use default.
    if(domainname.empty())
    {
        domainname = mi.GetDomainname();
    }

    if(debugMode)
    {
        // Show what we would have used - even if user specified specific host/domain
        wcout << L"Generated hostname:   \"" << mi.GetHostname()
              << L"\" (" << mi.DumpSourceString(mi.GetHostnameSource()) << L")" << endl;
        wcout << L"Generated domainname: \"" << mi.GetDomainname()
              << L"\" (" << mi.DumpSourceString(mi.GetDomainnameSource()) << L")" << endl << endl;

        wcout << L"Using Host Name:     " << hostname << endl;
        wcout << L"Using Domain Name:   " << domainname << endl;
        wcout << L"Start Days:          " << startDays << endl;
        wcout << L"End Days:            " << endDays << endl;
        wcout << L"Cert Length:         " << bits << endl;
        wcout << L"Target Path:         " << targetPath << endl << endl;
    }

    // We only generate the certificate if "-f" was specified, or if no certificate exists
    // (Note: If no certificate exists, we should still return a success error code!)
    if (!doGenerateCert)
    {
        SCXFilePath keyPath;
        keyPath.SetDirectory(targetPath);
        keyPath.SetFilename(L"omikey.pem");

        SCXCoreLib::SCXFileInfo keyInfo(keyPath);
        if ( ! keyInfo.Exists() )
        {
            doGenerateCert = true;
        }
        else
        {
            wcerr << L"Certificate not generated - '" << keyPath.Get() << "' exists" << endl;
        }
    }

    int rc = 0;
    if (doGenerateCert)
    {
        rc = DoGenerate(targetPath, startDays, endDays, hostname, domainname, bits, debugMode);

        // When the domain or host name is specified through the command line we do not allow recovery.
        // Add an exception to this rule for testing purposes.
        if  ( (specified_domainname.empty() && specified_hostname.empty()) || testMode )
        {
            // When the domain or hostname is not RFC compliant, openssl fails to generate a cerificate.
            // We will try to fallback.
            if ( rc == ERROR_CERT_GENERATE )
            {
                wcout << "Hostname or domain likely not RFC compliant, trying fallback: \"localhost.local\"" << endl;
                rc = DoGenerate(targetPath, startDays, endDays, L"localhost", L"local", bits, debugMode);
            }
        }
    }

    if (debugMode)
    {
        wcout << L"return code = " << rc << endl;
    }
    exit(rc);
}

/*----------------------------------------------------------------------------*/
/**
    Generate Key and Certificate
    \param[in] targetPath Path where the certificates should be written.
    \param[in] startDays Days to offset valid start date.
    \param[in] endDays Days to offset valid end date.
    \param[in] hostname Hostname to put into the certificate.
    \param[in] domainname Domainname to put into the certificate.
    \param[in] bits Number of bits in key.
    \returns Zero on success.
*/
static int DoGenerate(const wstring & targetPath, int startDays, int endDays,
                      const wstring & hostname, const wstring & domainname,
                      int bits, bool bDebug)
{
    // Output what we'll be using for certificate generation
    wcout << L"Generating certificate with hostname=\"" << hostname << L"\"";
    if (domainname.length())
    {
        wcout << L", domainname=\"" << domainname << L"\"" ;
    }
    wcout << endl;

    std::wstring c_certFilename(L"omi-host-");  // Remainder must be generated
    const std::wstring c_keyFilename(L"omikey.pem");

    int rc = 0;
    // Do not allow an exception to slip out
    try
    {
        // The certificate filename must be something like omi-host-<hostname>.pem; generate it
        c_certFilename.append(hostname);
        c_certFilename.append(L".pem");

        SCXFilePath keyPath;
        keyPath.SetDirectory(targetPath);
        keyPath.SetFilename(c_keyFilename);
        SCXFilePath certPath;
        certPath.SetDirectory(targetPath);
        certPath.SetFilename(c_certFilename);
        SCXSSLCertificateLocalizedDomain cert(keyPath, certPath, startDays, endDays, hostname, domainname, bits);

        std::ostringstream debugChatter;
        debugChatter << endl;

        try
        {
            cert.Generate(debugChatter);
        }
        catch(const SCXCoreLib::SCXStringConversionException &ex)
        {
            if(bDebug)
                wcout << debugChatter.str().c_str();

            wcerr  << endl << "Generation of certificate raised an exception" << endl;
            wcerr << ex.Where() << endl;
            wcerr << ex.What() << endl;

            return 2;
        }
        catch(const SCXSSLException &e_ssl)
        {
            if(bDebug)
            {
                wcout << debugChatter.str().c_str();
                debugChatter.str("");
            }

            wcerr << e_ssl.What() << endl;
            return ERROR_CERT_GENERATE;
        }
        catch(const SCXCoreLib::SCXFilePathNotFoundException &ex)
        {
            wcerr  << endl << "Generation of certificate raised an exception" << endl;
            wcerr  << "Output path \"" << ex.GetPath().Get() << "\" does not exist" << endl;
            return 4;
        }

        if(bDebug)
        {
            wcout << debugChatter.str().c_str();
        }

        /*
        ** We actually have three certificate files in total:
        **
        ** Certificate File: omi-host-<hostname>.pem  (public)
        ** Key File:         omi-key.pem              (private)
        ** Soft link:        omi.pem  (soft link to certificate file, used by openwsman)
        **
        **
        ** Create the soft link to point to the certificate file.
        */

        SCXFilePath fpLinkFile;
        fpLinkFile.SetDirectory(targetPath);
        fpLinkFile.SetFilename(L"omi.pem");

        std::string sLinkFile = SCXCoreLib::StrToMultibyte(fpLinkFile.Get());
        std::string sCertFile = SCXCoreLib::StrToMultibyte(certPath.Get());

        rc = unlink(sLinkFile.c_str());
        if (0 != rc && ENOENT != errno) {
            throw SCXCoreLib::SCXErrnoFileException(L"unlink", fpLinkFile.Get(), errno, SCXSRCLOCATION);
        }

        rc = symlink(sCertFile.c_str(), sLinkFile.c_str());
        if (0 != rc) {
            throw SCXCoreLib::SCXErrnoFileException(L"unlink", fpLinkFile.Get(), errno, SCXSRCLOCATION);
        }

        /*
        ** Finally, make sure the permissions are right:
        ** The public key gets 444, the private key gets 400
        */

        rc = chmod(sCertFile.c_str(), 00444);
        if (0 != rc) {
            throw SCXCoreLib::SCXErrnoFileException(L"chmod", certPath.Get(), errno, SCXSRCLOCATION);
        }

        std::string sKeyFile = SCXCoreLib::StrToMultibyte(keyPath.Get());
        rc = chmod(sKeyFile.c_str(), 00400);
        if (0 != rc) {
            throw SCXCoreLib::SCXErrnoFileException(L"chmod", keyPath.Get(), errno, SCXSRCLOCATION);
        }
    }
    catch(const SCXCoreLib::SCXException & e)
    {
        wcout << e.Where() << endl
              << e.What() << endl;
        // use -1 to indicate an exception occured.
        rc = -1;
    }
    return rc;
}

/*----------------------------------------------------------------------------*/
/**
   Output a usage message.

   \param name Application name (derived from argv[0]).
   \param exitValue Value to return after writing the usage message.
   \return Does not return.
*/
static void usage(char const * const name, int exitValue)
{
    wcout << L"Usage: " << name << L" [-v] [-s days] [-e days] [-d domain] [-h host] [-g targetpath]" << endl
          << endl
          << L"-v             - toggle debug flag" << endl
          << L"-g targetpath  - generate certificates in targetpath" << endl
          << L"-s days        - days to offset valid start date with (0)" << endl
          << L"-e days        - days to offset valid end date with (3650)" << endl
          << L"-f             - force certificate to be generated even if one exists" << endl
          << L"-d domain      - domain name" << endl
          << L"-h host        - host name" << endl
          << L"-b bits        - number of key bits" << endl
          << L"-?             - this help message" << endl
    ;
    exit(exitValue);
}

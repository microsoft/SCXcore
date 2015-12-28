/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Test code for SCX Core Provider

   \date        2015-12-23

   Test support code for SCX Core Provider

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <scxsystemlib/scxostypeinfo.h>

#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>

using namespace SCXCoreLib;

namespace SCXCore
{
    /**
       Gets the actual O/S distribution for the current installation

       \returns The actual O/S distribution for current installation

       \notes   Returning the actual O/S type, on Linux, is difficult. The main
       	        issue is that it can vary based on numerous factors (not the
                least of which includes: Is the kit currently installed, and
                what kit was installed prior to this kit installation). These
                issues make reliable tests extraordinarily difficult, partly
                because the code that fetches this is up in the PAL (one level
                up, and thus not mockable very easily).

                Solution: On non-linux platforms, just rely on our trusty call
                to GetDistributionName(), which works very reliably. On Linux,
                however, call the actual code to return the distro name (what
                the provider will do), validate for a list of valid responses,
                and continue along our merry way.
    */

    std::wstring GetActualDistributionName(std::wstring errMsg)
    {
#if !defined(linux)
        return GetDistributionName(errMsg);
#else
        // Add a list of possible responses (add to list if needed)
        std::vector<std::wstring> possibleResponses;
        possibleResponses.push_back(L"Unknown Linux Distribution");
        possibleResponses.push_back(L"Linux Distribution");
        possibleResponses.push_back(L"Red Hat Distribution");
        possibleResponses.push_back(L"SuSE Distribution");

        // Call the actual routine to fetch the system name
        std::wstring actualName;
        try {
            SCXSystemLib::SCXOSTypeInfo osinfo;
            actualName = osinfo.GetOSName(true);
        } catch (SCXException& e) {
            std::wstringstream err;
            err << L"Can't read OS name because of exception: " << e.What() << e.Where();
            //CPPUNIT_ASSERT_MESSAGE(err, false);
        }

        bool matchFound = false;
        for (std::vector<std::wstring>::const_iterator it = possibleResponses.begin(); it != possibleResponses.end(); ++it) {
            if (actualName == *it) {
                matchFound = true;
                break;
            }
        }

        CPPUNIT_ASSERT_MESSAGE("Unknown OSName returned: " + StrToMultibyte(actualName), matchFound);

        return actualName;
#endif // !defined(linux)
    }
}

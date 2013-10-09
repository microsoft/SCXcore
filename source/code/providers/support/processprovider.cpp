/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file     processprovider.cpp

    \brief    implementation of the Process Provider class.
    
    \date     12-03-27 14:15
*/
/*----------------------------------------------------------------------------*/

#include "processprovider.h"
#include <scxsystemlib/processenumeration.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/stringaid.h>

#include <sstream>
#include <algorithm>
#include <vector>

using namespace SCXSystemLib;
using namespace SCXCoreLib;


namespace SCXCore
{

    /*----------------------------------------------------------------------------*/
    /**
        Struct used for sorting on a specific value
    */
    struct ProcessInstanceSort 
    {
        ProcessInstanceSort() : procinst(0), value(0){}

        //! Pointer to instance containing all values
        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> procinst;
        //! Copy of value to sort on
        scxulong value;
    };

    /*----------------------------------------------------------------------------*/
    /**
        Compare two ProcessInstanceSort structs

        \param[in]     p1   First struct to comapare
        \param[in]     p2   Second struct to compare

        \returns       true if value in p1 is greater then in p2
    */
    static bool CompareProcSort(ProcessInstanceSort p1, ProcessInstanceSort p2)
    {
        return p1.value > p2.value;
    }

    void ProcessProvider::Load()
    {
        SCXASSERT( ms_loadCount >= 0 );
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.process_provider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"ProcessProvider::Load()");

            // UnixProcess provider
            SCXASSERT( NULL == m_processes );
            m_processes = new ProcessEnumeration();
            m_processes->Init();
        }
    }

    void ProcessProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"ProcessProvider::Unload()");

        SCXASSERT( ms_loadCount >= 1 );
        if ( 0 == --ms_loadCount )
        {
            if (m_processes != NULL)
            {
                m_processes->CleanUp();
                m_processes = NULL;
            }
        }
    }


    /*----------------------------------------------------------------------------*/
    /**
        Get the value for the spcified resource from a specified instance

        \param[in]     resource      Name of resource to get
        \param[in]     processinst   Instance to get resource from

        \returns       Value for specifed resource

        \throws        SCXInternalErrorException    If given resource not handled
    */
    scxulong ProcessProvider::GetResource(const std::wstring &resource, SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> processinst)
    {

        scxulong res = 0;
        bool gotResource = false;

        if (StrCompare(resource, L"CPUTime", true) == 0)
        {
            unsigned int cputime;
            gotResource = processinst->GetCPUTime(cputime);
            res = static_cast<scxulong>(cputime);
        }
        else if (StrCompare(resource, L"BlockReadsPerSecond", true) == 0)
        {
            gotResource = processinst->GetBlockReadsPerSecond(res);
        }
        else if (StrCompare(resource, L"BlockWritesPerSecond", true) == 0)
        {
            gotResource = processinst->GetBlockWritesPerSecond(res);
        }
        else if (StrCompare(resource, L"BlockTransfersPerSecond", true) == 0)
        {
            gotResource = processinst->GetBlockTransfersPerSecond(res);
        }
        else if (StrCompare(resource, L"PercentUserTime", true) == 0)
        {
            gotResource = processinst->GetPercentUserTime(res);
        }
        else if (StrCompare(resource, L"PercentPrivilegedTime", true) == 0)
        {
            gotResource = processinst->GetPercentPrivilegedTime(res);
        }
        else if (StrCompare(resource, L"UsedMemory", true) == 0)
        {
            gotResource = processinst->GetUsedMemory(res);
        }
        else if (StrCompare(resource, L"PercentUsedMemory", true) == 0)
        {
            gotResource = processinst->GetPercentUsedMemory(res);
        }
        else if (StrCompare(resource, L"PagesReadPerSec", true) == 0)
        {
            gotResource = processinst->GetPagesReadPerSec(res);
        }
        else
        {
            throw UnknownResourceException(resource, SCXSRCLOCATION);
        }

        if ( ! gotResource)
        {
            throw SCXInternalErrorException(StrAppend(L"GetResource: Failed to get resouce: ", resource), SCXSRCLOCATION);
        }

        return res;
    }

    void ProcessProvider::GetTopResourceConsumers(const std::wstring &resource, unsigned int count, std::wstring &result)
    {
        SCX_LOGTRACE(m_log, L"SCXProcessProvider GetTopResourceConsumers");

        std::wstringstream ss;
        std::vector<ProcessInstanceSort> procsort;

        SCXCoreLib::SCXThreadLock lock(m_processes->GetLockHandle());

        m_processes->UpdateNoLock(lock);

        // Build separate vector for sorting
        for(size_t i=0; i<m_processes->Size(); i++)
        {
            ProcessInstanceSort p;

            p.procinst = m_processes->GetInstance(i);
            p.value = GetResource(resource, p.procinst);
            procsort.push_back(p);
        }

        std::sort(procsort.begin(), procsort.end(), CompareProcSort);

        ss << std::endl << L"PID   Name                 " << resource << std::endl;
        ss << L"-------------------------------------------------------------" << std::endl;

        for(size_t i=0; i<procsort.size() && i<count; i++)
        {
            const ProcessInstanceSort* processinst = &procsort[i];

            scxulong pid;

            ss.width(5);
            if (processinst->procinst->GetPID(pid))
            {
                ss << pid;
            }
            else
            {
                ss << L"-----";
            }
            ss << L" ";

            std::string name;
            ss.setf(std::ios_base::left);
            ss.width(20);
            if (processinst->procinst->GetName(name))
            {
                ss << StrFromMultibyte(name);
            }
            else
            {
                ss << L"<unknown>";
            }
            ss.unsetf(std::ios_base::left);
            ss << L" ";

            ss.width(10);
            ss << processinst->value;

            ss << std::endl;
        }

        result = ss.str();
    }

}

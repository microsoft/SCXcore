/**
    \file     processprovider.h

    \brief    Declarations of the Process Provider class.


    \date     12-03-27 14:15

*/
/*----------------------------------------------------------------------------*/
#ifndef PROCESSPROVIDER_H
#define PROCESSPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxsystemlib/processenumeration.h>
#include "startuplog.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    class ProcessProvider
    {
    public:
        /*----------------------------------------------------------------------------*/
        /**
            Exception thrown when an unknown resource is requested.
        */
        class UnknownResourceException : public SCXCoreLib::SCXException
        {
        public: 
            /*----------------------------------------------------------------------------*/
            /**
                Ctor 
                \param[in] resource  Name of the resource requested.
                \param[in] l         Source code location object
            */
            UnknownResourceException(std::wstring resource, 
                                     const SCXCoreLib::SCXCodeLocation& l) : SCXException(l), 
                                                                             m_resource(resource)
            {           
            }

            //! Exception description string.
            //! \returns String representation of the exception.
            std::wstring What() const
            {
                return L"Unknown resource: " + m_resource;
            }

        protected:
            //! Contains the requested resource string.
            std::wstring   m_resource;
        };

        ProcessProvider() : m_processes(NULL) { }
        virtual ~ProcessProvider() { };
        
        void Load();
        void Unload();
        SCXHandle<SCXSystemLib::ProcessEnumeration> GetProcessEnumerator() { return m_processes; }
        SCXLogHandle& GetLogHandle(){ return m_log; }

        void GetTopResourceConsumers(const std::wstring &resource, unsigned int count, std::wstring &result);

    private:
        //! PAL implementation retrieving processes information for local host
        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessEnumeration> m_processes;

        static int ms_loadCount;
        SCXCoreLib::SCXLogHandle m_log; //!< Handle to log file.

        scxulong GetResource(const std::wstring &resource, SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> processinst);
    };

    extern ProcessProvider g_ProcessProvider;

} // End of namespace SCXCore

#endif

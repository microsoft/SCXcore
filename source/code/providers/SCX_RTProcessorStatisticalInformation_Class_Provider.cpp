/* @migen@ */
#include <MI.h>
#include "SCX_RTProcessorStatisticalInformation_Class_Provider.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxconfigfile.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <scxsystemlib/cpuenumeration.h>

#include "support/startuplog.h"
#include "support/scxcimutils.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

// Note that this is copied from the SCX_RTProcessorStatisticalInforamtion class
// code, but it must be separate since the two classes are constructed
// differently. Since this is in a private namespace, this works.
//
// It would be nice to restructure this code to share more common code, but it
// isn't possible to do that in the short timeframe before shipping. It's also
// not clear how to do this from an OMI perspective, unless the implementation
// is totally divorced from the _Class_Provider.cpp code. We'll leave that for
// another day.

namespace
{
    class CPUProvider
    {
    public:
        virtual ~CPUProvider() { };
        void Load()
        {
            if ( 1 == ++ms_loadCount )
            {
                m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.rtcpuprovider");
                SCXCore::LogStartup();
                SCX_LOGTRACE(m_log, L"RTCPUProvider::Load()");

                // See if we have a config file for overriding default RT provider settings
                time_t sampleSecs = 15;
                size_t sampleSize = 2;

                do {
                    SCXConfigFile conf(SCXCore::SCXConfFile);
                    try {
                        conf.LoadConfig();
                    }
                    catch (SCXFilePathNotFoundException &e)
                    {
                        continue;
                    }

                    std::wstring value;
                    if (conf.GetValue(L"RTCPUProv_SampleSecs", value))
                    {
                        sampleSecs = StrToUInt(value);
                    }

                    if (conf.GetValue(L"RTCPUProv_SampleSize", value))
                    {
                        sampleSize = StrToUInt(value);
                    }
                }
                while (true == false);

                // Log what we're starting the real time provider with
                SCX_LOGTRACE(m_log, StrAppend(StrAppend(
                    StrAppend(L"RTCPUProvider parameters: Sample Seconds = ",sampleSecs),
                    L", SampleSize = "), sampleSize));

                m_cpusEnum = new CPUEnumeration(
                    SCXHandle<CPUPALDependencies>(new CPUPALDependencies()),
                    sampleSecs, sampleSize);
                m_cpusEnum->Init();
            }
        }

        void Unload()
        {
            SCX_LOGTRACE(m_log, L"CPUProvider::Unload()");
            if (0 == --ms_loadCount)
            {
                if (m_cpusEnum != NULL)
                {
                    m_cpusEnum->CleanUp();
                    m_cpusEnum == NULL;
                }
            }
        }

        SCXCoreLib::SCXHandle<SCXSystemLib::CPUEnumeration> GetEnumCPUs() const
        {
            return m_cpusEnum;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }

    private:
        //! PAL implementation retrieving CPU information for local host
        SCXCoreLib::SCXHandle<SCXSystemLib::CPUEnumeration> m_cpusEnum;
        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    CPUProvider g_CPUProvider;
    int CPUProvider::ms_loadCount = 0;
}

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_RTProcessorStatisticalInformation_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::CPUInstance> cpuinst)
{
    // Populate the key values
    std::wstring name = cpuinst->GetProcName();
    inst.Name_value(StrToMultibyte(name).c_str());

    if (!keysOnly)
    {
        inst.Caption_value("Processor information");
        inst.Description_value("CPU usage statistics");

        scxulong data;

        inst.IsAggregate_value(cpuinst->IsTotal());

        if (cpuinst->GetProcessorTime(data))
        {
            inst.PercentProcessorTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetIdleTime(data))
        {
            inst.PercentIdleTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetUserTime(data))
        {
            inst.PercentUserTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetNiceTime(data))
        {
            inst.PercentNiceTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetPrivilegedTime(data))
        {
            inst.PercentPrivilegedTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetIowaitTime(data))
        {
            inst.PercentIOWaitTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetInterruptTime(data))
        {
            inst.PercentInterruptTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetDpcTime(data))
        {
            inst.PercentDPCTime_value(static_cast<unsigned char> (data));
        }
    }
    context.Post(inst);
}

SCX_RTProcessorStatisticalInformation_Class_Provider::SCX_RTProcessorStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_RTProcessorStatisticalInformation_Class_Provider::~SCX_RTProcessorStatisticalInformation_Class_Provider()
{
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));
        g_CPUProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(g_CPUProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_RTProcessorStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_RTProcessorStatisticalInformation_Class_Provider::Load", g_CPUProvider.GetLogHandle() );
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));
        g_CPUProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_RTProcessorStatisticalInformation_Class_Provider:::Unload", g_CPUProvider.GetLogHandle() );
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));

        // Prepare ProcessorStatisticalInformation Enumeration
        // (Note: Only do full update if we're not enumerating keys)
        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = g_CPUProvider.GetEnumCPUs();
        cpuEnum->Update(!keysOnly);

        for(size_t i = 0; i < cpuEnum->Size(); i++)
        {
            SCX_RTProcessorStatisticalInformation_Class inst;
            SCXHandle<SCXSystemLib::CPUInstance> cpuInst = cpuEnum->GetInstance(i);
            EnumerateOneInstance(context, inst, keysOnly, cpuInst);
        }

        // Enumerate Total instance
        SCXHandle<SCXSystemLib::CPUInstance> totalInst = cpuEnum->GetTotalInstance();
        if (totalInst != NULL)
        {
            // There will always be one total instance
            SCX_RTProcessorStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, totalInst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_RTProcessorStatisticalInformation_Class_Provider::EnumerateInstances",
                     g_CPUProvider.GetLogHandle() );
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_RTProcessorStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));

        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = g_CPUProvider.GetEnumCPUs();
        cpuEnum->Update(true);

        const std::string name = instanceName.Name_value().Str();

        if (name.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        bool instFound = false;
        SCXHandle<SCXSystemLib::CPUInstance> cpuInst;
        for(size_t i=0; i<cpuEnum->Size(); i++)
        {
            cpuInst = cpuEnum->GetInstance(i);
            // Compare key values of input args and the current instance
            if (cpuInst->GetProcName() == StrFromUTF8(name))
            {
                // Match
                instFound = true;
                break;
            }
        }

        if (instFound == false)
        {
            // As last resort, check if we the request is for the _Total instance
            if (cpuEnum->GetTotalInstance() != NULL)
            {
                cpuInst = cpuEnum->GetTotalInstance();
                if (cpuInst->GetProcName() == StrFromUTF8(name))
                {
                    instFound = true;
                }
            }

            if (instFound == false)
            {
                context.Post(MI_RESULT_NOT_FOUND);
                return;
            }
        }

        SCX_RTProcessorStatisticalInformation_Class inst;
        EnumerateOneInstance(context, inst, false, cpuInst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_RTProcessorStatisticalInformation_Class_Provider::GetInstance",
                    g_CPUProvider.GetLogHandle() );
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_RTProcessorStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_RTProcessorStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_RTProcessorStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_RTProcessorStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE

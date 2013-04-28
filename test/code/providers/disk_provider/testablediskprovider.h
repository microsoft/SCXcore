/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
    \file

    \brief       Provides a way into the disk provider for testing purposes

    \date        2008-09-23 12:54:20

*/
/*----------------------------------------------------------------------------*/
#ifndef TESTABLEDISKPROVIDER_H
#define TESTABLEDISKPROVIDER_H

#include <testutils/providertestutils.h>
#include <source/code/providers/disk_provider/diskprovider.h>

/*----------------------------------------------------------------------------*/
/**
    Class that exposes the protected methods of the disk provider for
    testing purposes.
*/
class TestableDiskProvider : public TestableProvider, public SCXCore::DiskProvider
{
public:
    TestableDiskProvider()
    {
        DoInit();
    }

    virtual ~TestableDiskProvider()
    {
        DoCleanup();
    }

    void TestDoGetInstance(const SCXProviderLib::SCXCallContext& callContext,
                           SCXProviderLib::SCXInstance& instance)
    {
        DoGetInstance(callContext, instance);
    }

    void TestDoEnumInstances(const SCXProviderLib::SCXCallContext& callContext,
                             SCXProviderLib::SCXInstanceCollection &instances)
    {
        DoEnumInstances(callContext, instances);
    }

    void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                  SCXProviderLib::SCXInstanceCollection &names)
    {
        DoEnumInstanceNames(callContext, names);
    }

    void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                 SCXProviderLib::SCXInstanceCollection &names,
                                 bool useParentImpl)
    {
        if (useParentImpl)
        {
            DoEnumInstanceNames(callContext, names);
        }
        else
        {
            SCXCore::DiskProvider::SupportedCimClasses disktype = static_cast<SCXCore::DiskProvider::SupportedCimClasses>(m_ProviderCapabilities.GetCimClassId(callContext.GetObjectPath()));

            SCXCoreLib::SCXHandle<SCXCore::ProviderAlgorithmInterface> disks = GetProviderAlgIfc(disktype);

            disks->GetInstanceKeys(names);
        }
    }

    void TestDoInvokeMethod(const SCXProviderLib::SCXCallContext& callContext,
                            const std::wstring& methodname,
                            const SCXProviderLib::SCXArgs& args,
                            SCXProviderLib::SCXArgs& outargs,
                            SCXProviderLib::SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }
};

#endif /* TESTABLEDISKPROVIDER_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

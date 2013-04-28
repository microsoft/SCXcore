/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
    \file

    \brief       Provides a way into the process provider for testing purposes

    \date        2008-09-23 08:59:31

*/
/*----------------------------------------------------------------------------*/
#ifndef TESTABLEPROCESSPROVIDER_H
#define TESTABLEPROCESSPROVIDER_H

#include <source/code/providers/process_provider/processprovider.h>

/*----------------------------------------------------------------------------*/
/**
    Class that exposes the protected methods of the process provider for
    testing purposes.
*/
class TestableProcessProvider : public TestableProvider, public SCXCore::ProcessProvider
{
public:
    void TestDoInit()
    {
        DoInit();
    }

    void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                 SCXProviderLib::SCXInstanceCollection &names)
    {
        DoEnumInstanceNames(callContext, names);
        if (SupportsSendInstance())
        {
            CPPUNIT_ASSERT( names.Size() == 0 );
            names = m_testInstances;
            m_testInstances.clear();
        }
    }

    void TestDoEnumInstances(const SCXProviderLib::SCXCallContext& callContext,
                             SCXProviderLib::SCXInstanceCollection &instances)
    {
        DoEnumInstances(callContext, instances);
        if (SupportsSendInstance())
        {
            CPPUNIT_ASSERT( instances.Size() == 0 );
            instances = m_testInstances;
            m_testInstances.clear();
        }
    }

    void TestDoGetInstance(const SCXProviderLib::SCXCallContext& callContext,
                           SCXProviderLib::SCXInstance& instance)
    {
        DoGetInstance(callContext, instance);
    }

    void TestDoInvokeMethod(const SCXProviderLib::SCXCallContext& callContext,
                            const std::wstring& methodname, const SCXProviderLib::SCXArgs& args,
                            SCXProviderLib::SCXArgs& outargs, SCXProviderLib::SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }

    void TestDoCleanup()
    {
        DoCleanup();
        m_testInstances.clear();
    }

    void ForceSample()
    {
        m_processes->SampleData();
    }

protected:
    // If we're configured to send by instance, we collect instances together here for test purposes
    virtual void SendInstanceName(const SCXProviderLib::SCXInstance& instance)
    {
        m_testInstances.AddInstance(instance);
    }

    // If we're configured to send by instance, we collect instances together here for test purposes
    virtual void SendInstance(const SCXProviderLib::SCXInstance& instance)
    {
        m_testInstances.AddInstance(instance);
    }

private:
    SCXProviderLib::SCXInstanceCollection m_testInstances;
};
#endif /* TESTABLEPROCESSPROVIDER_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

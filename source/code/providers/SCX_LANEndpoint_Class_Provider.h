/* @migen@ */
#ifndef _SCX_LANEndpoint_Class_Provider_h
#define _SCX_LANEndpoint_Class_Provider_h

#include "SCX_LANEndpoint.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"

MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** SCX_LANEndpoint provider class declaration
**
**==============================================================================
*/

class SCX_LANEndpoint_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    SCX_LANEndpoint_Class_Provider(
        Module* module);

    ~SCX_LANEndpoint_Class_Provider();

    void Load(
        Context& context);

    void Unload(
        Context& context);

    void EnumerateInstances(
        Context& context,
        const String& nameSpace,
        const PropertySet& propertySet,
        bool keysOnly,
        const MI_Filter* filter);

    void GetInstance(
        Context& context,
        const String& nameSpace,
        const SCX_LANEndpoint_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const SCX_LANEndpoint_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const SCX_LANEndpoint_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const SCX_LANEndpoint_Class& instance);

    void Invoke_RequestStateChange(
        Context& context,
        const String& nameSpace,
        const SCX_LANEndpoint_Class& instanceName,
        const SCX_LANEndpoint_RequestStateChange_Class& in);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_LANEndpoint_Class_Provider_h */


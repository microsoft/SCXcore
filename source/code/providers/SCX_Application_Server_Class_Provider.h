/* @migen@ */
#ifndef _SCX_Application_Server_Class_Provider_h
#define _SCX_Application_Server_Class_Provider_h

#include "SCX_Application_Server.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"

MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** SCX_Application_Server provider class declaration
**
**==============================================================================
*/

class SCX_Application_Server_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    SCX_Application_Server_Class_Provider(
        Module* module);

    ~SCX_Application_Server_Class_Provider();

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
        const SCX_Application_Server_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const SCX_Application_Server_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const SCX_Application_Server_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const SCX_Application_Server_Class& instance);

    void Invoke_SetDeepMonitoring(
        Context& context,
        const String& nameSpace,
        const SCX_Application_Server_Class& instanceName,
        const SCX_Application_Server_SetDeepMonitoring_Class& in);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_Application_Server_Class_Provider_h */


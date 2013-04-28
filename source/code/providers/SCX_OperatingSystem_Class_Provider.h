/* @migen@ */
#ifndef _SCX_OperatingSystem_Class_Provider_h
#define _SCX_OperatingSystem_Class_Provider_h

#include "SCX_OperatingSystem.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"

MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** SCX_OperatingSystem provider class declaration
**
**==============================================================================
*/

class SCX_OperatingSystem_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    SCX_OperatingSystem_Class_Provider(
        Module* module);

    ~SCX_OperatingSystem_Class_Provider();

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
        const SCX_OperatingSystem_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instance);

    void Invoke_RequestStateChange(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_RequestStateChange_Class& in);

    void Invoke_Reboot(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_Reboot_Class& in);

    void Invoke_Shutdown(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_Shutdown_Class& in);

    void Invoke_ExecuteCommand(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_ExecuteCommand_Class& in);

    void Invoke_ExecuteShellCommand(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_ExecuteShellCommand_Class& in);

    void Invoke_ExecuteScript(
        Context& context,
        const String& nameSpace,
        const SCX_OperatingSystem_Class& instanceName,
        const SCX_OperatingSystem_ExecuteScript_Class& in);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_OperatingSystem_Class_Provider_h */


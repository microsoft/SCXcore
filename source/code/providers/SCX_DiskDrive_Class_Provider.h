/* @migen@ */
#ifndef _SCX_DiskDrive_Class_Provider_h
#define _SCX_DiskDrive_Class_Provider_h

#include "SCX_DiskDrive.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"

MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** SCX_DiskDrive provider class declaration
**
**==============================================================================
*/

class SCX_DiskDrive_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    SCX_DiskDrive_Class_Provider(
        Module* module);

    ~SCX_DiskDrive_Class_Provider();

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
        const SCX_DiskDrive_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instance);

    void Invoke_RequestStateChange(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_RequestStateChange_Class& in);

    void Invoke_SetPowerState(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_SetPowerState_Class& in);

    void Invoke_Reset(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_Reset_Class& in);

    void Invoke_EnableDevice(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_EnableDevice_Class& in);

    void Invoke_OnlineDevice(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_OnlineDevice_Class& in);

    void Invoke_QuiesceDevice(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_QuiesceDevice_Class& in);

    void Invoke_SaveProperties(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_SaveProperties_Class& in);

    void Invoke_RestoreProperties(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_RestoreProperties_Class& in);

    void Invoke_LockMedia(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_LockMedia_Class& in);

    void Invoke_RemoveByName(
        Context& context,
        const String& nameSpace,
        const SCX_DiskDrive_Class& instanceName,
        const SCX_DiskDrive_RemoveByName_Class& in);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_DiskDrive_Class_Provider_h */


/* @migen@ */
#ifndef _SCX_FileSystem_Class_Provider_h
#define _SCX_FileSystem_Class_Provider_h

#include "SCX_FileSystem.h"
#ifdef __cplusplus
# include <micxx/micxx.h>
# include "module.h"

MI_BEGIN_NAMESPACE

/*
**==============================================================================
**
** SCX_FileSystem provider class declaration
**
**==============================================================================
*/

class SCX_FileSystem_Class_Provider
{
/* @MIGEN.BEGIN@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
private:
    Module* m_Module;

public:
    SCX_FileSystem_Class_Provider(
        Module* module);

    ~SCX_FileSystem_Class_Provider();

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
        const SCX_FileSystem_Class& instance,
        const PropertySet& propertySet);

    void CreateInstance(
        Context& context,
        const String& nameSpace,
        const SCX_FileSystem_Class& newInstance);

    void ModifyInstance(
        Context& context,
        const String& nameSpace,
        const SCX_FileSystem_Class& modifiedInstance,
        const PropertySet& propertySet);

    void DeleteInstance(
        Context& context,
        const String& nameSpace,
        const SCX_FileSystem_Class& instance);

    void Invoke_RequestStateChange(
        Context& context,
        const String& nameSpace,
        const SCX_FileSystem_Class& instanceName,
        const SCX_FileSystem_RequestStateChange_Class& in);

    void Invoke_RemoveByName(
        Context& context,
        const String& nameSpace,
        const SCX_FileSystem_Class& instanceName,
        const SCX_FileSystem_RemoveByName_Class& in);

/* @MIGEN.END@ CAUTION: PLEASE DO NOT EDIT OR DELETE THIS LINE. */
};

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_FileSystem_Class_Provider_h */


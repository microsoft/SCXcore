/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_FileSystemStatisticalInformation_h
#define _SCX_FileSystemStatisticalInformation_h

#include <MI.h>
#include "SCX_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_FileSystemStatisticalInformation [SCX_FileSystemStatisticalInformation]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_FileSystemStatisticalInformation /* extends SCX_StatisticalInformation */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalInformation properties */
    /*KEY*/ MI_ConstStringField Name;
    /* SCX_StatisticalInformation properties */
    MI_ConstBooleanField IsAggregate;
    /* SCX_FileSystemStatisticalInformation properties */
    MI_ConstBooleanField IsOnline;
    MI_ConstUint64Field FreeMegabytes;
    MI_ConstUint64Field UsedMegabytes;
    MI_ConstUint8Field PercentFreeSpace;
    MI_ConstUint8Field PercentUsedSpace;
    MI_ConstUint8Field PercentFreeInodes;
    MI_ConstUint8Field PercentUsedInodes;
    MI_ConstUint8Field PercentBusyTime;
    MI_ConstUint8Field PercentIdleTime;
    MI_ConstUint64Field BytesPerSecond;
    MI_ConstUint64Field ReadBytesPerSecond;
    MI_ConstUint64Field WriteBytesPerSecond;
    MI_ConstUint64Field TransfersPerSecond;
    MI_ConstUint64Field ReadsPerSecond;
    MI_ConstUint64Field WritesPerSecond;
    MI_ConstReal64Field AverageTransferTime;
    MI_ConstReal64Field AverageDiskQueueLength;
}
SCX_FileSystemStatisticalInformation;

typedef struct _SCX_FileSystemStatisticalInformation_Ref
{
    SCX_FileSystemStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystemStatisticalInformation_Ref;

typedef struct _SCX_FileSystemStatisticalInformation_ConstRef
{
    MI_CONST SCX_FileSystemStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystemStatisticalInformation_ConstRef;

typedef struct _SCX_FileSystemStatisticalInformation_Array
{
    struct _SCX_FileSystemStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_FileSystemStatisticalInformation_Array;

typedef struct _SCX_FileSystemStatisticalInformation_ConstArray
{
    struct _SCX_FileSystemStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_FileSystemStatisticalInformation_ConstArray;

typedef struct _SCX_FileSystemStatisticalInformation_ArrayRef
{
    SCX_FileSystemStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystemStatisticalInformation_ArrayRef;

typedef struct _SCX_FileSystemStatisticalInformation_ConstArrayRef
{
    SCX_FileSystemStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_FileSystemStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_FileSystemStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Construct(
    SCX_FileSystemStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_FileSystemStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clone(
    const SCX_FileSystemStatisticalInformation* self,
    SCX_FileSystemStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_FileSystemStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_FileSystemStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Destruct(SCX_FileSystemStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Delete(SCX_FileSystemStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Post(
    const SCX_FileSystemStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_InstanceID(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_SetPtr_InstanceID(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_InstanceID(
    SCX_FileSystemStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_Caption(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_SetPtr_Caption(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_Caption(
    SCX_FileSystemStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_Description(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_SetPtr_Description(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_Description(
    SCX_FileSystemStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_ElementName(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_SetPtr_ElementName(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_ElementName(
    SCX_FileSystemStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_Name(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_SetPtr_Name(
    SCX_FileSystemStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_Name(
    SCX_FileSystemStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_IsAggregate(
    SCX_FileSystemStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_IsAggregate(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_IsOnline(
    SCX_FileSystemStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsOnline)->value = x;
    ((MI_BooleanField*)&self->IsOnline)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_IsOnline(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->IsOnline, 0, sizeof(self->IsOnline));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_FreeMegabytes(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->FreeMegabytes)->value = x;
    ((MI_Uint64Field*)&self->FreeMegabytes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_FreeMegabytes(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->FreeMegabytes, 0, sizeof(self->FreeMegabytes));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_UsedMegabytes(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->UsedMegabytes)->value = x;
    ((MI_Uint64Field*)&self->UsedMegabytes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_UsedMegabytes(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->UsedMegabytes, 0, sizeof(self->UsedMegabytes));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentFreeSpace(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentFreeSpace)->value = x;
    ((MI_Uint8Field*)&self->PercentFreeSpace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentFreeSpace(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentFreeSpace, 0, sizeof(self->PercentFreeSpace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentUsedSpace(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedSpace)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedSpace)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentUsedSpace(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedSpace, 0, sizeof(self->PercentUsedSpace));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentFreeInodes(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentFreeInodes)->value = x;
    ((MI_Uint8Field*)&self->PercentFreeInodes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentFreeInodes(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentFreeInodes, 0, sizeof(self->PercentFreeInodes));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentUsedInodes(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentUsedInodes)->value = x;
    ((MI_Uint8Field*)&self->PercentUsedInodes)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentUsedInodes(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentUsedInodes, 0, sizeof(self->PercentUsedInodes));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentBusyTime(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentBusyTime)->value = x;
    ((MI_Uint8Field*)&self->PercentBusyTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentBusyTime(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentBusyTime, 0, sizeof(self->PercentBusyTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_PercentIdleTime(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIdleTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIdleTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_PercentIdleTime(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->PercentIdleTime, 0, sizeof(self->PercentIdleTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_BytesPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->BytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_BytesPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->BytesPerSecond, 0, sizeof(self->BytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_ReadBytesPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ReadBytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->ReadBytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_ReadBytesPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->ReadBytesPerSecond, 0, sizeof(self->ReadBytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_WriteBytesPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WriteBytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->WriteBytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_WriteBytesPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->WriteBytesPerSecond, 0, sizeof(self->WriteBytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_TransfersPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TransfersPerSecond)->value = x;
    ((MI_Uint64Field*)&self->TransfersPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_TransfersPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->TransfersPerSecond, 0, sizeof(self->TransfersPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_ReadsPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ReadsPerSecond)->value = x;
    ((MI_Uint64Field*)&self->ReadsPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_ReadsPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->ReadsPerSecond, 0, sizeof(self->ReadsPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_WritesPerSecond(
    SCX_FileSystemStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WritesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->WritesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_WritesPerSecond(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->WritesPerSecond, 0, sizeof(self->WritesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_AverageTransferTime(
    SCX_FileSystemStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageTransferTime)->value = x;
    ((MI_Real64Field*)&self->AverageTransferTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_AverageTransferTime(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->AverageTransferTime, 0, sizeof(self->AverageTransferTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Set_AverageDiskQueueLength(
    SCX_FileSystemStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageDiskQueueLength)->value = x;
    ((MI_Real64Field*)&self->AverageDiskQueueLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_FileSystemStatisticalInformation_Clear_AverageDiskQueueLength(
    SCX_FileSystemStatisticalInformation* self)
{
    memset((void*)&self->AverageDiskQueueLength, 0, sizeof(self->AverageDiskQueueLength));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_FileSystemStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_FileSystemStatisticalInformation_Self SCX_FileSystemStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_Load(
    SCX_FileSystemStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_Unload(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_EnumerateInstances(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_GetInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_CreateInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_ModifyInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_FileSystemStatisticalInformation_DeleteInstance(
    SCX_FileSystemStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_FileSystemStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_FileSystemStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_FileSystemStatisticalInformation_Class : public SCX_StatisticalInformation_Class
{
public:
    
    typedef SCX_FileSystemStatisticalInformation Self;
    
    SCX_FileSystemStatisticalInformation_Class() :
        SCX_StatisticalInformation_Class(&SCX_FileSystemStatisticalInformation_rtti)
    {
    }
    
    SCX_FileSystemStatisticalInformation_Class(
        const SCX_FileSystemStatisticalInformation* instanceName,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(
            &SCX_FileSystemStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_FileSystemStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_FileSystemStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        SCX_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_FileSystemStatisticalInformation_Class& operator=(
        const SCX_FileSystemStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_FileSystemStatisticalInformation_Class(
        const SCX_FileSystemStatisticalInformation_Class& x) :
        SCX_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_FileSystemStatisticalInformation_rtti;
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.IsOnline
    //
    
    const Field<Boolean>& IsOnline() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n);
    }
    
    void IsOnline(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsOnline_value() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n).value;
    }
    
    void IsOnline_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsOnline_exists() const
    {
        const size_t n = offsetof(Self, IsOnline);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsOnline_clear()
    {
        const size_t n = offsetof(Self, IsOnline);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.FreeMegabytes
    //
    
    const Field<Uint64>& FreeMegabytes() const
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        return GetField<Uint64>(n);
    }
    
    void FreeMegabytes(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& FreeMegabytes_value() const
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        return GetField<Uint64>(n).value;
    }
    
    void FreeMegabytes_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        GetField<Uint64>(n).Set(x);
    }
    
    bool FreeMegabytes_exists() const
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void FreeMegabytes_clear()
    {
        const size_t n = offsetof(Self, FreeMegabytes);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.UsedMegabytes
    //
    
    const Field<Uint64>& UsedMegabytes() const
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        return GetField<Uint64>(n);
    }
    
    void UsedMegabytes(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& UsedMegabytes_value() const
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        return GetField<Uint64>(n).value;
    }
    
    void UsedMegabytes_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        GetField<Uint64>(n).Set(x);
    }
    
    bool UsedMegabytes_exists() const
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void UsedMegabytes_clear()
    {
        const size_t n = offsetof(Self, UsedMegabytes);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentFreeSpace
    //
    
    const Field<Uint8>& PercentFreeSpace() const
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        return GetField<Uint8>(n);
    }
    
    void PercentFreeSpace(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentFreeSpace_value() const
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        return GetField<Uint8>(n).value;
    }
    
    void PercentFreeSpace_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentFreeSpace_exists() const
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentFreeSpace_clear()
    {
        const size_t n = offsetof(Self, PercentFreeSpace);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentUsedSpace
    //
    
    const Field<Uint8>& PercentUsedSpace() const
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        return GetField<Uint8>(n);
    }
    
    void PercentUsedSpace(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUsedSpace_value() const
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUsedSpace_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUsedSpace_exists() const
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUsedSpace_clear()
    {
        const size_t n = offsetof(Self, PercentUsedSpace);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentFreeInodes
    //
    
    const Field<Uint8>& PercentFreeInodes() const
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        return GetField<Uint8>(n);
    }
    
    void PercentFreeInodes(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentFreeInodes_value() const
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        return GetField<Uint8>(n).value;
    }
    
    void PercentFreeInodes_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentFreeInodes_exists() const
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentFreeInodes_clear()
    {
        const size_t n = offsetof(Self, PercentFreeInodes);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentUsedInodes
    //
    
    const Field<Uint8>& PercentUsedInodes() const
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        return GetField<Uint8>(n);
    }
    
    void PercentUsedInodes(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentUsedInodes_value() const
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        return GetField<Uint8>(n).value;
    }
    
    void PercentUsedInodes_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentUsedInodes_exists() const
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentUsedInodes_clear()
    {
        const size_t n = offsetof(Self, PercentUsedInodes);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentBusyTime
    //
    
    const Field<Uint8>& PercentBusyTime() const
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        return GetField<Uint8>(n);
    }
    
    void PercentBusyTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentBusyTime_value() const
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentBusyTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentBusyTime_exists() const
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentBusyTime_clear()
    {
        const size_t n = offsetof(Self, PercentBusyTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.PercentIdleTime
    //
    
    const Field<Uint8>& PercentIdleTime() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n);
    }
    
    void PercentIdleTime(const Field<Uint8>& x)
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n) = x;
    }
    
    const Uint8& PercentIdleTime_value() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n).value;
    }
    
    void PercentIdleTime_value(const Uint8& x)
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n).Set(x);
    }
    
    bool PercentIdleTime_exists() const
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        return GetField<Uint8>(n).exists ? true : false;
    }
    
    void PercentIdleTime_clear()
    {
        const size_t n = offsetof(Self, PercentIdleTime);
        GetField<Uint8>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.BytesPerSecond
    //
    
    const Field<Uint64>& BytesPerSecond() const
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        return GetField<Uint64>(n);
    }
    
    void BytesPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& BytesPerSecond_value() const
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void BytesPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool BytesPerSecond_exists() const
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void BytesPerSecond_clear()
    {
        const size_t n = offsetof(Self, BytesPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.ReadBytesPerSecond
    //
    
    const Field<Uint64>& ReadBytesPerSecond() const
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        return GetField<Uint64>(n);
    }
    
    void ReadBytesPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ReadBytesPerSecond_value() const
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void ReadBytesPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ReadBytesPerSecond_exists() const
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ReadBytesPerSecond_clear()
    {
        const size_t n = offsetof(Self, ReadBytesPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.WriteBytesPerSecond
    //
    
    const Field<Uint64>& WriteBytesPerSecond() const
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        return GetField<Uint64>(n);
    }
    
    void WriteBytesPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& WriteBytesPerSecond_value() const
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void WriteBytesPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool WriteBytesPerSecond_exists() const
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void WriteBytesPerSecond_clear()
    {
        const size_t n = offsetof(Self, WriteBytesPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.TransfersPerSecond
    //
    
    const Field<Uint64>& TransfersPerSecond() const
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        return GetField<Uint64>(n);
    }
    
    void TransfersPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& TransfersPerSecond_value() const
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void TransfersPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool TransfersPerSecond_exists() const
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void TransfersPerSecond_clear()
    {
        const size_t n = offsetof(Self, TransfersPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.ReadsPerSecond
    //
    
    const Field<Uint64>& ReadsPerSecond() const
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        return GetField<Uint64>(n);
    }
    
    void ReadsPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& ReadsPerSecond_value() const
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void ReadsPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool ReadsPerSecond_exists() const
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void ReadsPerSecond_clear()
    {
        const size_t n = offsetof(Self, ReadsPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.WritesPerSecond
    //
    
    const Field<Uint64>& WritesPerSecond() const
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        return GetField<Uint64>(n);
    }
    
    void WritesPerSecond(const Field<Uint64>& x)
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        GetField<Uint64>(n) = x;
    }
    
    const Uint64& WritesPerSecond_value() const
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        return GetField<Uint64>(n).value;
    }
    
    void WritesPerSecond_value(const Uint64& x)
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        GetField<Uint64>(n).Set(x);
    }
    
    bool WritesPerSecond_exists() const
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        return GetField<Uint64>(n).exists ? true : false;
    }
    
    void WritesPerSecond_clear()
    {
        const size_t n = offsetof(Self, WritesPerSecond);
        GetField<Uint64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.AverageTransferTime
    //
    
    const Field<Real64>& AverageTransferTime() const
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        return GetField<Real64>(n);
    }
    
    void AverageTransferTime(const Field<Real64>& x)
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        GetField<Real64>(n) = x;
    }
    
    const Real64& AverageTransferTime_value() const
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        return GetField<Real64>(n).value;
    }
    
    void AverageTransferTime_value(const Real64& x)
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        GetField<Real64>(n).Set(x);
    }
    
    bool AverageTransferTime_exists() const
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        return GetField<Real64>(n).exists ? true : false;
    }
    
    void AverageTransferTime_clear()
    {
        const size_t n = offsetof(Self, AverageTransferTime);
        GetField<Real64>(n).Clear();
    }

    //
    // SCX_FileSystemStatisticalInformation_Class.AverageDiskQueueLength
    //
    
    const Field<Real64>& AverageDiskQueueLength() const
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        return GetField<Real64>(n);
    }
    
    void AverageDiskQueueLength(const Field<Real64>& x)
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        GetField<Real64>(n) = x;
    }
    
    const Real64& AverageDiskQueueLength_value() const
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        return GetField<Real64>(n).value;
    }
    
    void AverageDiskQueueLength_value(const Real64& x)
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        GetField<Real64>(n).Set(x);
    }
    
    bool AverageDiskQueueLength_exists() const
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        return GetField<Real64>(n).exists ? true : false;
    }
    
    void AverageDiskQueueLength_clear()
    {
        const size_t n = offsetof(Self, AverageDiskQueueLength);
        GetField<Real64>(n).Clear();
    }
};

typedef Array<SCX_FileSystemStatisticalInformation_Class> SCX_FileSystemStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_FileSystemStatisticalInformation_h */

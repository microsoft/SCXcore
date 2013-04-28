/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_DiskDriveStatisticalInformation_h
#define _SCX_DiskDriveStatisticalInformation_h

#include <MI.h>
#include "SCX_StatisticalInformation.h"

/*
**==============================================================================
**
** SCX_DiskDriveStatisticalInformation [SCX_DiskDriveStatisticalInformation]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_DiskDriveStatisticalInformation /* extends SCX_StatisticalInformation */
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
    /* SCX_DiskDriveStatisticalInformation properties */
    MI_ConstBooleanField IsOnline;
    MI_ConstUint8Field PercentBusyTime;
    MI_ConstUint8Field PercentIdleTime;
    MI_ConstUint64Field BytesPerSecond;
    MI_ConstUint64Field ReadBytesPerSecond;
    MI_ConstUint64Field WriteBytesPerSecond;
    MI_ConstUint64Field TransfersPerSecond;
    MI_ConstUint64Field ReadsPerSecond;
    MI_ConstUint64Field WritesPerSecond;
    MI_ConstReal64Field AverageReadTime;
    MI_ConstReal64Field AverageWriteTime;
    MI_ConstReal64Field AverageTransferTime;
    MI_ConstReal64Field AverageDiskQueueLength;
}
SCX_DiskDriveStatisticalInformation;

typedef struct _SCX_DiskDriveStatisticalInformation_Ref
{
    SCX_DiskDriveStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDriveStatisticalInformation_Ref;

typedef struct _SCX_DiskDriveStatisticalInformation_ConstRef
{
    MI_CONST SCX_DiskDriveStatisticalInformation* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDriveStatisticalInformation_ConstRef;

typedef struct _SCX_DiskDriveStatisticalInformation_Array
{
    struct _SCX_DiskDriveStatisticalInformation** data;
    MI_Uint32 size;
}
SCX_DiskDriveStatisticalInformation_Array;

typedef struct _SCX_DiskDriveStatisticalInformation_ConstArray
{
    struct _SCX_DiskDriveStatisticalInformation MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_DiskDriveStatisticalInformation_ConstArray;

typedef struct _SCX_DiskDriveStatisticalInformation_ArrayRef
{
    SCX_DiskDriveStatisticalInformation_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDriveStatisticalInformation_ArrayRef;

typedef struct _SCX_DiskDriveStatisticalInformation_ConstArrayRef
{
    SCX_DiskDriveStatisticalInformation_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_DiskDriveStatisticalInformation_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_DiskDriveStatisticalInformation_rtti;

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Construct(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_DiskDriveStatisticalInformation_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clone(
    const SCX_DiskDriveStatisticalInformation* self,
    SCX_DiskDriveStatisticalInformation** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_DiskDriveStatisticalInformation_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_DiskDriveStatisticalInformation_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Destruct(SCX_DiskDriveStatisticalInformation* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Delete(SCX_DiskDriveStatisticalInformation* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Post(
    const SCX_DiskDriveStatisticalInformation* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_InstanceID(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_SetPtr_InstanceID(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_InstanceID(
    SCX_DiskDriveStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_Caption(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_SetPtr_Caption(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_Caption(
    SCX_DiskDriveStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_Description(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_SetPtr_Description(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_Description(
    SCX_DiskDriveStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_ElementName(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_SetPtr_ElementName(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_ElementName(
    SCX_DiskDriveStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_Name(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_SetPtr_Name(
    SCX_DiskDriveStatisticalInformation* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_Name(
    SCX_DiskDriveStatisticalInformation* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_IsAggregate(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsAggregate)->value = x;
    ((MI_BooleanField*)&self->IsAggregate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_IsAggregate(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->IsAggregate, 0, sizeof(self->IsAggregate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_IsOnline(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsOnline)->value = x;
    ((MI_BooleanField*)&self->IsOnline)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_IsOnline(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->IsOnline, 0, sizeof(self->IsOnline));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_PercentBusyTime(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentBusyTime)->value = x;
    ((MI_Uint8Field*)&self->PercentBusyTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_PercentBusyTime(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->PercentBusyTime, 0, sizeof(self->PercentBusyTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_PercentIdleTime(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint8 x)
{
    ((MI_Uint8Field*)&self->PercentIdleTime)->value = x;
    ((MI_Uint8Field*)&self->PercentIdleTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_PercentIdleTime(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->PercentIdleTime, 0, sizeof(self->PercentIdleTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_BytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->BytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_BytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->BytesPerSecond, 0, sizeof(self->BytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_ReadBytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ReadBytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->ReadBytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_ReadBytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->ReadBytesPerSecond, 0, sizeof(self->ReadBytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_WriteBytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WriteBytesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->WriteBytesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_WriteBytesPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->WriteBytesPerSecond, 0, sizeof(self->WriteBytesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_TransfersPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->TransfersPerSecond)->value = x;
    ((MI_Uint64Field*)&self->TransfersPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_TransfersPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->TransfersPerSecond, 0, sizeof(self->TransfersPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_ReadsPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->ReadsPerSecond)->value = x;
    ((MI_Uint64Field*)&self->ReadsPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_ReadsPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->ReadsPerSecond, 0, sizeof(self->ReadsPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_WritesPerSecond(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->WritesPerSecond)->value = x;
    ((MI_Uint64Field*)&self->WritesPerSecond)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_WritesPerSecond(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->WritesPerSecond, 0, sizeof(self->WritesPerSecond));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_AverageReadTime(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageReadTime)->value = x;
    ((MI_Real64Field*)&self->AverageReadTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_AverageReadTime(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->AverageReadTime, 0, sizeof(self->AverageReadTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_AverageWriteTime(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageWriteTime)->value = x;
    ((MI_Real64Field*)&self->AverageWriteTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_AverageWriteTime(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->AverageWriteTime, 0, sizeof(self->AverageWriteTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_AverageTransferTime(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageTransferTime)->value = x;
    ((MI_Real64Field*)&self->AverageTransferTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_AverageTransferTime(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->AverageTransferTime, 0, sizeof(self->AverageTransferTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Set_AverageDiskQueueLength(
    SCX_DiskDriveStatisticalInformation* self,
    MI_Real64 x)
{
    ((MI_Real64Field*)&self->AverageDiskQueueLength)->value = x;
    ((MI_Real64Field*)&self->AverageDiskQueueLength)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_DiskDriveStatisticalInformation_Clear_AverageDiskQueueLength(
    SCX_DiskDriveStatisticalInformation* self)
{
    memset((void*)&self->AverageDiskQueueLength, 0, sizeof(self->AverageDiskQueueLength));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_DiskDriveStatisticalInformation provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_DiskDriveStatisticalInformation_Self SCX_DiskDriveStatisticalInformation_Self;

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_Load(
    SCX_DiskDriveStatisticalInformation_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_Unload(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_EnumerateInstances(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_GetInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_CreateInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* newInstance);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_ModifyInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_DiskDriveStatisticalInformation_DeleteInstance(
    SCX_DiskDriveStatisticalInformation_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_DiskDriveStatisticalInformation* instanceName);


/*
**==============================================================================
**
** SCX_DiskDriveStatisticalInformation_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_DiskDriveStatisticalInformation_Class : public SCX_StatisticalInformation_Class
{
public:
    
    typedef SCX_DiskDriveStatisticalInformation Self;
    
    SCX_DiskDriveStatisticalInformation_Class() :
        SCX_StatisticalInformation_Class(&SCX_DiskDriveStatisticalInformation_rtti)
    {
    }
    
    SCX_DiskDriveStatisticalInformation_Class(
        const SCX_DiskDriveStatisticalInformation* instanceName,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(
            &SCX_DiskDriveStatisticalInformation_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_DiskDriveStatisticalInformation_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        SCX_StatisticalInformation_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_DiskDriveStatisticalInformation_Class(
        const MI_ClassDecl* clDecl) :
        SCX_StatisticalInformation_Class(clDecl)
    {
    }
    
    SCX_DiskDriveStatisticalInformation_Class& operator=(
        const SCX_DiskDriveStatisticalInformation_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_DiskDriveStatisticalInformation_Class(
        const SCX_DiskDriveStatisticalInformation_Class& x) :
        SCX_StatisticalInformation_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_DiskDriveStatisticalInformation_rtti;
    }

    //
    // SCX_DiskDriveStatisticalInformation_Class.IsOnline
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
    // SCX_DiskDriveStatisticalInformation_Class.PercentBusyTime
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
    // SCX_DiskDriveStatisticalInformation_Class.PercentIdleTime
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
    // SCX_DiskDriveStatisticalInformation_Class.BytesPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.ReadBytesPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.WriteBytesPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.TransfersPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.ReadsPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.WritesPerSecond
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
    // SCX_DiskDriveStatisticalInformation_Class.AverageReadTime
    //
    
    const Field<Real64>& AverageReadTime() const
    {
        const size_t n = offsetof(Self, AverageReadTime);
        return GetField<Real64>(n);
    }
    
    void AverageReadTime(const Field<Real64>& x)
    {
        const size_t n = offsetof(Self, AverageReadTime);
        GetField<Real64>(n) = x;
    }
    
    const Real64& AverageReadTime_value() const
    {
        const size_t n = offsetof(Self, AverageReadTime);
        return GetField<Real64>(n).value;
    }
    
    void AverageReadTime_value(const Real64& x)
    {
        const size_t n = offsetof(Self, AverageReadTime);
        GetField<Real64>(n).Set(x);
    }
    
    bool AverageReadTime_exists() const
    {
        const size_t n = offsetof(Self, AverageReadTime);
        return GetField<Real64>(n).exists ? true : false;
    }
    
    void AverageReadTime_clear()
    {
        const size_t n = offsetof(Self, AverageReadTime);
        GetField<Real64>(n).Clear();
    }

    //
    // SCX_DiskDriveStatisticalInformation_Class.AverageWriteTime
    //
    
    const Field<Real64>& AverageWriteTime() const
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        return GetField<Real64>(n);
    }
    
    void AverageWriteTime(const Field<Real64>& x)
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        GetField<Real64>(n) = x;
    }
    
    const Real64& AverageWriteTime_value() const
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        return GetField<Real64>(n).value;
    }
    
    void AverageWriteTime_value(const Real64& x)
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        GetField<Real64>(n).Set(x);
    }
    
    bool AverageWriteTime_exists() const
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        return GetField<Real64>(n).exists ? true : false;
    }
    
    void AverageWriteTime_clear()
    {
        const size_t n = offsetof(Self, AverageWriteTime);
        GetField<Real64>(n).Clear();
    }

    //
    // SCX_DiskDriveStatisticalInformation_Class.AverageTransferTime
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
    // SCX_DiskDriveStatisticalInformation_Class.AverageDiskQueueLength
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

typedef Array<SCX_DiskDriveStatisticalInformation_Class> SCX_DiskDriveStatisticalInformation_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_DiskDriveStatisticalInformation_h */

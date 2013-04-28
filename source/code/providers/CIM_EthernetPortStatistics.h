/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _CIM_EthernetPortStatistics_h
#define _CIM_EthernetPortStatistics_h

#include <MI.h>
#include "CIM_NetworkPortStatistics.h"

/*
**==============================================================================
**
** CIM_EthernetPortStatistics [CIM_EthernetPortStatistics]
**
** Keys:
**    InstanceID
**
**==============================================================================
*/

typedef struct _CIM_EthernetPortStatistics /* extends CIM_NetworkPortStatistics */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    /*KEY*/ MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_StatisticalData properties */
    MI_ConstDatetimeField StartStatisticTime;
    MI_ConstDatetimeField StatisticTime;
    MI_ConstDatetimeField SampleInterval;
    /* CIM_NetworkPortStatistics properties */
    MI_ConstUint64Field BytesTransmitted;
    MI_ConstUint64Field BytesReceived;
    MI_ConstUint64Field PacketsTransmitted;
    MI_ConstUint64Field PacketsReceived;
    /* CIM_EthernetPortStatistics properties */
    MI_ConstUint32Field SymbolErrors;
    MI_ConstUint32Field AlignmentErrors;
    MI_ConstUint32Field FCSErrors;
    MI_ConstUint32Field SingleCollisionFrames;
    MI_ConstUint32Field MultipleCollisionFrames;
    MI_ConstUint32Field SQETestErrors;
    MI_ConstUint32Field DeferredTransmissions;
    MI_ConstUint32Field LateCollisions;
    MI_ConstUint32Field ExcessiveCollisions;
    MI_ConstUint32Field InternalMACTransmitErrors;
    MI_ConstUint32Field InternalMACReceiveErrors;
    MI_ConstUint32Field CarrierSenseErrors;
    MI_ConstUint32Field FrameTooLongs;
}
CIM_EthernetPortStatistics;

typedef struct _CIM_EthernetPortStatistics_Ref
{
    CIM_EthernetPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EthernetPortStatistics_Ref;

typedef struct _CIM_EthernetPortStatistics_ConstRef
{
    MI_CONST CIM_EthernetPortStatistics* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EthernetPortStatistics_ConstRef;

typedef struct _CIM_EthernetPortStatistics_Array
{
    struct _CIM_EthernetPortStatistics** data;
    MI_Uint32 size;
}
CIM_EthernetPortStatistics_Array;

typedef struct _CIM_EthernetPortStatistics_ConstArray
{
    struct _CIM_EthernetPortStatistics MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
CIM_EthernetPortStatistics_ConstArray;

typedef struct _CIM_EthernetPortStatistics_ArrayRef
{
    CIM_EthernetPortStatistics_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EthernetPortStatistics_ArrayRef;

typedef struct _CIM_EthernetPortStatistics_ConstArrayRef
{
    CIM_EthernetPortStatistics_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
CIM_EthernetPortStatistics_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl CIM_EthernetPortStatistics_rtti;

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Construct(
    CIM_EthernetPortStatistics* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &CIM_EthernetPortStatistics_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clone(
    const CIM_EthernetPortStatistics* self,
    CIM_EthernetPortStatistics** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL CIM_EthernetPortStatistics_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &CIM_EthernetPortStatistics_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Destruct(CIM_EthernetPortStatistics* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Delete(CIM_EthernetPortStatistics* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Post(
    const CIM_EthernetPortStatistics* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_InstanceID(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_SetPtr_InstanceID(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_InstanceID(
    CIM_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_Caption(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_SetPtr_Caption(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_Caption(
    CIM_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_Description(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_SetPtr_Description(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_Description(
    CIM_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_ElementName(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_SetPtr_ElementName(
    CIM_EthernetPortStatistics* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_ElementName(
    CIM_EthernetPortStatistics* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_StartStatisticTime(
    CIM_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StartStatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StartStatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_StartStatisticTime(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->StartStatisticTime, 0, sizeof(self->StartStatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_StatisticTime(
    CIM_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->StatisticTime)->value = x;
    ((MI_DatetimeField*)&self->StatisticTime)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_StatisticTime(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->StatisticTime, 0, sizeof(self->StatisticTime));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_SampleInterval(
    CIM_EthernetPortStatistics* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->SampleInterval)->value = x;
    ((MI_DatetimeField*)&self->SampleInterval)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_SampleInterval(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->SampleInterval, 0, sizeof(self->SampleInterval));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_BytesTransmitted(
    CIM_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesTransmitted)->value = x;
    ((MI_Uint64Field*)&self->BytesTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_BytesTransmitted(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->BytesTransmitted, 0, sizeof(self->BytesTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_BytesReceived(
    CIM_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->BytesReceived)->value = x;
    ((MI_Uint64Field*)&self->BytesReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_BytesReceived(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->BytesReceived, 0, sizeof(self->BytesReceived));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_PacketsTransmitted(
    CIM_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsTransmitted)->value = x;
    ((MI_Uint64Field*)&self->PacketsTransmitted)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_PacketsTransmitted(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->PacketsTransmitted, 0, sizeof(self->PacketsTransmitted));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_PacketsReceived(
    CIM_EthernetPortStatistics* self,
    MI_Uint64 x)
{
    ((MI_Uint64Field*)&self->PacketsReceived)->value = x;
    ((MI_Uint64Field*)&self->PacketsReceived)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_PacketsReceived(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->PacketsReceived, 0, sizeof(self->PacketsReceived));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_SymbolErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SymbolErrors)->value = x;
    ((MI_Uint32Field*)&self->SymbolErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_SymbolErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->SymbolErrors, 0, sizeof(self->SymbolErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_AlignmentErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->AlignmentErrors)->value = x;
    ((MI_Uint32Field*)&self->AlignmentErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_AlignmentErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->AlignmentErrors, 0, sizeof(self->AlignmentErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_FCSErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->FCSErrors)->value = x;
    ((MI_Uint32Field*)&self->FCSErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_FCSErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->FCSErrors, 0, sizeof(self->FCSErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_SingleCollisionFrames(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SingleCollisionFrames)->value = x;
    ((MI_Uint32Field*)&self->SingleCollisionFrames)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_SingleCollisionFrames(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->SingleCollisionFrames, 0, sizeof(self->SingleCollisionFrames));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_MultipleCollisionFrames(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MultipleCollisionFrames)->value = x;
    ((MI_Uint32Field*)&self->MultipleCollisionFrames)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_MultipleCollisionFrames(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->MultipleCollisionFrames, 0, sizeof(self->MultipleCollisionFrames));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_SQETestErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->SQETestErrors)->value = x;
    ((MI_Uint32Field*)&self->SQETestErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_SQETestErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->SQETestErrors, 0, sizeof(self->SQETestErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_DeferredTransmissions(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->DeferredTransmissions)->value = x;
    ((MI_Uint32Field*)&self->DeferredTransmissions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_DeferredTransmissions(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->DeferredTransmissions, 0, sizeof(self->DeferredTransmissions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_LateCollisions(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->LateCollisions)->value = x;
    ((MI_Uint32Field*)&self->LateCollisions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_LateCollisions(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->LateCollisions, 0, sizeof(self->LateCollisions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_ExcessiveCollisions(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->ExcessiveCollisions)->value = x;
    ((MI_Uint32Field*)&self->ExcessiveCollisions)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_ExcessiveCollisions(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->ExcessiveCollisions, 0, sizeof(self->ExcessiveCollisions));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_InternalMACTransmitErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->InternalMACTransmitErrors)->value = x;
    ((MI_Uint32Field*)&self->InternalMACTransmitErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_InternalMACTransmitErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->InternalMACTransmitErrors, 0, sizeof(self->InternalMACTransmitErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_InternalMACReceiveErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->InternalMACReceiveErrors)->value = x;
    ((MI_Uint32Field*)&self->InternalMACReceiveErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_InternalMACReceiveErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->InternalMACReceiveErrors, 0, sizeof(self->InternalMACReceiveErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_CarrierSenseErrors(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->CarrierSenseErrors)->value = x;
    ((MI_Uint32Field*)&self->CarrierSenseErrors)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_CarrierSenseErrors(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->CarrierSenseErrors, 0, sizeof(self->CarrierSenseErrors));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Set_FrameTooLongs(
    CIM_EthernetPortStatistics* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->FrameTooLongs)->value = x;
    ((MI_Uint32Field*)&self->FrameTooLongs)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_Clear_FrameTooLongs(
    CIM_EthernetPortStatistics* self)
{
    memset((void*)&self->FrameTooLongs, 0, sizeof(self->FrameTooLongs));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** CIM_EthernetPortStatistics.ResetSelectedStats()
**
**==============================================================================
*/

typedef struct _CIM_EthernetPortStatistics_ResetSelectedStats
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstUint32Field MIReturn;
    /*IN*/ MI_ConstStringAField SelectedStatistics;
}
CIM_EthernetPortStatistics_ResetSelectedStats;

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_ResetSelectedStats_Set_MIReturn(
    CIM_EthernetPortStatistics_ResetSelectedStats* self,
    MI_Uint32 x)
{
    ((MI_Uint32Field*)&self->MIReturn)->value = x;
    ((MI_Uint32Field*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_ResetSelectedStats_Clear_MIReturn(
    CIM_EthernetPortStatistics_ResetSelectedStats* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_ResetSelectedStats_Set_SelectedStatistics(
    CIM_EthernetPortStatistics_ResetSelectedStats* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_ResetSelectedStats_SetPtr_SelectedStatistics(
    CIM_EthernetPortStatistics_ResetSelectedStats* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL CIM_EthernetPortStatistics_ResetSelectedStats_Clear_SelectedStatistics(
    CIM_EthernetPortStatistics_ResetSelectedStats* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}


/*
**==============================================================================
**
** CIM_EthernetPortStatistics_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class CIM_EthernetPortStatistics_Class : public CIM_NetworkPortStatistics_Class
{
public:
    
    typedef CIM_EthernetPortStatistics Self;
    
    CIM_EthernetPortStatistics_Class() :
        CIM_NetworkPortStatistics_Class(&CIM_EthernetPortStatistics_rtti)
    {
    }
    
    CIM_EthernetPortStatistics_Class(
        const CIM_EthernetPortStatistics* instanceName,
        bool keysOnly) :
        CIM_NetworkPortStatistics_Class(
            &CIM_EthernetPortStatistics_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    CIM_EthernetPortStatistics_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_NetworkPortStatistics_Class(clDecl, instance, keysOnly)
    {
    }
    
    CIM_EthernetPortStatistics_Class(
        const MI_ClassDecl* clDecl) :
        CIM_NetworkPortStatistics_Class(clDecl)
    {
    }
    
    CIM_EthernetPortStatistics_Class& operator=(
        const CIM_EthernetPortStatistics_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    CIM_EthernetPortStatistics_Class(
        const CIM_EthernetPortStatistics_Class& x) :
        CIM_NetworkPortStatistics_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &CIM_EthernetPortStatistics_rtti;
    }

    //
    // CIM_EthernetPortStatistics_Class.SymbolErrors
    //
    
    const Field<Uint32>& SymbolErrors() const
    {
        const size_t n = offsetof(Self, SymbolErrors);
        return GetField<Uint32>(n);
    }
    
    void SymbolErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, SymbolErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& SymbolErrors_value() const
    {
        const size_t n = offsetof(Self, SymbolErrors);
        return GetField<Uint32>(n).value;
    }
    
    void SymbolErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, SymbolErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool SymbolErrors_exists() const
    {
        const size_t n = offsetof(Self, SymbolErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void SymbolErrors_clear()
    {
        const size_t n = offsetof(Self, SymbolErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.AlignmentErrors
    //
    
    const Field<Uint32>& AlignmentErrors() const
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        return GetField<Uint32>(n);
    }
    
    void AlignmentErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& AlignmentErrors_value() const
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        return GetField<Uint32>(n).value;
    }
    
    void AlignmentErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool AlignmentErrors_exists() const
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void AlignmentErrors_clear()
    {
        const size_t n = offsetof(Self, AlignmentErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.FCSErrors
    //
    
    const Field<Uint32>& FCSErrors() const
    {
        const size_t n = offsetof(Self, FCSErrors);
        return GetField<Uint32>(n);
    }
    
    void FCSErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, FCSErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& FCSErrors_value() const
    {
        const size_t n = offsetof(Self, FCSErrors);
        return GetField<Uint32>(n).value;
    }
    
    void FCSErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, FCSErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool FCSErrors_exists() const
    {
        const size_t n = offsetof(Self, FCSErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void FCSErrors_clear()
    {
        const size_t n = offsetof(Self, FCSErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.SingleCollisionFrames
    //
    
    const Field<Uint32>& SingleCollisionFrames() const
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        return GetField<Uint32>(n);
    }
    
    void SingleCollisionFrames(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& SingleCollisionFrames_value() const
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        return GetField<Uint32>(n).value;
    }
    
    void SingleCollisionFrames_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        GetField<Uint32>(n).Set(x);
    }
    
    bool SingleCollisionFrames_exists() const
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void SingleCollisionFrames_clear()
    {
        const size_t n = offsetof(Self, SingleCollisionFrames);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.MultipleCollisionFrames
    //
    
    const Field<Uint32>& MultipleCollisionFrames() const
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        return GetField<Uint32>(n);
    }
    
    void MultipleCollisionFrames(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& MultipleCollisionFrames_value() const
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        return GetField<Uint32>(n).value;
    }
    
    void MultipleCollisionFrames_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        GetField<Uint32>(n).Set(x);
    }
    
    bool MultipleCollisionFrames_exists() const
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void MultipleCollisionFrames_clear()
    {
        const size_t n = offsetof(Self, MultipleCollisionFrames);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.SQETestErrors
    //
    
    const Field<Uint32>& SQETestErrors() const
    {
        const size_t n = offsetof(Self, SQETestErrors);
        return GetField<Uint32>(n);
    }
    
    void SQETestErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, SQETestErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& SQETestErrors_value() const
    {
        const size_t n = offsetof(Self, SQETestErrors);
        return GetField<Uint32>(n).value;
    }
    
    void SQETestErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, SQETestErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool SQETestErrors_exists() const
    {
        const size_t n = offsetof(Self, SQETestErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void SQETestErrors_clear()
    {
        const size_t n = offsetof(Self, SQETestErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.DeferredTransmissions
    //
    
    const Field<Uint32>& DeferredTransmissions() const
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        return GetField<Uint32>(n);
    }
    
    void DeferredTransmissions(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& DeferredTransmissions_value() const
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        return GetField<Uint32>(n).value;
    }
    
    void DeferredTransmissions_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        GetField<Uint32>(n).Set(x);
    }
    
    bool DeferredTransmissions_exists() const
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void DeferredTransmissions_clear()
    {
        const size_t n = offsetof(Self, DeferredTransmissions);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.LateCollisions
    //
    
    const Field<Uint32>& LateCollisions() const
    {
        const size_t n = offsetof(Self, LateCollisions);
        return GetField<Uint32>(n);
    }
    
    void LateCollisions(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, LateCollisions);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& LateCollisions_value() const
    {
        const size_t n = offsetof(Self, LateCollisions);
        return GetField<Uint32>(n).value;
    }
    
    void LateCollisions_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, LateCollisions);
        GetField<Uint32>(n).Set(x);
    }
    
    bool LateCollisions_exists() const
    {
        const size_t n = offsetof(Self, LateCollisions);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void LateCollisions_clear()
    {
        const size_t n = offsetof(Self, LateCollisions);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.ExcessiveCollisions
    //
    
    const Field<Uint32>& ExcessiveCollisions() const
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        return GetField<Uint32>(n);
    }
    
    void ExcessiveCollisions(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& ExcessiveCollisions_value() const
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        return GetField<Uint32>(n).value;
    }
    
    void ExcessiveCollisions_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        GetField<Uint32>(n).Set(x);
    }
    
    bool ExcessiveCollisions_exists() const
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void ExcessiveCollisions_clear()
    {
        const size_t n = offsetof(Self, ExcessiveCollisions);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.InternalMACTransmitErrors
    //
    
    const Field<Uint32>& InternalMACTransmitErrors() const
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        return GetField<Uint32>(n);
    }
    
    void InternalMACTransmitErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& InternalMACTransmitErrors_value() const
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        return GetField<Uint32>(n).value;
    }
    
    void InternalMACTransmitErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool InternalMACTransmitErrors_exists() const
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void InternalMACTransmitErrors_clear()
    {
        const size_t n = offsetof(Self, InternalMACTransmitErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.InternalMACReceiveErrors
    //
    
    const Field<Uint32>& InternalMACReceiveErrors() const
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        return GetField<Uint32>(n);
    }
    
    void InternalMACReceiveErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& InternalMACReceiveErrors_value() const
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        return GetField<Uint32>(n).value;
    }
    
    void InternalMACReceiveErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool InternalMACReceiveErrors_exists() const
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void InternalMACReceiveErrors_clear()
    {
        const size_t n = offsetof(Self, InternalMACReceiveErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.CarrierSenseErrors
    //
    
    const Field<Uint32>& CarrierSenseErrors() const
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        return GetField<Uint32>(n);
    }
    
    void CarrierSenseErrors(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& CarrierSenseErrors_value() const
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        return GetField<Uint32>(n).value;
    }
    
    void CarrierSenseErrors_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        GetField<Uint32>(n).Set(x);
    }
    
    bool CarrierSenseErrors_exists() const
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void CarrierSenseErrors_clear()
    {
        const size_t n = offsetof(Self, CarrierSenseErrors);
        GetField<Uint32>(n).Clear();
    }

    //
    // CIM_EthernetPortStatistics_Class.FrameTooLongs
    //
    
    const Field<Uint32>& FrameTooLongs() const
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        return GetField<Uint32>(n);
    }
    
    void FrameTooLongs(const Field<Uint32>& x)
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        GetField<Uint32>(n) = x;
    }
    
    const Uint32& FrameTooLongs_value() const
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        return GetField<Uint32>(n).value;
    }
    
    void FrameTooLongs_value(const Uint32& x)
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        GetField<Uint32>(n).Set(x);
    }
    
    bool FrameTooLongs_exists() const
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        return GetField<Uint32>(n).exists ? true : false;
    }
    
    void FrameTooLongs_clear()
    {
        const size_t n = offsetof(Self, FrameTooLongs);
        GetField<Uint32>(n).Clear();
    }
};

typedef Array<CIM_EthernetPortStatistics_Class> CIM_EthernetPortStatistics_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _CIM_EthernetPortStatistics_h */

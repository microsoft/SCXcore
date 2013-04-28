/* @migen@ */
/*
**==============================================================================
**
** WARNING: THIS FILE WAS AUTOMATICALLY GENERATED. PLEASE DO NOT EDIT.
**
**==============================================================================
*/
#ifndef _SCX_Application_Server_h
#define _SCX_Application_Server_h

#include <MI.h>
#include "CIM_LogicalElement.h"

/*
**==============================================================================
**
** SCX_Application_Server [SCX_Application_Server]
**
** Keys:
**    Name
**
**==============================================================================
*/

typedef struct _SCX_Application_Server /* extends CIM_LogicalElement */
{
    MI_Instance __instance;
    /* CIM_ManagedElement properties */
    MI_ConstStringField InstanceID;
    MI_ConstStringField Caption;
    MI_ConstStringField Description;
    MI_ConstStringField ElementName;
    /* CIM_ManagedSystemElement properties */
    MI_ConstDatetimeField InstallDate;
    /*KEY*/ MI_ConstStringField Name;
    MI_ConstUint16AField OperationalStatus;
    MI_ConstStringAField StatusDescriptions;
    MI_ConstStringField Status;
    MI_ConstUint16Field HealthState;
    MI_ConstUint16Field CommunicationStatus;
    MI_ConstUint16Field DetailedStatus;
    MI_ConstUint16Field OperatingStatus;
    MI_ConstUint16Field PrimaryStatus;
    /* CIM_LogicalElement properties */
    /* SCX_Application_Server properties */
    MI_ConstStringField HttpPort;
    MI_ConstStringField HttpsPort;
    MI_ConstStringField Port;
    MI_ConstStringField Protocol;
    MI_ConstStringField Version;
    MI_ConstStringField MajorVersion;
    MI_ConstStringField DiskPath;
    MI_ConstStringField Type;
    MI_ConstStringField Profile;
    MI_ConstStringField Cell;
    MI_ConstStringField Node;
    MI_ConstStringField Server;
    MI_ConstBooleanField IsDeepMonitored;
    MI_ConstBooleanField IsRunning;
}
SCX_Application_Server;

typedef struct _SCX_Application_Server_Ref
{
    SCX_Application_Server* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Application_Server_Ref;

typedef struct _SCX_Application_Server_ConstRef
{
    MI_CONST SCX_Application_Server* value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Application_Server_ConstRef;

typedef struct _SCX_Application_Server_Array
{
    struct _SCX_Application_Server** data;
    MI_Uint32 size;
}
SCX_Application_Server_Array;

typedef struct _SCX_Application_Server_ConstArray
{
    struct _SCX_Application_Server MI_CONST* MI_CONST* data;
    MI_Uint32 size;
}
SCX_Application_Server_ConstArray;

typedef struct _SCX_Application_Server_ArrayRef
{
    SCX_Application_Server_Array value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Application_Server_ArrayRef;

typedef struct _SCX_Application_Server_ConstArrayRef
{
    SCX_Application_Server_ConstArray value;
    MI_Boolean exists;
    MI_Uint8 flags;
}
SCX_Application_Server_ConstArrayRef;

MI_EXTERN_C MI_CONST MI_ClassDecl SCX_Application_Server_rtti;

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Construct(
    SCX_Application_Server* self,
    MI_Context* context)
{
    return MI_ConstructInstance(context, &SCX_Application_Server_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clone(
    const SCX_Application_Server* self,
    SCX_Application_Server** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Boolean MI_CALL SCX_Application_Server_IsA(
    const MI_Instance* self)
{
    MI_Boolean res = MI_FALSE;
    return MI_Instance_IsA(self, &SCX_Application_Server_rtti, &res) == MI_RESULT_OK && res;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Destruct(SCX_Application_Server* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Delete(SCX_Application_Server* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Post(
    const SCX_Application_Server* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_InstanceID(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_InstanceID(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        0,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_InstanceID(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Caption(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Caption(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Caption(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Description(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Description(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        2,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Description(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        2);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_ElementName(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_ElementName(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_ElementName(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_InstallDate(
    SCX_Application_Server* self,
    MI_Datetime x)
{
    ((MI_DatetimeField*)&self->InstallDate)->value = x;
    ((MI_DatetimeField*)&self->InstallDate)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_InstallDate(
    SCX_Application_Server* self)
{
    memset((void*)&self->InstallDate, 0, sizeof(self->InstallDate));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Name(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Name(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        5,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Name(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        5);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_OperationalStatus(
    SCX_Application_Server* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&arr,
        MI_UINT16A,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_OperationalStatus(
    SCX_Application_Server* self,
    const MI_Uint16* data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        6,
        (MI_Value*)&arr,
        MI_UINT16A,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_OperationalStatus(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        6);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_StatusDescriptions(
    SCX_Application_Server* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&arr,
        MI_STRINGA,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_StatusDescriptions(
    SCX_Application_Server* self,
    const MI_Char** data,
    MI_Uint32 size)
{
    MI_Array arr;
    arr.data = (void*)data;
    arr.size = size;
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        7,
        (MI_Value*)&arr,
        MI_STRINGA,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_StatusDescriptions(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        7);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Status(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Status(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        8,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Status(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        8);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_HealthState(
    SCX_Application_Server* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->HealthState)->value = x;
    ((MI_Uint16Field*)&self->HealthState)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_HealthState(
    SCX_Application_Server* self)
{
    memset((void*)&self->HealthState, 0, sizeof(self->HealthState));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_CommunicationStatus(
    SCX_Application_Server* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->CommunicationStatus)->value = x;
    ((MI_Uint16Field*)&self->CommunicationStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_CommunicationStatus(
    SCX_Application_Server* self)
{
    memset((void*)&self->CommunicationStatus, 0, sizeof(self->CommunicationStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_DetailedStatus(
    SCX_Application_Server* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->DetailedStatus)->value = x;
    ((MI_Uint16Field*)&self->DetailedStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_DetailedStatus(
    SCX_Application_Server* self)
{
    memset((void*)&self->DetailedStatus, 0, sizeof(self->DetailedStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_OperatingStatus(
    SCX_Application_Server* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->OperatingStatus)->value = x;
    ((MI_Uint16Field*)&self->OperatingStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_OperatingStatus(
    SCX_Application_Server* self)
{
    memset((void*)&self->OperatingStatus, 0, sizeof(self->OperatingStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_PrimaryStatus(
    SCX_Application_Server* self,
    MI_Uint16 x)
{
    ((MI_Uint16Field*)&self->PrimaryStatus)->value = x;
    ((MI_Uint16Field*)&self->PrimaryStatus)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_PrimaryStatus(
    SCX_Application_Server* self)
{
    memset((void*)&self->PrimaryStatus, 0, sizeof(self->PrimaryStatus));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_HttpPort(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_HttpPort(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        14,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_HttpPort(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        14);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_HttpsPort(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_HttpsPort(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        15,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_HttpsPort(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        15);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Port(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Port(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        16,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Port(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        16);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Protocol(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Protocol(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        17,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Protocol(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        17);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Version(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Version(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        18,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Version(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        18);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_MajorVersion(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_MajorVersion(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        19,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_MajorVersion(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        19);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_DiskPath(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        20,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_DiskPath(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        20,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_DiskPath(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        20);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Type(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Type(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        21,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Type(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        21);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Profile(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Profile(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        22,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Profile(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        22);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Cell(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Cell(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        23,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Cell(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        23);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Node(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Node(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        24,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Node(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        24);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_Server(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetPtr_Server(
    SCX_Application_Server* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        25,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_Server(
    SCX_Application_Server* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        25);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_IsDeepMonitored(
    SCX_Application_Server* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsDeepMonitored)->value = x;
    ((MI_BooleanField*)&self->IsDeepMonitored)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_IsDeepMonitored(
    SCX_Application_Server* self)
{
    memset((void*)&self->IsDeepMonitored, 0, sizeof(self->IsDeepMonitored));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Set_IsRunning(
    SCX_Application_Server* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->IsRunning)->value = x;
    ((MI_BooleanField*)&self->IsRunning)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_Clear_IsRunning(
    SCX_Application_Server* self)
{
    memset((void*)&self->IsRunning, 0, sizeof(self->IsRunning));
    return MI_RESULT_OK;
}

/*
**==============================================================================
**
** SCX_Application_Server.SetDeepMonitoring()
**
**==============================================================================
*/

typedef struct _SCX_Application_Server_SetDeepMonitoring
{
    MI_Instance __instance;
    /*OUT*/ MI_ConstBooleanField MIReturn;
    /*IN*/ MI_ConstStringField id;
    /*IN*/ MI_ConstBooleanField deep;
    /*IN*/ MI_ConstStringField protocol;
    /*IN*/ MI_ConstStringField elevationType;
}
SCX_Application_Server_SetDeepMonitoring;

MI_EXTERN_C MI_CONST MI_MethodDecl SCX_Application_Server_SetDeepMonitoring_rtti;

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Construct(
    SCX_Application_Server_SetDeepMonitoring* self,
    MI_Context* context)
{
    return MI_ConstructParameters(context, &SCX_Application_Server_SetDeepMonitoring_rtti,
        (MI_Instance*)&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clone(
    const SCX_Application_Server_SetDeepMonitoring* self,
    SCX_Application_Server_SetDeepMonitoring** newInstance)
{
    return MI_Instance_Clone(
        &self->__instance, (MI_Instance**)newInstance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Destruct(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    return MI_Instance_Destruct(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Delete(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    return MI_Instance_Delete(&self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Post(
    const SCX_Application_Server_SetDeepMonitoring* self,
    MI_Context* context)
{
    return MI_PostInstance(context, &self->__instance);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Set_MIReturn(
    SCX_Application_Server_SetDeepMonitoring* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->MIReturn)->value = x;
    ((MI_BooleanField*)&self->MIReturn)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clear_MIReturn(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    memset((void*)&self->MIReturn, 0, sizeof(self->MIReturn));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Set_id(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_SetPtr_id(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        1,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clear_id(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        1);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Set_deep(
    SCX_Application_Server_SetDeepMonitoring* self,
    MI_Boolean x)
{
    ((MI_BooleanField*)&self->deep)->value = x;
    ((MI_BooleanField*)&self->deep)->exists = 1;
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clear_deep(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    memset((void*)&self->deep, 0, sizeof(self->deep));
    return MI_RESULT_OK;
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Set_protocol(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_SetPtr_protocol(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        3,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clear_protocol(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        3);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Set_elevationType(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        0);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_SetPtr_elevationType(
    SCX_Application_Server_SetDeepMonitoring* self,
    const MI_Char* str)
{
    return self->__instance.ft->SetElementAt(
        (MI_Instance*)&self->__instance,
        4,
        (MI_Value*)&str,
        MI_STRING,
        MI_FLAG_BORROW);
}

MI_INLINE MI_Result MI_CALL SCX_Application_Server_SetDeepMonitoring_Clear_elevationType(
    SCX_Application_Server_SetDeepMonitoring* self)
{
    return self->__instance.ft->ClearElementAt(
        (MI_Instance*)&self->__instance,
        4);
}

/*
**==============================================================================
**
** SCX_Application_Server provider function prototypes
**
**==============================================================================
*/

/* The developer may optionally define this structure */
typedef struct _SCX_Application_Server_Self SCX_Application_Server_Self;

MI_EXTERN_C void MI_CALL SCX_Application_Server_Load(
    SCX_Application_Server_Self** self,
    MI_Module_Self* selfModule,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Application_Server_Unload(
    SCX_Application_Server_Self* self,
    MI_Context* context);

MI_EXTERN_C void MI_CALL SCX_Application_Server_EnumerateInstances(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_PropertySet* propertySet,
    MI_Boolean keysOnly,
    const MI_Filter* filter);

MI_EXTERN_C void MI_CALL SCX_Application_Server_GetInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* instanceName,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Application_Server_CreateInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* newInstance);

MI_EXTERN_C void MI_CALL SCX_Application_Server_ModifyInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* modifiedInstance,
    const MI_PropertySet* propertySet);

MI_EXTERN_C void MI_CALL SCX_Application_Server_DeleteInstance(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const SCX_Application_Server* instanceName);

MI_EXTERN_C void MI_CALL SCX_Application_Server_Invoke_SetDeepMonitoring(
    SCX_Application_Server_Self* self,
    MI_Context* context,
    const MI_Char* nameSpace,
    const MI_Char* className,
    const MI_Char* methodName,
    const SCX_Application_Server* instanceName,
    const SCX_Application_Server_SetDeepMonitoring* in);


/*
**==============================================================================
**
** SCX_Application_Server_Class
**
**==============================================================================
*/

#ifdef __cplusplus
# include <micxx/micxx.h>

MI_BEGIN_NAMESPACE

class SCX_Application_Server_Class : public CIM_LogicalElement_Class
{
public:
    
    typedef SCX_Application_Server Self;
    
    SCX_Application_Server_Class() :
        CIM_LogicalElement_Class(&SCX_Application_Server_rtti)
    {
    }
    
    SCX_Application_Server_Class(
        const SCX_Application_Server* instanceName,
        bool keysOnly) :
        CIM_LogicalElement_Class(
            &SCX_Application_Server_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Application_Server_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        CIM_LogicalElement_Class(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Application_Server_Class(
        const MI_ClassDecl* clDecl) :
        CIM_LogicalElement_Class(clDecl)
    {
    }
    
    SCX_Application_Server_Class& operator=(
        const SCX_Application_Server_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Application_Server_Class(
        const SCX_Application_Server_Class& x) :
        CIM_LogicalElement_Class(x)
    {
    }

    static const MI_ClassDecl* GetClassDecl()
    {
        return &SCX_Application_Server_rtti;
    }

    //
    // SCX_Application_Server_Class.HttpPort
    //
    
    const Field<String>& HttpPort() const
    {
        const size_t n = offsetof(Self, HttpPort);
        return GetField<String>(n);
    }
    
    void HttpPort(const Field<String>& x)
    {
        const size_t n = offsetof(Self, HttpPort);
        GetField<String>(n) = x;
    }
    
    const String& HttpPort_value() const
    {
        const size_t n = offsetof(Self, HttpPort);
        return GetField<String>(n).value;
    }
    
    void HttpPort_value(const String& x)
    {
        const size_t n = offsetof(Self, HttpPort);
        GetField<String>(n).Set(x);
    }
    
    bool HttpPort_exists() const
    {
        const size_t n = offsetof(Self, HttpPort);
        return GetField<String>(n).exists ? true : false;
    }
    
    void HttpPort_clear()
    {
        const size_t n = offsetof(Self, HttpPort);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.HttpsPort
    //
    
    const Field<String>& HttpsPort() const
    {
        const size_t n = offsetof(Self, HttpsPort);
        return GetField<String>(n);
    }
    
    void HttpsPort(const Field<String>& x)
    {
        const size_t n = offsetof(Self, HttpsPort);
        GetField<String>(n) = x;
    }
    
    const String& HttpsPort_value() const
    {
        const size_t n = offsetof(Self, HttpsPort);
        return GetField<String>(n).value;
    }
    
    void HttpsPort_value(const String& x)
    {
        const size_t n = offsetof(Self, HttpsPort);
        GetField<String>(n).Set(x);
    }
    
    bool HttpsPort_exists() const
    {
        const size_t n = offsetof(Self, HttpsPort);
        return GetField<String>(n).exists ? true : false;
    }
    
    void HttpsPort_clear()
    {
        const size_t n = offsetof(Self, HttpsPort);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Port
    //
    
    const Field<String>& Port() const
    {
        const size_t n = offsetof(Self, Port);
        return GetField<String>(n);
    }
    
    void Port(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Port);
        GetField<String>(n) = x;
    }
    
    const String& Port_value() const
    {
        const size_t n = offsetof(Self, Port);
        return GetField<String>(n).value;
    }
    
    void Port_value(const String& x)
    {
        const size_t n = offsetof(Self, Port);
        GetField<String>(n).Set(x);
    }
    
    bool Port_exists() const
    {
        const size_t n = offsetof(Self, Port);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Port_clear()
    {
        const size_t n = offsetof(Self, Port);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Protocol
    //
    
    const Field<String>& Protocol() const
    {
        const size_t n = offsetof(Self, Protocol);
        return GetField<String>(n);
    }
    
    void Protocol(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Protocol);
        GetField<String>(n) = x;
    }
    
    const String& Protocol_value() const
    {
        const size_t n = offsetof(Self, Protocol);
        return GetField<String>(n).value;
    }
    
    void Protocol_value(const String& x)
    {
        const size_t n = offsetof(Self, Protocol);
        GetField<String>(n).Set(x);
    }
    
    bool Protocol_exists() const
    {
        const size_t n = offsetof(Self, Protocol);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Protocol_clear()
    {
        const size_t n = offsetof(Self, Protocol);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Version
    //
    
    const Field<String>& Version() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n);
    }
    
    void Version(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n) = x;
    }
    
    const String& Version_value() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n).value;
    }
    
    void Version_value(const String& x)
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n).Set(x);
    }
    
    bool Version_exists() const
    {
        const size_t n = offsetof(Self, Version);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Version_clear()
    {
        const size_t n = offsetof(Self, Version);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.MajorVersion
    //
    
    const Field<String>& MajorVersion() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<String>(n);
    }
    
    void MajorVersion(const Field<String>& x)
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<String>(n) = x;
    }
    
    const String& MajorVersion_value() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<String>(n).value;
    }
    
    void MajorVersion_value(const String& x)
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<String>(n).Set(x);
    }
    
    bool MajorVersion_exists() const
    {
        const size_t n = offsetof(Self, MajorVersion);
        return GetField<String>(n).exists ? true : false;
    }
    
    void MajorVersion_clear()
    {
        const size_t n = offsetof(Self, MajorVersion);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.DiskPath
    //
    
    const Field<String>& DiskPath() const
    {
        const size_t n = offsetof(Self, DiskPath);
        return GetField<String>(n);
    }
    
    void DiskPath(const Field<String>& x)
    {
        const size_t n = offsetof(Self, DiskPath);
        GetField<String>(n) = x;
    }
    
    const String& DiskPath_value() const
    {
        const size_t n = offsetof(Self, DiskPath);
        return GetField<String>(n).value;
    }
    
    void DiskPath_value(const String& x)
    {
        const size_t n = offsetof(Self, DiskPath);
        GetField<String>(n).Set(x);
    }
    
    bool DiskPath_exists() const
    {
        const size_t n = offsetof(Self, DiskPath);
        return GetField<String>(n).exists ? true : false;
    }
    
    void DiskPath_clear()
    {
        const size_t n = offsetof(Self, DiskPath);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Type
    //
    
    const Field<String>& Type() const
    {
        const size_t n = offsetof(Self, Type);
        return GetField<String>(n);
    }
    
    void Type(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Type);
        GetField<String>(n) = x;
    }
    
    const String& Type_value() const
    {
        const size_t n = offsetof(Self, Type);
        return GetField<String>(n).value;
    }
    
    void Type_value(const String& x)
    {
        const size_t n = offsetof(Self, Type);
        GetField<String>(n).Set(x);
    }
    
    bool Type_exists() const
    {
        const size_t n = offsetof(Self, Type);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Type_clear()
    {
        const size_t n = offsetof(Self, Type);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Profile
    //
    
    const Field<String>& Profile() const
    {
        const size_t n = offsetof(Self, Profile);
        return GetField<String>(n);
    }
    
    void Profile(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Profile);
        GetField<String>(n) = x;
    }
    
    const String& Profile_value() const
    {
        const size_t n = offsetof(Self, Profile);
        return GetField<String>(n).value;
    }
    
    void Profile_value(const String& x)
    {
        const size_t n = offsetof(Self, Profile);
        GetField<String>(n).Set(x);
    }
    
    bool Profile_exists() const
    {
        const size_t n = offsetof(Self, Profile);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Profile_clear()
    {
        const size_t n = offsetof(Self, Profile);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Cell
    //
    
    const Field<String>& Cell() const
    {
        const size_t n = offsetof(Self, Cell);
        return GetField<String>(n);
    }
    
    void Cell(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Cell);
        GetField<String>(n) = x;
    }
    
    const String& Cell_value() const
    {
        const size_t n = offsetof(Self, Cell);
        return GetField<String>(n).value;
    }
    
    void Cell_value(const String& x)
    {
        const size_t n = offsetof(Self, Cell);
        GetField<String>(n).Set(x);
    }
    
    bool Cell_exists() const
    {
        const size_t n = offsetof(Self, Cell);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Cell_clear()
    {
        const size_t n = offsetof(Self, Cell);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Node
    //
    
    const Field<String>& Node() const
    {
        const size_t n = offsetof(Self, Node);
        return GetField<String>(n);
    }
    
    void Node(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Node);
        GetField<String>(n) = x;
    }
    
    const String& Node_value() const
    {
        const size_t n = offsetof(Self, Node);
        return GetField<String>(n).value;
    }
    
    void Node_value(const String& x)
    {
        const size_t n = offsetof(Self, Node);
        GetField<String>(n).Set(x);
    }
    
    bool Node_exists() const
    {
        const size_t n = offsetof(Self, Node);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Node_clear()
    {
        const size_t n = offsetof(Self, Node);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.Server
    //
    
    const Field<String>& Server() const
    {
        const size_t n = offsetof(Self, Server);
        return GetField<String>(n);
    }
    
    void Server(const Field<String>& x)
    {
        const size_t n = offsetof(Self, Server);
        GetField<String>(n) = x;
    }
    
    const String& Server_value() const
    {
        const size_t n = offsetof(Self, Server);
        return GetField<String>(n).value;
    }
    
    void Server_value(const String& x)
    {
        const size_t n = offsetof(Self, Server);
        GetField<String>(n).Set(x);
    }
    
    bool Server_exists() const
    {
        const size_t n = offsetof(Self, Server);
        return GetField<String>(n).exists ? true : false;
    }
    
    void Server_clear()
    {
        const size_t n = offsetof(Self, Server);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.IsDeepMonitored
    //
    
    const Field<Boolean>& IsDeepMonitored() const
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        return GetField<Boolean>(n);
    }
    
    void IsDeepMonitored(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsDeepMonitored_value() const
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        return GetField<Boolean>(n).value;
    }
    
    void IsDeepMonitored_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsDeepMonitored_exists() const
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsDeepMonitored_clear()
    {
        const size_t n = offsetof(Self, IsDeepMonitored);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_Application_Server_Class.IsRunning
    //
    
    const Field<Boolean>& IsRunning() const
    {
        const size_t n = offsetof(Self, IsRunning);
        return GetField<Boolean>(n);
    }
    
    void IsRunning(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, IsRunning);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& IsRunning_value() const
    {
        const size_t n = offsetof(Self, IsRunning);
        return GetField<Boolean>(n).value;
    }
    
    void IsRunning_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, IsRunning);
        GetField<Boolean>(n).Set(x);
    }
    
    bool IsRunning_exists() const
    {
        const size_t n = offsetof(Self, IsRunning);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void IsRunning_clear()
    {
        const size_t n = offsetof(Self, IsRunning);
        GetField<Boolean>(n).Clear();
    }
};

typedef Array<SCX_Application_Server_Class> SCX_Application_Server_ClassA;

class SCX_Application_Server_SetDeepMonitoring_Class : public Instance
{
public:
    
    typedef SCX_Application_Server_SetDeepMonitoring Self;
    
    SCX_Application_Server_SetDeepMonitoring_Class() :
        Instance(&SCX_Application_Server_SetDeepMonitoring_rtti)
    {
    }
    
    SCX_Application_Server_SetDeepMonitoring_Class(
        const SCX_Application_Server_SetDeepMonitoring* instanceName,
        bool keysOnly) :
        Instance(
            &SCX_Application_Server_SetDeepMonitoring_rtti,
            &instanceName->__instance,
            keysOnly)
    {
    }
    
    SCX_Application_Server_SetDeepMonitoring_Class(
        const MI_ClassDecl* clDecl,
        const MI_Instance* instance,
        bool keysOnly) :
        Instance(clDecl, instance, keysOnly)
    {
    }
    
    SCX_Application_Server_SetDeepMonitoring_Class(
        const MI_ClassDecl* clDecl) :
        Instance(clDecl)
    {
    }
    
    SCX_Application_Server_SetDeepMonitoring_Class& operator=(
        const SCX_Application_Server_SetDeepMonitoring_Class& x)
    {
        CopyRef(x);
        return *this;
    }
    
    SCX_Application_Server_SetDeepMonitoring_Class(
        const SCX_Application_Server_SetDeepMonitoring_Class& x) :
        Instance(x)
    {
    }

    //
    // SCX_Application_Server_SetDeepMonitoring_Class.MIReturn
    //
    
    const Field<Boolean>& MIReturn() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n);
    }
    
    void MIReturn(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& MIReturn_value() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).value;
    }
    
    void MIReturn_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Set(x);
    }
    
    bool MIReturn_exists() const
    {
        const size_t n = offsetof(Self, MIReturn);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void MIReturn_clear()
    {
        const size_t n = offsetof(Self, MIReturn);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_Application_Server_SetDeepMonitoring_Class.id
    //
    
    const Field<String>& id() const
    {
        const size_t n = offsetof(Self, id);
        return GetField<String>(n);
    }
    
    void id(const Field<String>& x)
    {
        const size_t n = offsetof(Self, id);
        GetField<String>(n) = x;
    }
    
    const String& id_value() const
    {
        const size_t n = offsetof(Self, id);
        return GetField<String>(n).value;
    }
    
    void id_value(const String& x)
    {
        const size_t n = offsetof(Self, id);
        GetField<String>(n).Set(x);
    }
    
    bool id_exists() const
    {
        const size_t n = offsetof(Self, id);
        return GetField<String>(n).exists ? true : false;
    }
    
    void id_clear()
    {
        const size_t n = offsetof(Self, id);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_SetDeepMonitoring_Class.deep
    //
    
    const Field<Boolean>& deep() const
    {
        const size_t n = offsetof(Self, deep);
        return GetField<Boolean>(n);
    }
    
    void deep(const Field<Boolean>& x)
    {
        const size_t n = offsetof(Self, deep);
        GetField<Boolean>(n) = x;
    }
    
    const Boolean& deep_value() const
    {
        const size_t n = offsetof(Self, deep);
        return GetField<Boolean>(n).value;
    }
    
    void deep_value(const Boolean& x)
    {
        const size_t n = offsetof(Self, deep);
        GetField<Boolean>(n).Set(x);
    }
    
    bool deep_exists() const
    {
        const size_t n = offsetof(Self, deep);
        return GetField<Boolean>(n).exists ? true : false;
    }
    
    void deep_clear()
    {
        const size_t n = offsetof(Self, deep);
        GetField<Boolean>(n).Clear();
    }

    //
    // SCX_Application_Server_SetDeepMonitoring_Class.protocol
    //
    
    const Field<String>& protocol() const
    {
        const size_t n = offsetof(Self, protocol);
        return GetField<String>(n);
    }
    
    void protocol(const Field<String>& x)
    {
        const size_t n = offsetof(Self, protocol);
        GetField<String>(n) = x;
    }
    
    const String& protocol_value() const
    {
        const size_t n = offsetof(Self, protocol);
        return GetField<String>(n).value;
    }
    
    void protocol_value(const String& x)
    {
        const size_t n = offsetof(Self, protocol);
        GetField<String>(n).Set(x);
    }
    
    bool protocol_exists() const
    {
        const size_t n = offsetof(Self, protocol);
        return GetField<String>(n).exists ? true : false;
    }
    
    void protocol_clear()
    {
        const size_t n = offsetof(Self, protocol);
        GetField<String>(n).Clear();
    }

    //
    // SCX_Application_Server_SetDeepMonitoring_Class.elevationType
    //
    
    const Field<String>& elevationType() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n);
    }
    
    void elevationType(const Field<String>& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n) = x;
    }
    
    const String& elevationType_value() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).value;
    }
    
    void elevationType_value(const String& x)
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Set(x);
    }
    
    bool elevationType_exists() const
    {
        const size_t n = offsetof(Self, elevationType);
        return GetField<String>(n).exists ? true : false;
    }
    
    void elevationType_clear()
    {
        const size_t n = offsetof(Self, elevationType);
        GetField<String>(n).Clear();
    }
};

typedef Array<SCX_Application_Server_SetDeepMonitoring_Class> SCX_Application_Server_SetDeepMonitoring_ClassA;

MI_END_NAMESPACE

#endif /* __cplusplus */

#endif /* _SCX_Application_Server_h */

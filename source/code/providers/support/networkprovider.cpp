/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file     networkprovider.cpp

    \brief    Implementation of the Network Provider Dependencies  class.

    \date     12-03-21 11:21
*/
/*----------------------------------------------------------------------------*/
#include "networkprovider.h"

namespace SCXCore
{
    NetworkProvider g_NetworkProvider;
}
int SCXCore::NetworkProvider::ms_loadCount = 0;

/*----------------------------------------------------------------------------*/
/**
 * Initialize the interfaces
 */
void SCXCore::NetworkProviderDependencies::InitIntf() 
{
    m_interfaces = new NetworkInterfaceEnumeration();
    m_interfaces->Init();
}

/*----------------------------------------------------------------------------*/
/**
 * Clean up and release resources
 */
void SCXCore::NetworkProviderDependencies::CleanUpIntf() 
{
    m_interfaces->CleanUp();
    m_interfaces = 0;
}

/*----------------------------------------------------------------------------*/
/**
 * Update interfaces`
 * \param[in]   updateInstances   Update existing instances only
 */
void SCXCore::NetworkProviderDependencies::UpdateIntf(bool updateInstances)
{
    m_interfaces->Update(updateInstances);
}

/*----------------------------------------------------b------------------------*/
/** Retrive the number of interfaces
  * \returns  Number of interfaces
  */
size_t SCXCore::NetworkProviderDependencies::IntfCount() const 
{
    return m_interfaces->Size();
}

/*----------------------------------------------------------------------------*/
/** Retrieve interface at index
 * \param[in]    pos     Index to retrieve interface at
 * \returns      Interface at the index
 */
SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> SCXCore::NetworkProviderDependencies::GetIntf(size_t pos) const 
{
    return m_interfaces->GetInstance(pos);
}

/*----------------------------------------------------------------------------*/
/** Retrieve interface by name. 
 * \param[in]    intfId the interface name to retrieve interface at
 * \returns      Interface at the name 
 */
SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> SCXCore::NetworkProviderDependencies::GetIntf(const std::wstring& intfId) const 
{
    return m_interfaces->GetInstance(intfId);
}

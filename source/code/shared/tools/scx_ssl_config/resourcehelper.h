/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file
   
   \brief      Resource helper classes.
   
   \date       2-12-2008
   
   These classes provide automated resource control.
   
*/

#ifndef RESOURCEHELPER_H
#define RESOURCEHELPER_H

#include <iosfwd>
#include <cassert>

/** 
    Helper class to perform resouce management.
    
    Resources are allocated by a void (*fn)(void) call and deallocated the same way.
*/
class ManagedResource {
public:
    typedef void (*fnptr)();    ///< Define a resource alloc/dealloc function pointer type.

private:
    fnptr m_ReleaseFcn;         ///< Release resource function pointer.

public:
    /** CTOR
        \param[in] load Resource load function pointer.
        \param[in] release Resource release function pointer.
        
        Create a resource control object and load the resource.
    */
    ManagedResource(fnptr load, fnptr release) : m_ReleaseFcn(release)
    {
        assert(m_ReleaseFcn);
        if (0 != load)
        {
            (*load)();
        }
    }

    /** DTOR
        Release the loaded resource.
    */
    ~ManagedResource()
    {
        (*m_ReleaseFcn)();
    }
};


/**
   Helper class to manage pointer resources.

   The class maintains a pointer to a resource. It must be provided methods to
   load the pointer and to free the pointer when the resource is to be released.

*/
template<typename T> struct ManagedValueResource {
    typedef void (*releaseptr)(T *);    ///< Resource release function prototype.

    T * m_Value;                        ///< Value pointer.
    releaseptr m_ReleaseFcn;            ///< Release function pointer.

    /**
       CTOR
       Create a resource control object with a given initial value.
       \param[in] init The initial value of the pointer.
       \param[in] rp A release function pointer.
    */
    ManagedValueResource(T *init, releaseptr rp) :
        m_ReleaseFcn(rp)
    {
        m_Value = init;
    }

    /**
       DTOR
       Release the managed value.
    */
    ~ManagedValueResource()
    {
        (*m_ReleaseFcn)(m_Value);
        m_Value = 0;
    }    

    /**
       Get the value.
       \returns The value pointer.
    */
    T * Get()
    {
        return m_Value;
    }

    /**
       Check for assigned value.
       \returns true if the value is unassigned.
    */
    bool operator !()
    {
        return 0 == m_Value;
    }

};


#endif /* RESOURCEHELPER_H */


/*--------------------------E-N-D---O-F---F-I-L-E----------------------------*/


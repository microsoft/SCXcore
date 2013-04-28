/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Public interface of blah blah functionality
    
    \date        07-07-13 11:23:02

    Contains blah blah detailed description. [OPTIONAL]
    
*/
/*----------------------------------------------------------------------------*/
#ifndef EXAMPLE_H
#define EXAMPLE_H


/** 
    The demo namespace used in the Doxygen example.

    This is the full description of the namespace. It need to be defined in one 
    single location only. 
 */
namespace DoxyDemo {


    //! This is the description of the enumeration, using C++ syntax. The text 
    //! can obviously span several lines. In that case the first sentence 
    //! used as brief description, and the rest goes to detailed description.
    enum DoxyDemoEnumeration {
        eFirstValue1,                 //!< Value is first
        eSecondValue1,                //!< Value is second
        eDoxyDemoEnumerationEndmark1  //!< Endmark 
    }; 

    /** This is the description of the enumeration, using block comment syntax. */
    enum DoxyDemoEnumerationBlock {
        eFirstValue2,                 /**< Value is first */
        eSecondValue2,                /**< Value is second */
        eDoxyDemoEnumerationEndmark2  /**< Endmark   */
    }; 

    //! This is the description of the enumeration, with documentation before each item. 
    enum DoxyDemoEnumerationBefore {
        //! Value is first - could have used block comments as well
        eFirstValue3,
        //! Value is second
        eSecondValue3,               
        //! Endmark  
        eDoxyDemoEnumerationEndmark3 
    }; 

    /*----------------------------------------------------------------------------*/
    /**
       This is the brief description of a function.
       
       \param       x Control which X to use 
       \param[in]   y The name of the X
       \returns     The calculated xy value
       
       \date        07-07-13 11:22:22
       
       This function usk dui a hams suttle, unproportionable, ax monogynist, dye 
       meloe, idyll mainsail wag lye, gauming, be. Drawl, fanes, arless in 
       screeman boy fred, pons, junkmen <em>really</em> asweve agoranome, wise 
       spew, med. This is controlled by \a and \a y.

       Dippy, nock, jimpy anisoin wry cyclized, loll so shunted, sides, cesta, 
       a ladyfishes. Haversine gulose misdiet, specific bye, cyst galvanizers
       extravasate, restab, unharmoniousness apse, ganglionless a chuckholes, 
       unwit. A headstall hi nonconvergently tie, uh, ropand, euphrasies, 
       he, immarginate. Ark portaging, cure tax, myrtol. 
       
       \li Rerises a dud, in textarian.
       \li Slow um ptyalocele blushes, cub.
       \li Voguey, ungainness, do. 
       
       Mob windjam, shed, sold aril, coy, par, me. Dept, manors stagedom 
       sped coyotillos ha bebed, sativae.   This function is blah blurgh bliff. 
       
    */
    int MyDemoFunction(int x, std::string y) 
    {
        return 2;
    };
    

    /*----------------------------------------------------------------------------*/
    /**
       Inefficient algorithm
       
       \param[in]   zooBaff Specifies which baff to use
       \returns     The calculated \a zoo value
       
       \date        07-07-13 11:22:22
       
       This function usk dui a hams suttle, unproportionable, ax monogynist, dye 
       meloe. Dippy, nock, jimpy anisoin wry cyclized.

       \deprecated Use the more efficient MyDemoFunction instead.

       \note This function is very expensive to call.

       \warning This is what a warning looks like.

       More text

       \remarks This is a remark paragraph. 
    
       
    */
    int SomeOldFunctionDoxygenDemo(int zooBaff) 
    {
        return 9;
    };
    
    /*----------------------------------------------------------------------------*/
    /**
       Brief explanation here, appearing in lists etc.
       
       \date        07-07-13 11:22:54

       Taily hoiden ya folk unvivacious bug, ha naveled slog, a dispensable, bar,
       fruitier, hideous dublin, size sue soft. Nab on stereotypography sit,
       chazzanut ok, nowch pant, a a averts it joypopping a nightless. Oh lug
       oleary, dank, hurt. Cafe, tubular, preform sovkhozes, git hared, 
       nondoctrinal, byland. Decontamination, overannotate. Reconsigns, if, 
       chicanes, other.

       \ex
       \code
       for (DoxyDemoClass.xyz();;)
       {
           enter verbatim code examples here
       }
       \endcode
       
       \internal 
       This text will be rendered only for internal documentation, until the 
       end of the comment is encountered.
       
       \li This bullet will only be visible in internal documentation
       \li This bullet too
       
       And this text as well. 
       
    */
    class DoxyDemoClass 
    {
    public:
        /*----------------------------------------------------------------------------*/
        /**
           This is the brief description of a function.
           
           \param       theParameter Controls something
           \returns     The calculated xy value
           
           \date        07-07-13 11:22:22

           \throws      SCXInvalidArgument for incorrect input
           \throws      SCXInternalError for incorrect input

           \pre         The scrop must be initiated
           \post        Boofle will be restored
           \invariant   Sprof is always positive

           This member function usk dui a hams suttle, unproportionable, ax monogynist, dye 
           meloe, idyll mainsail wag lye, gauming, be. Drawl, fanes, arless in 
           screeman boy fred, pons, junkmen <em>really</em> asweve agoranome, wise 
           spew, med. This is controlled by \a x.
           
           Dippy, nock, jimpy anisoin wry cyclized, loll so shunted, sides, cesta, 
           a ladyfishes. Haversine gulose misdiet, specific bye, cyst galvanizers
           extravasate, restab, unharmoniousness apse, ganglionless a chuckholes, 
           unwit. A headstall hi nonconvergently tie, uh, ropand, euphrasies, 
           he, immarginate. Ark portaging, cure tax, myrtol. 
           
           \li Rerises a dud, in textarian.
           \li Slow um ptyalocele blushes, cub.
           \li Voguey, ungainness, do. 
           
           Mob windjam, shed, sold aril, coy, par, me. Dept, manors stagedom 
           sped coyotillos ha bebed, sativae.   This function is blah blurgh bliff. 

           \ex
           \verbatim
           $> drook -baff=49
           \endverbatim
           
        */
        int AMemberFunction(int theParameter = 3) const
        {
            return 5;
        }

        /**
           \overload
        */
        // NOTE that the overload directive must be in a block comment, for some reason
        //      (according to documentation and tests)
        int AMemberFunction(string theParameter) const
        {
            return 6;
        }
        
    private:
        /** One syntax of commenting the variable */
        int m_Something;    
        
        int m_Different;     //!< If you prefer to have documentation afterwards
    };
    
}

/**
    \page ExamplePAL Overview of the Example PAL implementation

    The PAL funcitonality is designed to proivide the same information output 
    although the data collection is very different. 

    \section Solaris
    On Solaris, blah blah
    \li Swap - read via API
    \li Page - the same thing, right?

    \section Linux

    Linux values are read from /proc/blahblah
    \li Swap - read from file
    \li Page - the same thing, right?
    
    This is implemented using MyDemoFunction(), basta.

*/



#endif /* EXAMPLE_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

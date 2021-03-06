//
// FILE NAME: CIDLib_Boolean.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 03/26/2017
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  $_CIDLib_CopyRight2_$
//
// DESCRIPTION:
//
//  This is the header for the CIDLib_Boolean.Cpp file. This file implements a class wrapper
//  (TBoolean) for a boolean value. It is a very simple simple class and makes no attempt to
//  create a fully functional boolean class. Its purely for formatting purposes and for when a
//  boolean value needs to act like an object. It does though provide equality operators.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//
#pragma once


#pragma CIDLIB_PACK(CIDLIBPACK)

// ---------------------------------------------------------------------------
//  CLASS: TBoolean
// PREFIX: b
// ---------------------------------------------------------------------------
class CIDLIBEXP TBoolean :

    public TObject, public MFormattable, public MDuplicable, public MStreamable
{
    public  :
        // -------------------------------------------------------------------
        // Constructors and Destructor
        // -------------------------------------------------------------------
        TBoolean();

        TBoolean
        (
            const   tCIDLib::TBoolean       bVal
        );

        TBoolean(const TBoolean&) = default;

        ~TBoolean();


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TBoolean& operator=(const TBoolean&) = default;

        TBoolean& operator=
        (
                    tCIDLib::TBoolean       bSrc
        );

        tCIDLib::TBoolean operator==
        (
            const   TBoolean&               bToTest
        )   const;

        tCIDLib::TBoolean operator!=
        (
            const   TBoolean&               bToTest
        )   const;

        tCIDLib::TBoolean operator==
        (
            const   tCIDLib::TBoolean       bToTest
        )   const;

        tCIDLib::TBoolean operator!=
        (
            const   tCIDLib::TBoolean       bToTest
        )   const;


        // -------------------------------------------------------------------
        //  Public, non-virtual methods
        // -------------------------------------------------------------------
        tCIDLib::TBoolean bVal() const
        {
            return m_bVal;
        }

        tCIDLib::TBoolean bVal
        (
            const   tCIDLib::TBoolean       bNewVal
        );


    protected   :
        // -------------------------------------------------------------------
        //  Protected, inherited methods
        // -------------------------------------------------------------------
        tCIDLib::TVoid FormatTo
        (
                    TTextOutStream&         strmDest
        )   const override;

        tCIDLib::TVoid StreamFrom
        (
                    TBinInStream&           strmToReadFrom
        ) override;

        tCIDLib::TVoid StreamTo
        (
                    TBinOutStream&          strmToWriteTo
        )   const override;


    private             :
        // -------------------------------------------------------------------
        //  Public data members
        //
        //  m_bVal
        //      Storage for the data value.
        // -------------------------------------------------------------------
        tCIDLib::TBoolean       m_bVal;


        // -------------------------------------------------------------------
        //  Do any needed magic macros
        // -------------------------------------------------------------------
        RTTIDefs(TBoolean,TObject)
        DefPolyDup(TBoolean)
        NulObject(TBoolean)
};

#pragma CIDLIB_POPPACK



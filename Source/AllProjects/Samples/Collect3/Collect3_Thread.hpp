//
// FILE NAME: Collect3_Thread.hpp
//
// AUTHOR: Dean Roddey
//
// CREATED: 08/07/1997
//
// COPYRIGHT: $_CIDLib_CopyRight_$
//
//  This file is part of a demonstration program of the CIDLib C++
//  Frameworks. Its contents are distributed 'as is', to provide guidance on
//  the use of the CIDLib system. However, these demos are not intended to
//  represent a full fledged applications. Any direct use of demo code in
//  user applications is at the user's discretion, and no warranties are
//  implied as to its correctness or applicability.
//
// DESCRIPTION:
//
//  This is the header for the Collect3_Thread.cpp module. This module
//  implements the thread class used by this program.
//
// CAVEATS/GOTCHAS:
//
// LOG:
//
//  $_CIDLib_Log_$
//


// ---------------------------------------------------------------------------
//   CLASS: TColThread
//  PREFIX: thr
// ---------------------------------------------------------------------------
class TColThread : public TThread
{
    public :
        // -------------------------------------------------------------------
        //  Public types
        // -------------------------------------------------------------------
        enum class EThreadTypes
        {
            Adder
            , Remover
        };


        // -------------------------------------------------------------------
        //  Constructors and destructors
        // -------------------------------------------------------------------
        TColThread() = delete;

        TColThread
        (
                    TTestCol* const         pcolToUse
            , const EThreadTypes            eType
            ,       TTextOutStream* const   pstrmOut
        );

        TColThread(const TColThread&) = delete;

        ~TColThread();


        // -------------------------------------------------------------------
        //  Public operators
        // -------------------------------------------------------------------
        TColThread& operator=(const TColThread&) = delete;


    protected   :
        // -------------------------------------------------------------------
        //  Protected, inherited methods
        // -------------------------------------------------------------------
        tCIDLib::EExitCodes eProcess();


    private :
        // -------------------------------------------------------------------
        //  Private data members
        //
        //  m_eType
        //      The type of thread this instance should be, an adder or a
        //      remover.
        //
        //  m_pcolToUse
        //      This is a pointer to the collection that the thread works
        //      on. Its not adopted, just referenced. The type is just a
        //      typedef of a template collection.
        //
        //  m_pstrmOut
        //      The stream to use for text output. Note that text output
        //      is effectively synchronized using the collection lock. Since
        //      the thread only outputs when the collection is locked, the
        //      output is naturally synchronized.
        // -------------------------------------------------------------------
        EThreadTypes    m_eType;
        TTestCol*       m_pcolToUse;
        TTextOutStream* m_pstrmOut;


        // -------------------------------------------------------------------
        //  Do any required macros
        // -------------------------------------------------------------------
        RTTIDefs(TColThread,TThread)
};

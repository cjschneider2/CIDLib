// ----------------------------------------------------------------------------
//  FILE: CIDOrbUC_CfgSrvClientProxy.cpp
//  DATE: Tue, Feb 26 15:38:53 2019 -0500
//    ID: 9BEA088A1BD33D3A-FB3EA0B995167E0E
//
//  This file was generated by the Charmed Quark CIDIDL compiler. Do not make
//  changes by hand, because they will be lost if the file is regenerated.
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------
#include "CIDOrbUC_.hpp"

// ----------------------------------------------------------------------------
// Magic macros
// ----------------------------------------------------------------------------
AdvRTTIDecls(TCIDCfgSrvClientProxy,TOrbClientBase)


// ----------------------------------------------------------------------------
// TCIDCfgSrvClientProxy: Public, static data
// ----------------------------------------------------------------------------
const TString TCIDCfgSrvClientProxy::strInterfaceId(L"9BEA088A1BD33D3A-FB3EA0B995167E0E");
const TString TCIDCfgSrvClientProxy::strScope(L"/CIDLib/CfgSrv/%(h)");
const TString TCIDCfgSrvClientProxy::strAdminBinding(L"/CIDLib/CfgSrv/%(h)/CoreAdmin");
const TString TCIDCfgSrvClientProxy::strBinding(L"/CIDLib/CfgSrv/%(h)/RepoObj");



// ----------------------------------------------------------------------------
// TCIDCfgSrvClientProxy: Constructors and Destructor
// ----------------------------------------------------------------------------
TCIDCfgSrvClientProxy::TCIDCfgSrvClientProxy()
{
}

TCIDCfgSrvClientProxy::
TCIDCfgSrvClientProxy(const TOrbObjId& ooidSrc, const TString& strNSBinding)
{
    #if CID_DEBUG_ON
    if (!ooidSrc.oidKey().bIsInterfaceId(strInterfaceId))
    {
        facCIDOrb().ThrowErr
        (
            CID_FILE
            , CID_LINE
            , kOrbErrs::errcClient_BadIntfId
            , tCIDLib::ESeverities::Failed
            , tCIDLib::EErrClasses::BadParms
            , ooidSrc.oidKey().mhashInterface()
            , strInterfaceId
        );
    }
    #endif
    SetObjId(ooidSrc, strNSBinding, kCIDLib::False);
}

TCIDCfgSrvClientProxy::~TCIDCfgSrvClientProxy()
{
}

// ----------------------------------------------------------------------------
// TCIDCfgSrvClientProxy: Public, non-virtual methods
// ----------------------------------------------------------------------------
tCIDLib::TVoid TCIDCfgSrvClientProxy::AddObject
(
    const TString& strKey
    , const tCIDLib::TCard4 c4BufSz_mbufObjData
    , const THeapBuf& mbufObjData
    , const tCIDLib::TCard4 c4Reserve)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"AddObject");
        ocmdToUse.strmOut() << strKey;
        ocmdToUse.strmOut() << c4BufSz_mbufObjData;
        ocmdToUse.strmOut().c4WriteBuffer(mbufObjData, c4BufSz_mbufObjData);
        ocmdToUse.strmOut() << c4Reserve;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bAddOrUpdate
(
    const TString& strKey
    , tCIDLib::TCard4& c4Version
    , const tCIDLib::TCard4 c4BufSz_mbufObjData
    , const THeapBuf& mbufObjData
    , const tCIDLib::TCard4 c4Reserve)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bAddOrUpdate");
        ocmdToUse.strmOut() << strKey;
        ocmdToUse.strmOut() << c4BufSz_mbufObjData;
        ocmdToUse.strmOut().c4WriteBuffer(mbufObjData, c4BufSz_mbufObjData);
        ocmdToUse.strmOut() << c4Reserve;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> c4Version;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bAllObjectsUnder
(
    const TString& strStartScope
    , TVector<TString>& colPathsFound)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bAllObjectsUnder");
        ocmdToUse.strmOut() << strStartScope;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colPathsFound;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bDeleteObjectIfExists
(
    const TString& strKey)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bDeleteObjectIfExists");
        ocmdToUse.strmOut() << strKey;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bFindNameUnder
(
    const TString& strName
    , const TString& strStartScope
    , TVector<TString>& colPathsFound)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bFindNameUnder");
        ocmdToUse.strmOut() << strName;
        ocmdToUse.strmOut() << strStartScope;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colPathsFound;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bKeyExists
(
    const TString& strKey)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bKeyExists");
        ocmdToUse.strmOut() << strKey;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bKeyExists2
(
    const TString& strKey
    , tCIDLib::TCard4& c4Version)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bKeyExists2");
        ocmdToUse.strmOut() << strKey;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> c4Version;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TBoolean TCIDCfgSrvClientProxy::bReadObject
(
    const TString& strKey
    , tCIDLib::TCard4& c4BufSz_mbufToFill
    , THeapBuf& mbufToFill
    , tCIDLib::TCard4& c4Version)
{
    tCIDLib::TBoolean retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"bReadObject");
        ocmdToUse.strmOut() << strKey;
        ocmdToUse.strmOut() << c4Version;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> c4BufSz_mbufToFill;
        ocmdToUse.strmIn().c4ReadBuffer(mbufToFill, c4BufSz_mbufToFill);
        ocmdToUse.strmIn() >> c4Version;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TCard4 TCIDCfgSrvClientProxy::c4QueryObjectsInScope
(
    const TString& strParScope
    , TVector<TString>& colToFill)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4QueryObjectsInScope");
        ocmdToUse.strmOut() << strParScope;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colToFill;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TCard4 TCIDCfgSrvClientProxy::c4QuerySubScopes
(
    const TString& strParScope
    , TVector<TString>& colToFill)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4QuerySubScopes");
        ocmdToUse.strmOut() << strParScope;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> colToFill;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TCard4 TCIDCfgSrvClientProxy::c4UpdateObject
(
    const TString& strKey
    , const tCIDLib::TCard4 c4BufSz_mbufObjData
    , const THeapBuf& mbufObjData)
{
    tCIDLib::TCard4 retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"c4UpdateObject");
        ocmdToUse.strmOut() << strKey;
        ocmdToUse.strmOut() << c4BufSz_mbufObjData;
        ocmdToUse.strmOut().c4WriteBuffer(mbufObjData, c4BufSz_mbufObjData);
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}

tCIDLib::TVoid TCIDCfgSrvClientProxy::DeleteObject
(
    const TString& strKey)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"DeleteObject");
        ocmdToUse.strmOut() << strKey;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::TVoid TCIDCfgSrvClientProxy::DeleteScope
(
    const TString& strScopeKey)
{
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"DeleteScope");
        ocmdToUse.strmOut() << strScopeKey;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
}

tCIDLib::ELoadRes TCIDCfgSrvClientProxy::eReadObject
(
    const TString& strKey
    , tCIDLib::TCard4& c4BufSz_mbufToFill
    , THeapBuf& mbufToFill
    , tCIDLib::TCard4& c4Version
    , const tCIDLib::TBoolean bThrowIfNot)
{
    tCIDLib::ELoadRes retVal;
    TCmdQItem* pcqiToUse = pcqiGetCmdItem(ooidThis().oidKey());
    TOrbCmd& ocmdToUse = pcqiToUse->ocmdData();
    try
    {
        ocmdToUse.strmOut() << TString(L"eReadObject");
        ocmdToUse.strmOut() << strKey;
        ocmdToUse.strmOut() << c4Version;
        ocmdToUse.strmOut() << bThrowIfNot;
        Dispatch(30000, pcqiToUse);
        ocmdToUse.strmIn().Reset();
        ocmdToUse.strmIn() >> retVal;
        ocmdToUse.strmIn() >> c4BufSz_mbufToFill;
        ocmdToUse.strmIn().c4ReadBuffer(mbufToFill, c4BufSz_mbufToFill);
        ocmdToUse.strmIn() >> c4Version;
        GiveBackCmdItem(pcqiToUse);
    }
    catch(TError& errToCatch)
    {
        GiveBackCmdItem(pcqiToUse);
        errToCatch.AddStackLevel(CID_FILE, CID_LINE);
        throw;
    }
    return retVal;
}



/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for HikPlayerOcx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __HikPlayerOcxidl_h__
#define __HikPlayerOcxidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DHikPlayerOcx_FWD_DEFINED__
#define ___DHikPlayerOcx_FWD_DEFINED__
typedef interface _DHikPlayerOcx _DHikPlayerOcx;

#endif 	/* ___DHikPlayerOcx_FWD_DEFINED__ */


#ifndef ___DHikPlayerOcxEvents_FWD_DEFINED__
#define ___DHikPlayerOcxEvents_FWD_DEFINED__
typedef interface _DHikPlayerOcxEvents _DHikPlayerOcxEvents;

#endif 	/* ___DHikPlayerOcxEvents_FWD_DEFINED__ */


#ifndef __HikPlayerOcx_FWD_DEFINED__
#define __HikPlayerOcx_FWD_DEFINED__

#ifdef __cplusplus
typedef class HikPlayerOcx HikPlayerOcx;
#else
typedef struct HikPlayerOcx HikPlayerOcx;
#endif /* __cplusplus */

#endif 	/* __HikPlayerOcx_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_HikPlayerOcx_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_HikPlayerOcx_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_HikPlayerOcx_0000_0000_v0_0_s_ifspec;


#ifndef __HikPlayerOcxLib_LIBRARY_DEFINED__
#define __HikPlayerOcxLib_LIBRARY_DEFINED__

/* library HikPlayerOcxLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_HikPlayerOcxLib;

#ifndef ___DHikPlayerOcx_DISPINTERFACE_DEFINED__
#define ___DHikPlayerOcx_DISPINTERFACE_DEFINED__

/* dispinterface _DHikPlayerOcx */
/* [uuid] */ 


EXTERN_C const IID DIID__DHikPlayerOcx;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7ae1c05e-73be-4741-9b03-25ddec1cccc2")
    _DHikPlayerOcx : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHikPlayerOcxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DHikPlayerOcx * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DHikPlayerOcx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DHikPlayerOcx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DHikPlayerOcx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DHikPlayerOcx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DHikPlayerOcx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DHikPlayerOcx * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DHikPlayerOcxVtbl;

    interface _DHikPlayerOcx
    {
        CONST_VTBL struct _DHikPlayerOcxVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHikPlayerOcx_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DHikPlayerOcx_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DHikPlayerOcx_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DHikPlayerOcx_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DHikPlayerOcx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DHikPlayerOcx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DHikPlayerOcx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHikPlayerOcx_DISPINTERFACE_DEFINED__ */


#ifndef ___DHikPlayerOcxEvents_DISPINTERFACE_DEFINED__
#define ___DHikPlayerOcxEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DHikPlayerOcxEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DHikPlayerOcxEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("8b69d5cb-662a-423b-b1b0-5060fcbdfd5e")
    _DHikPlayerOcxEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHikPlayerOcxEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DHikPlayerOcxEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DHikPlayerOcxEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DHikPlayerOcxEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DHikPlayerOcxEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DHikPlayerOcxEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DHikPlayerOcxEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DHikPlayerOcxEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DHikPlayerOcxEventsVtbl;

    interface _DHikPlayerOcxEvents
    {
        CONST_VTBL struct _DHikPlayerOcxEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHikPlayerOcxEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DHikPlayerOcxEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DHikPlayerOcxEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DHikPlayerOcxEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DHikPlayerOcxEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DHikPlayerOcxEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DHikPlayerOcxEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHikPlayerOcxEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HikPlayerOcx;

#ifdef __cplusplus

class DECLSPEC_UUID("872b31ba-01b5-4264-93e0-169d9c298c06")
HikPlayerOcx;
#endif
#endif /* __HikPlayerOcxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



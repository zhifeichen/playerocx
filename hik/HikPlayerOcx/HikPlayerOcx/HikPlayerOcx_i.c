

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_HikPlayerOcxLib,0x29eee6fd,0x9b6e,0x4b97,0xaa,0xf5,0x6a,0x7b,0x7a,0x79,0x5a,0xd4);


MIDL_DEFINE_GUID(IID, DIID__DHikPlayerOcx,0x7ae1c05e,0x73be,0x4741,0x9b,0x03,0x25,0xdd,0xec,0x1c,0xcc,0xc2);


MIDL_DEFINE_GUID(IID, DIID__DHikPlayerOcxEvents,0x8b69d5cb,0x662a,0x423b,0xb1,0xb0,0x50,0x60,0xfc,0xbd,0xfd,0x5e);


MIDL_DEFINE_GUID(CLSID, CLSID_HikPlayerOcx,0x872b31ba,0x01b5,0x4264,0x93,0xe0,0x16,0x9d,0x9c,0x29,0x8c,0x06);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif




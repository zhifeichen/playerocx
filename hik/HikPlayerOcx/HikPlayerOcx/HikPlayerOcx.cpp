// HikPlayerOcx.cpp: CHikPlayerOcxApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "HikPlayerOcx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CHikPlayerOcxApp theApp;

const GUID CDECL _tlid = {0x29eee6fd,0x9b6e,0x4b97,{0xaa,0xf5,0x6a,0x7b,0x7a,0x79,0x5a,0xd4}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CHikPlayerOcxApp::InitInstance - DLL 初始化

BOOL CHikPlayerOcxApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。

	}

	return bInit;
}



// CHikPlayerOcxApp::ExitInstance - DLL 终止

int CHikPlayerOcxApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}

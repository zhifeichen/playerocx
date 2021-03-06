// HikPlayerPropPage.cpp : CHikPlayerPropPage 属性页类的实现。

#include "stdafx.h"
#include "HikPlayerOcx.h"
#include "HikPlayerPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CHikPlayerPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CHikPlayerPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHikPlayerPropPage, "MFCACTIVEXCONT.HikPlayerPropPage.1",
	0x5eca8f88,0x1151,0x4be3,0xaf,0x8b,0xbd,0x44,0xb8,0x99,0x76,0xb0)

// CHikPlayerPropPage::CHikPlayerPropPageFactory::UpdateRegistry -
// 添加或移除 CHikPlayerPropPage 的系统注册表项

BOOL CHikPlayerPropPage::CHikPlayerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HIKPLAYEROCX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CHikPlayerPropPage::CHikPlayerPropPage - 构造函数

CHikPlayerPropPage::CHikPlayerPropPage() :
	COlePropertyPage(IDD, IDS_HIKPLAYEROCX_PPG_CAPTION)
{
}

// CHikPlayerPropPage::DoDataExchange - 在页和属性间移动数据

void CHikPlayerPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CHikPlayerPropPage 消息处理程序

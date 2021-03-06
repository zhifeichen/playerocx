// HikPlayerCtrl.cpp : CHikPlayerCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "HikPlayerOcx.h"
#include "HikPlayerCtrl.h"
#include "HikPlayerPropPage.h"
#include "afxdialogex.h"

#include "HCNetSDK.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser)
{
    char tempbuf[256] = { 0 };
    switch (dwType)
    {
    case EXCEPTION_RECONNECT:    //预览时重连
        printf("----------reconnect--------%lld\n", time(NULL));
        break;
    default:
        break;
    }
}

IMPLEMENT_DYNCREATE(CHikPlayerCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CHikPlayerCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CHikPlayerCtrl, COleControl)
	DISP_FUNCTION_ID(CHikPlayerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
    DISP_FUNCTION_ID(CHikPlayerCtrl, "StartPlay", dispidStartPlay, StartPlay, VT_EMPTY, VTS_NONE)
    DISP_FUNCTION_ID(CHikPlayerCtrl, "StopPlay", dispidStopPlay, StopPlay, VT_EMPTY, VTS_NONE)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "HostIP", dispidHostIP, m_HostIP, OnHostIPChanged, VT_BSTR)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "HostPort", dispidHostPort, m_HostPort, OnHostPortChanged, VT_UI2)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "UserName", dispidUserName, m_UserName, OnUserNameChanged, VT_BSTR)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "Password", dispidPassword, m_Password, OnPasswordChanged, VT_BSTR)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "Channel", dispidChannel, m_Channel, OnChannelChanged, VT_I4)
    DISP_PROPERTY_NOTIFY_ID(CHikPlayerCtrl, "StreamType", dispidStreamType, m_StreamType, OnStreamTypeChanged, VT_I4)
    DISP_FUNCTION_ID(CHikPlayerCtrl, "Init", dispidInit, Init, VT_BOOL, VTS_NONE)
    DISP_FUNCTION_ID(CHikPlayerCtrl, "Cleanup", dispidCleanup, Cleanup, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CHikPlayerCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CHikPlayerCtrl, 1)
	PROPPAGEID(CHikPlayerPropPage::guid)
END_PROPPAGEIDS(CHikPlayerCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHikPlayerCtrl, "MFCACTIVEXCONTRO.HikPlayerCtrl.1",
	0x872b31ba,0x01b5,0x4264,0x93,0xe0,0x16,0x9d,0x9c,0x29,0x8c,0x06)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CHikPlayerCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DHikPlayerOcx = {0x7ae1c05e,0x73be,0x4741,{0x9b,0x03,0x25,0xdd,0xec,0x1c,0xcc,0xc2}};
const IID IID_DHikPlayerOcxEvents = {0x8b69d5cb,0x662a,0x423b,{0xb1,0xb0,0x50,0x60,0xfc,0xbd,0xfd,0x5e}};

// 控件类型信息

static const DWORD _dwHikPlayerOcxOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHikPlayerCtrl, IDS_HIKPLAYEROCX, _dwHikPlayerOcxOleMisc)

// CHikPlayerCtrl::CHikPlayerCtrlFactory::UpdateRegistry -
// 添加或移除 CHikPlayerCtrl 的系统注册表项

BOOL CHikPlayerCtrl::CHikPlayerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HIKPLAYEROCX,
			IDB_HIKPLAYEROCX,
			afxRegApartmentThreading,
			_dwHikPlayerOcxOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CHikPlayerCtrl::CHikPlayerCtrl - 构造函数

CHikPlayerCtrl::CHikPlayerCtrl():
    m_HostPort(8000), m_Channel(1), m_StreamType(0)
{
	InitializeIIDs(&IID_DHikPlayerOcx, &IID_DHikPlayerOcxEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CHikPlayerCtrl::~CHikPlayerCtrl - 析构函数

CHikPlayerCtrl::~CHikPlayerCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CHikPlayerCtrl::OnDraw - 绘图函数

void CHikPlayerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH)));
	//pdc->Ellipse(rcBounds);
}

// CHikPlayerCtrl::DoPropExchange - 持久性支持

void CHikPlayerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CHikPlayerCtrl::OnResetState - 将控件重置为默认状态

void CHikPlayerCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CHikPlayerCtrl::AboutBox - 向用户显示“关于”框

void CHikPlayerCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_HIKPLAYEROCX);
	dlgAbout.DoModal();
}


// CHikPlayerCtrl 消息处理程序


void CHikPlayerCtrl::StartPlay()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加调度处理程序代码
    //设置异常消息回调函数
    NET_DVR_SetExceptionCallBack_V30(0, NULL, g_ExceptionCallBack, NULL);

    //登录参数，包括设备地址、登录用户、密码等
    NET_DVR_USER_LOGIN_INFO struLoginInfo = { 0 };
    struLoginInfo.bUseAsynLogin = 0; //同步登录方式
    strcpy_s(struLoginInfo.sDeviceAddress, m_HostIP); //设备IP地址
    struLoginInfo.wPort = m_HostPort; //设备服务端口
    strcpy_s(struLoginInfo.sUserName, m_UserName); //设备登录用户名
    strcpy_s(struLoginInfo.sPassword, m_Password); //设备登录密码

                                                 //设备信息, 输出参数
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = { 0 };

    lUserID = NET_DVR_Login_V40(&struLoginInfo, &struDeviceInfoV40);
    if (lUserID < 0)
    {
        CString msg;
        msg.Format("Login failed, error code: %d\nuser name: %s, password: %s", 
            NET_DVR_GetLastError(),
            m_UserName, m_Password);
        AfxMessageBox(msg);
        printf("Login failed, error code: %d\n", NET_DVR_GetLastError());
        NET_DVR_Cleanup();
        return;
    }

    //---------------------------------------
    //启动预览并设置回调数据流
    HWND hWnd = GetSafeHwnd();     //获取窗口句柄
    NET_DVR_PREVIEWINFO struPlayInfo = { 0 };
    struPlayInfo.hPlayWnd = hWnd;         //需要SDK解码时句柄设为有效值，仅取流不解码时可设为空
    struPlayInfo.lChannel = m_Channel;       //预览通道号 33
    struPlayInfo.dwStreamType = m_StreamType;       //0-主码流，1-子码流，2-码流3，3-码流4，以此类推
    struPlayInfo.dwLinkMode = 0;       //0- TCP方式，1- UDP方式，2- 多播方式，3- RTP方式，4-RTP/RTSP，5-RSTP/HTTP
    struPlayInfo.bBlocked = 1;       //0- 非阻塞取流，1- 阻塞取流

    lRealPlayHandle = NET_DVR_RealPlay_V40(lUserID, &struPlayInfo, NULL, NULL);
    if (lRealPlayHandle < 0)
    {
        CString msg;
        msg.Format("NET_DVR_RealPlay_V40 error, error code: %d\n", NET_DVR_GetLastError());
        AfxMessageBox(msg);
        printf("NET_DVR_RealPlay_V40 error\n");
        NET_DVR_Logout(lUserID);
        NET_DVR_Cleanup();
        return;
    }

}


void CHikPlayerCtrl::StopPlay()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加调度处理程序代码
    //关闭预览
    NET_DVR_StopRealPlay(lRealPlayHandle);
    //注销用户
    NET_DVR_Logout(lUserID);
    Invalidate();
}


void CHikPlayerCtrl::OnHostIPChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码
    //AfxMessageBox(TEXT("host ip changed!"));

    SetModifiedFlag();
}


void CHikPlayerCtrl::OnHostPortChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码

    SetModifiedFlag();
}


void CHikPlayerCtrl::OnUserNameChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码

    SetModifiedFlag();
}


void CHikPlayerCtrl::OnPasswordChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码

    SetModifiedFlag();
}


void CHikPlayerCtrl::OnChannelChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码

    SetModifiedFlag();
}


void CHikPlayerCtrl::OnStreamTypeChanged()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加属性处理程序代码

    SetModifiedFlag();
}


VARIANT_BOOL CHikPlayerCtrl::Init()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加调度处理程序代码
    BOOL ret;
    while (1) {
        // 初始化
        ret = NET_DVR_Init();
        if (!ret) break;
        //设置连接时间与重连时间
        ret = NET_DVR_SetConnectTime(2000, 1);
        if (!ret) break;
        ret = NET_DVR_SetReconnect(10000, true);
        break;
    }
    if (ret)
        return VARIANT_TRUE;
    else
        return VARIANT_FALSE;
}


void CHikPlayerCtrl::Cleanup()
{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

    // TODO: 在此添加调度处理程序代码

    //释放SDK资源
    NET_DVR_Cleanup();
}

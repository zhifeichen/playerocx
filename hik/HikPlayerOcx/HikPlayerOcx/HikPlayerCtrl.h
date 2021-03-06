#pragma once

// HikPlayerCtrl.h : CHikPlayerCtrl ActiveX 控件类的声明。


// CHikPlayerCtrl : 请参阅 HikPlayerCtrl.cpp 了解实现。

class CHikPlayerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHikPlayerCtrl)

// 构造函数
public:
	CHikPlayerCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CHikPlayerCtrl();

	DECLARE_OLECREATE_EX(CHikPlayerCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CHikPlayerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHikPlayerCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CHikPlayerCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
        dispidCleanup = 10L,
        dispidInit = 9L,
        dispidStreamType = 8,
        dispidChannel = 7,
        dispidPassword = 6,
        dispidUserName = 5,
        dispidHostPort = 4,
        dispidHostIP = 3,
        dispidStopPlay = 2L,
        dispidStartPlay = 1L
    };
protected:
    void StartPlay();
    void StopPlay();

private:
    // 注册用户
    LONG lUserID;
    LONG lRealPlayHandle;
protected:
    void OnHostIPChanged();
    CString m_HostIP;
    void OnHostPortChanged();
    USHORT m_HostPort;
    void OnUserNameChanged();
    CString m_UserName;
    void OnPasswordChanged();
    CString m_Password;
    void OnChannelChanged();
    LONG m_Channel;
    void OnStreamTypeChanged();
    LONG m_StreamType;
    VARIANT_BOOL Init();
    void Cleanup();
};


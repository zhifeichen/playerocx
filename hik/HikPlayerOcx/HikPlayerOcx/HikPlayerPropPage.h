#pragma once

// HikPlayerPropPage.h: CHikPlayerPropPage 属性页类的声明。


// CHikPlayerPropPage : 请参阅 HikPlayerPropPage.cpp 了解实现。

class CHikPlayerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHikPlayerPropPage)
	DECLARE_OLECREATE_EX(CHikPlayerPropPage)

// 构造函数
public:
	CHikPlayerPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_HIKPLAYEROCX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};


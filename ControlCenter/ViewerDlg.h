#pragma once
#include "rdpviewer1.h"
#include "resource.h"
#include "FullScreenOpDlg.h"


// CViewerDlg 对话框
// 这是当对于一个监控会话条目点击右键“打开监控窗口"时弹出的对话框
// 用于单独的查看一个监控对象的桌面

class CViewerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CViewerDlg)

public:
	CViewerDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CViewerDlg();

// 对话框数据
	enum { IDD = IDD_VIEWER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


private:
	BOOL m_bFullScrMode;
	CFullScreenOpDlg m_fsOpDlg;


public:
	CRdpviewer1 m_Viewer;

	

	virtual BOOL OnInitDialog();


	void Connect(LPTSTR ticket,LPTSTR username=_T("sun"),LPTSTR userpass=_T(""));
	void Disconnect();
	void SetFullScreen(BOOL bFull=TRUE);

	afx_msg void OnSize(UINT nType, int cx, int cy);	
	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg LRESULT OnExitFullScreen(WPARAM, LPARAM);
};

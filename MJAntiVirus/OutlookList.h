#if !defined(AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_)
#define AFX_OUTINTERFACEDLG_H__0D6A438A_04F2_41CC_8F5E_00046FA0C248__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutlookList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutlookList window
#include "ListButton.h"
#define LISTID = 2010;

//����˫���б���ͼ��Ļص�����
typedef void(ItemDlbFun)(const CListCtrl* pListCtrl,int nItemIndex);

class COutlookList : public CListCtrl
{
// Construction
public:
	COutlookList();
	CPtrArray m_pButton; //��ť����
	UINT m_ButtonCount ; //��ť����
	UINT m_LeftMargin; //ͼ���б���ʾ����߾�
	CListCtrl m_ClientList; //�ڿͻ�������ʾ��ͼ��
	ItemDlbFun* pItemDlbFun; //��ͼ���˫���¼�
// Attributes
public:

// Operations

private:
	UINT m_ButtonHeight; //��ť�߶�
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutlookList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetImageLists(CImageList* pImagelist);
	void ShowButtonItems(UINT nIndex);
	void AddButtonItems(UINT nIndex,CString& strItem);
	UINT GetBtmBtnHeight();
	CRect GetListClientRect();
	int GetBtmTopIndex();
	UINT GetNumCurToBtmBtn(UINT nIndex);
	UINT GetTopButtonHeight();
	UINT CommandToIndex(UINT nID);
	void OnButtonDown(UINT bIndex, UINT nID);
	CRect GetAddButtonRect();
	void AddButton(LPCSTR text,UINT uID);
	virtual ~COutlookList();

	// Generated message map functions
protected:
	//{{AFX_MSG(COutlookList)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTLOOKLIST_H__C190DC04_038D_4AB9_994F_804C7DCB9E28__INCLUDED_)

// IconMenu1.h: interface for the CIconMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_)
#define AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

const int MAX_MENUCOUNT = 20,ITEMHEIGHT = 26,ITEMWIDTH= 120; //�˵�������


/*************************************
CMenuItemInfo�ṹ���ڼ�¼�˵�����Ϣ
*************************************/
struct CMenuItemInfo
{
	CString m_ItemText;//�˵����ı�
	int m_IconIndex;//�˵�������
	int m_ItemID;//�˵���� -2����˵�,-1����ʽ�˵�,0�ָ���,������ͨ�˵�
};

class CIconMenu : public CMenu  
{
public:
	CMenuItemInfo m_ItemLists[MAX_MENUCOUNT]; //�˵�����Ϣ
	int m_index; //��ʱ����
	int m_iconindex;
	BOOL m_isdrawtitle;
	CFont m_titlefont;
	CIconMenu();
	int m_save;
	BOOL ChangeMenuItem(CMenu* m_menu,BOOL m_Toped = FALSE);
	BOOL  AttatchMenu(HMENU m_hmenu);
	void DrawItemText(CDC* m_pdc,LPSTR str,CRect m_rect);
	void DrawTopMenu(CDC* m_pdc,CRect m_rect,BOOL m_selected = FALSE); //���ƶ���˵�
	void DrawSeparater(CDC* m_pdc,CRect m_rect);//���Ʒָ���
	void DrawComMenu(CDC* m_pdc,CRect m_rect,COLORREF m_fromcolor,COLORREF m_tocolor, BOOL m_selected = FALSE);
	void DrawMenuIcon(CDC* m_pdc,CRect m_rect,int m_icon );
	void DrawMenuTitle(CDC* m_pdc,CRect m_rect,CString m_title);
	//override memu's viutual method
	virtual ~CIconMenu();
	virtual void MeasureItem( LPMEASUREITEMSTRUCT lpStruct);//���ò˵����С
	virtual void DrawItem(LPDRAWITEMSTRUCT lpStruct);//�ػ�˵���

};

#endif // !defined(AFX_ICONMENU1_H__FAA8B855_EE72_4332_96D7_73F8FA07E521__INCLUDED_)

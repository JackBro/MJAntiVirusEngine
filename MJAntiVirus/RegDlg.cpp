// RegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mjantivirus.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog


CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegDlg)
	DDX_Control(pDX, IDC_LAB_REGSTATE, m_lab_regstate);
	DDX_Control(pDX, IDC_EDIT_REGCODE, m_edit_regcode);
	DDX_Control(pDX, IDC_BTN_REG, m_btn_reg);
	DDX_Control(pDX, IDC_BTN_QUITREG, m_btn_quitreg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegDlg, CDialog)
	//{{AFX_MSG_MAP(CRegDlg)
	ON_BN_CLICKED(IDC_BTN_REG, OnBtnReg)
	ON_BN_CLICKED(IDC_BTN_QUITREG, OnBtnQuitreg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegDlg message handlers

BOOL CRegDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	pMysocket = new CMysocket(this); //�����׽��ֶ���
	if (!pMysocket->Create()) //�����׽���
	{
		delete pMysocket;
		MessageBox("�׽��ִ���ʧ��.");
		this->m_lab_regstate.SetWindowText("���ؼ�����������⡣");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.SetReadOnly();
		this->m_btn_quitreg.SetFocus();
		return FALSE;
	}
	//connect
	int port;
	port = 5555; //��ȡ�˿�
	if  (! pMysocket->Connect("127.0.0.1",port)) //���ӷ�����
	{
		MessageBox("���ӷ�����ʧ��!");
		this->m_lab_regstate.SetWindowText("���ӷ�����ʧ��! ������δ�����򱾵ؼ��������δ���ӡ�");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.SetReadOnly();
		this->m_btn_quitreg.SetFocus();
		return FALSE;
	}
	else
	{
		//MessageBox("���ӳɹ�������");
		CString str;
		str="L"+this->RegisterProgram();
		pMysocket->Send(str.GetBuffer(str.GetLength()),str.GetLength());	
		//this->m_lab_regstate.SetWindowText("���ӷ������ɹ�������дע���롣");	
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegDlg::OnBtnReg() 
{
	// TODO: Add your control notification handler code here
	CString temp,temp2;
	this->m_edit_regcode.GetWindowText(temp2);
	temp='R';
	temp+=temp2;
	temp+=this->RegisterProgram();
	//MessageBox(temp);
	int num = pMysocket->Send(temp.GetBuffer(temp.GetLength()),temp.GetLength());
}

void CRegDlg::OnBtnQuitreg() 
{
	// TODO: Add your control notification handler code here
	this->pMysocket->Close();
	delete this->pMysocket;
	this->DestroyWindow();
}

void CRegDlg::ReceiveData()
{
	char buffer[200];
	//���մ���������
	int factdata =  pMysocket->Receive(buffer,200);
	buffer[factdata] = '\0';
	CString str;
	str.Format("%s",buffer);
	if(str=="HasRegister")
	{
		this->m_lab_regstate.SetWindowText("���������ע�ᡣ");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.EnableWindow(FALSE);
	}
	else if(str=="HasNotRegister")
	{
		this->m_lab_regstate.SetWindowText("���ӷ������ɹ�������дע���롣");
		this->m_btn_reg.EnableWindow();
		this->m_edit_regcode.EnableWindow();
	}
	else if(str=="SuccessReg")
	{
		MessageBox("ע��ɹ���");
		this->m_lab_regstate.SetWindowText("ע��ɹ���");
		this->m_btn_reg.EnableWindow(FALSE);
		this->m_edit_regcode.EnableWindow(FALSE);
	}
	else if(str=="RegisterFailByErrorRegCode")
	{
		MessageBox("ע��ʧ�ܣ�");
		this->m_lab_regstate.SetWindowText("ע��ʧ�ܣ�������ע�������");
		this->m_btn_reg.EnableWindow();
		this->m_edit_regcode.EnableWindow();
	}
}
CString CRegDlg::RegisterProgram()
{
 	unsigned long s1,s2;       
	CString MyCpuID,CPUID1,CPUID2;   
 	__asm
 	{   
		push eax
		push edx
 		mov eax,01h
 		xor edx,edx
 		cpuid
 		mov s1,edx
 		mov s2,eax
		pop edx
		pop eax
	}   
	CPUID1.Format("%08X%08X",s1,s2);   
	__asm
	{   
		push eax
		push ecx
		push edx
		mov eax,03h   
		xor ecx,ecx   
		xor edx,edx   
		cpuid   
		mov s1,edx   
		mov s2,ecx
		pop edx
		pop ecx
		pop eax
	}   
	CPUID2.Format("%08X%08X",s1,s2);   
	MyCpuID=CPUID1+CPUID2;
	DWORD ser;
	char namebuf[128];
	char filebuf[128];
	::GetVolumeInformation("c:\\",namebuf,128,&ser,0,0,filebuf,128);
	CString strdisk;
	strdisk.Format("%d",ser);
	CString strmachine;
	strmachine=MyCpuID.Mid(13,5); //��MyCpuID�ĵ�13λ��ʼȡ5��
	strmachine+=strdisk.Mid(3,5);//��strdisk�ĵ�3λ��ʼȡ5��,�ϲ����ɻ�����
	return strmachine;
}

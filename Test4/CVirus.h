#include <afxcoll.h> //CDWordArra���CObArray���ͷ�ļ�
#define MJVIRUSSIGNVERSION  585
#define MJVIRUSVERSION  595
class CVirusSignature: public CObject  //������������
{
	DECLARE_SERIAL(CVirusSignature)//Serialize���������ô˺�
	//IMPLEMENT_SERIAL(CVirusSignature, CObject, 1 ) �ú����//VirusSignature.cpp�ļ�����
private:
	DWORD m_vsOffset;  //���ļ���ʼλ�õ�ƫ����
	DWORD m_vsSize;   //�������ֽڳ���
	CDWordArray m_vs;        //�����봮
public:
	CVirusSignature();     //���캯��
	DWORD GetvsOffset();  //��ȡƫ����
	DWORD GetvsSize();    //��ȡ�����볤��
	BOOL vsCreate(DWORD, DWORD, CDWordArray&);//����һ�������롣0���ɹ���1�ɹ� ע��˴�������CDWordArray&������û��=����
	BOOL vsCompare(CDWordArray&);  //�жϴ��ļ���ȡ�����ֽڴ��Ƿ���������ƥ�䡣0��ƥ�䣬1ƥ��
	void Serialize(CArchive&);  //��дSerialize����
	BOOL WriteVS(CArchive&);  //�Ѷ���д���ļ���0���ɹ���1�ɹ�
	BOOL ReadVS(CArchive&);  //���ļ���ȡ����0���ɹ���1�ɹ�
};
class CVirus: public CObject  //������
{
	DECLARE_SERIAL(CVirus )
	//IMPLEMENT_SERIAL(CVirus, CObject, 1 ) �ú����Virus.cpp�ļ�����
private:
	CString m_vName; //�ò�����
	DWORD m_vscount; //�ò�������������
	CObArray m_vsArray; //�������������
public:
	
	CVirus();	//���캯��
	BOOL LoadFromFile(CString);  //���ļ��ж�ȡ������Ϣ�������롣0���ɹ���1�ɹ�
	BOOL WriteToFile(CString);  //���ļ�д��ò�������0���ɹ���1�ɹ�
	BOOL vMatch(CFile&); //��Ŀ���ļ��Ƚϣ��ж��Ƿ�Ϊ������0���ǣ�1��
	CString GetvName();  //���ظò����Ĳ������ơ�
	DWORD GetvsCount(); //���ظò�����������������
	BOOL vCreate(CString,DWORD,CObArray&); //����һ����������0���ɹ���1�ɹ�
	BOOL KillVirus(CFile&); //��Ŀ���ļ��������ƻ�����0���ɹ���1�ɹ�
	void Serialize(CArchive&);  //��дSerialize����
};

#if !defined(AFX_AGENTCTLSPEECHINPUT_H__5EA05D36_4B51_45D2_A861_767C40227325__INCLUDED_)
#define AFX_AGENTCTLSPEECHINPUT_H__5EA05D36_4B51_45D2_A861_767C40227325__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CAgentCtlSpeechInput wrapper class

class CAgentCtlSpeechInput : public COleDispatchDriver
{
public:
	CAgentCtlSpeechInput() {}		// Calls COleDispatchDriver default constructor
	CAgentCtlSpeechInput(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAgentCtlSpeechInput(const CAgentCtlSpeechInput& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	BOOL GetEnabled();
	CString GetLanguage();
	CString GetHotKey();
	BOOL GetInstalled();
	CString GetEngine();
	void SetEngine(LPCTSTR lpszNewValue);
	BOOL GetListeningTip();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGENTCTLSPEECHINPUT_H__5EA05D36_4B51_45D2_A861_767C40227325__INCLUDED_)
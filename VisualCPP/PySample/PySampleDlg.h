
// PySampleDlg.h : ��� ����
//

#pragma once


// CPySampleDlg ��ȭ ����
class CPySampleDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPySampleDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PYSAMPLE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton01();
	afx_msg void OnBnClickedButton02();
	afx_msg void OnBnClickedButton03();
	afx_msg void OnBnClickedButton04();
	afx_msg void OnBnClickedButton05();
	afx_msg void OnBnClickedButton06();
	afx_msg void OnBnClickedButton07();
	afx_msg void OnBnClickedButton08();
};

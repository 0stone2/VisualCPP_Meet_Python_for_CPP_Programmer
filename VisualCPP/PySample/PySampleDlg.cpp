
// PySampleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "PySample.h"
#include "PySampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define __PYTHON_35__


#if defined(__PYTHON_35__)
	#if defined(_DEBUG)
		#pragma comment(lib, "C:/Script/Python/libs/python35_d.lib")
	#else
		#pragma comment(lib, "C:/Script/Python/libs/python35.lib")
	#endif
#endif

#include "C:/Script/Python/include/Python.h"



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPySampleDlg 대화 상자



CPySampleDlg::CPySampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PYSAMPLE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPySampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPySampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON01, &CPySampleDlg::OnBnClickedButton01)
	ON_BN_CLICKED(IDC_BUTTON02, &CPySampleDlg::OnBnClickedButton02)
	ON_BN_CLICKED(IDC_BUTTON03, &CPySampleDlg::OnBnClickedButton03)
	ON_BN_CLICKED(IDC_BUTTON04, &CPySampleDlg::OnBnClickedButton04)
	ON_BN_CLICKED(IDC_BUTTON05, &CPySampleDlg::OnBnClickedButton05)
	ON_BN_CLICKED(IDC_BUTTON06, &CPySampleDlg::OnBnClickedButton06)
	ON_BN_CLICKED(IDC_BUTTON07, &CPySampleDlg::OnBnClickedButton07)
	ON_BN_CLICKED(IDC_BUTTON08, &CPySampleDlg::OnBnClickedButton08)
END_MESSAGE_MAP()


// CPySampleDlg 메시지 처리기

BOOL CPySampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPySampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPySampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CPySampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Append_Script_Path()
{
	TCHAR szCurrentDir[MAX_PATH]{ 0, };
	TCHAR szScriptDir[MAX_PATH]{ 0, };

	GetCurrentDirectory(MAX_PATH, szCurrentDir);

	_stprintf_s(szScriptDir, MAX_PATH, _T("%s\\Script"), szCurrentDir);

	PySys_SetPath(szScriptDir);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 1 장 - C에서 Python 호출하기
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 1 - Python 스크립트 파일 실행하기
//
void CPySampleDlg::OnBnClickedButton01()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pModule{ NULL };
	
	__try {
		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample01");
		if (NULL == pModule) __leave;

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess) 
			OutputDebugString(_T("Python OK\n"));
		else 
			OutputDebugString(_T("Python Error\n"));

		if (NULL != pModule) Py_DECREF(pModule);
		Py_Finalize();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 2 - Python 전역 변수 조작하기
//
void CPySampleDlg::OnBnClickedButton02()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pModule{ NULL };
	PyObject *	pWelcomMessage{ NULL };
	PyObject *	pWhoamI{ NULL };
	PyObject *	pVersion{ NULL };
	PyObject *	pNewVersion{ NULL };

	char *		szWelcomMessage{ NULL };
	char *		szWhoamI{ NULL };
	long		nVersion{ 0 };

	char		szDbgString[MAX_PATH]{ 0, };

	__try {
		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample02");
		if (NULL == pModule) __leave;

		pWelcomMessage = PyObject_GetAttrString(pModule, "szWelcomMessage");
		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		pVersion = PyObject_GetAttrString(pModule, "nVersion");

		PyArg_Parse(pWelcomMessage, "s", &szWelcomMessage);
		PyArg_Parse(pWhoamI, "s", &szWhoamI);
		PyArg_Parse(pVersion, "l", &nVersion);

		sprintf_s(szDbgString, "szWelcomMessage = %s\n", szWelcomMessage);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "nVersion = %d\n", nVersion);
		OutputDebugStringA(szDbgString);


		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));

		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pWelcomMessage) Py_DECREF(pWelcomMessage);
		if (NULL != pWhoamI) Py_DECREF(pWhoamI);
		if (NULL != pVersion) Py_DECREF(pVersion);
		if (NULL != pNewVersion) Py_DECREF(pNewVersion);

		bSuccess = FALSE;
		pModule = NULL;
		pWelcomMessage = NULL;
		pWhoamI = NULL;
		pVersion = NULL;
		pNewVersion = NULL;

		szWelcomMessage = NULL;
		szWhoamI = NULL;
		nVersion = 0;

		Py_Finalize();
	}
	exit(0);

	__try {
		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample02");
		if (NULL == pModule) __leave;



		pNewVersion = Py_BuildValue("l", 3);
		PyObject_SetAttrString(pModule, "nVersion", pNewVersion);



		pWelcomMessage = PyObject_GetAttrString(pModule, "szWelcomMessage");
		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		pVersion = PyObject_GetAttrString(pModule, "nVersion");

		PyArg_Parse(pWelcomMessage, "s", &szWelcomMessage);
		PyArg_Parse(pWhoamI, "s", &szWhoamI);
		PyArg_Parse(pVersion, "l", &nVersion);

		sprintf_s(szDbgString, "szWelcomMessage = %s\n", szWelcomMessage);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "szWhoamI = %s\n", szWhoamI);
		OutputDebugStringA(szDbgString);

		sprintf_s(szDbgString, "nVersion = %d\n", nVersion);
		OutputDebugStringA(szDbgString);

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));

		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pWelcomMessage) Py_DECREF(pWelcomMessage);
		if (NULL != pWhoamI) Py_DECREF(pWhoamI);
		if (NULL != pVersion) Py_DECREF(pVersion);
		if (NULL != pNewVersion) Py_DECREF(pNewVersion);

		bSuccess = FALSE;
		pModule = NULL;
		pWelcomMessage = NULL;
		pWhoamI = NULL;
		pVersion = NULL;
		pNewVersion = NULL;

		Py_Finalize();
	}
}



void DontWriteByteCode(BOOL bYes)
{
	if (TRUE == bYes)
	{
		PySys_SetObject("dont_write_bytecode", Py_True);
	}
	else
	{
		PySys_SetObject("dont_write_bytecode", Py_False);
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 3 - Python 함수 호출하기
//
void CPySampleDlg::OnBnClickedButton03()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pModule{ NULL };
	PyObject *	pWelcomMessage{ NULL };
	PyObject *	pWhoamI{ NULL };
	PyObject *	pFunction_01{ NULL };
	PyObject *	pFunction_02{ NULL };
	PyObject *	pFunction_03{ NULL };
	PyObject *	pFunction_04{ NULL };
	PyObject *	pFunction_05{ NULL };
	PyObject *	pArgument{ NULL };

	PyObject *	pReturn{ NULL };
	char *		szWelcomMessage{ NULL };
	char *		szWhoamI{ NULL };
	char *		szReturnString{ NULL };
	BOOL		bBoolean{ FALSE };

	__try {
		Py_Initialize();

		Append_Script_Path();
		DontWriteByteCode(TRUE);


		pModule = PyImport_ImportModule("Sample03");
		if (NULL == pModule) __leave;

		pWelcomMessage = PyObject_GetAttrString(pModule, "szWelcomMessage");
		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");


		PyArg_Parse(pWelcomMessage, "s", &szWelcomMessage);
		PyArg_Parse(pWhoamI, "s", &szWhoamI);


		//////////////////////////////////////////////////////////////
		//
		// Call myfunc_1
		// 
		pFunction_01 = PyObject_GetAttrString(pModule, "myfunc_1");
		if (NULL == pFunction_01) __leave;

		pReturn = PyObject_CallObject(pFunction_01, NULL);
		if (Py_None != pReturn) __leave;
		//if (None != Py_TYPE(pReturn)) __leave;

		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		PyArg_Parse(pWhoamI, "s", &szWhoamI);



		//////////////////////////////////////////////////////////////
		//
		// Call myfunc_2
		//
		pFunction_02 = PyObject_GetAttrString(pModule, "myfunc_2");
		if (NULL == pFunction_02) __leave;

		pReturn = PyObject_CallObject(pFunction_02, NULL);
		if (NULL == pReturn) __leave;
		if (FALSE == PyUnicode_Check(pReturn)) __leave;
		PyArg_Parse(pReturn, "s", &szReturnString);

		/*
		wchar_t *pString = PyUnicode_AsWideCharString(pReturn, NULL);
		PyMem_Free(pString);
		*/

		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		PyArg_Parse(pWhoamI, "s", &szWhoamI);


		//////////////////////////////////////////////////////////////
		//
		// Call myfunc_3
		//
		pFunction_03 = PyObject_GetAttrString(pModule, "myfunc_3");
		if (NULL == pFunction_03) __leave;

		pReturn = PyObject_CallObject(pFunction_03, NULL);
		if (NULL == pReturn) __leave;
		if (FALSE == PyTuple_Check(pReturn)) __leave;
		PyArg_Parse(PyTuple_GetItem(pReturn, 0), "s", &szReturnString);
		PyArg_Parse(PyTuple_GetItem(pReturn, 1), "p", &bBoolean);

		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		PyArg_Parse(pWhoamI, "s", &szWhoamI);




		//////////////////////////////////////////////////////////////
		//
		// Call myfunc_4
		//
		pFunction_04 = PyObject_GetAttrString(pModule, "myfunc_4");
		if (NULL == pFunction_04) __leave;
		pArgument = PyTuple_Pack(1, PyUnicode_FromFormat("%s", "myfunc_4"));
		pReturn = PyObject_CallObject(pFunction_04, pArgument);
		if (NULL != pArgument) Py_DECREF(pArgument);
		pArgument = NULL;
		if (NULL == pReturn) __leave;
		if (FALSE == PyTuple_Check(pReturn)) __leave;
		PyArg_Parse(PyTuple_GetItem(pReturn, 0), "s", &szReturnString);
		PyArg_Parse(PyTuple_GetItem(pReturn, 1), "p", &bBoolean);

		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		PyArg_Parse(pWhoamI, "s", &szWhoamI);



		//////////////////////////////////////////////////////////////
		//
		// Call myfunc_5
		//
		pFunction_05 = PyObject_GetAttrString(pModule, "myfunc_5");
		if (NULL == pFunction_05) __leave;
		pArgument = PyTuple_Pack(2, PyUnicode_FromFormat("%s", "myfunc_5"), Py_True);
		pReturn = PyObject_CallObject(pFunction_05, pArgument);
		if (NULL != pArgument) Py_DECREF(pArgument);
		pArgument = NULL;
		if (NULL == pReturn) __leave;
		if (FALSE == PyTuple_Check(pReturn)) __leave;
		PyArg_Parse(PyTuple_GetItem(pReturn, 0), "s", &szReturnString);
		PyArg_Parse(PyTuple_GetItem(pReturn, 1), "p", &bBoolean);

		pWhoamI = PyObject_GetAttrString(pModule, "szWhoamI");
		PyArg_Parse(pWhoamI, "s", &szWhoamI);


		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));

		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pWelcomMessage) Py_DECREF(pWelcomMessage);
		if (NULL != pWhoamI) Py_DECREF(pWhoamI);
		if (NULL != pFunction_01) Py_DECREF(pFunction_01);
		if (NULL != pFunction_02) Py_DECREF(pFunction_02);
		if (NULL != pFunction_03) Py_DECREF(pFunction_03);
		if (NULL != pFunction_04) Py_DECREF(pFunction_04);
		if (NULL != pFunction_05) Py_DECREF(pFunction_05);
		if (NULL != pArgument) Py_DECREF(pArgument);

		
		bSuccess = FALSE;
		pModule = NULL;
		pWelcomMessage = NULL;
		pWhoamI = NULL;

		szWelcomMessage = NULL;
		szWhoamI = NULL;


		Py_Finalize();
	}
}


static PyObject *MyDbgString1(PyObject *pSelf)
{
	PyObject *	pReturn{ NULL };

	OutputDebugString(_T("MyDbgString 호출됨\n"));

	Py_INCREF(Py_None);
	pReturn = Py_None;

	return pReturn;
}

static PyMethodDef ExtMethods1[] = {
	{ "DbgString", (PyCFunction)MyDbgString1, METH_NOARGS, "Execute a OutputDebugString"},
	{NULL, NULL, 0, NULL} 
};


static struct PyModuleDef PyExtModule1 = {
	PyModuleDef_HEAD_INIT,
	"PyExt",
	NULL,
	-1,	
	ExtMethods1
};


PyMODINIT_FUNC PyInit_Ext1(void)
{
	return PyModule_Create(&PyExtModule1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 2 장 - Python에서 C 호출하기
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 4 - Python에서 호출 가능한 C함수 만들기 1
//
void CPySampleDlg::OnBnClickedButton04()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pExt{ NULL };
	PyObject *	pModule{ NULL };

	__try {
		PyImport_AppendInittab("PyExt", PyInit_Ext1);

		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample04");
		if (NULL == pModule) __leave;

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));


		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pExt) Py_DECREF(pExt);
		Py_Finalize();
	}
}

static PyObject *MyDbgString2(PyObject *pSelf, PyObject *pArg)
{
	PyObject *	pReturn{ NULL };
	char *		szDbgString;
	/* Treat arg as a borrowed reference. */
	Py_INCREF(pArg);

	PyArg_Parse(pArg, "s", &szDbgString);
	OutputDebugStringA(szDbgString);

	Py_INCREF(Py_None);
	pReturn = Py_None;

	return pReturn;
}

static PyObject *MySum(PyObject *pSelf, PyObject *pArg)
{
	PyObject *	pReturn{ NULL };
	int			nStartVar{ 0 };
	int			nStopVar{ 0 };
	int			nSum{ 0 };

	/* Treat arg as a borrowed reference. */
	Py_INCREF(pArg);

	PyArg_ParseTuple(pArg, "II", &nStartVar, &nStopVar);

	for (int nIndex = nStartVar; nIndex <= nStopVar; nIndex++)
	{
		nSum += nIndex;
	}

	pReturn = PyLong_FromUnsignedLong(nSum);

	return pReturn;
}

static PyMethodDef ExtMethods2[] = {
	{ "DbgString",  (PyCFunction)MyDbgString2, METH_O, "Execute a OutputDebugString" },
	{ "Sum",  (PyCFunction)MySum, METH_VARARGS, "Execute a OutputDebugString" },
	{ NULL, NULL, 0, NULL }
};


static struct PyModuleDef PyExtModule2 = {
	PyModuleDef_HEAD_INIT,
	"PyExt",
	NULL,
	-1,	
	ExtMethods2
};


PyMODINIT_FUNC PyInit_Ext2(void)
{
	return PyModule_Create(&PyExtModule2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 5 - Python에서 호출 가능한 C함수 만들기 2
//
void CPySampleDlg::OnBnClickedButton05()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pExt{ NULL };
	PyObject *	pModule{ NULL };

	__try {
		PyImport_AppendInittab("PyExt", PyInit_Ext2);

		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample05");
		if (NULL == pModule) __leave;

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));


		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pExt) Py_DECREF(pExt);
		Py_Finalize();
	}
}

static PyObject *MyDbgString3(PyObject *pSelf, PyObject *pArg)
{
	PyObject *	pReturn{ NULL };
	char *		szDbgString;
	wchar_t		wszDbgString[MAX_PATH]{ 0, };

	/* Treat arg as a borrowed reference. */
	Py_INCREF(pArg);

	PyArg_Parse(pArg, "s", &szDbgString);

	int nLen = MultiByteToWideChar(CP_UTF8, 0, szDbgString, strlen(szDbgString), NULL, NULL);
	MultiByteToWideChar(CP_UTF8, 0, szDbgString, strlen(szDbgString), wszDbgString, nLen);

	OutputDebugStringW(wszDbgString);

	Py_INCREF(Py_None);
	pReturn = Py_None;

	return pReturn;
}

static PyObject *MySumAndAverage(PyObject *pSelf, PyObject *pArg)
{
	PyObject *	pReturn{ NULL };
	int			nStartVar{ 0 };
	int			nStopVar{ 0 };
	int			nSum{ 0 };
	int			nAverage{ 0 };

	/* Treat arg as a borrowed reference. */
	Py_INCREF(pArg);

	PyArg_ParseTuple(pArg, "II", &nStartVar, &nStopVar);

	for (int nIndex = nStartVar; nIndex <= nStopVar; nIndex++)
	{
		nSum += nIndex;
	}

	nAverage = nSum / (nStopVar - nStartVar + 1);

	pReturn = Py_BuildValue("(ll)", nSum, nAverage);

	return pReturn;
}

static PyMethodDef ExtMethods3[] = {
	{ "DbgString",  (PyCFunction)MyDbgString3, METH_O, "Execute a OutputDebugString" },
	{ "SumAndAverage",  (PyCFunction)MySumAndAverage, METH_VARARGS, "Execute a OutputDebugString" },
	{ NULL, NULL, 0, NULL }
};


static struct PyModuleDef PyExtModule3 = {
	PyModuleDef_HEAD_INIT,
	"PyExt",
	NULL,	
	-1,	
	ExtMethods3
};


PyMODINIT_FUNC PyInit_Ext3(void)
{
	OutputDebugStringA("Enter PyInit_Ext3\n");
	return PyModule_Create(&PyExtModule3);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 6 - Python에서 호출 가능한 C함수 만들기 3
//
void CPySampleDlg::OnBnClickedButton06()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL		bSuccess{ FALSE };
	PyObject *	pModule{ NULL };

	__try {
		PyImport_AppendInittab("PyExt", PyInit_Ext3);

		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample06");
		if (NULL == pModule) __leave;

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));


		if (NULL != pModule) Py_DECREF(pModule);
		Py_Finalize();
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// 3 장 - Python 확장 모듈(DLL) 만들기
//
//
////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////
// 예제 7 - MyDbgString을 DLL로 구현하기
//
void CPySampleDlg::OnBnClickedButton07()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	BOOL		bSuccess{ FALSE };
	HMODULE		hExt;
	PyObject *	pExt{ NULL };
	PyObject *	pModule{ NULL };

	PyObject *(*InitPyExt)();

	__try {
		hExt = LoadLibrary(_T("C:/Users/user 915/Documents/Projects/VisualCPP_Meet_Python_for_CPP_Programmer/PyExt/1차/PyExt/Debug/PyExt.pyd"));
		InitPyExt = (PyObject *(*)())GetProcAddress(hExt, "InitPyExt");
		PyImport_AppendInittab("PyExt", InitPyExt);

		Py_Initialize();

		Append_Script_Path();

		pModule = PyImport_ImportModule("Sample07");
		if (NULL == pModule) __leave;

		bSuccess = TRUE;
	}
	__finally {
		if (TRUE == bSuccess)
			OutputDebugString(_T("Python OK\n"));
		else
			OutputDebugString(_T("Python Error\n"));


		if (NULL != pModule) Py_DECREF(pModule);
		if (NULL != pExt) Py_DECREF(pExt);
		Py_Finalize();
	}
}


void CPySampleDlg::OnBnClickedButton08()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

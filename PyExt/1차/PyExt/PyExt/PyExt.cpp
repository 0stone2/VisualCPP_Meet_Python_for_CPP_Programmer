// PyExt.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"


#define __PYTHON_35__


#if defined(__PYTHON_35__)
#if defined(_DEBUG)
#pragma comment(lib, "C:/Script/Python/libs/python35_d.lib")
#else
#pragma comment(lib, "C:/Script/Python/libs/python35.lib")
#endif
#endif

#include "C:/Script/Python/include/Python.h"

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

static PyMethodDef PyExt_Methods[] = {
	{ "DbgString", (PyCFunction)MyDbgString3, METH_O, "DbgString() doc string" },
	{ "SumAndAverage",  (PyCFunction)MySumAndAverage, METH_VARARGS, "SumAndAverage() doc string" },
	{ NULL, NULL }
};

static struct PyModuleDef PyExt_Module = {
	PyModuleDef_HEAD_INIT,
	"PyExt",
	"PyExt Module doc string",
	-1,
	PyExt_Methods,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC InitPyExt(void)
{
	OutputDebugStringA("Enter InitPyExt\n");
	return PyModule_Create(&PyExt_Module);
}

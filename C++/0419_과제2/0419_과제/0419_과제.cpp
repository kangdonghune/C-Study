// 0419_����.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "0419_����.h"
#include "MainApp.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
HWND g_HWND;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���⿡ �ڵ带 �Է��մϴ�.

	// ���� ���ڿ��� �ʱ�ȭ�մϴ�.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY0419_, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);


	// ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0419_));

	MSG msg;

	// �⺻ �޽��� �����Դϴ�.
	CMainApp* pMain = CMainApp::Create();

	if (pMain == nullptr)
		return 0;

	DWORD dwOldTime = GetTickCount(); //�ü������ �����찡 ���� ���� �ð��� ��ȯ���ִ� �Լ�. �뷫 1/1000��; ����Ʈ���� ���¿� ���� ������ �߻��Ѵ�.
	//GetMessage //��� �޽����� �߻����� ������ ���ŷ ���¿� ������. �׷��� ���ӿ� �������� �ʴ´�.
	msg.message = WM_NULL;
	while (WM_QUIT != msg.message)
	{
		
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))//�޽����� �߻���Ű�� �޽���ť�� �޽����� ���µ� �о���� �޽����� ������ false ��ȯ
		{
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		
	
		if (dwOldTime < GetTickCount()) // �������� �ʹ� ���� ���ϱ� �ð����� ������ ��. �뷫 0.01��
		{
			pMain->Update_MainApp();
			pMain->Render_MainApp();
			dwOldTime = GetTickCount();
			pMain->SetFrame()++;
		}		
	}
	if (pMain)
	{
		delete pMain;
		pMain = nullptr;
	}
	return (int)msg.wParam;

}



//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0419_));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_MY0419_);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.
   RECT rc = { 0, 0, WINCX, WINCY };
   AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
   HWND hWnd = CreateWindowW(szWindowClass, L"�ѽ��", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);
  

   if (!hWnd)
   {
      return FALSE;
   }
   g_HWND = hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_KEYDOWN:
		switch (wParam)
		{
			// 		case VK_LEFT:
			// 			rc.left -= 5; 
			// 			rc.right -= 5; 
			// 			break; 
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		default:
			break;
		}
		break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

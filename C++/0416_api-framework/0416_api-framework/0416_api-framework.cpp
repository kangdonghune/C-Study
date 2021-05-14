// 0416_api-framework.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "0416_api-framework.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;                                // ���� �ν��Ͻ��Դϴ�.
WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	//h�� handle
	//�ڵ��̶�?
	//��� ���� ���� ǥ���ϴµ� ���Ǵ� ��
	//������ �����ѹ�. ������� ġ�ڸ� �ֹε�Ϲ�ȣ.
	//unsigned ���� Ÿ��.

                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0416_APIFRAMEWORK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);//������â�� ��Ÿ���� ����.

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow)) //������ â ����.
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0416_APIFRAMEWORK));

    MSG msg;

    // �⺻ �޽��� �����Դϴ�.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW; //���� ���� ���̰� ���ϸ� â�� ���� �׸��ڴ�.
    wcex.lpfnWndProc    = WndProc; //�޽����� ó���ϴ� ���, ��â�� �޽��� ó���ϴ� �Լ�
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0416_APIFRAMEWORK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0416_APIFRAMEWORK); //�޴��ٸ� ��� �� ����. �̰� ����� ������.
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
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) //������ â ����.
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   /*
   ���ڿ���
   sbcs-�̱� ����Ʈ ĳ���� ��. 1byte�� ���� ó�� =�ƽ�Ű �ڵ�ǥ
   mbcs-��Ƽ ����Ʈ ĳ���� ��. 1����Ʈ�� ó�� ������ ���ڴ� 1����Ʈ�� �� �� ���ڴ� 2����Ʈ��, sbcs�� �����ϴ� ����. �ٵ� �̷��� ���ڸ��� ���̰� �޶����� ���� �ҷ����� �ܰ迡�� ���̵��� ��������.
   wbcs-���̵� ����Ʈ ĳ���� ��, � ���� �� �� 2����Ʈ�� ó���ع����ڴ�.
   wchat - 2����Ʈ ĳ���ͼ��� ���ڴ�.
	*/

   HWND hWnd = CreateWindowW(szWindowClass, /*szTitle-wchar Ÿ��*/ L"Ÿ��Ʋ ����", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT/*������ġ*/, 0, CW_USEDEFAULT/*ȭ�����*/, 0, nullptr, nullptr, hInstance, nullptr); //���� ���������� ���� �� ������ ���� �־���Ѵ�. �ƴϸ� ������ �� ������ �ִ�.

   if (!hWnd)
   {
      return FALSE;
   }

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //callback �̶�� �ϸ� �ü������ �ʿ信 ���ؼ� ȣ���ϴ� �Լ�. ���� ȣ���ϴ� �Լ��� �ƴϴ�.
{
	RECT rc;
	rc.left = 100;
	rc.top = 100;
	rc.right = 300;
	rc.bottom = 300;
	switch (message)
	{
	case WM_TIMER:
		InvalidateRect(hWnd, nullptr, true); //���࿡ ����Ʈ ���� ���� �ʹٸ� nullptr �Ǵ� 0. ���⼱ �簢���� ���������� ������ ��� ����� �׸���.
		break;
	case WM_CREATE:  //������ �� �� �� �� ȣ��.
		SetTimer(hWnd,0,0,nullptr); //eElapse�� 0���� �ϸ� ����Ʈ 0.001�ʷ� ��������.
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmId)
		{
	
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			KillTimer(hWnd,0);
			DestroyWindow(hWnd); //â�� ���ִ� �Լ�.
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_KEYDOWN:
	{
	case VK_LEFT:
		rc.left -= 5;
		rc.right -= 5;
		break;
	}
	break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps); //�⺻������ �׸��׸��⿡ �ʿ��� ����ü�� �����״�.
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
			MoveToEx(hdc, 100, 100, nullptr);//lppoint�� ������ Ŀ���� �ִ� ��ġ;
			LineTo(hdc, 200, 200); //������ ��ǥ��. 
			LineTo(hdc, 300, 100);
			LineTo(hdc, 200, 0);
			LineTo(hdc, 100, 100);
			Rectangle(hdc, rc.left, rc.top, rc.right,rc.bottom);
			Ellipse(hdc, 500,500,700,700);
			EndPaint(hWnd, &ps);
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

// 0416_api-framework.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "0416_api-framework.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, 
	//h는 handle
	//핸들이란?
	//어떠한 고유 값을 표현하는데 사용되는 것
	//일종의 고유넘버. 사람으로 치자면 주민등록번호.
	//unsigned 정수 타입.

                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0416_APIFRAMEWORK, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);//윈도우창의 스타일을 결정.

    // 응용 프로그램 초기화를 수행합니다.
    if (!InitInstance (hInstance, nCmdShow)) //윈도우 창 생성.
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0416_APIFRAMEWORK));

    MSG msg;

    // 기본 메시지 루프입니다.
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
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW; //가로 세로 길이가 변하면 창을 새로 그리겠다.
    wcex.lpfnWndProc    = WndProc; //메시지를 처리하는 방식, 주창의 메시지 처리하는 함수
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0416_APIFRAMEWORK));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0416_APIFRAMEWORK); //메뉴바를 어떻게 할 건지. 이거 지우면 없어짐.
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) //윈도우 창 생성.
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   /*
   문자열은
   sbcs-싱글 바이트 캐릭터 셋. 1byte로 문자 처리 =아스키 코드표
   mbcs-멀티 바이트 캐릭터 셋. 1바이트로 처리 가능한 문자는 1바이트로 그 외 문자는 2바이트로, sbcs를 포함하는 관계. 근데 이러면 문자마다 길이가 달라져서 저장 불러오는 단계에서 난이도가 높아진다.
   wbcs-와이드 바이트 캐릭터 셋, 어떤 언어든 걍 다 2바이트로 처리해버리겠다.
   wchat - 2바이트 캐릭터셋을 쓰겠다.
	*/

   HWND hWnd = CreateWindowW(szWindowClass, /*szTitle-wchar 타입*/ L"타이틀 변경", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT/*생성위치*/, 0, CW_USEDEFAULT/*화면비율*/, 0, nullptr, nullptr, hInstance, nullptr); //값을 임의적으로 넣을 떈 비율을 맞춰 넣어야한다. 아니면 에러가 날 요지가 있다.

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) //callback 이라고 하면 운영체제에서 필요에 의해서 호출하는 함수. 내가 호출하는 함수가 아니다.
{
	RECT rc;
	rc.left = 100;
	rc.top = 100;
	rc.right = 300;
	rc.bottom = 300;
	switch (message)
	{
	case WM_TIMER:
		InvalidateRect(hWnd, nullptr, true); //만약에 디폴트 값을 쓰고 싶다면 nullptr 또는 0. 여기선 사각형을 설정해주지 않으면 모두 지우고 그린다.
		break;
	case WM_CREATE:  //생성될 때 단 한 번 호출.
		SetTimer(hWnd,0,0,nullptr); //eElapse는 0으로 하면 디폴트 0.001초로 정해진다.
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다.
		switch (wmId)
		{
	
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			KillTimer(hWnd,0);
			DestroyWindow(hWnd); //창을 없애는 함수.
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
            HDC hdc = BeginPaint(hWnd, &ps); //기본적으로 그림그리기에 필요한 구조체룰 만들어뒀다.
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
			MoveToEx(hdc, 100, 100, nullptr);//lppoint는 이전에 커서가 있던 위치;
			LineTo(hdc, 200, 200); //윈도우 좌표계. 
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

// 정보 대화 상자의 메시지 처리기입니다.
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

// NewTRPG.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Main.h"
#include <crtdbg.h>

int main()
{
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CMain tMain;
	tMain.ReadyMain();
	tMain.UpdateMain();
    return 0;
}


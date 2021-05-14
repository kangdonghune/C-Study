// 0331.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "Player.h"


int g_iValue = 3; //이런 식으로 선언하면 선언된 cpp에서 밖에 쓰질 못한다. 그래서 미리 컴파일된 헤더에서 extern로 지정을 해줘야 한다.
//
//int main()
//{
//	//extern
//
//	cout << g_iValue << endl;
//	CPlayer CP;
//	CP.GetGVelue();
//	cout << g_iValue << endl;
//	cout << &g_iValue << endl;
//	
//    return 0;
//}


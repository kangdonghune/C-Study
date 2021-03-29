#pragma once
#include "stdafx.h"
#include "grademanagement.h"
#ifndef run_system_H
#define run_system_H

/*
1. 화면출력
2. 선택지에 따른 입력, 출력
3. 프로그램 종료.
*/

class CRunSystem
{
public:
	void Init(); 
	void PrintMainScreen();
	

private:
	CGradeManegement* m_pGradeManegement; //기본 생성자 자동 사용. 동적할당을 위해 포인터로.
};

#endif // !run_system_H

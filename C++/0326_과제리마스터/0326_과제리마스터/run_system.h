#pragma once
#include "stdafx.h"
#include "grademanagement.h"
#ifndef run_system_H
#define run_system_H

/*
1. ȭ�����
2. �������� ���� �Է�, ���
3. ���α׷� ����.
*/

class CRunSystem
{
public:
	void Init(); 
	void PrintMainScreen();
	

private:
	CGradeManegement* m_pGradeManegement; //�⺻ ������ �ڵ� ���. �����Ҵ��� ���� �����ͷ�.
};

#endif // !run_system_H

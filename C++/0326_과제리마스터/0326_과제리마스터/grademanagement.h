#pragma once
#include "stdafx.h" //�̸� �����ϵ� ����� ���� ��� ���� ���� ���� �δ� �� ���� ������ ����. ���� ��� ���.Ŭ�������� �� �ʿ伺�� �־ �̸� ������ �� ���̴� ��� ����� �߰��صδ� �� ���� ������?
#include "struct.h"

#ifndef grademanagement_H
#define grademanagement_H

class CGradeManegement
{
public:
	void Init();//���� �� ��� ���� �ʱ�ȭ.
	//�л� ���� �Է�
	void InputStudent(int size);//�л� ���� �߰�
	void InputStudentData(int size, STUDENT* pStudents, int count = 0 );//�л� ���� �Է�. -�л� ���� �Է� �κ� ������.
	//�л� ���� �˻�
	void SearchStudent (char SearchName[]);
	//����ǥ ���`
	void PrintGradeCard(int index);
	void PrintGradeCardAll();
private:
	int m_iStudentNum; //���� �л� ��. //���� ���� �ϰ� ���Ǹ� �� ���ִ� ������ ������ �����ڸ� �ۼ��� �� ���� ���̱� ����?
	STUDENT* m_tStudents; //�л� �� ���� �迭 ������. �����Ҵ��� ���� �����ͷ�
};
#endif // !grademanagement_H

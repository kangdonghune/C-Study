#pragma once
#include "stdafx.h" //미리 컴파일된 헤더는 보통 헤더 순서 제일 위에 두는 게 오류 방지에 좋다. 보통 모든 헤더.클래스에서 쓸 필요성이 있어서 미리 컴파일 한 것이니 모든 헤더에 추가해두는 게 좋지 않을까?
#include "struct.h"

#ifndef grademanagement_H
#define grademanagement_H

class CGradeManegement
{
public:
	void Init();//시작 시 멤버 변수 초기화.
	//학생 정보 입력
	void InputStudent(int size);//학생 정보 추가
	void InputStudentData(int size, STUDENT* pStudents, int count = 0 );//학생 정보 입력. -학생 정보 입력 부분 마무리.
	//학생 정보 검색
	void SearchStudent (char SearchName[]);
	//성적표 출력`
	void PrintGradeCard(int index);
	void PrintGradeCardAll();
private:
	int m_iStudentNum; //현재 학생 수. //굳이 선언만 하고 정의를 안 해주는 이유는 어차피 생성자를 작성할 때 해줄 것이기 때문?
	STUDENT* m_tStudents; //학생 별 정보 배열 포인터. 동적할당을 위해 포인터로
};
#endif // !grademanagement_H

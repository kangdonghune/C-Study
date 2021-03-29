#include "stdafx.h"
#include "grademanagement.h"

void CGradeManegement::Init() //헤더 선언을 cpp에서 정의해줄 수 전역 함수와 구분을 두기 위해 범위 지정 연산자 ::로 해당 클래스의 함수임을 명시해준다,
{
	m_iStudentNum = 0;
	m_tStudents = nullptr;
}

void CGradeManegement::InputStudent(int size)
{
	if (!m_tStudents) //학생 정보 배열이 nullptr 초기화 상태인 경우. nullptr은 bool형식으로 사용 시 false 반환
	{
		m_iStudentNum += size; //학생 수 추가.
		m_tStudents = new STUDENT[m_iStudentNum];//학생 수만큼의 동적배열 할당.
		InputStudentData(size, m_tStudents); // 초기화 상태이기에 카운트는 디펄트 값인 0
	}
	else //이미 정보가 들어와 있는 경우.
	{
		//기존에 학생 수 만큼 선언되어 있단 동적 배열을 해제한 후 새로운 크기로 추가 할당해야함.
		STUDENT* temp = new STUDENT[m_iStudentNum+size]; //현재 배운 방식의 포인터 동적 배열로는 길이를 반환할 방법이 없기에 일단 길이 변경 보류.
		memset(temp, 0, m_iStudentNum + size);// temp 배열 쓰레기값 제거를 위해 0 초기화
		memmove(temp, m_tStudents, sizeof(STUDENT)*m_iStudentNum); //사발적으로 이건 포인터 값이다.
		//memmove(받을 포인터, 줄 포인터, 옮길 데이터 바이트 크기); 이니 sizeof를 이용해 기존 성적표의 크기를 받아다가 복사해주자.
		//임시 교환 배열에 기존 학생 정보 배열을 옮겨담았다면 해당 배열 동적할당 해제.
		delete[] m_tStudents; //해제.
		m_tStudents = temp; //사라질 temp가 가진 heap 주소를 복사.
		InputStudentData(size, m_tStudents, m_iStudentNum); //이미 있던 것들은 복사해뒀기에 시작 인덱스가 기존 학생 수부터.
		m_iStudentNum += size; //모든 작업을 마쳤기에 현재 학생 수에 추가해준 학생 수를 더해준다.

		//temp는 지역 변수이므로 해당 else문 끝나면 사라짐. 그 주소를 이어받은 m_tStudent는 다시 여기로 들어올 시 할당해제 해주고 주소값 새로 받기에 메모리문제 해결.
	}

	cout << "입력을 마쳤습니다." << endl;
}

void CGradeManegement::InputStudentData(int size, STUDENT * pStudents, int count)
{
	while (size > 0)
	{
		cout << "학생 정보를 입력하세요." << endl;
		cout << "이름: ";
		cin >> pStudents[count].szName;
		cout << endl;

		cout << "수학: ";
		cin >> pStudents[count].iKor;
		cout << endl;

		cout << "영어: ";
		cin >> pStudents[count].iEng;
		cout << endl;

		cout << "수학: ";
		cin >> pStudents[count].iMath;
		cout << endl;

		count++;
		size--;
		system("cls");
	}
}

void CGradeManegement::SearchStudent(char SearchName[])
{
	if (m_tStudents == nullptr)
	{
		cout << "탐색할 학생 정보가 없습니다." << endl;
		return;
	}
	for (int i = 0; i < m_iStudentNum; i++)
	{
		if (!strcmp(m_tStudents[i].szName, SearchName))
		{
			PrintGradeCard(i);
		}
	}
}

void CGradeManegement::PrintGradeCard(int index)
{
	if (m_tStudents == nullptr)
	{
		cout << "입력된 학생 정보가 없습니다." << endl;
		return;
	}
	else if (index >= m_iStudentNum || index < 0)
	{
		cout << "입력된 인덱스 값이 오류입니다." << endl;
		return;
	}
	else
	{
		int iTotal = m_tStudents[index].iKor + m_tStudents[index].iEng + m_tStudents[index].iMath;
		float iAverage = iTotal / 3.f;
		cout << "이름: " << m_tStudents[index].szName << "\t국어: " << m_tStudents[index].iKor << "\t영어: " << m_tStudents[index].iEng << "\t수학: " << m_tStudents[index].iMath << "\t 평균: " << iAverage << "\t 총점: " << iTotal << endl;
	}
}

void CGradeManegement::PrintGradeCardAll() //현재 발생점. 처음과 맨 끝 학생 정보가 엉터리가 됨. 1번 인덱스 문제다. 2.뎅글링포인터다.
{
	if (m_tStudents == nullptr)
	{
		cout << "입력된 학생 정보가 없습니다." << endl;
		return;
	}
	for (int i = 0; i < m_iStudentNum; i++)
	{
		PrintGradeCard(i);
	}
}




#include "stdafx.h"
#include "run_system.h"

void CRunSystem::Init()
{
	m_pGradeManegement = nullptr; //일단 nullptr 초기화.
	m_pGradeManegement = new CGradeManegement; //크기만큼 할당. 기본생성자 없으니 멤버 변수 값을 쓰레기 값으로 기본 생성.
	m_pGradeManegement->Init(); //생성된 CGradeManegement를 쓰레기값에서 초기화.
}

void CRunSystem::PrintMainScreen()
{
	int iSelect=0;
	while (iSelect != 4)
	{
		cout << "--성적표 관리 시스템--" << endl;
		cout << "1.학생 정보 입력.\t 2.학생 정보 검색.\t 3.성적표 출력.\t 4.프로그램 종료" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			system("cls");
			cout << "입력할 학생 수를 입력해주세요." << endl;
			int iSize;
			cin >> iSize;
			m_pGradeManegement->InputStudent(iSize); //입력받은 수 만큼 학생 정보 입력
			break;
		case 2:
			system("cls");
			cout << "검색할 학생 이름을 입력하세요." << endl;
			char szSName[32];
			cin >> szSName;
			m_pGradeManegement->SearchStudent(szSName);
			break;
		case 3:
			system("cls");
			cout << "성적표를 출력합니다." << endl;
			m_pGradeManegement->PrintGradeCardAll();
			break;
		case 4:
			cout << "프로그램을 종료합니다." << endl;
			return;
		default:
			cout << "입력 오류입니다.." << endl;
			continue;
		}
		system("pause");
		system("cls");
	}
}

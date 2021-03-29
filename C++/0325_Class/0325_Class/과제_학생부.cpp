/*
성적표 관리 프로그램 만들어 오기
성적표 관리하는 클래스를 입력, 탐색, 출력 함수 갖게끔 만들기
입력시 입력할 학생 수 만큼 동적 배열로 작성할 것.
모든 입력이 완료되고 다음 추가 입력시에는 학생수에서 추가되는 학생의 수만큼 또 입력 받기

ex) 최초 5명을 입력하고 전체 출력시에는 5명분의 성적표 출력.
후에 2명의 학생을 추가 입력 받고 전체 출력하면 총 7명 분 성적표 출력되어야 함.
*/

//추가적으로 이름 순으로 성적표 정렬.
#include "stdafx.h"
#include "gradecard.h"





class CGradeCard
{
public:
	void InsertInfo(int InputCount)
	{
		m_iStudentCount += InputCount;
		while(InputCount > 0)
		{
			std::cout << "학생 정보를 입력하세요." << std::endl;
			std::cout << "이름: ";
			std::cin >> m_Student[m_iNowCount].szName;
			std::cout << std::endl;
			std::cout << "국어 점수: ";
			std::cin >> m_Student[m_iNowCount].iKor;
			std::cout << std::endl;
			std::cout << "영어 점수: ";
			std::cin >> m_Student[m_iNowCount].iEng;
			std::cout << std::endl;
			std::cout << "수학 점수: ";
			std::cin >> m_Student[m_iNowCount].iMath;
			std::cout << std::endl;
			m_iNowCount++;
			InputCount--;
			std::system("cls");
		}
		//NameSorted();
	}
	GRADECARD* SearchStudent()
	{
		GRADECARD* ptrGC = nullptr;
		std::cout << "찾을 학생의 이름을 입력하세요 : ";
		char SearchName[32]{};
		std::cin >> SearchName;
		std::cout << std::endl;
		for (int i = 0; i <m_iStudentCount; i++)
		{
			if (!strcmp(SearchName, m_Student[i].szName))
			{
				std::cout << "이름: " << m_Student[i].szName << " 국어 점수: " << m_Student[i].iKor << "점 영어 점수: " << m_Student[i].iEng << "점 수학 점수: " << m_Student[i].iMath << "점" << std::endl;
				ptrGC = &m_Student[i];
				return ptrGC;
			}

				
		}
		std::cout << "찾지 못했습니다." << std::endl;
		return ptrGC;
	} 
	void PrintStudent()
	{
		std::cout << "성적표 총 인원: " << m_iStudentCount << std::endl;
		for (int i = 0; i < m_iStudentCount; i++)
		{
			std::cout << "이름: " << m_Student[i].szName << " 국어 점수: " << m_Student[i].iKor << "점 영어 점수: " << m_Student[i].iEng << "점 수학 점수: " << m_Student[i].iMath << "점" << std::endl;
		}
	}

	/*void NameSorted()
	{
		for (int i = 0; i < m_iStudentCount-1; i++)
		{
			for (int j = 0; j < m_iStudentCount; j++)
			{
				if (0 < strcmp(m_Student[i].szName, m_Student[j].szName))
				{
					GRADECARD temp = m_Student[i];
					m_Student[i] = m_Student[j];
					m_Student[j] = temp;
				}
			}
		}
	}*/

	GRADECARD* GetStudent() { return m_Student; }
	void SetStudent(GRADECARD* SetGradeCard) { m_Student = SetGradeCard; }
	int GetStudentNum() { return m_iStudentCount; }
	void SetStudenNum(int iStudentNum) { m_iStudentCount = iStudentNum;}

	

private:
	int m_iStudentCount = 0;
	int m_iNowCount = 0;
	GRADECARD* m_Student = new GRADECARD[m_iStudentCount];
};

int main()
{
	CGradeCard tMyGCard;
	int iSelect;
	do
	{
		std::cout << "1.성적표 정보 입력 2.성적표 검색 3.성적표 출력 4.프로그램 종료." << std::endl;
		std::cin >> iSelect;
		int iInputCount = 0;
		if (0 >= iSelect || 5 <= iSelect)
			continue;
		switch (iSelect)
		{
		case 1:
			std::cout << "입력할 학생 수를 적어주세요 : ";
			std::cin >> iInputCount;
			std::cout << std::endl;
			tMyGCard.InsertInfo(iInputCount);
			break;
		case 2:
			tMyGCard.SearchStudent();
			std::system("pause");
			break;
		case 3:
			tMyGCard.PrintStudent();
			std::system("pause");
			break;
		case 4:
			break;
		default:
			std::cout << "에러발생" << std::endl;
			std::system("pause");
			break;
		}
		
	
	} while (iSelect != 4);
	
	return 0;
}
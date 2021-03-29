/*
����ǥ ���� ���α׷� ����� ����
����ǥ �����ϴ� Ŭ������ �Է�, Ž��, ��� �Լ� ���Բ� �����
�Է½� �Է��� �л� �� ��ŭ ���� �迭�� �ۼ��� ��.
��� �Է��� �Ϸ�ǰ� ���� �߰� �Է½ÿ��� �л������� �߰��Ǵ� �л��� ����ŭ �� �Է� �ޱ�

ex) ���� 5���� �Է��ϰ� ��ü ��½ÿ��� 5����� ����ǥ ���.
�Ŀ� 2���� �л��� �߰� �Է� �ް� ��ü ����ϸ� �� 7�� �� ����ǥ ��µǾ�� ��.
*/

//�߰������� �̸� ������ ����ǥ ����.
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
			std::cout << "�л� ������ �Է��ϼ���." << std::endl;
			std::cout << "�̸�: ";
			std::cin >> m_Student[m_iNowCount].szName;
			std::cout << std::endl;
			std::cout << "���� ����: ";
			std::cin >> m_Student[m_iNowCount].iKor;
			std::cout << std::endl;
			std::cout << "���� ����: ";
			std::cin >> m_Student[m_iNowCount].iEng;
			std::cout << std::endl;
			std::cout << "���� ����: ";
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
		std::cout << "ã�� �л��� �̸��� �Է��ϼ��� : ";
		char SearchName[32]{};
		std::cin >> SearchName;
		std::cout << std::endl;
		for (int i = 0; i <m_iStudentCount; i++)
		{
			if (!strcmp(SearchName, m_Student[i].szName))
			{
				std::cout << "�̸�: " << m_Student[i].szName << " ���� ����: " << m_Student[i].iKor << "�� ���� ����: " << m_Student[i].iEng << "�� ���� ����: " << m_Student[i].iMath << "��" << std::endl;
				ptrGC = &m_Student[i];
				return ptrGC;
			}

				
		}
		std::cout << "ã�� ���߽��ϴ�." << std::endl;
		return ptrGC;
	} 
	void PrintStudent()
	{
		std::cout << "����ǥ �� �ο�: " << m_iStudentCount << std::endl;
		for (int i = 0; i < m_iStudentCount; i++)
		{
			std::cout << "�̸�: " << m_Student[i].szName << " ���� ����: " << m_Student[i].iKor << "�� ���� ����: " << m_Student[i].iEng << "�� ���� ����: " << m_Student[i].iMath << "��" << std::endl;
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
		std::cout << "1.����ǥ ���� �Է� 2.����ǥ �˻� 3.����ǥ ��� 4.���α׷� ����." << std::endl;
		std::cin >> iSelect;
		int iInputCount = 0;
		if (0 >= iSelect || 5 <= iSelect)
			continue;
		switch (iSelect)
		{
		case 1:
			std::cout << "�Է��� �л� ���� �����ּ��� : ";
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
			std::cout << "�����߻�" << std::endl;
			std::system("pause");
			break;
		}
		
	
	} while (iSelect != 4);
	
	return 0;
}
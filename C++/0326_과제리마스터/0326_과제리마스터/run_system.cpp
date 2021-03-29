#include "stdafx.h"
#include "run_system.h"

void CRunSystem::Init()
{
	m_pGradeManegement = nullptr; //�ϴ� nullptr �ʱ�ȭ.
	m_pGradeManegement = new CGradeManegement; //ũ�⸸ŭ �Ҵ�. �⺻������ ������ ��� ���� ���� ������ ������ �⺻ ����.
	m_pGradeManegement->Init(); //������ CGradeManegement�� �����Ⱚ���� �ʱ�ȭ.
}

void CRunSystem::PrintMainScreen()
{
	int iSelect=0;
	while (iSelect != 4)
	{
		cout << "--����ǥ ���� �ý���--" << endl;
		cout << "1.�л� ���� �Է�.\t 2.�л� ���� �˻�.\t 3.����ǥ ���.\t 4.���α׷� ����" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			system("cls");
			cout << "�Է��� �л� ���� �Է����ּ���." << endl;
			int iSize;
			cin >> iSize;
			m_pGradeManegement->InputStudent(iSize); //�Է¹��� �� ��ŭ �л� ���� �Է�
			break;
		case 2:
			system("cls");
			cout << "�˻��� �л� �̸��� �Է��ϼ���." << endl;
			char szSName[32];
			cin >> szSName;
			m_pGradeManegement->SearchStudent(szSName);
			break;
		case 3:
			system("cls");
			cout << "����ǥ�� ����մϴ�." << endl;
			m_pGradeManegement->PrintGradeCardAll();
			break;
		case 4:
			cout << "���α׷��� �����մϴ�." << endl;
			return;
		default:
			cout << "�Է� �����Դϴ�.." << endl;
			continue;
		}
		system("pause");
		system("cls");
	}
}

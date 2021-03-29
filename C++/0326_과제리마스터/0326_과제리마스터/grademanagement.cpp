#include "stdafx.h"
#include "grademanagement.h"

void CGradeManegement::Init() //��� ������ cpp���� �������� �� ���� �Լ��� ������ �α� ���� ���� ���� ������ ::�� �ش� Ŭ������ �Լ����� ������ش�,
{
	m_iStudentNum = 0;
	m_tStudents = nullptr;
}

void CGradeManegement::InputStudent(int size)
{
	if (!m_tStudents) //�л� ���� �迭�� nullptr �ʱ�ȭ ������ ���. nullptr�� bool�������� ��� �� false ��ȯ
	{
		m_iStudentNum += size; //�л� �� �߰�.
		m_tStudents = new STUDENT[m_iStudentNum];//�л� ����ŭ�� �����迭 �Ҵ�.
		InputStudentData(size, m_tStudents); // �ʱ�ȭ �����̱⿡ ī��Ʈ�� ����Ʈ ���� 0
	}
	else //�̹� ������ ���� �ִ� ���.
	{
		//������ �л� �� ��ŭ ����Ǿ� �ִ� ���� �迭�� ������ �� ���ο� ũ��� �߰� �Ҵ��ؾ���.
		STUDENT* temp = new STUDENT[m_iStudentNum+size]; //���� ��� ����� ������ ���� �迭�δ� ���̸� ��ȯ�� ����� ���⿡ �ϴ� ���� ���� ����.
		memset(temp, 0, m_iStudentNum + size);// temp �迭 �����Ⱚ ���Ÿ� ���� 0 �ʱ�ȭ
		memmove(temp, m_tStudents, sizeof(STUDENT)*m_iStudentNum); //��������� �̰� ������ ���̴�.
		//memmove(���� ������, �� ������, �ű� ������ ����Ʈ ũ��); �̴� sizeof�� �̿��� ���� ����ǥ�� ũ�⸦ �޾ƴٰ� ����������.
		//�ӽ� ��ȯ �迭�� ���� �л� ���� �迭�� �Űܴ�Ҵٸ� �ش� �迭 �����Ҵ� ����.
		delete[] m_tStudents; //����.
		m_tStudents = temp; //����� temp�� ���� heap �ּҸ� ����.
		InputStudentData(size, m_tStudents, m_iStudentNum); //�̹� �ִ� �͵��� �����صױ⿡ ���� �ε����� ���� �л� ������.
		m_iStudentNum += size; //��� �۾��� ���Ʊ⿡ ���� �л� ���� �߰����� �л� ���� �����ش�.

		//temp�� ���� �����̹Ƿ� �ش� else�� ������ �����. �� �ּҸ� �̾���� m_tStudent�� �ٽ� ����� ���� �� �Ҵ����� ���ְ� �ּҰ� ���� �ޱ⿡ �޸𸮹��� �ذ�.
	}

	cout << "�Է��� ���ƽ��ϴ�." << endl;
}

void CGradeManegement::InputStudentData(int size, STUDENT * pStudents, int count)
{
	while (size > 0)
	{
		cout << "�л� ������ �Է��ϼ���." << endl;
		cout << "�̸�: ";
		cin >> pStudents[count].szName;
		cout << endl;

		cout << "����: ";
		cin >> pStudents[count].iKor;
		cout << endl;

		cout << "����: ";
		cin >> pStudents[count].iEng;
		cout << endl;

		cout << "����: ";
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
		cout << "Ž���� �л� ������ �����ϴ�." << endl;
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
		cout << "�Էµ� �л� ������ �����ϴ�." << endl;
		return;
	}
	else if (index >= m_iStudentNum || index < 0)
	{
		cout << "�Էµ� �ε��� ���� �����Դϴ�." << endl;
		return;
	}
	else
	{
		int iTotal = m_tStudents[index].iKor + m_tStudents[index].iEng + m_tStudents[index].iMath;
		float iAverage = iTotal / 3.f;
		cout << "�̸�: " << m_tStudents[index].szName << "\t����: " << m_tStudents[index].iKor << "\t����: " << m_tStudents[index].iEng << "\t����: " << m_tStudents[index].iMath << "\t ���: " << iAverage << "\t ����: " << iTotal << endl;
	}
}

void CGradeManegement::PrintGradeCardAll() //���� �߻���. ó���� �� �� �л� ������ ���͸��� ��. 1�� �ε��� ������. 2.���۸������ʹ�.
{
	if (m_tStudents == nullptr)
	{
		cout << "�Էµ� �л� ������ �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < m_iStudentNum; i++)
	{
		PrintGradeCard(i);
	}
}




#include <iostream>

using namespace std;



typedef struct
{
	char Name[20];
	int StudentNum;
	int iKor;
	int iEng;
	int iMath;
}STUDENT;

//����ü�� ����ϴ� ��� �ܺ��Լ� ������ ����ü���� �ؿ� �־���� ������ ������ �߻����� �ʴ´�.
void InputStudentInfo(STUDENT Students[], int iStudentsCount, int* iInputCount); 
void ReviseStudentInfo(STUDENT Students[],int iStudentsCount);
void PrintStudentsInfo(STUDENT Students[], int iStudentsCount);
int SearchStudentInfo(STUDENT Students[], int iStudentsCount);
int SearchStudentInfo(STUDENT Students[], int iStudentsCount, int ReviseNum);



int main()
{
	const int iStudentsCount = 3;
	int iInputCount = 0;
	STUDENT Students[iStudentsCount]{};

	while (true)
	{
		cout << "1.�Է�, 2,���� 3.��ü���, 4.�˻����, 5.���� " << endl;
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			InputStudentInfo(Students, iStudentsCount, &iInputCount);
			break;
		case 2:
			ReviseStudentInfo(Students, iStudentsCount);
			break;
		case 3:
			PrintStudentsInfo(Students, iStudentsCount);
			break;
		case 4:
			SearchStudentInfo(Students, iStudentsCount);
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
			break;
		}


	}

	return 0;
}

void InputStudentInfo(STUDENT Students[], int iStudentsCount, int* iInputCount)
{
	cout << "�л� ���� �Է�" << endl;
	if (Students[iStudentsCount - 1].Name[0] != 0)
	{
		cout << "�Է��� �� �ִ� �л��� �ִ��Դϴ�. �ԷºҰ�" << endl;
		return;
	}
		
	cout << "�л��� �̸��� �Է��Ͻÿ�." << endl;
	cin >> Students[*iInputCount].Name;
	cout << "�л��� �й��� �Է��Ͻÿ�." << endl;
	cin >> Students[*iInputCount].StudentNum;
	cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
	cin >> Students[*iInputCount].iKor;
	cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
	cin >> Students[*iInputCount].iEng;
	cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
	cin >> Students[*iInputCount].iMath;
	*iInputCount++;
	system("cls");
}

void ReviseStudentInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "�л� ���� ����" << endl;	
	cout << "�����ϰ��� �ϴ� �л� �й��� �Է��Ͻÿ�." << endl;
	int ReviseNum;
	cin >> ReviseNum;
	ReviseNum = SearchStudentInfo(Students, iStudentsCount, ReviseNum);
	if (ReviseNum == -1)
		return;
	else {
		cout << "�л��� �̸��� �Է��Ͻÿ�." << endl;
		cin >> Students[ReviseNum].Name;
		cout << "�л��� �й��� �Է��Ͻÿ�." << endl;
		cin >> Students[ReviseNum].StudentNum;
		cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
		cin >> Students[ReviseNum].iKor;
		cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
		cin >> Students[ReviseNum].iEng;
		cout << "�л��� ���� ������ �Է��Ͻÿ�." << endl;
		cin >> Students[ReviseNum].iMath;
	}
	system("cls");
}

int SearchStudentInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "�л� ���� �˻�(�й��� �Է��ϼ���,)" << endl;
	int SearchNum;
	cin >> SearchNum;

	for (int i = 0; i < iStudentsCount; i++)
	{
		if (Students[i].StudentNum == SearchNum)
		{
			cout << "�л� ��ȣ : " << Students[i].StudentNum << "��\t" << "�̸� : " << Students[i].Name << "\t ���� ���� : " << Students[i].iKor << "\t ���� ���� : " << Students[i].iEng << "\t ���� ���� : " << Students[i].iMath << endl;
			return i;
			system("cls");
		}
	}
	cout << "�ش��ϴ� �й��� �����ϴ�." << endl;
	return 0;
}
int SearchStudentInfo(STUDENT Students[], int iStudentsCount, int ReviseNum)
{
	for (int i = 0; i < iStudentsCount; i++)
	{
		if (Students[i].StudentNum == ReviseNum)
			return i;
	}
	cout << "�ش��ϴ� �й��� �����ϴ�." << endl;
	return -1;
}
void PrintStudentsInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "��ü �л� ����" << endl;
	for (int i = 0; i < iStudentsCount; i++)
	{
		cout << "�л� ��ȣ : " << Students[i].StudentNum<< "��\t" << "�̸� : " << Students[i].Name << "\t ���� ���� : " << Students[i].iKor << "\t ���� ���� : " << Students[i].iEng << "\t ���� ���� : " << Students[i].iMath << endl;
	}
}
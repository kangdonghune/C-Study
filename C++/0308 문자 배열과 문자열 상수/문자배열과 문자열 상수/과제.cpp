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

//구조체를 사용하는 경우 외부함수 선언이 구조체보다 밑에 있어야지 컴파일 에러가 발생하지 않는다.
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
		cout << "1.입력, 2,수정 3.전체출력, 4.검색출력, 5.종료 " << endl;
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
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}


	}

	return 0;
}

void InputStudentInfo(STUDENT Students[], int iStudentsCount, int* iInputCount)
{
	cout << "학생 정보 입력" << endl;
	if (Students[iStudentsCount - 1].Name[0] != 0)
	{
		cout << "입력할 수 있는 학생이 최대입니다. 입력불가" << endl;
		return;
	}
		
	cout << "학생의 이름을 입력하시오." << endl;
	cin >> Students[*iInputCount].Name;
	cout << "학생의 학번을 입력하시오." << endl;
	cin >> Students[*iInputCount].StudentNum;
	cout << "학생의 국어 성적을 입력하시오." << endl;
	cin >> Students[*iInputCount].iKor;
	cout << "학생의 영어 성적을 입력하시오." << endl;
	cin >> Students[*iInputCount].iEng;
	cout << "학생의 수학 성적을 입력하시오." << endl;
	cin >> Students[*iInputCount].iMath;
	*iInputCount++;
	system("cls");
}

void ReviseStudentInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "학생 정보 수정" << endl;	
	cout << "수정하고자 하는 학생 학번을 입력하시오." << endl;
	int ReviseNum;
	cin >> ReviseNum;
	ReviseNum = SearchStudentInfo(Students, iStudentsCount, ReviseNum);
	if (ReviseNum == -1)
		return;
	else {
		cout << "학생의 이름을 입력하시오." << endl;
		cin >> Students[ReviseNum].Name;
		cout << "학생의 학번을 입력하시오." << endl;
		cin >> Students[ReviseNum].StudentNum;
		cout << "학생의 국어 성적을 입력하시오." << endl;
		cin >> Students[ReviseNum].iKor;
		cout << "학생의 영어 성적을 입력하시오." << endl;
		cin >> Students[ReviseNum].iEng;
		cout << "학생의 수학 성적을 입력하시오." << endl;
		cin >> Students[ReviseNum].iMath;
	}
	system("cls");
}

int SearchStudentInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "학생 정보 검색(학번을 입력하세요,)" << endl;
	int SearchNum;
	cin >> SearchNum;

	for (int i = 0; i < iStudentsCount; i++)
	{
		if (Students[i].StudentNum == SearchNum)
		{
			cout << "학생 번호 : " << Students[i].StudentNum << "번\t" << "이름 : " << Students[i].Name << "\t 국어 성적 : " << Students[i].iKor << "\t 영어 성적 : " << Students[i].iEng << "\t 수학 성적 : " << Students[i].iMath << endl;
			return i;
			system("cls");
		}
	}
	cout << "해당하는 학번이 없습니다." << endl;
	return 0;
}
int SearchStudentInfo(STUDENT Students[], int iStudentsCount, int ReviseNum)
{
	for (int i = 0; i < iStudentsCount; i++)
	{
		if (Students[i].StudentNum == ReviseNum)
			return i;
	}
	cout << "해당하는 학번이 없습니다." << endl;
	return -1;
}
void PrintStudentsInfo(STUDENT Students[], int iStudentsCount)
{
	cout << "전체 학생 정보" << endl;
	for (int i = 0; i < iStudentsCount; i++)
	{
		cout << "학생 번호 : " << Students[i].StudentNum<< "번\t" << "이름 : " << Students[i].Name << "\t 국어 성적 : " << Students[i].iKor << "\t 영어 성적 : " << Students[i].iEng << "\t 수학 성적 : " << Students[i].iMath << endl;
	}
}
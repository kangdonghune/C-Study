#include <iostream>
#include <string>
using namespace std;

void PrintArray(string names[], int point[], int count)
{
	for (int y = 0; y < count; y++)
	{
		cout << names[y] << " : ";
		cout << point[y] << endl;
	}
}



int main()
{
	//����1. ������ �̸��� ������ ���������� ���
	
	string names[6] = { "ö��", "����", "���", "�ΰ�", "����", "�ϰ�" };
	int point[6] = { 60,70,50,76,80,99 };

	PrintArray(names, point, size(names));

	//���� 2.���ĺ� �ƽ�Ű ����0ǥ �����
	
	char LargeAlpha[26]{};
	char SmallAlpha[26]{};
	for (int i = 65, j= 0; i < 91; i++, j++)
	{
		LargeAlpha[j] = i;
		SmallAlpha[j] = i+32;
	}

	char AsciiCode[2][26];
	
	//AsciiCode[0] = LargeAlpha;

	for (int i = 0; i < size(AsciiCode[0]); i++)
	{
		AsciiCode[0][i] = LargeAlpha[i];
	}

	for (int i = 0; i < size(AsciiCode[1]); i++)
	{
		AsciiCode[1][i] = SmallAlpha[i];
	}

	for (int i = 0; i < size(AsciiCode); i++)
	{
		for (int j = 0; j < size(AsciiCode[i]); j++)
		{
			cout << AsciiCode[i][j] << " : " << (int)AsciiCode[i][j]<< " ";
		}
		cout << "" << endl;
	}

}
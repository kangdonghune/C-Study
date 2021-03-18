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
	//문제1. 각각의 이름과 점수를 순차적으로 출력
	
	string names[6] = { "철수", "영희", "재경", "민경", "국경", "록경" };
	int point[6] = { 60,70,50,76,80,99 };

	PrintArray(names, point, size(names));

	//문제 2.알파벳 아스키 문자0표 만들기
	
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
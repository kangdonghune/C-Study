// 0413.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

template <typename T>
bool Ascending(T Num1, T Num2)
{
	if (Num1 < Num2)
		return true;
	else
		return false;
}

bool IsEven(int iNum)
{
	if (iNum % 2 == 0)
		return true;
	else
		return false;
}
int main()
{
	//조건자. bool값을 반환하는 함수 또는 함수 객체.
	//단항조건자와 이항조건자
	vector<int> vecInt;
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(5);
	vecInt.push_back(1);
	vecInt.push_back(7);
	vecInt.push_back(6);
	vecInt.push_back(9);
	vecInt.push_back(8);
	sort(vecInt.begin(), vecInt.end(), Ascending<int>); //sort는 defalut 오름차순. 조건자에 따라 내림차순으로도.
	int iCount = count_if(vecInt.begin(), vecInt.end(), IsEven); //마지막 인자로 조건자 함수의 주소를 받는다. 객체 함수면 임시생성자()까지 붙여서.

	for (auto& iNum : vecInt)
	{
		cout << iNum << endl;
	}
	cout << iCount << endl;

	return 0;
}


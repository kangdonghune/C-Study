// 0413.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	//������. bool���� ��ȯ�ϴ� �Լ� �Ǵ� �Լ� ��ü.
	//���������ڿ� ����������
	vector<int> vecInt;
	vecInt.push_back(2);
	vecInt.push_back(3);
	vecInt.push_back(5);
	vecInt.push_back(1);
	vecInt.push_back(7);
	vecInt.push_back(6);
	vecInt.push_back(9);
	vecInt.push_back(8);
	sort(vecInt.begin(), vecInt.end(), Ascending<int>); //sort�� defalut ��������. �����ڿ� ���� �����������ε�.
	int iCount = count_if(vecInt.begin(), vecInt.end(), IsEven); //������ ���ڷ� ������ �Լ��� �ּҸ� �޴´�. ��ü �Լ��� �ӽû�����()���� �ٿ���.

	for (auto& iNum : vecInt)
	{
		cout << iNum << endl;
	}
	cout << iCount << endl;

	return 0;
}


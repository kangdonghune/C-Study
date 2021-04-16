// 0413.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <functional>


int main()
{
	//list- node ���, ���Ի��� ����.
	list<int> lstInt;

	lstInt.push_back(1);
	lstInt.push_back(9);
	lstInt.push_back(42);
	lstInt.push_back(2);
	lstInt.push_back(0);
	lstInt.push_back(23);

	lstInt.pop_back();
	lstInt.pop_front();
	lstInt.push_front(0); // �յڷ� ���� ���� �� �ִ�.

	list<int>::iterator iter = lstInt.begin();
	//cout << *(iter + 2) << endl; ����Ʈ�� �迭 ����� �ƴϱ⿡ ������ ���� ����� �Ұ��ϴ�.
	//����� �ݺ��ڴ� ������ ���ų� �ڷΰ��ų��� �ȴ�. ++ -- �� �����ε� �Ǿ��ִ�.
	list<int>::size_type i = 10;
	i = lstInt.max_size();
	for (; iter != lstInt.end(); ++iter)
	{
		cout << *iter << endl;
	}
	
	for (auto& iNum : lstInt) // �������for���� �ڵ����� ���̸� ��Ƽ� �����´�. �� �� ��� �߰� ���� ������ �ȵȴ�. ����ϴ��� �� ��� ���߰� �����ٴ� ������.
	{
		cout << iNum << endl;
	}

	lstInt.sort(); //default ��������
	for (auto& iNum : lstInt) // �������for���� �ڵ����� ���̸� ��Ƽ� �����´�. �� �� ��� �߰� ���� ������ �ȵȴ�. ����ϴ��� �� ��� ���߰� �����ٴ� ������.
	{
		cout << iNum << endl;
	}
	lstInt.sort(greater<>());
	for (auto& iNum : lstInt) // �������for���� �ڵ����� ���̸� ��Ƽ� �����´�. �� �� ��� �߰� ���� ������ �ȵȴ�. ����ϴ��� �� ��� ���߰� �����ٴ� ������.
	{
		cout << iNum << endl;
	}

	//���Ϳ��� ���̴� ���ʹ� �˰��� ����� sort�� ������ ����Ʈ�� ��� �Լ��� sort�� ������ �ִ�.
	
	return 0;
}


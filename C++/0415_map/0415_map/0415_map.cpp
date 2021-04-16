// 0415_map.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <algorithm>

int main()
{
	//map- �����-���������̳�, Ʈ�� ����.  �ڰ���������Ʈ��(���� ��)
	//���� ���� �� �ڵ������� �Ͼ�� ���� ���Ҵ� �⺻ Ű�� ������ �ѽ��� �̷��. key ���� ���Ե� ���Ŀ��� const ���ȭ �ȴ�. value�� ���� ����.
	//���� Ž���� �ϴ� Ž���� ������. ��� ���� ������ �Ҹ��ϴ�.
	//����� �� �����ϰ� ������ �����ε��� �Ǿ��ִ�.
	//�ߺ�Ű�� ��� x

	
	map<int, int> mapInt;
	//map�� Ű�� ���� �ѽ��� ������. pair
	pair<int, int> tPair;
	tPair.first = 1;
	tPair.second = 20;
	mapInt.insert(tPair); //1
	mapInt.insert(pair<int, int>(2, 30));//2
	mapInt.insert({});//3
	mapInt.insert(make_pair(88, 85));//4
	mapInt.insert(map<int, int>::value_type(5, 60));//5 insert�� �ߺ� Ű�� �� ���� x
	mapInt[8] = 70;//6 . //�ش� Ű ���� ������ ������ ����� 0�ʱ�ȭ. �̰��� 8�� ���� ��Ȳ�̴� 8�̶�� Ű�� 70�̶�� ������ ���� �� �״�� �־����. Ű�� �ߺ��� ��� ������ �������� �����ع�����. ���Ժ��ٴ� Ű���˻� �� ���� ���� �ø� �������.
	mapInt.emplace(make_pair(55, 85));
	mapInt.emplace(843, 11);

	mapInt.erase(2);//Ű ������ ���� ���� �ְ� �ݺ��ڷ� ���� ���� �ִ�.

	map<int, int>::iterator iter = mapInt.begin();

	for (; iter != mapInt.end(); iter++)
	{
		cout << (*iter).first << "," << (*iter).second << endl;
	}

	map<const char*, int> mapStudent; // Ű���� �ּҰ��� ��� �ּҰ����� ������ �Ѵ�. �ƽ�Ű �ڵ峪 �׷� �ŷ� ���ĵǴ°� �ƴϴ�. find()�� �� ���� �ƽ�Ű�� �׷� �� �ƴϰ� �ּҰ����� Ž���Ѵ�.

	mapStudent.emplace("�ؼ�", 28);

	map<const char*, int>::iterator iter2 = mapStudent.begin();

	for (; iter2 != mapStudent.end(); iter2++)
	{
		cout << (*iter2).first << "," << (*iter2).second << endl;
	}
    return 0;
}


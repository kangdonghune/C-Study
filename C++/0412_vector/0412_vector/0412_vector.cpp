// 0412_vector.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	//vector = ���ø� ���. �迭 ��� �����̳��� ����.
	//�߰� ���� ������ �Ҹ�. Ž���� ����

	//������̼� Ÿ�԰��� �������� ���� �Ҵ����� �� ��������� �Ѵ�.
	vector<int> vecInt;
	vecInt.push_back(10); // Ŭ���� �ȿ� ������ �߰� ������ ���� ��� �Լ��� �ִ�.
	vecInt.at(0) = 12; // �ش� �ε��� �� ����.
	vecInt.pop_back();
	vecInt.size(); // ���� ������ ��ȯ.
	vecInt.capacity(); // ���� �Ҵ���� ũ�⸦ ��ȯ. 1.5��� ����.
	vecInt.clear(); //�ϴ� ���������� �Լ�.
	vector<int> vecTemp;
	vecInt.swap(vecTemp); //�������� �� ������� �ߴ�. �� �迭�� ������ �ع����� 0�ʱ�ȭ. ��� �ٲ� �迭�� �ܿ� ũ�Ⱑ ���´�.
	//�׷��� �߰�ȣ ����� ������� ���� ������ ����� �����ع����� �ٲ� �� �ش� ���Ͱ� �Ҹ��ϴ� �̷� ����� �ִ�.
	//�ٵ� �̰� �� �����ϴ� ���� �ӽ� �޸�, �ӽ� ��ü�� ���� �ع�����.
	//c++ 11 ������ ���ķ� ���� ���̰� �ִµ� 11���� �̻� ������ �� �Ŷ� Ȯ���� ������ �ϴ� �� ��Ŀ� �ͼ������� ���� �� �� ���� �Լ��� �Ẹ��.
	vecTemp.swap(vector<int>());
	cout << vecTemp.size() << endl;
	cout << vecTemp.capacity() << endl;
	vecInt.empty();//��������� true �ƴϸ� false;
	vecInt.push_back(10);
	//�ݺ��� iterator - �����Ϳ� ����� ����
	//�����̳� ���� ������ �ٸ��� ��ȸ����� ȹ��ȭ.
	//�� �����̳ʸ��� ��ü�������� ����. ���ʹ� �迭 ��� ����Ʈ�� ��� ��� ���� ��� ��� Ʈ�� ����.
	//���� �ϳ��� ����Ű�� �⺻ ������ �ϸ� ���ҿ� �����Ͽ� �����͸� �а� �� �� �ִ�.
	//�ݺ����� �������� ���� ���� �ݺ���, ����� �ݺ���,// �ܹ��� �ݺ���, const �ݺ���.
	//������ ��쿡�� ���� ���� �ݺ���, ����Ʈ�� ����� �ݺ���.
	vector<int>::iterator iter = vecInt.begin();//int�� �Ҵ� Ÿ������ �޴� vector�� �ݺ���.
	cout << *iter << endl;
	*iter = 20;
	cout << *iter << endl;

	//���� ���� �ݺ���.
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);
	vecInt.push_back(60);
	vecInt.push_back(70);
	vecInt.push_back(80);
	vecInt.push_back(90);
	vecInt.push_back(100);
	vecInt.push_back(110);
	vecInt.push_back(100);
	vecInt.push_back(110);

	vector<int>::iterator iter2 = vecInt.end();//end()�� ���� �������� �� �� �ּ�. back�� ������ ����.
	iter2--;
	cout << *iter2 << endl;
	vecInt.insert(iter2 - 5, 70);
	iter2 = vecInt.erase(iter2 - 5);//erase�� ��� �ش� iter �ݺ����� ��ȿȭ�� ����Ų��. �׷��� �ش� iter �ٷ� ���� �ּҰ��� ��ȯ���ش�.
	//iter2 �� erase �� ������ ������ ���� ���� �ּҿ��µ� �� ĭ �� ������鼭 iter - 1 �� ������ �� ���� �ּҰ� �ȴ�.
	//�ݺ��� �� ���� ���� �ʱ�ȭ�� ����� �� ������. ���� ���� �ٷ� �ʱ�ȭ�� ������.
	//�ù�. �ݺ��ڴ� �ּҸ� ����Ű�µ� capacity�� �� ���� �߰��� �� �޸� ���Ҵ��� �Ǹ� �ּҰ��� �ٲ�� ������ iter�� ��ȿ���� ���� �ּҸ� ����Ű�� �ȴ�.
	//�ݺ��� ���� ���� begin�̳� end�� �ʱ�ȭ���ָ鼭 ����.
	cout << vecInt.size() << endl;
	cout << vecInt.capacity() << endl;
	
	//erase �� insert �� ���� ���Ϳ� ������ ���ϴ� �������� �ּҿ� �ش��ϴ� ���Ұ��� ����Ǳ� ������ ������ �����.

	vector<int> vecInt3;
	vecInt3.reserve(10); //capacity ���� �̸� �������ִ� ��. ���� �Ҵ� �����༭ ���� �� ������.
	vecInt3.resize(4); //resize�� ���ұ��� �Ҵ��� �ϴ� ��. �ٵ� �� �� ���� capacity�� resize�� reserve�� �������� ���Ѵ�.


	//cout << *iter2 << endl;
	//for (int iNum : vecInt)
	//	cout << iNum << endl;

	return 0;
}


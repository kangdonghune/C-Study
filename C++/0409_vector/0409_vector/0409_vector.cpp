// 0409_vector.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>

//�����迭 ������� ������� �����̳�
//�����迭 ����̱⿡ �ε��� ���ٰ���
//���͵� �ᱹ ��ü��. ��ü�� �����Ϳ� �����͸� �ٷ�� ����̴�.
int main()
{
	vector<int> vecInt; // vector ����
	vecInt.push_back(10); // �ڿ������� �����ϴ� ���� ���� ���� �Լ�.000000000
	cout << vecInt[0] << endl;
	vecInt.pop_back();
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);
	vecInt.push_back(60);
	cout << vecInt[0] << endl;
	cout << vecInt.size() << endl; //���� ������ ������ ��ȯ.
	for (int a : vecInt)
	{
		cout << a << endl;
	}
	for (auto a : vecInt) // �ڵ����� ������ �����Ͽ� �����Ϸ��� ����
	{
		cout << a << endl;
	}

	//using namespace std;
	//vector <int> v1;
	//vector <int>::iterator Iter;

	//v1.push_back(10);
	//v1.push_back(20);
	//v1.push_back(30);

	//cout << "v1 =";
	//for (Iter = v1.begin(); Iter != v1.end(); Iter++)
	//	cout << " " << *Iter;
	//cout << endl;

	//// initialize a vector of vectors by moving v1
	//vector < vector <int> > vv1;

	//vv1.emplace(vv1.begin(), move(v1));
	//if (vv1.size() != 0 && vv1[0].size() != 0)
	//{
	//	cout << "vv1[0] =";
	//	for (Iter = vv1[0].begin(); Iter != vv1[0].end(); Iter++)
	//		cout << " " << *Iter;
	//	cout << endl;
	//}

    return 0;
}


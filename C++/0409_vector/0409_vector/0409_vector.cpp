// 0409_vector.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>

//동적배열 기반으로 만들어진 컨테이너
//동적배열 기반이기에 인덱스 접근가능
//벡터도 결국 객체다. 객체는 데이터와 데이터를 다루는 기술이다.
int main()
{
	vector<int> vecInt; // vector 선언
	vecInt.push_back(10); // 뒤에서부터 삽입하는 벡터 원소 삽입 함수.000000000
	cout << vecInt[0] << endl;
	vecInt.pop_back();
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
	vecInt.push_back(50);
	vecInt.push_back(60);
	cout << vecInt[0] << endl;
	cout << vecInt.size() << endl; //현재 원소의 개수를 반환.
	for (int a : vecInt)
	{
		cout << a << endl;
	}
	for (auto a : vecInt) // 자동으로 변수를 추정하여 컴파일러가 결정
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


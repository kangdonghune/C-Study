// 0415_map.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <algorithm>

int main()
{
	//map- 노드기반-연관컨테이너, 트리 구조.  자가균형이진트리(레드 블랙)
	//원소 삽입 시 자동정렬이 일어나며 맵의 원소는 기본 키와 벨류로 한쌍을 이룬다. key 경우는 삽입된 이후에는 const 상수화 된다. value는 변경 가능.
	//이진 탐색을 하니 탐색을 빠르다. 대신 삽입 삭제가 불리하다.
	//노드기반 중 유일하게 연산자 오버로딩이 되어있다.
	//중복키값 허용 x

	
	map<int, int> mapInt;
	//map은 키와 벨류 한쌍을 가진다. pair
	pair<int, int> tPair;
	tPair.first = 1;
	tPair.second = 20;
	mapInt.insert(tPair); //1
	mapInt.insert(pair<int, int>(2, 30));//2
	mapInt.insert({});//3
	mapInt.insert(make_pair(88, 85));//4
	mapInt.insert(map<int, int>::value_type(5, 60));//5 insert는 중복 키값 시 실행 x
	mapInt[8] = 70;//6 . //해당 키 값이 없으면 공간을 만들고 0초기화. 이경우는 8이 없는 상황이니 8이라는 키와 70이라는 벨류를 가진 걸 그대로 넣어버린. 키가 중복될 경우 벨류를 대입으로 수정해버린다. 삽입보다는 키값검색 후 벨류 수정 시를 고려하자.
	mapInt.emplace(make_pair(55, 85));
	mapInt.emplace(843, 11);

	mapInt.erase(2);//키 값으로 지울 수도 있고 반복자로 지울 수도 있다.

	map<int, int>::iterator iter = mapInt.begin();

	for (; iter != mapInt.end(); iter++)
	{
		cout << (*iter).first << "," << (*iter).second << endl;
	}

	map<const char*, int> mapStudent; // 키값이 주소값인 경우 주소값으로 정렬을 한다. 아스키 코드나 그런 거로 정렬되는게 아니다. find()를 쓸 때도 아스키나 그런 게 아니고 주소값으로 탐색한다.

	mapStudent.emplace("준성", 28);

	map<const char*, int>::iterator iter2 = mapStudent.begin();

	for (; iter2 != mapStudent.end(); iter2++)
	{
		cout << (*iter2).first << "," << (*iter2).second << endl;
	}
    return 0;
}


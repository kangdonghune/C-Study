// 0412_vector.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	//vector = 템플릿 기반. 배열 기반 컨테이너의 딜종.
	//중간 삽입 삭제에 불리. 탐색에 유리

	//얼로케이션 타입값이 포인터일 경우는 할당해제 후 제거해줘야 한다.
	vector<int> vecInt;
	vecInt.push_back(10); // 클래스 안에 데이터 추가 삭제를 위한 멤버 함수가 있다.
	vecInt.at(0) = 12; // 해당 인덱스 값 변경.
	vecInt.pop_back();
	vecInt.size(); // 원소 개수를 반환.
	vecInt.capacity(); // 현재 할당받은 크기를 반환. 1.5배로 증가.
	vecInt.clear(); //싹다 지워버리는 함수.
	vector<int> vecTemp;
	vecInt.swap(vecTemp); //옛날에는 이 방식으로 했다. 빈 배열과 스왚을 해버려서 0초기화. 대신 바꾼 배열에 잔여 크기가 남는다.
	//그러면 중괄호 벗어나면 사라지는 지역 변수를 만들고 스왚해버리면 바꾼 후 해당 벡터가 소멸하니 이런 방식이 있다.
	//근데 이건 좀 복잡하니 차라리 임시 메모리, 임시 객체로 만들어서 해버리자.
	//c++ 11 이전과 이후로 많은 차이가 있는데 11버젼 이상 버젼을 쓸 거란 확신이 없으니 일단 이 방식에 익숙해지고 추후 좀 더 편한 함수를 써보자.
	vecTemp.swap(vector<int>());
	cout << vecTemp.size() << endl;
	cout << vecTemp.capacity() << endl;
	vecInt.empty();//비어있으면 true 아니면 false;
	vecInt.push_back(10);
	//반복자 iterator - 포인터와 비슷한 개념
	//컨테이너 마다 구조가 다른데 순회방법을 획일화.
	//각 컨테이너마다 객체형식으로 제공. 벡터는 배열 기반 리스트는 노드 기반 맵은 노드 기반 트리 구조.
	//원소 하나를 가리키는 기본 역할을 하며 원소에 접근하여 데이터를 읽고 쓸 수 있다.
	//반복자의 종류에는 임의 접근 반복자, 양반향 반복자,// 단방향 반복자, const 반복자.
	//벡터의 경우에는 임의 접근 반복자, 리스트는 양방향 반복자.
	vector<int>::iterator iter = vecInt.begin();//int를 할당 타입으로 받는 vector의 반복자.
	cout << *iter << endl;
	*iter = 20;
	cout << *iter << endl;

	//임의 접근 반복자.
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

	vector<int>::iterator iter2 = vecInt.end();//end()는 원소 마지막의 그 뒤 주소. back은 마지막 원소.
	iter2--;
	cout << *iter2 << endl;
	vecInt.insert(iter2 - 5, 70);
	iter2 = vecInt.erase(iter2 - 5);//erase의 경우 해당 iter 반복자의 무효화를 일으킨다. 그래서 해당 iter 바로 다음 주소값을 반환해준다.
	//iter2 는 erase 전 벡터의 마지막 원소 다음 주소였는데 한 칸 씩 댕겨지면서 iter - 1 도 참조할 수 없는 주소가 된다.
	//반복자 쓸 때는 자주 초기화를 해줘야 덜 터진다. 쓰고 나면 바로 초기화를 해주자.
	//시발. 반복자는 주소를 가리키는데 capacity가 다 차서 추가할 떄 메모리 재할당이 되면 주소값이 바뀌니 기존의 iter가 유효하지 못한 주소를 가리키게 된다.
	//반복자 쓰고 나면 begin이나 end로 초기화해주면서 하자.
	cout << vecInt.size() << endl;
	cout << vecInt.capacity() << endl;
	
	//erase 든 insert 든 기존 벡터에 변형을 가하는 시점에서 주소에 해당하는 원소값이 변경되기 때문에 문제가 생긴다.

	vector<int> vecInt3;
	vecInt3.reserve(10); //capacity 값을 미리 예약해주는 것. 원소 할당 안해줘서 접근 시 터진다.
	vecInt3.resize(4); //resize는 원소까지 할당을 하는 것. 근데 한 번 잡힌 capacity는 resize나 reserve로 줄이지는 못한다.


	//cout << *iter2 << endl;
	//for (int iNum : vecInt)
	//	cout << iNum << endl;

	return 0;
}


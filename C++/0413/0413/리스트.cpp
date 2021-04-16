// 0413.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <functional>


int main()
{
	//list- node 기반, 삽입삭제 유리.
	list<int> lstInt;

	lstInt.push_back(1);
	lstInt.push_back(9);
	lstInt.push_back(42);
	lstInt.push_back(2);
	lstInt.push_back(0);
	lstInt.push_back(23);

	lstInt.pop_back();
	lstInt.pop_front();
	lstInt.push_front(0); // 앞뒤로 뺴고 넣을 수 있다.

	list<int>::iterator iter = lstInt.begin();
	//cout << *(iter + 2) << endl; 리스트는 배열 기반이 아니기에 다음과 같은 방식이 불가하다.
	//양방향 반복자는 앞으로 가거나 뒤로가거나만 된다. ++ -- 만 오버로딩 되어있다.
	list<int>::size_type i = 10;
	i = lstInt.max_size();
	for (; iter != lstInt.end(); ++iter)
	{
		cout << *iter << endl;
	}
	
	for (auto& iNum : lstInt) // 범위기반for문은 자동으로 길이를 잡아서 가져온다. 단 이 경우 중간 삽입 삭제가 안된다. 사용하더라도 그 경우 멈추고 나간다는 식으로.
	{
		cout << iNum << endl;
	}

	lstInt.sort(); //default 오름차순
	for (auto& iNum : lstInt) // 범위기반for문은 자동으로 길이를 잡아서 가져온다. 단 이 경우 중간 삽입 삭제가 안된다. 사용하더라도 그 경우 멈추고 나간다는 식으로.
	{
		cout << iNum << endl;
	}
	lstInt.sort(greater<>());
	for (auto& iNum : lstInt) // 범위기반for문은 자동으로 길이를 잡아서 가져온다. 단 이 경우 중간 삽입 삭제가 안된다. 사용하더라도 그 경우 멈추고 나간다는 식으로.
	{
		cout << iNum << endl;
	}

	//벡터와의 차이는 벡터는 알고리즘 헤더의 sort를 쓰지만 리스트는 멤버 함수로 sort를 가지고 있다.
	
	return 0;
}


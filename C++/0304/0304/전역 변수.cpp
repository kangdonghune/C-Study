#include <iostream>

using namespace std;

int gValue; //전역변수
static int iStatic;
//static 변수는 지역에서도 선언 가능하며 초기화는 단 한 번만 실시된다. 그에 따라 함수가 반복되도 변수가 초기화되지 않고 누적될 수 있다.

//전역 변수나 static 변수는 일단 메모리 공간 낭비가 있다.
//자주 계속 쓰는 거면 상관없는데 한 두번 쓰고 말거면 계속 상주시키는 게 낭비다
//그리고 전역에서 건들 수 있다는 거는 수정이 마음대로 이루어질 수 있다는 거고 곧 문제가 될 수 있다는 거니 주의해서 쓰자
//그래서 전역변수 말고 매개변수 등으로 데이터를 건네주는 것.
void Test1() //변수가 계속 증가
{
	static int iStatic2 = 0;
	iStatic2++;
	cout << iStatic2 << endl;
}

void Test2() //변수가 매번 초기화 되어 값 증가 없음.
{
	int iNonStatic = 0;
	iNonStatic++;
	cout << iNonStatic << endl;
}

int main()
{
	Test1();
	Test1();
	Test1();
	Test1();
	Test1();

	Test2();
	Test2();
	Test2();
	Test2();
	Test2();
	Test2();
}


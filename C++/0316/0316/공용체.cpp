#include <iostream>
using namespace std;

union MyUnion // 공용체. 멤버 변수 중 하나만 선택.
{
	int a;
	int b;
};

enum Player // 열거형에 들어가는 것들은 기본적으로 상수(정수) 기질을 가지게 된다. 따로 지정하지 않으면 순서대로 0부터 부여. 필요한 상수들을 묶어놓은 것.
{
	Player_ATT = 12, //이런 식으로 값을 지정해주면 그 다음 거는 13 14 이런 식으로 이전 것에 +1 한 값이 들어간다.
	Player_DIE, // 13 . 참고로 동일한 숫자를 지정할 수 있지만 굳이 그렇게 쓸 필요성이 적다.
	Size //이런 식으로 size 등을 넣어두면 배열의 크기 같은 것을 지정할 때도 사용하기 쉽다. 이를 이용하면 함수에서도 size를 별도로 매개변수로 안 받고도 쓸 수 있다.
};

struct MyStruct
{

};

void main()
{
	MyUnion tUnion = { 10 };
	cout << tUnion.a << "," << tUnion.b << endl;
	// 같은 메모리 공간을 공유해서 쓰는 구나. 메모리 공간에 또 다른 이름을 부여할 수 있다.
	// 자료형을 커스텀마이징해서 써야할 때 쓰였다.
	// 사용하기가 쉽지도 않아서 잘 쓰이진 않는다.

	Player ePlayer = Player_ATT;
	switch (ePlayer)
	{
	case Player_ATT: // 이런 식으로 상수나 숫자 같은 게 아니라 보다 명시적인 이름으로 적어줄 수 있다.
		break;
	}
	//Player ePlayer = 1; // 이 경우는 서로 타입이 달라 대입이 안 된다.
	int Player = Player_ATT; // 반대는 되는데 이를 통해 알 수 있는 건 교환법칙이 성립하지 않는다.
	//ePlayer = Player_ATT + Player_DIE; //이 경우는 더 해진 두 수가 상수가 아니라 정수가 되어서 연산이 안된다. 
	//이는 Player의 값은 상수로 인식이 되어 int에 넣을 수 있는데 반대의 경우 Player 자료형에 대해 모르기에 int 값을 넣지 못한다.
	//꼭 기억해라. 교환법칙 안된다.
}
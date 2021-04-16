#include "stdafx.h"
#include "C_Object.h"
#include "Player.h"
#include "Monster.h"
#include "User.h"

int main()
{
	//CPlayer tPlayer; //자식을 생성하게 되면 부모 생성자를 먼저 호출한 뒤 자식 생성자가 호출 된다. 소멸할 때는 자식이 먼저 소멸되고 이후 부모가 소멸된다.
	//tPlayer.Render(); //자식이 부모의 멤버 변수를 가져다 쓴다.
	CUser tU;
	tU.SetHp(50);
	tU.Render();
	cout << tU.m_iHP << endl;
	return 0;

	//상속은 is ~ a 관계와 has ~ a 관계가 있다.
	//전자는 자식은 부모다. 후자는 자식은 부모의 것을 가지고 있다.
	//후자는 잘 안 꾸리는 편이다. 다중상속의 위험이 있다. 차라리 포인터 멤버 변수로 가지고 말지.
	//has a 관계로 꾸릴 경우 함수 명, 변수명 등이 겹치는 등의 문제로 모호성 문제가 발생한다.
	//이런 경우 차라리 멤버 변수로 해서 사용하자. class명 C~;  하고 cpp에서 include해서 쓰자.  또는 포인터 멤버로 쓰거나. 그게 메모리적으로 좋긴하다.

	//객체 포인터
	//포인터 변수인데 객체의 주소값을 가지는
	//객체 포인터 만의 고유한 기능
	//부모 객체 포인터의 경우 직, 간접적으로 상속받는 클래스들의 주소값을 보관할 수 있다.
	//객체 포인터의 경우 실 객체가 뭔지 신경 안 쓰고  타입이 맞는지만 체크. 그래서 객체 포인터의 멤버를 사용할 때도 실 객체가 아닌 포인터 타입의 객체 멤버만 한정적으로 쓸 수 있다.

	//CPlayer tPlayer;
	//CPlayer* pPlayer;
	//C_Object* pObj = &tPlayer;
	//pPlayer = (CPlayer*)pObj; //반대로 부모 객체 포인터에 있던 거를 실 객체와 같은 타입의 자식 포인터에 넣어줄 때는 실 객체형으로 형변환을 해주고 넣어줘야 오류 발생이 없다.
	//pObj->most_Render();// 해당 클래스 자체의 함수를 쓸 수도 있고..다만 자식의 함수나 멤버는 접근 불가.

	//걍 실 객체의 포인터로 하면 되지 부모 객체 포인터로 받을 필요가 있을까? 라는 의문이 있을 수 있는데 이게 유지 보수에 편하다.
	//자식 클래스를 매개변수로 받는 함수가 있을 때 자식 클래스가 추가 될 때마다 일일이 다 바꿔줘야 하지만 부호 형식의 객체 포인터로 바꿔주면 자식 클래스가 늘어나도 일일이 수정이 필요 없다.
}
#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	:m_szJob("a"),
	//별도로 부모 생성자를 입력해주지 않을 때 묵시적으로 C_Object() 부모의 기본 생성자를 사용한다고 생각하면 되나? 
	C_Object(100, 20, 5) //자식이 초기화 하고 싶다면 부모의 생성자를 사용하라.
{
	m_iAtt = 10; // 이런 식으로 해도 되지만 차라리 부모 생성자를 오버로딩해서 부모 생성자를 호출하는 것도 된다.
	cout << "자식 생성자 호출" << endl;
}


CPlayer::~CPlayer()
{
	cout << "자식 소멸자 호출" << endl;
}

void CPlayer::Render()
{
	cout << m_iHP << endl;
	cout << m_iAtt << endl;
	cout << m_iDex << endl;
	cout << this->m_szJob << endl;
}

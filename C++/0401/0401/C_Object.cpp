#include "stdafx.h"
#include "C_Object.h"


C_Object::C_Object()
	:m_iHP(0), m_iAtt(0), m_iDex(0)
{
	cout << "부모 생성자 호출" << endl;
}

C_Object::C_Object(int Hp, int Att, int Dex)
	:m_iHP(Hp), m_iAtt(Att), m_iDex(Dex)
{
	cout << "오버로딩 된 부모 생성자" << endl;
}



void C_Object::most_Render()
{
	cout << "최상위의 랜더" << endl;
}

C_Object::~C_Object()
{
	cout << "부모 소멸자 호출" << endl;
}

void C_Object::SetHp(int a)
{
	this->m_iHP << a;
}

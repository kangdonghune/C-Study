#include "stdafx.h"
#include "C_Object.h"


C_Object::C_Object()
	:m_iHP(0), m_iAtt(0), m_iDex(0)
{
	cout << "�θ� ������ ȣ��" << endl;
}

C_Object::C_Object(int Hp, int Att, int Dex)
	:m_iHP(Hp), m_iAtt(Att), m_iDex(Dex)
{
	cout << "�����ε� �� �θ� ������" << endl;
}



void C_Object::most_Render()
{
	cout << "�ֻ����� ����" << endl;
}

C_Object::~C_Object()
{
	cout << "�θ� �Ҹ��� ȣ��" << endl;
}

void C_Object::SetHp(int a)
{
	this->m_iHP << a;
}

#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
	:m_szJob("a"),
	//������ �θ� �����ڸ� �Է������� ���� �� ���������� C_Object() �θ��� �⺻ �����ڸ� ����Ѵٰ� �����ϸ� �ǳ�? 
	C_Object(100, 20, 5) //�ڽ��� �ʱ�ȭ �ϰ� �ʹٸ� �θ��� �����ڸ� ����϶�.
{
	m_iAtt = 10; // �̷� ������ �ص� ������ ���� �θ� �����ڸ� �����ε��ؼ� �θ� �����ڸ� ȣ���ϴ� �͵� �ȴ�.
	cout << "�ڽ� ������ ȣ��" << endl;
}


CPlayer::~CPlayer()
{
	cout << "�ڽ� �Ҹ��� ȣ��" << endl;
}

void CPlayer::Render()
{
	cout << m_iHP << endl;
	cout << m_iAtt << endl;
	cout << m_iDex << endl;
	cout << this->m_szJob << endl;
}

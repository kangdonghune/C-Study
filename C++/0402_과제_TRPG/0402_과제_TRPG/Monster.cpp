#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
	Init();
}


CMonster::~CMonster()
{
}

void CMonster::Init()
{
	m_pStatus = new STATUS; // �÷��̾� ���� �� �������ͽ� ����ü �����Ҵ�.
	*m_pStatus = {}; // ��� �� 0 �ʱ�ȭ.
}

void CMonster::ShowInfo()
{
	cout << "----------------------------------------" << endl;
	cout << "Lv:\t" << m_pStatus->m_iLV << endl;
	cout << "����:\t" << m_pStatus->m_szClassName << endl;
	cout << "HP:\t" << m_pStatus->m_iHP << endl;
	cout << "���ݷ�:\t" << m_pStatus->m_iATK << endl;
	cout << "����:\t" << m_pStatus->m_iDEF << endl;
	cout << "����ġ:\t" << m_pStatus->m_iEXP << endl;
	cout << "���:\t" << m_pStatus->m_iGold << endl;
	cout << "----------------------------------------" << endl;
}

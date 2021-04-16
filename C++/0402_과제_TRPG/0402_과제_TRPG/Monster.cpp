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
	m_pStatus = new STATUS; // 플레이어 생성 시 스테이터스 구조체 동적할당.
	*m_pStatus = {}; // 모든 값 0 초기화.
}

void CMonster::ShowInfo()
{
	cout << "----------------------------------------" << endl;
	cout << "Lv:\t" << m_pStatus->m_iLV << endl;
	cout << "직업:\t" << m_pStatus->m_szClassName << endl;
	cout << "HP:\t" << m_pStatus->m_iHP << endl;
	cout << "공격력:\t" << m_pStatus->m_iATK << endl;
	cout << "방어력:\t" << m_pStatus->m_iDEF << endl;
	cout << "경험치:\t" << m_pStatus->m_iEXP << endl;
	cout << "골드:\t" << m_pStatus->m_iGold << endl;
	cout << "----------------------------------------" << endl;
}

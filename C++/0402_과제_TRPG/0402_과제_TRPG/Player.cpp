#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	Init();
}


CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_pStatus = new STATUS; // 플레이어 생성 시 스테이터스 구조체 동적할당.
	*m_pStatus = {}; // 모든 값 0 초기화.
	m_pStatus->m_iMaxInvenSize = 3;
	
}

void CPlayer::ShowInfo()
{
	cout << "----------------------------------------" << endl;
	cout << "이름:\t" << m_pStatus->m_szName << endl;
	cout << "Lv:\t" << m_pStatus->m_iLV << endl;
	cout << "직업:\t" << m_pStatus->m_szClassName << endl;
	cout << "HP:\t" << m_pStatus->m_iHP << endl;
	cout << "공격력:\t" << m_pStatus->m_iATK << endl;
	cout << "방어력:\t" << m_pStatus->m_iDEF << endl;
	cout << "남은 경험치:\t" << m_pStatus->m_iMaxExp - m_pStatus->m_iEXP << endl;
	cout << "소지금:\t" << m_pStatus->m_iGold << endl;
	cout << "인벤토리:\t" << m_pStatus->m_iMaxInvenSize << endl;
	cout << "----------------------------------------" << endl;
}

void CPlayer::LeverUp()
{
	cout << "빰빠빠! 레벨이 올랐습니다!" << endl;
	m_pStatus->m_iLV++;
	m_pStatus->m_iMaxExp += 30;
	m_pStatus->m_iEXP = 0;
	system("pause");
}

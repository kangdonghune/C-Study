#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	SetStatus().iInvenMaxSize = 3;
}


CPlayer::~CPlayer()
{
	cout << "플레이어 소멸" << endl;
	if (m_vecInventory.capacity() != 0)
	{
		cout << "인벤토리 제거" << endl;
		m_vecInventory.clear();
		m_vecInventory.swap(vector<STATUS>());//플레이어 소멸 시 할당된 벡터 제거.
	}
	system("pause");
}

void CPlayer::ShowStatus()
{
	cout << "------------플레이어------------" << endl;
	cout << "이름:\t" << GetStatus().szName << endl;
	cout << "직업:\t" << GetStatus().szClass << endl;
	cout << "레벨:\t" << GetStatus().iLV << endl;
	cout << "체력:\t" << GetStatus().iHP << endl;
	cout << "공격력:\t" << GetStatus().iATK << endl;
	cout << "방어력:\t" << GetStatus().iDEF << endl;
	cout << "남은 경험치:\t" << GetStatus().iMAXEXP - GetStatus().iEXP << endl;
	cout << "골드:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}

void CPlayer::LevelUp()
{
	SetStatus().iLV++;
	SetStatus().iHP = GetStatus().iMAXHP;
	SetStatus().iEXP = 0;
	SetStatus().iMAXEXP = GetStatus().iMAXEXP * 1.2f;
	if (!strcmp(GetStatus().szClass, "전사"))
	{
		SetStatus().iMAXHP = GetStatus().iMAXHP*1.2f;
		SetStatus().iATK = GetStatus().iATK *1.1f;
		SetStatus().iDEF = GetStatus().iDEF *1.2f;
	}
	if (!strcmp(GetStatus().szClass, "법사"))
	{
		SetStatus().iHP += GetStatus().iHP*1.1f;
		SetStatus().iATK += GetStatus().iATK *1.3f;
		SetStatus().iDEF += GetStatus().iDEF *1;
	}
	if (!strcmp(GetStatus().szClass, "도적"))
	{
		SetStatus().iHP += GetStatus().iHP*1.1f;
		SetStatus().iATK += GetStatus().iATK *1.2f;
		SetStatus().iDEF += GetStatus().iDEF *1.1f;
	}
	cout << "레벨업 했습니다." << endl;
	system("pause");
}

void CPlayer::ReSetHP()
{
	SetStatus().iHP = GetStatus().iMAXHP;
}

const vector<STATUS>& CPlayer::GetInventory()
{
	return m_vecInventory;
}

vector<STATUS>& CPlayer::SetInventory()
{
	return m_vecInventory;
}

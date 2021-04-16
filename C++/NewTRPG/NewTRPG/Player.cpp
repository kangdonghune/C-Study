#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	SetStatus().iInvenMaxSize = 3;
}


CPlayer::~CPlayer()
{
	cout << "�÷��̾� �Ҹ�" << endl;
	if (m_vecInventory.capacity() != 0)
	{
		cout << "�κ��丮 ����" << endl;
		m_vecInventory.clear();
		m_vecInventory.swap(vector<STATUS>());//�÷��̾� �Ҹ� �� �Ҵ�� ���� ����.
	}
	system("pause");
}

void CPlayer::ShowStatus()
{
	cout << "------------�÷��̾�------------" << endl;
	cout << "�̸�:\t" << GetStatus().szName << endl;
	cout << "����:\t" << GetStatus().szClass << endl;
	cout << "����:\t" << GetStatus().iLV << endl;
	cout << "ü��:\t" << GetStatus().iHP << endl;
	cout << "���ݷ�:\t" << GetStatus().iATK << endl;
	cout << "����:\t" << GetStatus().iDEF << endl;
	cout << "���� ����ġ:\t" << GetStatus().iMAXEXP - GetStatus().iEXP << endl;
	cout << "���:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}

void CPlayer::LevelUp()
{
	SetStatus().iLV++;
	SetStatus().iHP = GetStatus().iMAXHP;
	SetStatus().iEXP = 0;
	SetStatus().iMAXEXP = GetStatus().iMAXEXP * 1.2f;
	if (!strcmp(GetStatus().szClass, "����"))
	{
		SetStatus().iMAXHP = GetStatus().iMAXHP*1.2f;
		SetStatus().iATK = GetStatus().iATK *1.1f;
		SetStatus().iDEF = GetStatus().iDEF *1.2f;
	}
	if (!strcmp(GetStatus().szClass, "����"))
	{
		SetStatus().iHP += GetStatus().iHP*1.1f;
		SetStatus().iATK += GetStatus().iATK *1.3f;
		SetStatus().iDEF += GetStatus().iDEF *1;
	}
	if (!strcmp(GetStatus().szClass, "����"))
	{
		SetStatus().iHP += GetStatus().iHP*1.1f;
		SetStatus().iATK += GetStatus().iATK *1.2f;
		SetStatus().iDEF += GetStatus().iDEF *1.1f;
	}
	cout << "������ �߽��ϴ�." << endl;
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

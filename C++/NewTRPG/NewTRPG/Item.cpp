#include "stdafx.h"
#include "Item.h"


CItem::CItem()
{
}


CItem::~CItem()
{
}

void CItem::SettingItem(const char * pItemName, int iHP, int iATK, int iDEF, int iGold)
{
	strcpy_s(SetStatus().szName,pItemName);
	SetStatus().iHP = iHP;
	SetStatus().iATK = iATK;
	SetStatus().iDEF = iDEF;
	SetStatus().iGold = iGold;
}

void CItem::ShowStatus()
{
	cout << "-------------������-------------" << endl;
	cout << "�̸�:\t" << GetStatus().szName << endl;
	cout << "ü��:\t" << GetStatus().iHP << endl;
	cout << "���ݷ�:\t" << GetStatus().iATK << endl;
	cout << "����:\t" << GetStatus().iDEF << endl;
	cout << "���:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}

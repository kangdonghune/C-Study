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
	cout << "-------------아이템-------------" << endl;
	cout << "이름:\t" << GetStatus().szName << endl;
	cout << "체력:\t" << GetStatus().iHP << endl;
	cout << "공격력:\t" << GetStatus().iATK << endl;
	cout << "방어력:\t" << GetStatus().iDEF << endl;
	cout << "골드:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}

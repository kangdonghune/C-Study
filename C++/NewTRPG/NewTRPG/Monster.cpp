#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::ShowStatus()
{
	cout << "-------------몬스터-------------" << endl;
	cout << "직업:\t" << GetStatus().szClass << endl;
	cout << "레벨:\t" << GetStatus().iLV << endl;
	cout << "체력:\t" << GetStatus().iHP << endl;
	cout << "공격력:\t" << GetStatus().iATK << endl;
	cout << "방어력:\t" << GetStatus().iDEF << endl;
	cout << "경험치:\t" << GetStatus().iEXP << endl;
	cout << "골드:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}


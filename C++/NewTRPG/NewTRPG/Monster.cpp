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
	cout << "-------------����-------------" << endl;
	cout << "����:\t" << GetStatus().szClass << endl;
	cout << "����:\t" << GetStatus().iLV << endl;
	cout << "ü��:\t" << GetStatus().iHP << endl;
	cout << "���ݷ�:\t" << GetStatus().iATK << endl;
	cout << "����:\t" << GetStatus().iDEF << endl;
	cout << "����ġ:\t" << GetStatus().iEXP << endl;
	cout << "���:\t" << GetStatus().iGold << endl;
	cout << "--------------------------------" << endl;
}


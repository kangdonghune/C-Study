#include "stdafx.h"
#include "C_Object.h"


C_Object::C_Object()
	:m_tSTATUS({})
{
}


C_Object::~C_Object()
{
}

void C_Object::Init()
{
}

const STATUS& C_Object::GetStatus()
{
	return m_tSTATUS;
}

STATUS& C_Object::SetStatus()
{
	return m_tSTATUS;
}

void C_Object::SetDamege(C_Object * DEF)
{
	int Damege = DEF->GetStatus().iDEF - GetStatus().iATK;
	if (0 > Damege)
	{
		DEF->SetStatus().iHP += Damege;
	}
}

void C_Object::ReadyGameObj(const char * pClassName, int iHP, int iATK, int iDEF, int iLV, int iMAXEXP, int iGold)
{
	strcpy_s(SetStatus().szClass, pClassName);
	SetStatus().iLV = iLV;
	SetStatus().iMAXHP = iHP;
	SetStatus().iHP = GetStatus().iMAXHP;
	SetStatus().iATK = iATK;
	SetStatus().iDEF = iDEF;
	SetStatus().iEXP = 0;
	SetStatus().iMAXEXP = iMAXEXP;
	SetStatus().iGold = 9999;
}

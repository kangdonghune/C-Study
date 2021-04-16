#include "stdafx.h"
#include "Equipment.h"


CEquipment::CEquipment()
	:m_pEquipStat(nullptr)
{
	Init();
}
CEquipment::~CEquipment()
{
}

void CEquipment::Init()
{
	m_pEquipStat = new EQUIPMENT_STATUS;
	*m_pEquipStat = {};
}

EQUIPMENT_STATUS *  CEquipment::GetEquipStat()
{
	return m_pEquipStat;
}

EQUIPMENT_STATUS* CEquipment::SetEquipment(EQUIPMENT_STATUS *& rEquipStat)
{
	return rEquipStat;
}

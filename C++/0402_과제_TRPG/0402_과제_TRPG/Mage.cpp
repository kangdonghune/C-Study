#include "stdafx.h"
#include "Mage.h"


CMage::CMage()
{
	strcpy_s(m_pStatus->m_szClassName, "นýป็");
	m_pStatus->m_iLV = 1;
	m_pStatus->m_iHP = 50 + m_pStatus->m_iLV * 5;
	m_pStatus->m_iATK = 30 + m_pStatus->m_iLV * 3;
	m_pStatus->m_iDEF = 0 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 0;
	m_pStatus->m_iMaxExp = 100;
	m_pStatus->m_iGold = 10;
}


CMage::~CMage()
{
}

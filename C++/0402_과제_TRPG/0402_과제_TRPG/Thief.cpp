#include "stdafx.h"
#include "Thief.h"


CThief::CThief()
{
	strcpy_s(m_pStatus->m_szClassName, "µµÀû");
	m_pStatus->m_iLV = 1;
	m_pStatus->m_iHP = 80 + m_pStatus->m_iLV * 7;
	m_pStatus->m_iATK = 22 + m_pStatus->m_iLV * 2;
	m_pStatus->m_iDEF = 1 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 0;
	m_pStatus->m_iMaxExp = 100;
	m_pStatus->m_iGold = 10;
}


CThief::~CThief()
{
}

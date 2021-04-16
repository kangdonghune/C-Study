#include "stdafx.h"
#include "Wariior.h"


CWariior::CWariior()
{
	strcpy_s(m_pStatus->m_szClassName, "ภüป็");
	m_pStatus->m_iLV = 1;
	m_pStatus->m_iHP = 100 + m_pStatus->m_iLV * 10;
	m_pStatus->m_iATK = 20 + m_pStatus->m_iLV;
	m_pStatus->m_iDEF = 3 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 0;
	m_pStatus->m_iMaxExp = 100;
	m_pStatus->m_iGold = 10;
}


CWariior::~CWariior()
{
}

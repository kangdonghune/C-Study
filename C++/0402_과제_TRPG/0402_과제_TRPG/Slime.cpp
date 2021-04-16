#include "stdafx.h"
#include "Slime.h"
#include <time.h>

CSlime::CSlime()
{
	srand(unsigned(time(NULL)));
	strcpy_s(m_pStatus->m_szClassName, "½½¶óÀÓ");
	m_pStatus->m_iLV = (rand() % 5) + 1;
	m_pStatus->m_iHP = 30 + m_pStatus->m_iLV * 3;
	m_pStatus->m_iATK = 5 + m_pStatus->m_iLV;
	m_pStatus->m_iDEF = 2 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 10 + m_pStatus->m_iLV * 5;
	m_pStatus->m_iGold = 10 + m_pStatus->m_iLV * 5;
}


CSlime::~CSlime()
{
}




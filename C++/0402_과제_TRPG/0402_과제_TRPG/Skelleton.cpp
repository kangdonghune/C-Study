#include "stdafx.h"
#include "Skelleton.h"
#include <time.h>

CSkelleton::CSkelleton()
{
	srand(unsigned(time(NULL)));
	strcpy_s(m_pStatus->m_szClassName, "ÇØ°ñº´»ç");
	m_pStatus->m_iLV = (rand() % 5) * 2;
	m_pStatus->m_iHP = 45 + m_pStatus->m_iLV * 3;
	m_pStatus->m_iATK = 8 + m_pStatus->m_iLV;
	m_pStatus->m_iDEF = 6 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 15 + m_pStatus->m_iLV * 5;
	m_pStatus->m_iGold = 100 + m_pStatus->m_iLV * 10;
}


CSkelleton::~CSkelleton()
{
	
}


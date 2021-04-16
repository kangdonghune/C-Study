#include "stdafx.h"
#include "Orc.h"
#include <time.h>
COrc::COrc()
{
	srand(unsigned(time(NULL)));
	strcpy_s(m_pStatus->m_szClassName, "¿ÀÅ©");
	m_pStatus->m_iLV = (rand() % 5) * 3;
	m_pStatus->m_iHP = 70 + m_pStatus->m_iLV * 3;
	m_pStatus->m_iATK = 12 + m_pStatus->m_iLV;
	m_pStatus->m_iDEF = 10 + m_pStatus->m_iLV;
	m_pStatus->m_iEXP = 25 + m_pStatus->m_iLV * 5;
	m_pStatus->m_iGold = 300 + m_pStatus->m_iLV * 10;
}


COrc::~COrc()
{

}


#include "stdafx.h"
#include "ScrollManeger.h"

float CScrollManeger::m_fScrollX = 0.f;
float CScrollManeger::m_fScrollY = 0.f;
CScrollManeger::CScrollManeger()
{
}


CScrollManeger::~CScrollManeger()
{
}

void CScrollManeger::ScrollLcok()
{
	if (0 < m_fScrollX)
		m_fScrollX = 0;
	if (0 < m_fScrollY)
		m_fScrollY = 0;

}


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

float CScrollManeger::Set_ScrollX(float _fx)
{
	m_fScrollX += _fx;
	return _fx;
}

float CScrollManeger::Set_ScrollY(float _fy)
{
	m_fScrollY += _fy;
	return _fy;
}

void CScrollManeger::ScrollLcok()
{
	if (0 < m_fScrollX)
		m_fScrollX = 0;
	if (0 < m_fScrollY)
		m_fScrollY = 0;
	

}



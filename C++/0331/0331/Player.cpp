#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::GetGVelue()
{
	g_iValue = 30;
	cout << g_iValue << endl;
	cout << &g_iValue << endl;
}

#include "stdafx.h"
#include "Wave.h"
#include "ScrollManeger.h"
#include <random>
#include "GameObjectManeger.h"
#include "Player.h"

CWave::CWave()
{
}


CWave::~CWave()
{
}

bool CWave::Wave()
{
	static float OldX = 0;
	static float OldY = 0;
	static int Count = 0;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dir(-1, 1);
	OldX += CScrollManeger::Set_ScrollX(dir(gen)*30);
	OldY += CScrollManeger::Set_ScrollY(dir(gen)*30);
	Count++;
	if (3 <= Count)
	{
		CScrollManeger::Set_ScrollX(-OldX);
		CScrollManeger::Set_ScrollY(-OldY);
		Count = 0;
		OldX = 0;
		OldY = 0;
		return false;
	}
	else
		return true;
}

bool CWave::WaveGunRebound()
{
	static float fAngle = dynamic_cast<CPlayer*>(CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::PLAYER).back())->Get_MyGun()->GetInfo()->fAngle;
	static float fAngle2 = 0;
	fAngle2 += 30.f;

	CScrollManeger::Set_ScrollX(-cosf(fAngle/RADIAN) *(sinf(fAngle2) * 8.f));
	//CScrollManeger::Set_ScrollY(-sinf(fAngle/RADIAN) *(sinf(fAngle2) * 5.f));

	if (fAngle2 == 360.f)
	{
		fAngle2 = 0;
		return false;
	}
	else
		return true;
}

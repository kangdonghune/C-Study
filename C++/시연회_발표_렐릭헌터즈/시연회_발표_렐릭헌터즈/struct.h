#pragma once

typedef struct tag_Objinfomation
{
	float fX; //x¡¬«•
	float fY; //y¡¬«•
	int iCX; //x√‡ ≥–¿Ã
	int iCY;//y√‡ ≥–¿Ã
	int iMaxHp;
	int iHP;
	int iDamege;
	float fSpeed;
	float fAngle;
	float fDirX;
	float fDirY;
	DWORD dwTime;
	DWORD LimitTime;
}GAMEOBJINFO;

typedef struct tag_GunInfomation
{
	float	fBulletTime;
	float	fBulletCoolTime;
	float	fBulletDist;
	int		iBulletDamege;
	ITEM::Name Name;
}GUNINFO;

typedef struct tag_BulletInfomation
{
	float	fBulletTime;
	float	fBulletCoolTime;
	float	fBulletDist;
	int		iBulletDamege;
}BULLETINFO;

typedef struct tag_MapObjInfo
{
	float fX;
	float fY;
	int iCX;
	int iCY;
	MAPOBJECT::Object ObjType;
	MAPOBJECTTYPE::TYPE Objfeature;
	int iCellingNum;
	int iWallNum;
}MAPINFO;

typedef struct tag_AnimationINFO
{
	int iStart;
	int iEnd;

}ANIINFO;

typedef struct tag_LaserPointer
{
	float fX;
	float fY;
	float TargetDir;
	float fSpeed;
	float fdistance;
	RECT  RC;
}LaserPoint;

typedef struct tag_acceleration
{
	float fPower;
	float Gravity;
	float fAccel;
}GRAVITY;

typedef struct tag_LogoInfo
{
	float fX;
	float fY;
	int iCX;
	int iCY;
	DWORD dwTime;
	DWORD Limit;
	int iRenderStart;
	int iRenderEnd;
}LOGOINFO;


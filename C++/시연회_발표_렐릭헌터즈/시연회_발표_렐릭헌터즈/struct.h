#pragma once

typedef struct tag_Objinfomation
{
	float fX; //x��ǥ
	float fY; //y��ǥ
	int iCX; //x�� ����
	int iCY;//y�� ����
	int iMaxHp;
	int iHP;
	int iDamege;
	float fSpeed;
	float fAngle;
}G_INFO;

typedef struct tag_MapObjInfo
{
	float fX;
	float fY;
	int iCX;
	int iCY;
}M_INFO;


typedef struct tag_AnimationINFO
{
	int iStart;
	int iEnd;

}ANIINFO;


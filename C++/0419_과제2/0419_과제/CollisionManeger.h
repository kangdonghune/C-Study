#pragma once
class CGameObj;
class CCollisionManeger
{
private:
	CCollisionManeger();

public:
	~CCollisionManeger();

public:
	static void Collision_Rect(list<CGameObj*>* pIisttDest,list<CGameObj*>*plistSrc);
};


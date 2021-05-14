#include "stdafx.h"
#include "CollisionManeger.h"
#include "GameObj.h"

CCollisionManeger::CCollisionManeger()
{
}


CCollisionManeger::~CCollisionManeger()
{
}

void CCollisionManeger::Collision_Rect(list<CGameObj*>* pIistDest, list<CGameObj*>* plistSrc)
{
	RECT rc = {};
	for (auto& pDestObj : *pIistDest)
	{
		for (auto& pSrcObj : *plistSrc)
		{
			if (IntersectRect(&rc, pDestObj->GetRect(), pSrcObj->GetRect()))
			{

			}
		}
	}
}

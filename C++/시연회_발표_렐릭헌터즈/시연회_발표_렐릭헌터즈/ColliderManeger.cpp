#include "stdafx.h"
#include "ColliderManeger.h"
#include "GameObject.h"
#include "MapObject.h"

CColliderManeger* CColliderManeger::m_pInstance = nullptr;
CColliderManeger::CColliderManeger()
{
}


CColliderManeger::~CColliderManeger()
{
}

CColliderManeger * CColliderManeger::Get_ColliderManeger()
{
	if (nullptr == m_pInstance)
		m_pInstance = new CColliderManeger();
	return m_pInstance;
}

void CColliderManeger::Destroy_ColliderManeger()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CColliderManeger::Collision_PlayerAndNonePassObj(vector<CMapObject*>* pDestList, list<CGameObject*>* pSrcList) // 둘이 충돌할 경우 src리스트에 있는 대상을 겹친 만큼 밀어내주자.
{
	float fPushX = 0.f, fPushY = 0.f;
	RECT rc{};
	for (auto& pSrcObject : *pSrcList)
	{
		for (auto& pDestObject : *pDestList)
		{
			if (pDestObject->GetMInfo()->Objfeature == MAPOBJECTTYPE::NONEPASS && IntersectRect(&rc , &pDestObject->GetRect(), &pSrcObject->GetHitBox()))
			{
			//	MessageBox(g_HWND, L"충돌!", L"충돌 콜리더", MB_OK);
				float fPushX = (pDestObject->GetMInfo()->iCX/2 + PLAYER_HITBOXCX / 2) - fabs(pDestObject->GetMInfo()->fX - pSrcObject->GetInfo()->fX);
				float fPushY = (pDestObject->GetMInfo()->iCY/2 + PLAYER_HITBOXCY / 2) - fabs(pDestObject->GetMInfo()->fY - pSrcObject->GetInfo()->fY);
				if (fPushX < 1)
					fPushX = 1;
				if (fPushY < 1)
					fPushY = 1;
				if (fPushX > fPushY)
				{
					if (pDestObject->GetMInfo()->fY > pSrcObject->GetInfo()->fY)
						fPushY *= -1.f;
					pSrcObject->SetPos(pSrcObject->GetInfo()->fX , pSrcObject->GetInfo()->fY + fPushY);
				}
					
				else
				{
					if (pDestObject->GetMInfo()->fX > pSrcObject->GetInfo()->fX)
						fPushX *= -1.f;
					pSrcObject->SetPos(pSrcObject->GetInfo()->fX + fPushX, pSrcObject->GetInfo()->fY);
				}
					
				
			}
		}
	}

}
void CColliderManeger::Collision_BulletAndNonePassObj(vector<CMapObject*>* pDestList, list<CGameObject*>* pSrcList)
{

	RECT rc{};
	for (auto& pSrcObject : *pSrcList)
	{
		for (auto& pDestObject : *pDestList)
		{
			if (pDestObject->GetMInfo()->Objfeature == MAPOBJECTTYPE::NONEPASS && IntersectRect(&rc, &pDestObject->GetRect(), &pSrcObject->GetRect()))
			{
				pSrcObject->SetDead();
			}
		}
	}
}
void CColliderManeger::Collision_UnitAndBullet(list<CGameObject*>* pDestList, list<CGameObject*>* pSrcList)
{
	RECT rc{};
	for (auto& pSrcObject : *pSrcList)
	{
		for (auto& pDestObject : *pDestList)
		{
			if (IntersectRect(&rc, &pDestObject->GetHitBox(), &pSrcObject->GetRect()))
			{
				pSrcObject->SetDemage(pDestObject);
				pSrcObject->SetDead();
			}
		}
	}
}
//충돌 체크는 어디서 해야하는가?
//게임매니저와 맵매니저는 다른 곳에 존재하니 아예 SCene에서 해주자? = 씬마다 만드는 건 에반데.

bool CColliderManeger::Check_Rect(const MAPINFO * pDstInfo, const GAMEOBJINFO * pSrcInfo, float * pOutX, float * pOutY)
{
	//두 렉트의 반지름 길이 구하고
	//x축 거리와 y축 거리가 둘 다 반지름 길이의 합보다 짧으면 충돌
	float fRadiusX = pDstInfo->iCX + pSrcInfo->iCX; // 두 사각형의 x축 넓이 길이의 합
	float fRadiusY = pDstInfo->iCY + pSrcInfo->iCY; // 두 사각형의 y축 넓이 길이의 합
	float fdistanceX = fabs(pDstInfo->fX - pSrcInfo->fX); // 실제 두 사각형의 x축 길이의 합.
	float fdistanceY = fabs(pDstInfo->fY - pSrcInfo->fY); // 실제 두 사각형의 y축 길이의 합.

	if (fdistanceX > fRadiusX && fdistanceY > fRadiusY)
	{
		*pOutX = fRadiusX - fdistanceX; //두 사각형의 반지름에서 실제 거리를 빼는 것으로 x축으로 겹친 길이를 구한다.
		*pOutY = fRadiusX - fdistanceY; //두 사각형의 반지름에서 실제 거리를 빼는 것으로 y축으로 겹친 길이를 구한다.
		return true;
	}


	return false;
}

bool CColliderManeger::Check_Rect(const GAMEOBJINFO * pDstInfo, const GAMEOBJINFO * pSrcInfo, float * pOutX, float * pOutY)
{
	//두 렉트의 반지름 길이 구하고
	//x축 거리와 y축 거리가 둘 다 반지름 길이의 합보다 짧으면 충돌
	float fRadiusX = pDstInfo->iCX + pSrcInfo->iCX; // 두 사각형의 x축 넓이 길이의 합
	float fRadiusY = pDstInfo->iCY + pSrcInfo->iCY; // 두 사각형의 y축 넓이 길이의 합
	float fdistanceX = fabs(pDstInfo->fX - pSrcInfo->fX); // 실제 두 사각형의 x축 길이의 합.
	float fdistanceY = fabs(pDstInfo->fY - pSrcInfo->fY); // 실제 두 사각형의 y축 길이의 합.

	if (fdistanceX <= fRadiusX && fdistanceY <= fRadiusY)
	{
		*pOutX = fRadiusX - fdistanceX; //두 사각형의 반지름에서 실제 거리를 빼는 것으로 x축으로 겹친 길이를 구한다.
		*pOutY = fRadiusX - fdistanceY; //두 사각형의 반지름에서 실제 거리를 빼는 것으로 y축으로 겹친 길이를 구한다.
		return true;
	}


	return false;
}

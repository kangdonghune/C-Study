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

void CColliderManeger::Collision_PlayerAndNonePassObj(vector<CMapObject*>* pDestList, list<CGameObject*>* pSrcList) // ���� �浹�� ��� src����Ʈ�� �ִ� ����� ��ģ ��ŭ �о����.
{
	float fPushX = 0.f, fPushY = 0.f;
	RECT rc{};
	for (auto& pSrcObject : *pSrcList)
	{
		for (auto& pDestObject : *pDestList)
		{
			if (pDestObject->GetMInfo()->Objfeature == MAPOBJECTTYPE::NONEPASS && IntersectRect(&rc , &pDestObject->GetRect(), &pSrcObject->GetHitBox()))
			{
			//	MessageBox(g_HWND, L"�浹!", L"�浹 �ݸ���", MB_OK);
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
//�浹 üũ�� ��� �ؾ��ϴ°�?
//���ӸŴ����� �ʸŴ����� �ٸ� ���� �����ϴ� �ƿ� SCene���� ������? = ������ ����� �� ���ݵ�.

bool CColliderManeger::Check_Rect(const MAPINFO * pDstInfo, const GAMEOBJINFO * pSrcInfo, float * pOutX, float * pOutY)
{
	//�� ��Ʈ�� ������ ���� ���ϰ�
	//x�� �Ÿ��� y�� �Ÿ��� �� �� ������ ������ �պ��� ª���� �浹
	float fRadiusX = pDstInfo->iCX + pSrcInfo->iCX; // �� �簢���� x�� ���� ������ ��
	float fRadiusY = pDstInfo->iCY + pSrcInfo->iCY; // �� �簢���� y�� ���� ������ ��
	float fdistanceX = fabs(pDstInfo->fX - pSrcInfo->fX); // ���� �� �簢���� x�� ������ ��.
	float fdistanceY = fabs(pDstInfo->fY - pSrcInfo->fY); // ���� �� �簢���� y�� ������ ��.

	if (fdistanceX > fRadiusX && fdistanceY > fRadiusY)
	{
		*pOutX = fRadiusX - fdistanceX; //�� �簢���� ���������� ���� �Ÿ��� ���� ������ x������ ��ģ ���̸� ���Ѵ�.
		*pOutY = fRadiusX - fdistanceY; //�� �簢���� ���������� ���� �Ÿ��� ���� ������ y������ ��ģ ���̸� ���Ѵ�.
		return true;
	}


	return false;
}

bool CColliderManeger::Check_Rect(const GAMEOBJINFO * pDstInfo, const GAMEOBJINFO * pSrcInfo, float * pOutX, float * pOutY)
{
	//�� ��Ʈ�� ������ ���� ���ϰ�
	//x�� �Ÿ��� y�� �Ÿ��� �� �� ������ ������ �պ��� ª���� �浹
	float fRadiusX = pDstInfo->iCX + pSrcInfo->iCX; // �� �簢���� x�� ���� ������ ��
	float fRadiusY = pDstInfo->iCY + pSrcInfo->iCY; // �� �簢���� y�� ���� ������ ��
	float fdistanceX = fabs(pDstInfo->fX - pSrcInfo->fX); // ���� �� �簢���� x�� ������ ��.
	float fdistanceY = fabs(pDstInfo->fY - pSrcInfo->fY); // ���� �� �簢���� y�� ������ ��.

	if (fdistanceX <= fRadiusX && fdistanceY <= fRadiusY)
	{
		*pOutX = fRadiusX - fdistanceX; //�� �簢���� ���������� ���� �Ÿ��� ���� ������ x������ ��ģ ���̸� ���Ѵ�.
		*pOutY = fRadiusX - fdistanceY; //�� �簢���� ���������� ���� �Ÿ��� ���� ������ y������ ��ģ ���̸� ���Ѵ�.
		return true;
	}


	return false;
}

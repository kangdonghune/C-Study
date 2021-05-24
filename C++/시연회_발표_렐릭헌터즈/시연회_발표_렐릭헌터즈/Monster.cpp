#include "stdafx.h"
#include "Monster.h"
#include "MapObjectManeger.h"
#include "MapObject.h"

CMonster::CMonster()
	:MoveOn(false)
{
}


CMonster::~CMonster()
{
}

bool CMonster::RayTracying()
{
	m_tLaser.fX = m_tInfo.fX;
	m_tLaser.fY = m_tInfo.fY;
	m_tLaser.TargetDir = atan2f(m_pTarget->GetInfo()->fY - m_tInfo.fY, m_pTarget->GetInfo()->fX - m_tInfo.fX);
	m_tLaser.fSpeed = 6.f;
	m_tLaser.fdistance = 0;
	RECT Temp{};
	//타겟잡고 레이저 발싸 충돌 여부 파악
	while (m_tLaser.fdistance < 700.f)
	{
		//레이저포인터가 쭉 이동하면서 충돌여부 체크, 맵과 충돌하면 false 아니면 플레이어와 몬스터 사이 장애물 없음.
		m_tLaser.fX += cosf(m_tLaser.TargetDir)*m_tLaser.fSpeed;
		m_tLaser.fY += sinf(m_tLaser.TargetDir)*m_tLaser.fSpeed;
		m_tLaser.fdistance += m_tLaser.fSpeed;

		m_tLaser.RC = { static_cast<LONG>(m_tLaser.fX - 3), static_cast<LONG>(m_tLaser.fY - 3), static_cast<LONG>(m_tLaser.fX + 3), static_cast<LONG>(m_tLaser.fY + 3) };

		if (IntersectRect(&Temp, &m_pTarget->GetHitBox(), &m_tLaser.RC))
			return true;

		for (int i = 1; i < MAPOBJECT::END; i++)
		{
			for (auto& pObjcet : CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i))
			{
				if (pObjcet->GetMInfo()->Objfeature == MAPOBJECTTYPE::NONEPASS && IntersectRect(&Temp, &m_tLaser.RC, &(pObjcet->GetRect())))
				{
					return false;
				}
			}
		}

	}
	return true;
}

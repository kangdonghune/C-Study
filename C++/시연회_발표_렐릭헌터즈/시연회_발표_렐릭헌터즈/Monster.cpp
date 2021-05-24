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
	//Ÿ����� ������ �߽� �浹 ���� �ľ�
	while (m_tLaser.fdistance < 700.f)
	{
		//�����������Ͱ� �� �̵��ϸ鼭 �浹���� üũ, �ʰ� �浹�ϸ� false �ƴϸ� �÷��̾�� ���� ���� ��ֹ� ����.
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

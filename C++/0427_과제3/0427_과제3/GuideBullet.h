#pragma once
#include "GameObject.h"
class CGuideBullet :
	public CGameObject
{
private:
	CGuideBullet();
public:
	~CGuideBullet();

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject(HDC hdc) override;
	virtual void Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual void Release_GameObject() override;

public:
	static CGameObject* Create(HDC hdc, void* shotter);
	void SetTarget(CGameObject* pTarget) { m_pTarget = pTarget; }
	void SetAngle() { m_fAngle = atan2((m_pTarget->GetInfo()->fY - m_tInfo.fY), (m_pTarget->GetInfo()->fY - m_tInfo.fY));}
	void SetStart(CGameObject* pShotter) { m_tStartPos = *(pShotter->GetInfo()); }
	void IsIdle();
private:
	CGameObject* m_pTarget;
	INFO m_tStartPos;

};


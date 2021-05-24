#pragma once
class CGameObject abstract
{
public:
	explicit CGameObject();
	virtual ~CGameObject();

public:
	const RECT GetHitBox() { return m_rcHitBox; }
	const GAMEOBJINFO* GetInfo() { return &m_tInfo; }
	const int GetState() { return m_iState; }
	const RECT GetRect() { return m_Rc; }
	int GetDir() { return m_idir; }
	const ANIINFO Get_GunAni() { return m_tGunAni; }
	GUNINFO* Get_GunInfo() { return &m_tGunInfo; }
	ANIINFO* Set_GunAni() { return &m_tGunAni; }
	void SetState(int State) { m_iState = State; }
	void SetInfo(GAMEOBJINFO* pInfo) { m_tInfo = *pInfo; }
	GAMEOBJINFO* SetInfo() { return &m_tInfo; }
	void SetPos(float x, float y) { m_tInfo.fX = x; m_tInfo.fY = y; }
	void SetDir();
	void SetAngle(float Angle) { m_tInfo.fAngle = Angle; }
	void SetDead() { m_iState = DEAD; }
	void SetDemage(CGameObject* pTarget) { pTarget->SetInfo()->iHP -= m_tInfo.iDamege; }
	CGameObject* GetTarget() { return m_pTarget; }
	CGameObject* Get_MyGun() { return m_pMyGun; }
	void UpdateRect();
	void SetHold() { m_iState = HOLD; }

	float CheckTargetDir(CGameObject* pTarget);
	float CheckMouseDir();
	void  AngleToTarget(float targetX, float targetY) { m_tInfo.fAngle = atan2f((targetY - m_tInfo.fY), (targetX - m_tInfo.fX)); }
public:
	virtual int Ready_GameObject() = 0;
	virtual int Render_GameObject(HDC hdc) = 0;
	virtual int Update_GameObject() = 0;
	virtual int LateUpdate_GameObject() = 0;
	virtual int Release_GameObject() = 0;

protected:
	GAMEOBJINFO m_tInfo;
	RECT m_Rc;
	RECT m_rcHitBox;
	unsigned int m_iState;
	unsigned int m_iOldState;
	ANIINFO m_tAni;
	ANIINFO m_tGunAni;
	POINT m_tMouse;
	HDC m_ObjectDc;
	int m_idir;
	GUNINFO m_tGunInfo;
	CGameObject* m_pTarget;
	CGameObject* m_pMyGun;
};


#pragma once
class CGameObject abstract
{
public:
	explicit CGameObject();
	virtual ~CGameObject();

public:
	const G_INFO* GetInfo() { return &m_tInfo; }
	const int GetState() { return m_iState; }
	const RECT* GetRect() { return &m_Rc; }
	void SetInfo(G_INFO* pInfo) { m_tInfo = *pInfo; }
	void SetAngle(float Angle) { m_tInfo.fAngle = Angle; }
	void UpdateRect();
	float CheckMouseDir();
	int GetDir() { return m_idir; }
public:
	virtual int Ready_GameObject() = 0;
	virtual int Render_GameObject(HDC hdc) = 0;
	virtual int Update_GameObject() = 0;
	virtual int LateUpdate_GameObject() = 0;
	virtual int Release_GameObject() = 0;

protected:
	G_INFO m_tInfo;
	RECT m_Rc;
	unsigned int m_iState;
	unsigned int m_iOldState;
	ANIINFO m_tAni;
	POINT m_tMouse;
	HDC m_ObjectDc;
	int m_idir;

};


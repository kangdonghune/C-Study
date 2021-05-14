#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	int Update_Rect();

public:
	virtual int Ready_GameObject() = 0;
	virtual int Render_GameObject() = 0;
	virtual int Update_GameObject() = 0;
	virtual int LateUpdate_GameObject() = 0;
	virtual int Release_GameObject() = 0;

protected:
	INFO m_tInfo;
	bool m_bisDead;
	RECT m_rc;
	HDC m_hdc;
};


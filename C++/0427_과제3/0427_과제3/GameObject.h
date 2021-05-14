#pragma once
class CGameObject abstract
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	virtual int Ready_GameObject(HDC hdc) = 0;
	virtual void Render_GameObject(HDC hdc) = 0;
	virtual int Update_GameObject() = 0;
	virtual int LateUpdate_GameObject() = 0;
	virtual void Release_GameObject() = 0;


public:
	const INFO* GetInfo() { return &m_tInfo; }
	INFO* SetInfo() { return &m_tInfo; }
	const RECT* GetRect() { return &m_Rect; }
	RECT* SetRect(RECT rc) { return &m_Rect; }
	void UpdateRect();
	void Dead() { m_bIsDead = DEAD; }

protected:
	HDC m_Gamehdc;
	INFO m_tInfo;//x,y ÁÂÇ¥ µµÇü ³ÐÀÌ 
	RECT m_Rect;//left, top, right, bottom (long Çü½Ä)
	HBRUSH m_Brush;
	HBRUSH m_oldBrush;
	bool m_bIsDead;
	POINT mouse;
	float m_fAngle;
};


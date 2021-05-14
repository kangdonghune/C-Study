#pragma once
class CGameObj abstract
{
public:
	CGameObj();
	virtual ~CGameObj();
public:
	virtual int Ready_GameObj() = 0;
	virtual void Render_GameObj(HDC hdc) = 0;
	virtual void Update_GameObj() = 0;
	virtual void Release_GameObj() = 0;
	void SetXY(XY tXY) { m_tXY.fX = tXY.fX;  m_tXY.fY = tXY.fY; m_tXY.iWide = 20; }
	
	XY GetXY() { return m_tXY; }
	int& SetDir() { return m_iBulletDir; }
	RECT* GetRect() { return &rc; };
protected:
	XY m_tXY;
	HDC m_hdc;
	int m_iSpeed;
	int m_iBulletDir;
	HBRUSH myBrush;
	HBRUSH oldBrush;
	RECT rc;
};


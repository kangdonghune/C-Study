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
protected:
	XY m_tXY;
};


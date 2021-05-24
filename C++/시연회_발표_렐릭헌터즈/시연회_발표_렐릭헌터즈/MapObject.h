#pragma once
class CMapObject abstract
{
public:
	explicit CMapObject();
	virtual ~CMapObject();

public:
	const MAPINFO* GetMInfo() { return &m_tMapInfo;}
	const RECT GetRect() { return m_Rc; }
	
	MAPINFO* SetMINFO() { return &m_tMapInfo; }
	void SetDead() { m_iState = DEAD; }

	void Update_Rect();
	const int& GetState() { return m_iState; }

public:
	virtual int Ready_MapObject() = 0;
	virtual int Render_MapObject(HDC hdc) = 0;
	virtual int Update_MapObject() = 0;
	virtual int LateUpdate_MapObject() = 0;
	virtual int Release_MapObject() = 0;

protected:
	MAPINFO m_tMapInfo;
	RECT m_Rc;
	int m_iState;
};


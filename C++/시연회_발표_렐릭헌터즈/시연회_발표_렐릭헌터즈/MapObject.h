#pragma once
class CMapObject abstract
{
public:
	explicit CMapObject();
	virtual ~CMapObject();

public:
	const M_INFO* GetMInfo() { return &m_tMapInfo;}
	M_INFO* SetMINFO() { return &m_tMapInfo; }
	void Update_Rect();
	const int& GetState() { return m_iState; }
public:
	virtual int Ready_MapObject() = 0;
	virtual int Render_MapObject(HDC hdc) = 0;
	virtual int Update_MapObject() = 0;
	virtual int LateUpdate_MapObject() = 0;
	virtual int Release_MapObject() = 0;

protected:
	M_INFO m_tMapInfo;
	RECT m_Rc;
	int m_iState;
};


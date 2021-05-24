#pragma once
class CLogo
{
private:
public:
	CLogo();
	virtual ~CLogo();

public:
	static CLogo* Create();

public:
	void UpdateRect();
	int Get_State() { return m_iState;}
public:

	virtual int Ready_Logo();
	virtual int Update_Logo();
	virtual int Render_Logo(HDC hdc);
	virtual int Release_Logo();

protected:
	LOGOINFO m_tInfo;
	RECT m_rc;
	int m_iState;
};


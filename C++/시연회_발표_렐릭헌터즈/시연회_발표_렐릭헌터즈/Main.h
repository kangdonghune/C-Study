#pragma once
class CMain
{
private:
	CMain();
public:
	~CMain();

public:
	static CMain* Create();

public:
	int Ready_Main();
	int Render_Main();
	int Update_Main();
	int LateUpdate_Main();
	int Release_Main();


private:
	HDC m_hdc;

};


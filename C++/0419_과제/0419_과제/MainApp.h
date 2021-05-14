#pragma once

class CGameObj;
class CMainApp
{

private:
	CMainApp();
public:
	~CMainApp();
public:
	int Ready_MainApp();
	void Render_MainApp();
	void Update_MainApp();
	void Release_MainApp();
	static CMainApp* Create();
private:
	CGameObj* m_pPlayer;
	HDC m_hdc;

};


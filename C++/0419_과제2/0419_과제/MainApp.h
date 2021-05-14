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

	void CountBullet();
	void CountFPS();
	int& SetFrame() { return m_iFrameCount; }
private:
	CGameObj* m_pPlayer;
	CGameObj* m_pEnemy;
	HDC m_hdc;
	list<CGameObj*> m_BulletList;
	int m_iFrameCount;
	int m_iFps;
};


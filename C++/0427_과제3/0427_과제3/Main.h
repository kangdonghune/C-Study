#pragma once
class CGameObject;
class CMain
{
private:
	CMain();
public:
	~CMain();
public:
	virtual int Ready_Main();
	virtual void Render_Main();
	virtual void Update_Main();
	virtual void LateUpdate_Main();
	virtual void Release_Main();

public:
	static CMain* Create();
private:
	HDC m_Mainhdc;
	list<CGameObject*> m_pGameObjList[GameObjectList::SIZE];
	DWORD m_dwEnemySpawnTime = GetTickCount();
};


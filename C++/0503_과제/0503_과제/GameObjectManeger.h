#pragma once
class CGameObject;
class CGameObjectManeger
{
private:
	CGameObjectManeger();
	~CGameObjectManeger();

public:
	static CGameObjectManeger* Get_Maneger();

public:
	int Add_GameObject(OBJECT::Objects Num, CGameObject* pObject);

public:
	int Ready_GameObjectManeger();
	int Render_GameObjectManeger();
	int Update_GameObjectManeger();
	int LateUpdate_GameObjectManeger();
	int Release_GameObjectManeger();

private:
	static CGameObjectManeger* m_pInstance;
	list<CGameObject*> m_listObject[OBJECT::END];
};


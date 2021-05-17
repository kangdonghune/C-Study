#pragma once
class CGameObject;
class CGameObjectManeger
{
private:
	CGameObjectManeger();
	~CGameObjectManeger();

public:
	static CGameObjectManeger* Get_GameObjectManeger();
	static void Destroy_GameObjectManeger();

public:
	int Add_GameObject(GAMEOBJECT::Object Num, CGameObject* pObject);
	const list<CGameObject*> GetList(GAMEOBJECT::Object Num) { return m_listGameObject[Num]; }
	list<CGameObject*> SetList(GAMEOBJECT::Object Num) { return m_listGameObject[Num]; }
public:
	int Ready_GameObjectManeger();
	int Render_GameObjectManeger(HDC hdc);
	int Update_GameObjectManeger();
	int LateUpdate_GameObjectManeger();
	int Release_GameObjectManeger();
public:
	CGameObject* Get_Target(GAMEOBJECT::Object Num);
private:
	static CGameObjectManeger* m_pInstance;
	list<CGameObject*> m_listGameObject[GAMEOBJECT::END];
};


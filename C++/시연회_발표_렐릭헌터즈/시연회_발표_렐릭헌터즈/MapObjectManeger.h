#pragma once
class CMapObject;
class CMapObjectManeger
{
private:
	CMapObjectManeger();
public:
	~CMapObjectManeger();

public:
	static CMapObjectManeger* Get_MapManeger();

public:
	int	Insert_MapObject(MAPOBJECT::Object TYPE,CMapObject* pObject);
	vector<CMapObject*> SetList(MAPOBJECT::Object TYPE) { return m_pMapObjectList[TYPE];}
	void Save_MapObjectManager();
	void Load_MapObjectManager();

public:
	int Render_MapObjectManeger(HDC hdc);
	int Update_MapObjectManerger();
	int LateUpdate_MapObjectManeger();
	int Release_MapObjectManeger();

private:
	static CMapObjectManeger* m_pInstatnce;
	vector<CMapObject*> m_pMapObjectList[MAPOBJECT::END];
	
};


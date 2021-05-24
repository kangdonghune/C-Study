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
	const vector<CMapObject*>* Get_ObjectVector(MAPOBJECT::Object NUM) { return &m_pMapObjectList[NUM]; }
	vector<CMapObject*> Get_ObjectVector(int Num) { return m_pMapObjectList[Num]; }

	vector<CMapObject*> Set_ObjectVector(MAPOBJECT::Object NUM) { return m_pMapObjectList[NUM]; }
	
	vector<CMapObject*> SetList(MAPOBJECT::Object TYPE) { return m_pMapObjectList[TYPE];}
	int	Insert_MapObject(MAPOBJECT::Object TYPE,CMapObject* pObject);
	void Save_MapObjectManager();
	void Load_MapObjectManager(TCHAR* pFilePath);
	void Update_Scroll();

public:
	int Render_MapObjectManeger(HDC hdc);
	int Update_MapObjectManerger();
	int LateUpdate_MapObjectManeger();
	int Release_MapObjectManeger();

private:
	static CMapObjectManeger* m_pInstatnce;
	vector<CMapObject*> m_pMapObjectList[MAPOBJECT::END];
	
};


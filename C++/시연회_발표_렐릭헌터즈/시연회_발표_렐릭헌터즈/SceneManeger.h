#pragma once
class CScene;
class CGameObject;
class CMapObject;
class CSceneManeger
{
public:
	enum ID {SCENE_LODING, SCENE_MENU, SCENE_EDIT ,SCENE_STAGE1, SCENE_BOSS, SCENE_END};
private:
	CSceneManeger();
	~CSceneManeger();

public:
	static CSceneManeger* Get_SceneManeger();
	static void Destroy_SceneManeger();

public:
	void Change_SceneManager(ID eNextScene);
	CScene* GetScene() { return m_pScene; }

	bool GetWaveOn() { return WaveOn; }
	void SetWaveOn(bool boolvalue) { WaveOn = boolvalue; }
	void SetWaveGunRebounde(bool boolvalue) { WaveGunRebounde = boolvalue; }
public:

public:
	void Update_SceneManager();
	void Render_SceneManager(HDC hDC);
	void Release_SceneManager();
private:
	static	CSceneManeger* m_pInstance;
	CScene* m_pScene;
	ID		m_eCurScene;
	ID		m_eNextScene;
	CScene* m_pOldScene;

	bool WaveOn;
	bool WaveGunRebounde;
};


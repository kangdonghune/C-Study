#pragma once
class CScene;
class CSceneManeger
{
public:
	enum ID {SCENE_LODING, SCENE_MENU, SCENE_EDIT ,SCENE_STAGE1, SCENE_END};
private:
	CSceneManeger();
	~CSceneManeger();

public:
	static CSceneManeger* Get_SceneManeger();
	static void Destroy_SceneManeger();

public:
	void Change_SceneManager(ID eNextScene);

public:
	void Update_SceneManager();
	void Render_SceneManager(HDC hDC);
	void Release_SceneManager();

private:
	static	CSceneManeger* m_pInstance;
	CScene* m_pScene;
	ID		m_eCurScene;
	ID		m_eNextScene;
};


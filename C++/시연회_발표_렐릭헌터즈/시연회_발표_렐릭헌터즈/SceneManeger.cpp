#include "stdafx.h"
#include "SceneManeger.h"
#include "Scene.h"
#include "Editor.h"
#include "Stage.h"
#include "MainMenu.h"

CSceneManeger* CSceneManeger::m_pInstance = nullptr;
CSceneManeger::CSceneManeger()
{
}


CSceneManeger::~CSceneManeger()
{
}

CSceneManeger * CSceneManeger::Get_SceneManeger()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CSceneManeger();
	}
	return m_pInstance;
}

	void CSceneManeger::Destroy_SceneManeger()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance == nullptr;
	}
}

void CSceneManeger::Change_SceneManager(ID eNextScene)
{
	m_eNextScene = eNextScene;
	if (m_eCurScene != m_eNextScene)
	{
		Delete_Dynamic(m_pScene);
		switch (m_eNextScene)
		{
		/*case CSceneManeger::SCENE_LOADING:
			m_pScene = CLoading::Create();
			break;*/
		case CSceneManeger::SCENE_MENU:
			m_pScene = CMainMenu::Create();
			break;
		case CSceneManeger::SCENE_STAGE1:
			m_pScene = CStage::Create();
			break;
		case CSceneManeger::SCENE_EDIT:
			m_pScene = CEditor::Create();
			break;
		case CSceneManeger::SCENE_END:
			break;
		default:
			break;
		}
		m_eCurScene = m_eNextScene;
	}
}

void CSceneManeger::Update_SceneManager()
{
	m_pScene->Update_Scene();
}

void CSceneManeger::Render_SceneManager(HDC hDC)
{
	m_pScene->Render_Scene(hDC);
}

void CSceneManeger::Release_SceneManager()
{
	Delete_Dynamic(m_pScene);
}

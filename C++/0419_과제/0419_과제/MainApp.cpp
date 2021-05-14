#include "stdafx.h"
#include "MainApp.h"
#include "Player.h"

CMainApp::CMainApp()
	:m_pPlayer(nullptr)
{
}


CMainApp::~CMainApp()
{
}

int CMainApp::Ready_MainApp()
{
	m_hdc = GetDC(g_HWND);
	m_pPlayer = CPlayer::Create();
	if (nullptr == m_pPlayer) 
		return Ready_Fail;
	
	return Ready_Success;
}

void CMainApp::Render_MainApp()
{
	m_pPlayer->Render_GameObj(m_hdc) ;
}

void CMainApp::Update_MainApp()
{
	m_pPlayer->Update_GameObj();
}

void CMainApp::Release_MainApp()
{
	ReleaseDC(g_HWND, m_hdc);
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}

CMainApp* CMainApp::Create()
{
	CMainApp* pInstance = new CMainApp;
		if (0 > pInstance->Ready_MainApp())
		{
			delete pInstance;
			pInstance = nullptr;
			return pInstance;
		}

	return pInstance;
}

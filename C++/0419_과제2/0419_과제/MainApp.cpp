#include "stdafx.h"
#include "MainApp.h"
#include "Player.h"
#include "Enemy.h"
CMainApp::CMainApp()
	:m_pPlayer(nullptr)
	,m_pEnemy(nullptr)
	,m_iFrameCount(0)
	,m_iFps(0)
{
}


CMainApp::~CMainApp()
{
}

int CMainApp::Ready_MainApp()
{
	m_hdc = GetDC(g_HWND);
	if (nullptr == m_pPlayer)
	{
		m_pPlayer = CPlayer::Create();
		dynamic_cast<CPlayer*>(m_pPlayer)->SetBulletList(&m_BulletList);
	}
	if (nullptr == m_pEnemy)
	{
		m_pEnemy = CEnemy::Create(m_hdc);
	}
	//m_pPlayer = CPlayer::Create();
	//if (nullptr == m_pPlayer) 
	//	return Ready_Fail;
	//CPlayer* pTemp = dynamic_cast<CPlayer*>(m_pPlayer);
	//if (nullptr == pTemp)
	//{
	//	delete m_pPlayer;
	//	m_pPlayer = nullptr;
	//	return Ready_Fail;
	//}
	//pTemp->SetBulletList(&m_BulletList);
	//m_pPlayer = pTemp;
	return Ready_Success;
}


void CMainApp::Render_MainApp()
{
	Rectangle(m_hdc, 0, 0, WINCX, WINCY);
	Rectangle(m_hdc, 100, 100, 700, 500);
	CountBullet();
	CountFPS();

	for (auto& pBullet : m_BulletList)
	{
		pBullet->Render_GameObj(m_hdc);
	}
	m_pPlayer->Render_GameObj(m_hdc);
	m_pEnemy->Render_GameObj(m_hdc);
	
}

void CMainApp::Update_MainApp()
{
	m_pPlayer->Update_GameObj();

	m_pEnemy->Update_GameObj();

	for (auto& pBullet : m_BulletList)
	{
		pBullet->Update_GameObj();
	}
	list<CGameObj*>::iterator iter = m_BulletList.begin();
	for (; iter != m_BulletList.end(); iter++)
	{
		RECT temp;
		if (IntersectRect(&temp ,m_pEnemy->GetRect(), (*iter)->GetRect()))
		{
			iter = m_BulletList.erase(iter);
			delete m_pEnemy;
			m_pPlayer = nullptr;
		}
		if (100 >= (*iter)->GetXY().fX || 700 <= (*iter)->GetXY().fX || 100 >= (*iter)->GetXY().fY || 500 <= (*iter)->GetXY().fY)
		{
			iter = m_BulletList.erase(iter);
		}
		if (iter == m_BulletList.end())
			break;
	}
	
	
	
}

void CMainApp::Release_MainApp()
{
	ReleaseDC(g_HWND, m_hdc);
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	for (auto& pBullet : m_BulletList)
	{
		if (pBullet)
		{
			delete pBullet;
			pBullet = nullptr;
		}	
	}
	m_BulletList.clear();
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

void CMainApp::CountBullet()
{
	wchar_t szBullet[11] = L"ÃÑ¾Ë ¼ö:";
	wchar_t szBulletCount[4];
	_itow_s(m_BulletList.size(), szBulletCount, sizeof(szBulletCount) / 2, 10);
	wcscat_s(szBullet, szBulletCount);
	TextOut(m_hdc, 100, 70, szBullet, wcslen(szBullet));
}

void CMainApp::CountFPS()
{

	static DWORD dwFrameTime = GetTickCount();
	static wchar_t szFPS[11] = L"FPS:";
	if (wcslen(szFPS) == wcslen(L"FPS:"))
	{
		wchar_t szFPSCount[6];
		_itow_s(m_iFps, szFPSCount, sizeof(szFPSCount) / 2, 10);
		wcscat_s(szFPS, szFPSCount);
	}
	if (dwFrameTime + 1000 < GetTickCount())
	{
		m_iFps = m_iFrameCount;
		m_iFrameCount = 0;
		wcscpy_s(szFPS, L"FPS:");
		dwFrameTime = GetTickCount();
	}
	TextOut(m_hdc, 600, 70, szFPS, wcslen(szFPS));
	
}

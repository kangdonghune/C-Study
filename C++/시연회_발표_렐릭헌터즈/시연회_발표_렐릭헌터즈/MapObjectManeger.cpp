#include "stdafx.h"
#include "MapObjectManeger.h"
#include "MapObject.h"
#include "Tile.h"
#include "Celling.h"
#include "ScrollManeger.h"
#include "GameObject.h"
#include "GameObjectManeger.h"
#include "ColliderManeger.h"
#include "Wall.h"

CMapObjectManeger* CMapObjectManeger::m_pInstatnce = nullptr;
CMapObjectManeger::CMapObjectManeger()
{
}

CMapObjectManeger::~CMapObjectManeger()
{
	Release_MapObjectManeger();
}
int CMapObjectManeger::Insert_MapObject(MAPOBJECT::Object TYPE, CMapObject * pObject)
{
	if (TYPE >= MAPOBJECT::END || pObject == nullptr)
		return Function_Fail;
	m_pMapObjectList[TYPE].emplace_back(pObject);
}

void CMapObjectManeger::Save_MapObjectManager()
{
	HANDLE hFile = CreateFile(L"../Data/MapData.dat", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
		return;
	DWORD dwByte = 0;
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		for (auto& pObject : m_pMapObjectList[i])
		{
			WriteFile(hFile, pObject->GetMInfo(), sizeof(MAPINFO), &dwByte, nullptr);
		}
	}
	CloseHandle(hFile);
	
	//MessageBox(nullptr, L"저장완료", L"저장시스템", MB_OK);
}

void CMapObjectManeger::Load_MapObjectManager(TCHAR* pFilePath)
{
	HANDLE hFile = CreateFile(pFilePath, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
		return;

	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		for (auto& pObject : m_pMapObjectList[i])
		{
			Delete_Dynamic(pObject);
		}
		m_pMapObjectList[i].clear();
		m_pMapObjectList[i].shrink_to_fit();
	}
	DWORD dwByte = 0;
	MAPINFO tMInfo{};
	POINT pt;
	while (true)
	{
		ReadFile(hFile, &tMInfo, sizeof(MAPINFO), &dwByte, nullptr);
		if (0 == dwByte)
			break;
		switch (tMInfo.ObjType)
		{
		case MAPOBJECT::TILE:
			pt.x = tMInfo.fX;
			pt.y = tMInfo.fY;
			m_pInstatnce->Insert_MapObject(MAPOBJECT::TILE, CTile::Create(pt));
			break;
		case MAPOBJECT::CELLING :
			pt.x = tMInfo.fX;
			pt.y = tMInfo.fY;
			m_pInstatnce->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(pt));
			m_pInstatnce->Get_MapManeger()->Get_ObjectVector(MAPOBJECT::CELLING)->back()->SetMINFO()->iCellingNum = tMInfo.iCellingNum;
			break;
		case MAPOBJECT::WALL:
			pt.x = tMInfo.fX;
			pt.y = tMInfo.fY;
			m_pInstatnce->Insert_MapObject(MAPOBJECT::WALL, CWall::Create(pt));
			m_pInstatnce->Get_MapManeger()->Get_ObjectVector(MAPOBJECT::WALL)->back()->SetMINFO()->iWallNum = tMInfo.iWallNum;
			break;
		default:
			break;
		}
	}
	CloseHandle(hFile);
	//MessageBox(nullptr, L"불러오기 완료", L"불러오기 시스템", MB_OK);
}

void CMapObjectManeger::Update_Scroll()
{
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		for (auto& pObject : m_pMapObjectList[i])
		{
			pObject->SetMINFO()->fX += CScrollManeger::Get_ScrollX();
			pObject->SetMINFO()->fY += CScrollManeger::Get_ScrollY();
		}
	}
}

int CMapObjectManeger::Release_MapObjectManeger()
{
	Delete_Dynamic(m_pInstatnce);
	return Function_Pass;
}

int CMapObjectManeger::Render_MapObjectManeger(HDC hdc)
{
	//컬링

	float fScrollX = CScrollManeger::Get_ScrollX();
	float fScrollY = CScrollManeger::Get_ScrollY();

	float ScreenXL = 0 - fScrollX;
	float ScreenXR = WINCX - fScrollX;
	float ScreenYT = 0 - fScrollY;
	float ScreenYB = WINCY - fScrollY;
	for (int i = 0; i < MAPOBJECT::END; ++i)
	{
		for (auto& iter = m_pMapObjectList[i].begin(); iter != m_pMapObjectList[i].end(); ++iter)
		{
			if (ScreenXL <= (*iter)->GetMInfo()->fX || ScreenXR >= (*iter)->GetMInfo()->fX)
			{
				if (ScreenYT <= (*iter)->GetMInfo()->fY || ScreenYB >= (*iter)->GetMInfo()->fY)
					(*iter)->Render_MapObject(hdc);
			}

		}
	}
	return Function_Pass;
}

int CMapObjectManeger::Update_MapObjectManerger()
{
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		for (auto& iter = m_pMapObjectList[i].begin(); iter != m_pMapObjectList[i].end();)
		{

			if (DEAD == (*iter)->GetState())
			{
				Delete_Dynamic(*iter);
				iter = m_pMapObjectList[i].erase(iter);
			}
			else
			{
				(*iter)->Update_MapObject();
				++iter;
			}

		}
	}

	return Function_Pass;
}

int CMapObjectManeger::LateUpdate_MapObjectManeger()
{
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		for (auto& iter = m_pMapObjectList[i].begin(); iter != m_pMapObjectList[i].end(); ++iter)
		{
			(*iter)->LateUpdate_MapObject();
		}
	}
	return Function_Pass;
}



CMapObjectManeger * CMapObjectManeger::Get_MapManeger()
{
	if (nullptr == m_pInstatnce)
	{
		m_pInstatnce = new CMapObjectManeger();
	}
	return m_pInstatnce;
}



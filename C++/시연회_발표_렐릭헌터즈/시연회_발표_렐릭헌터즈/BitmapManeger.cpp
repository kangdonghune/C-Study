#include "stdafx.h"
#include "BitmapManeger.h"
#include "C_Bitmap.h"

CBitmapManeger* CBitmapManeger::m_BMpInstance(nullptr);

CBitmapManeger::CBitmapManeger()
{
}


CBitmapManeger::~CBitmapManeger()
{
}

CBitmapManeger * CBitmapManeger::Get_BitmapManeger()
{
	if (nullptr == m_BMpInstance)
	{
		m_BMpInstance = new CBitmapManeger();
		m_BMpInstance->Ready_BitmapManeger();
	}
		
	return m_BMpInstance;
}

void CBitmapManeger::Destroy_BitmapManeger()
{
	if (nullptr != m_BMpInstance)
	{
		delete m_BMpInstance;
		m_BMpInstance = nullptr;
	}
}

HDC CBitmapManeger::Get_BitmapDC(const TCHAR * pKey)
{
	auto& iter = find_if(m_mapBitmap.begin(), m_mapBitmap.end(), [&](auto& rPair)
	{
		return !lstrcmp(pKey, rPair.first);// 같으면 1 반환. 없으면 0이 되겠죠? 모든 값이 다 0이면 끝까지 가겠죠?
	});
	if (iter == m_mapBitmap.end()) //목록에 탐색값과 같은 키가 없으면
		return nullptr;

	return iter->second->Get_BitmapDC();
}

C_Bitmap * CBitmapManeger::Get_Bitmap(const TCHAR * pKey)
{
	auto& iter = find_if(m_mapBitmap.begin(), m_mapBitmap.end(), [&](auto& rPair)
	{
		return !lstrcmp(pKey, rPair.first);// 같으면 1 반환. 없으면 0이 되겠죠? 모든 값이 다 0이면 끝까지 가겠죠?
	});
	if (iter == m_mapBitmap.end()) //목록에 탐색값과 같은 키가 없으면
		return nullptr;

	return iter->second;
}



int CBitmapManeger::Insert_BitmapManeger(const TCHAR * pKey, const TCHAR* pFilePath)
{
	if (Get_BitmapDC(pKey) == nullptr)
	{
		C_Bitmap* pBitmap = C_Bitmap::Create(pFilePath);
		m_mapBitmap.emplace(pKey, pBitmap);
	}

	return Function_Pass;
}

int CBitmapManeger::Release_BitmapManeger()
{
	for (auto& rPair : m_mapBitmap)
		Delete_Dynamic(rPair.second);
	m_mapBitmap.clear();
	return Function_Pass;
}

int CBitmapManeger::Ready_BitmapManeger()
{
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_idle(L)", L"../Image/Player_idle(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_idle(R)", L"../Image/Player_idle(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(L)", L"../Image/Player_walk(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(R)", L"../Image/Player_walk(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(L)", L"../Image/Player_melee(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_run(L)", L"../Image/Player_run(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_run(R)", L"../Image/Player_run(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_melee(L)", L"../Image/Player_melee(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_melee(R)", L"../Image/Player_melee(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun(L)", L"../Image/Player_machinegun(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun(R)", L"../Image/Player_machinegun(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun_back", L"../Image/Player_machinegun_back.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun_back2", L"../Image/Player_machinegun_back.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_bullet", L"../Image/Player_bullet.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"BackBuffer", L"../Image/BackGround.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"DoubleBuff", L"../Image/BackGround.bmp");
	return Function_Pass;	
}



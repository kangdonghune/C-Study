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
	//플레이어 무빙
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_idle(L)", L"../Image/Player_idle(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_idle(R)", L"../Image/Player_idle(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(L)", L"../Image/Player_walk(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(R)", L"../Image/Player_walk(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_walk(L)", L"../Image/Player_melee(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_run(L)", L"../Image/Player_run(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_run(R)", L"../Image/Player_run(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_melee(L)", L"../Image/Player_melee(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_melee(R)", L"../Image/Player_melee(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_Dead(L)", L"../Image/Player_Dead(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_Dead(R)", L"../Image/Player_Dead(R).bmp");

	//무기
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun(L)", L"../Image/Player_machinegun(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_machinegun", L"../Image/Player_machinegun.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun(R)", L"../Image/Player_machinegun(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun_back", L"../Image/Player_machinegun_back.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"MuchineGun_back2", L"../Image/Player_machinegun_back.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_gun", L"../Image/Boss_gun.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Grenade", L"../Image/Grenade.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Grenade_boom", L"../Image/Grenade_boom.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"pistol", L"../Image/pistol.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"shotgun", L"../Image/shotgun.bmp");

	//아이템 팝업
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Pistol_Pop", L"../Image/Pistol_Pop.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"machinegun_Pop", L"../Image/machinegun_Pop.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"shotgun_PoP", L"../Image/shotgun_PoP.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Grenade_Pop", L"../Image/Grenade_Pop.bmp");

	//총알
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_bullet", L"../Image/Player_bullet.bmp"); //샷건용
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Pistol_Bullet", L"../Image/Pistol_Bullet.bmp");// 반복X
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Machgun_bullet", L"../Image/Machgun_bullet.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_Bullet", L"../Image/Boss_Bullet.bmp");

	//맵
	
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"BackBuffer", L"../Image/BackGround.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"DoubleBuff", L"../Image/BackGround.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"floor_desert", L"../Image/floor_desert.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Ceiling_desert", L"../Image/Ceiling_desert.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"desert_wall", L"../Image/desert_wall.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Celling_back", L"../Image/Celling_back.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"menu_main", L"../Image/menu_main.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Portal", L"../Image/Portal.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"PushButton", L"../Image/PushButton.bmp");
	
	//몬스터
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_idle(L)", L"../Image/Turtle_idle(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_idle(R)", L"../Image/Turtle_idle(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_walk(L)", L"../Image/Turtle_walk(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_walk(R)", L"../Image/Turtle_walk(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_Dead(L)", L"../Image/Turtle_Dead(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Turtle_Dead(R)", L"../Image/Turtle_Dead(R).bmp");

	//보스
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_idle(L)", L"../Image/Boss_idle(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_idle(R)", L"../Image/Boss_idle(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_dead(L)", L"../Image/Boss_dead(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_dead(R)", L"../Image/Boss_dead(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_walk(L)", L"../Image/Boss_walk(L).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_walk(R)", L"../Image/Boss_walk(R).bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_Egg", L"../Image/Boss_Egg.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_egg_crack", L"../Image/Boss_egg_crack.bmp");

	//이펙트
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Main_Logo", L"../Image/Main_Logo.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Check_Arrow", L"../Image/Check_Arrow.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"PressEnter", L"../Image/PressEnter.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Stage1_effect", L"../Image/Stage1_effect.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"StageBoss_effect", L"../Image/StageBoss_effect.bmp");


	//체력
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_HpFace", L"../Image/Player_HpFace.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Player_HpBar", L"../Image/Player_HpBar.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_HpBar", L"../Image/Boss_HpBar.bmp");
	CBitmapManeger::Get_BitmapManeger()->Insert_BitmapManeger(L"Boss_HPFace", L"../Image/Boss_HPFace.bmp");


	return Function_Pass;	
}



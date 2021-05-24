#pragma once
class CGameObject;
class CMapObject;
class CColliderManeger
{
private:
	CColliderManeger();
	~CColliderManeger();
public:
	static CColliderManeger* Get_ColliderManeger();
	static void Destroy_ColliderManeger();

public:
	void Collision_PlayerAndNonePassObj(vector<CMapObject*>* pDestList, list<CGameObject*>* pSrcList);
	void Collision_BulletAndNonePassObj(vector<CMapObject*>* pDestList, list<CGameObject*>* pSrcList);
	void Collision_UnitAndBullet(list<CGameObject*>* pDestList, list<CGameObject*>* pSrcList);
	void Collision_UnitAndGrenadeToM(list<CGameObject*>* pDestList, list<CGameObject*>* pSrcList);
	void Collision_UnitAndGrenade(list<CGameObject*>* pDestList, list<CGameObject*>* pSrcList);
private:
	bool Check_Rect(const MAPINFO* pDstInfo, const GAMEOBJINFO* pSrcInfo, float* pOutX, float* pOutY);
	bool Check_Rect(const GAMEOBJINFO* pDstInfo, const GAMEOBJINFO* pSrcInfo, float* pOutX, float* pOutY);
	static CColliderManeger* m_pInstance;
};


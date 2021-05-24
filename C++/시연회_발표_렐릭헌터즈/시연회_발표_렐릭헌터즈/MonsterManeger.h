#pragma once
class CGameObject;
class CMonsterManeger
{
private:
	CMonsterManeger();
public:
	~CMonsterManeger();
public:
	static CMonsterManeger* Get_MonsterManeger();

public:
	void Insert_Monster(MONSTER::Name Name, float X, float Y, CGameObject* pTarget);

private:
	static CMonsterManeger* m_pInstance;
};


#pragma once
class CPlayer;
class CLobby
{
public:
	CLobby();
	~CLobby();
	static void Save(CPlayer* pPlayer);
	void LobbyPlay(CPlayer* pPlayer);
};


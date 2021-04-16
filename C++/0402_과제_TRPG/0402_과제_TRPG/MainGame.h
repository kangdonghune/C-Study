#pragma once
#ifndef MainGame_h
#define MainGame_h

//1.새로하기 2. 이어하기
//선택 이후 로비로 이동.
class CPlayer;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void NewStart();
	static void Load(CPlayer** ppPlayer);
private:
	CPlayer* m_pPlayer;
};

#endif // !MainGame_h



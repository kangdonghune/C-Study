#pragma once
#ifndef MainGame_h
#define MainGame_h

//1.�����ϱ� 2. �̾��ϱ�
//���� ���� �κ�� �̵�.
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



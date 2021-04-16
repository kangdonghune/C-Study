#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
	Init();
}


CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_pStatus = new STATUS; // �÷��̾� ���� �� �������ͽ� ����ü �����Ҵ�.
	*m_pStatus = {}; // ��� �� 0 �ʱ�ȭ.
	m_pStatus->m_iMaxInvenSize = 3;
	
}

void CPlayer::ShowInfo()
{
	cout << "----------------------------------------" << endl;
	cout << "�̸�:\t" << m_pStatus->m_szName << endl;
	cout << "Lv:\t" << m_pStatus->m_iLV << endl;
	cout << "����:\t" << m_pStatus->m_szClassName << endl;
	cout << "HP:\t" << m_pStatus->m_iHP << endl;
	cout << "���ݷ�:\t" << m_pStatus->m_iATK << endl;
	cout << "����:\t" << m_pStatus->m_iDEF << endl;
	cout << "���� ����ġ:\t" << m_pStatus->m_iMaxExp - m_pStatus->m_iEXP << endl;
	cout << "������:\t" << m_pStatus->m_iGold << endl;
	cout << "�κ��丮:\t" << m_pStatus->m_iMaxInvenSize << endl;
	cout << "----------------------------------------" << endl;
}

void CPlayer::LeverUp()
{
	cout << "������! ������ �ö����ϴ�!" << endl;
	m_pStatus->m_iLV++;
	m_pStatus->m_iMaxExp += 30;
	m_pStatus->m_iEXP = 0;
	system("pause");
}

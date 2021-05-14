#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_GameObj();
}

int CPlayer::Ready_GameObj()
{
	m_tXY.fX = 400.f;
	m_tXY.fY = 300.f;
	m_tXY.iWide = 70;
	return Ready_Success;
}

void CPlayer::Render_GameObj(HDC hdc)
{
	RECT rc = { m_tXY.fX - (m_tXY.iWide / 2), m_tXY.fY - (m_tXY.iWide / 2), m_tXY.fX + (m_tXY.iWide / 2), m_tXY.fY + (m_tXY.iWide / 2) };
	Rectangle(hdc, rc.left,rc.top, rc.right, rc.bottom);
	
}

void CPlayer::Update_GameObj()
{
	/*��ȯ�� 4��
	0x0000 ���� �ƹ��͵� �� ����
	0x0001 1 ���� �ȴ��Ȱ� ������ ������ ��  �� ���� 1�� ������ ������
	0x8000 - 8000�� signed�̱� ������ ������. ���� ���ȴٴ� �ǹ�.
	0x8001  ���絵 ������ �ְ� �������� ������ �ִ�.
	*/
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) //���� ���� ���ο� ������� ���� �������� ���� ���� �� ��� //�ڵ������ ����Ǵ� �ܰ迡�� Ű�� ���ȴ��� �Ǻ�
		m_tXY.fX -= 8.f;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tXY.fX += 8.f;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tXY.fY -= 8.f;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tXY.fY += 8.f;

	if (GetAsyncKeyState(0x41))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = A;
	}
		
	if (GetAsyncKeyState(0x44))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = D;
	}
	if (GetAsyncKeyState(0x57))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = W;
	}
	if (GetAsyncKeyState(0x53))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = S;
	}
}

void CPlayer::Release_GameObj()
{

}

CPlayer* CPlayer::Create()
{
	CPlayer* pInstance = new CPlayer();
	if (0 > pInstance->Ready_GameObj()) // ready_Gameobj�� ����� ����Ǹ� 1, �ƴϸ� -1 ��ȯ.
	{
		delete pInstance;  // ����� �ʱ�ȭ�� �ȵǾ����� �Ҵ���� �� �����ϰ� 
		pInstance = nullptr; // nullptr�� �ʱ�ȭ.
		return pInstance;
	}
	return pInstance;
}



#pragma once
#include "Player.h"
class CUser : public CPlayer
{
public:
	CUser();
	~CUser();

public:
	int m_iHP; //���� �ڽİ� �θ��� ��� �������� ���ٸ�(�׷��� ����� �� ������) �ش� ��ü���� ȣ�� �� �켱�Ǵ� ���� ���� ��ü�� ��� ������. �ٵ� �θ��� �Լ��� ȣ���� ���� �θ� �������� ��� ������ ������ �ȴ�.
};


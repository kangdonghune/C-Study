#pragma once
#ifndef Field_h
#define Field_h

/*
�ʵ� ���� ��
1. �÷��̾� ���� ���
2. ���� ���� �� ���� ���� ���
3. �ο� �� ���� ���. -> 1 �ο�� (�÷��̾� ����) ���� ���� �� ���� �ݰ�. ó�� �������� 2. ����ģ�� ���� ���� ���� �� ���� ��ȯ ��� �� ����ġ �ʱ�ȭ �� ������ȯ . ���� ���� �� Ǯ�����ȸ��

+
���� ����� ���� �÷��̾��� ����ġ�� �ִ� ����ġ�� ������ ��� ������ �ϸ� Ǯ ����� ȸ��

*/


class CPlayer;
class CMonster;
class CEasy;

class CField
{
public:
	CField(CPlayer* pPlayer);
	~CField();
public:


public:
	CEasy* m_pEasy;
};


#endif // !Field_h

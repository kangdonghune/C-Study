#pragma once
class C_Object
{
public:
	C_Object();
	C_Object(int Hp, int Att, int Dex);

	void most_Render();
	~C_Object();

	void SetHp(int a);

protected: //protected �� ���ΰ� �ڽı��� ����ϴ� ���� ���� ������. private�� �ϸ� �ڽĿ����� �� �� �� �ִ�.
	//private�� ���ƵѰŸ� get,set �Լ��� �̿��� ���� �ְ� �޾ƾ� �Ѵ�. �ٵ� �׷� ������ ����. �ܺο��� ���� ����� �� ���м� ���� ����Ѱǵ� �ڽı��� �㰡 �� ���� ������ �ֳ�.
	int m_iHP;
	int m_iAtt;
	int m_iDex;
};


#pragma once
class CMyStatic
{
public:
	CMyStatic();
	~CMyStatic();

	static void StaticPrint();
	void Render();
public:
	static int m_ipublicStatic;
private:
	//static ��� ������ �����Ѵٸ� ����ƽ �������� �� �ٸ� �ʱ�ȭ ����� �ʿ��ϴ�. �޸� �Ҵ� ���� ������ class�� �ٸ��� ����
	static int m_iStatic;
	//static int m_iStatic = 0; �̴ϼȶ����� �������� �ʱ�ȭ �Ұ�.
	
};


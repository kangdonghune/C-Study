#include "stdafx.h"
#include "MyStatic.h"
//cpp �������� �ʱ�ȭ
//����ƽ ���� ���� �ʱ�ȭ.
int CMyStatic::m_iStatic = 0; // ���� ���� �����ڷ� Ư�� Ŭ������ ����ƽ�� �ʱ�ȭ �Ѵٰ� �������� �Ѵ�. �� ���ָ� ���� ���� �������� ����.
int CMyStatic::m_ipublicStatic = 0; //����� Ŭ���� �ʱ�ȭ���� ���Ⱑ �� ���� �Ͼ�ٴ� ���� �������.
CMyStatic::CMyStatic()
	//:m_iStatic(0) //������ ������ ����� ���⼭ �ʱ�ȭ�� ���� ����.
{
	m_iStatic = 0; //�̰� �������� �ʱ�ȭ�� �ƴϴ�.
}


CMyStatic::~CMyStatic()
{
}

void CMyStatic::StaticPrint()
{
	cout << "����ƽ �Լ� ����. Ŭ���� ���� ���̵� ��� �����մϴ�." << endl;
	// �̰��� Ŭ������ ���������� ���̱⿡ Ŭ������ ��� �Լ��� ������� ���Ѵ�.
}

void CMyStatic::Render()
{
	cout << m_iStatic << endl;
}

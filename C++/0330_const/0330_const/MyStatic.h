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
	//static 멤버 변수를 선언한다면 스테틱 변수만의 또 다른 초기화 방법이 필요하다. 메모리 할당 해제 시점이 class와 다르기 때문
	static int m_iStatic;
	//static int m_iStatic = 0; 이니셜라이저 문법으로 초기화 불가.
	
};


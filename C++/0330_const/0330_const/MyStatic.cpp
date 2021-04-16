#include "stdafx.h"
#include "MyStatic.h"
//cpp 전역에서 초기화
//스테틱 정적 변수 초기화.
int CMyStatic::m_iStatic = 0; // 범위 지정 연산자로 특정 클래스의 스테틱을 초기화 한다고 명시해줘야 한다. 안 해주면 전역 변수 선언으로 이해.
int CMyStatic::m_ipublicStatic = 0; //참고로 클래스 초기화보다 여기가 더 먼저 일어난다는 점을 기억하자.
CMyStatic::CMyStatic()
	//:m_iStatic(0) //비정적 데이터 멤버는 여기서 초기화할 수가 없다.
{
	m_iStatic = 0; //이건 대입이지 초기화가 아니다.
}


CMyStatic::~CMyStatic()
{
}

void CMyStatic::StaticPrint()
{
	cout << "스테틱 함수 생성. 클래스 생성 없이도 사용 가능합니다." << endl;
	// 이것은 클래스와 독립적으로 쓰이기에 클래스의 멤버 함수는 사용하지 못한다.
}

void CMyStatic::Render()
{
	cout << m_iStatic << endl;
}

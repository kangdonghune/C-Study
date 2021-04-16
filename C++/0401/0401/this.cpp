// 0401.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CTest
{
public:
	void Input(int m_iA)
	{
		//m_iA = m_iA;
		this->m_iA = m_iA; //기본적으로 컴파일러는 변수명을 읽을 때 this가 묵시적으로 붙어 있다. 그런데 변수명이 겹칠 경우는 명시적으로 this->를 붙여줘 해당 변수가 정확히 어떤 건지 구분해준다.
		//근데 헝가리안표기법 등으로 멤버 변수임을 드러나게 이름을 지어줬는데 매개변수를 같은 이름으로 지을 이유도 없고 부모와 멤버 이름이 겹치는 경우는 복잡해지니 이런 방식을 피하자.
	}

	void Render()
	{
		cout << m_iA << endl;
	}


private:
	int m_iA;
};


int main()
{
	//this. 매개변수와 멤버 변수의 이름이 같을 때 구분을 해주기 위해 this를 붙여서 해당 함수를 호출한 클래스의 변수라고 해주는 것이다.
	//this 객체 자신의 주소를 가지고 있는 포인터. 상수 포인터.
	CTest tT;
	tT.Input(1);
	tT.Render();
    return 0;
}


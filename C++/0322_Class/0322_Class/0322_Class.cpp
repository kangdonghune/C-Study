// 0322_Class.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CCar //C는 반드시 붙이는 게 좋다. 구조체랑 비슷하고 클래스와 구조체는 큰 차이가 없다. 
{
	//C부터 나온 구조체와 C++ 부터 나온 class와 큰 차이점이 없다. 큰 차이점은 하나
	//구조체는 데이터 집합. 클래스는 데이터와 데이터를 다루는 기능의 집합.

	int m_iSpeed; //m_ 멤버 변수라는 표기. 멤버 변수냐 지역 변수냐는 구분할 필요가 있다.
public:
	void Driving()
	{
		cout << "시속:" << m_iSpeed << "KM" << endl;
	}
};
//구조체는 접근제어 범위자가 기본적으로 디펄트값은 public 내외부 어디서든 접근할 수 있게 만들겠다.
//클래스는 디펄트 값이 private 내 안에 말고는 다 접근 못하게 막겠다.

int main()
{
	//class
	//객체지향-어떠한 개체. 데이터와 데이터를 다루는 기능(함수)을 하나로 묶어 객체로 만들어 프로그래밍 하는 방법.
	//함수를 통해 객체끼리 의사소통을 하는 것. 메시지 파싱

	CCar tCar; //구조체와의 차이점은 접근제어 지시자가 무엇으로 되어있느냐이다.
	tCar.Driving();
	return 0;
}


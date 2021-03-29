#include "stdafx.h"

class CCapsule
{
public:
	void Eat()
	{
		std::cout << "감기 싹 사라짐" << std::endl;
	}
};
class CCapsule1
{
public:
	void Eat()
	{
		std::cout << "감기 싹 사라짐1" << std::endl;
	}
};
class CCapsule2
{
public:
	void Eat()
	{
		std::cout << "감기 싹 사라짐2" << std::endl;
	}
};

class CSynthesisCapsule
{
public:
	void Eat()
	{
		C0.Eat();
		C1.Eat();
		C2.Eat();
	}//이런 식으로 캡슐화된 클래스에서 순서를 지정해주거나 작성자가 원하는 방식으로 작동하게끔 유도하는 것으로 함수가 엉키는 걸 방지.
private:	
	CCapsule C0;
	CCapsule1 C1;
	CCapsule2 C2;
};

void main()
{
	//캡슐화
	//필요한 기능들을 다 따로따로 만들어두면 기능의 순서들이 엉킬 수 있다.
	//따라서 필요한 기능들을 하나로 묶고 그거 하나만 호출하면 순서가 지켜지도록 정의하면 문제 발생을 막는다.
	CSynthesisCapsule CS;
	CS.Eat();
}
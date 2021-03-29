// 0326_생성자.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


class CConstruct
{
public:
	CConstruct() 
	{
		std::cout << "두근두근 생성자 호출" << std::endl;
	}

	CConstruct(int a)
	{
		std::cout << "두근두근 생성자 호출, 추가 생성자" << std::endl;
		iCount = a;
	}
	int GetCount() { return iCount; }
private:
	int iCount = 10;;
};

int main()
{
	//클래스가 생성이되고 자동으로 정의하고 호출하는 4가지 중 하나.
	//반환값이 없는 형태
	//함수의 일종이기에 오버로딩 가능.
	//CConstruct tConst = CConstruct(2); //사용자가 별도로 생성자 호출 안 할 시 객체를 생성할 때 컴파일러가 자동으로 기본 생성자 호출. 기본 생성자가 막혀있다면(private) 또는 사용자가 생성자를 만들었다면 사용자가 지정을 해줘야 한다.
	CConstruct tConst; //기본
	std::cout << tConst.GetCount() << std::endl;
	return 0;
}


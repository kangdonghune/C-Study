// 0405.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class C_Obj
{
	void CO_Test()
	{
		cout << "O" << endl;
	}

	virtual void Render() = 0;
};

class CP : public C_Obj
{
public:
	void CP_Test()
	{
		cout << "P" << endl;
		cout << m_iA << endl;
	}
	virtual void Render()
	{

	};

private:
	int m_iA = 10;

};

class CM : public C_Obj
{
public:

	void CM_Test()
	{
		cout << "M" << endl;
	}
	virtual void Render()
	{

	};
};
int main()
{
	C_Obj* pTest = new CP;
	C_Obj* pTest3 = new CM;
	//스테틱 캐스트는 부모만 같으면 형제로도 캐스팅이 된다. 문제는 형제가 서로 다른 멤버변수를 가지고 있을 때 이에 접근할 때 에러가 발생할 수 있다.
	//다이나믹 캐스트는 런타임 시점에 실행. 상속관계와 가상 함수의 유무도 따진다. 가상함수 없으면 형변환이 안된다. 최소 1개 이상
	//형변환이 안전하지 않다 판단하면 nullptr로 반환한다.
	//다이나믹 캐스트는 밑에서 nullptr 체크를 해주는 게 좋은 습관이다.
	dynamic_cast<CP*>(pTest)->CP_Test();
	CM* tCm = dynamic_cast<CM*>(pTest);
	tCm->CM_Test(); //딱히 CM의 멤버를 가져다 쓰는 게 아니라서 에러 자체는 안나지만 위험한 문장이다. 왜냐면 현재 tCm = nullptr 상태.
	if (tCm == nullptr)
		cout << "tCm이 비어있다." << endl;
	CP* pTest2 = dynamic_cast<CP*>(pTest);
	pTest2->CP_Test();
	//reinterpret_cast 는 형변환 대상이 포인터 혹은 레퍼런스를 대상으로 한다.
	//c 스타일 형변환과 동일. 잘못 여부 일절 따지지 않는다.

	//const_cast
	//포인터 혹은 레퍼런스에만 형변환을 허가.
	int iA = 10;
	const int* ptr = &iA; // 이 경우 값 변경을 할 수 없는데 const 캐스트는 이걸 가능하게 해준다. 
	//const 설정을 무너트린다. 근데 값을 바꾸지 마라고 const를 해둔 건데 그걸 함부로 푸는 거니 사용에 심사숙고하자.
	//원본(iA)이 const 면 const 캐스트를 해도 값이 변하지 않는다. 근데 디버깅 동안에는 값이 변한 걸로 인식이 된다는 문제가 있으니 유의하자.
	//여기서 발생하는 게 도중에 const 캐스트 한 걸로 연산을 해서 변수에 대입해버리면 그 변수는 또 바뀐 값으로 들어간다. 근데 출력할 때 보면 원본은 그대로.

    return 0;
}


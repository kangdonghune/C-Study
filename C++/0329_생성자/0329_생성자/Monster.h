#pragma once
#include "stdafx.h"


class CPlayer;
class CMonster
{
public:
	CMonster();
	~CMonster();

	void Test();

private:
	CPlayer* m_tPlayer; //기본적으로 선언만 되어있
	//추가로 정의부에서 include "해당 클래스 헤더" 를 해서 해당 클래스의 헤더를 가져다 정의해야지 해당 클래스가 가진 멤버나 함수를 활용 가능해진다.
	//CPlayer m_tPlayer2; //또는 전방 고 정의가 안되어있다면 해당 클래스의 크기를 알 수 없기에 멤버 변수로 타 클래스를 가지면 에러가 난다.
	//그래서 포인터를 사용하여 4바이트로 크기를 확정지어주면 에러가 해결.선언을 해주면 해당 클래스에 대해 인지하게 되고 위에 include한 것으로 정의 또한 완료하여 해당 클래스의 크기와 멤버, 함수 등을 쓸 수 있다.
};


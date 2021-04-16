#pragma once
#include "Player.h"
class CUser : public CPlayer
{
public:
	CUser();
	~CUser();

public:
	int m_iHP; //만약 자식과 부모의 멤버 변수명이 같다면(그렇게 만들면 안 되지만) 해당 객체에서 호출 시 우선되는 것은 현재 객체의 멤버 변수다. 근데 부모의 함수를 호출할 때는 부모 기준으로 멤버 변수가 잡히게 된다.
};


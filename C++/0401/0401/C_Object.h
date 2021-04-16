#pragma once
class C_Object
{
public:
	C_Object();
	C_Object(int Hp, int Att, int Dex);

	void most_Render();
	~C_Object();

	void SetHp(int a);

protected: //protected 는 본인과 자식까지 허용하는 접근 지시 제어자. private로 하면 자식에서도 못 쓸 수 있다.
	//private로 막아둘거면 get,set 함수를 이용해 값을 주고 받아야 한다. 근데 그럴 이유가 없다. 외부에서 쓰지 말라는 건 은닉성 등을 고려한건데 자식까진 허가 안 해줄 이유가 있나.
	int m_iHP;
	int m_iAtt;
	int m_iDex;
};


#pragma once
#include "C_Object.h" //상속 선언에서는 단순 선언만 해두면 되는 게 아니고 해당 부모의 모든 것을 알아야 하기에 헤더를 삽입해야 한다.

//전방선언은 존재 자체만 알려주는 것이기에 자식에서 어떤 데이터를 물려 받아야 하는 지 모르기 때문에 에러 발생.
class CPlayer : public C_Object //여기 붙인 public은 외부에서 자식 클래스를 객체로 만들었을 때 외부에서 부모 클래스의 public의 요소를 건들 수 있게 해주겠다.
								//protected는 자식에서 객체로 만들었을 때까지만 값 변경 허락, private는 상속받은 객체 내부에서만을 제외하곤 부모 멤버를 못 건들도록.
								//부모의 멤버 접근 지시 제어자의 defalut값을 지정해주는 것으로 자동으로 엄격한 쪽으로 맞춰준다..(public << protected < private)
								//부모 접근 지시자가 public인데 자식이 지정한 게 protected 면 protected로 부모의 지시자가 private면 그대로 private
								//보통은 public으로 설정해주는 편이다.(private 등으로 하면 부모에서 설정한 접근 지시제어자가 의미가 없어지니).
{						
public:
	CPlayer();
	~CPlayer();
public:
	void Render();

private:
	char m_szJob[32];
};

//자식은 부모의 크기 + 자기 자신의 크기를 가지고 만들어 진다.

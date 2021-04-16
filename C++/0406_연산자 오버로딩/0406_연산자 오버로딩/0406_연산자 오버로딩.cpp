// 0406_연산자 오버로딩.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CPoint
{
public:
	CPoint(float fx, float fy)
		:m_fx(fx), m_fy(fy)
	{
	}
public:
	void Render()
	{
		cout << m_fx << "," << m_fy << endl;
	}

public:
	CPoint& operator=(const CPoint& rPoint) // 디폴트 대입 연산자 굳이 리턴을 해주는 이유는 연속적인 연산이 가능하도록 하기 위해. 복사생성자와 기능이 같다. 같은 문제로 얕은 복사가 이루어진다는 문제가 있다.
	{
		m_fx = rPoint.m_fx;
		m_fy = rPoint.m_fy;
		return *this;
	}//만약에 멤버 변수로 포인터를 가지고 있을 경우, 그것도 할당된 주소값을 들고 있는 경우 깊은 복사로 구현을 해줘여 한다.

	CPoint operator+(const CPoint& rhs)
	{
		CPoint temp(0,0);
		temp.m_fx = this->m_fx + rhs.m_fx;
		temp.m_fy = this->m_fy + rhs.m_fy;
		return temp;
	}

	CPoint& operator++() 
		//전위 연산자 //이 경우 레퍼런스가 아니라 단순 CPoint를 넘겨주면 ++연산을 반복해서 사용할 경우 매 실행마다 반환 클래스가 임시 주소에 할당되고 해당 임시 주소에 대한 전위 연산이 반복된다.
		//그러면 결과적으론 연산이 1번만 실행되게 된다는 문제가 발생한다.(매 실행마다 임시 변수를 생성해 그 기준으로 하다보니 처음 1번만 원본에 대한 연산이 된다.)
	{
		m_fx += 1;
		m_fy += 1;
		return *this;
	}
	CPoint operator++(int) //후위 연산의 경우 인자로 int를 넘겨주면 된다. 애초에 증감식은 1씩 값 변동이기에 int로 고정을 해놔서 float같은 다른 인자를 주면 후위연산으로 인식이 안 된다.
	{
		CPoint tTemp(*this); //복사 생성자.
		m_fx += 1;
		m_fy += 1;
		return tTemp; //변하기 전 값을 반환해서 함수 실행시키고 원본은 변화 시킨 상태.
	}

private:
	float m_fx;
	float m_fy;
};

int main()
{
	//객체가 생성될 떄 자동으로 정의되는 4가지 생성자 소멸자 복사 생성자 디폴트 대입연산자.
	//연산자 오버로딩은 객체를 꾸릴 때 주로 사용을 한다.
	CPoint tPoint1(100, 200);
	CPoint tPoint2(200, 300);
	CPoint Total(0, 0);
	Total = tPoint1 + tPoint2; // Total.operator=(tPoint1.operator+(tPoint2)); 를 보다 편이하게 해둔 형태.
	++Total;
	++++Total;
	Total++.Render();
	Total.Render();
	tPoint1.Render();
	return 0;
}


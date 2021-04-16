// 0406_������ �����ε�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
	CPoint& operator=(const CPoint& rPoint) // ����Ʈ ���� ������ ���� ������ ���ִ� ������ �������� ������ �����ϵ��� �ϱ� ����. ��������ڿ� ����� ����. ���� ������ ���� ���簡 �̷�����ٴ� ������ �ִ�.
	{
		m_fx = rPoint.m_fx;
		m_fy = rPoint.m_fy;
		return *this;
	}//���࿡ ��� ������ �����͸� ������ ���� ���, �װ͵� �Ҵ�� �ּҰ��� ��� �ִ� ��� ���� ����� ������ ���࿩ �Ѵ�.

	CPoint operator+(const CPoint& rhs)
	{
		CPoint temp(0,0);
		temp.m_fx = this->m_fx + rhs.m_fx;
		temp.m_fy = this->m_fy + rhs.m_fy;
		return temp;
	}

	CPoint& operator++() 
		//���� ������ //�� ��� ���۷����� �ƴ϶� �ܼ� CPoint�� �Ѱ��ָ� ++������ �ݺ��ؼ� ����� ��� �� ���ึ�� ��ȯ Ŭ������ �ӽ� �ּҿ� �Ҵ�ǰ� �ش� �ӽ� �ּҿ� ���� ���� ������ �ݺ��ȴ�.
		//�׷��� ��������� ������ 1���� ����ǰ� �ȴٴ� ������ �߻��Ѵ�.(�� ���ึ�� �ӽ� ������ ������ �� �������� �ϴٺ��� ó�� 1���� ������ ���� ������ �ȴ�.)
	{
		m_fx += 1;
		m_fy += 1;
		return *this;
	}
	CPoint operator++(int) //���� ������ ��� ���ڷ� int�� �Ѱ��ָ� �ȴ�. ���ʿ� �������� 1�� �� �����̱⿡ int�� ������ �س��� float���� �ٸ� ���ڸ� �ָ� ������������ �ν��� �� �ȴ�.
	{
		CPoint tTemp(*this); //���� ������.
		m_fx += 1;
		m_fy += 1;
		return tTemp; //���ϱ� �� ���� ��ȯ�ؼ� �Լ� �����Ű�� ������ ��ȭ ��Ų ����.
	}

private:
	float m_fx;
	float m_fy;
};

int main()
{
	//��ü�� ������ �� �ڵ����� ���ǵǴ� 4���� ������ �Ҹ��� ���� ������ ����Ʈ ���Կ�����.
	//������ �����ε��� ��ü�� �ٸ� �� �ַ� ����� �Ѵ�.
	CPoint tPoint1(100, 200);
	CPoint tPoint2(200, 300);
	CPoint Total(0, 0);
	Total = tPoint1 + tPoint2; // Total.operator=(tPoint1.operator+(tPoint2)); �� ���� �����ϰ� �ص� ����.
	++Total;
	++++Total;
	Total++.Render();
	Total.Render();
	tPoint1.Render();
	return 0;
}


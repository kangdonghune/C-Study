// 0406.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "InlineFunc.h"

//������ �Լ� �ϳ��� ���� ����� �ϴ� ��.



class CShape
{
public:
	virtual void Draw() = 0;
};

class CTriangle : public CShape
{
public:
	virtual void Draw()
	{
		cout << "�ﰢ���� �׸���" << endl;
	}
public:
	
};

class CSquare : public CShape
{
public:
	virtual void Draw()
	{
		cout << "�簢���� �׸���." << endl;
	}
};


class CCircle : public CShape
{
public:
	virtual void Draw()
	{
		cout << "���� �׸���" << endl;
	}
};

//inline- ȣ��Ǵ� �Լ��� �� ���ο� ���ԵǴ� �������� ����Ǵ� �Լ�

void DrawC()
{
	cout << "C�� �׸���" << endl;
}

int main()
{
	CShape* pShapes[3] = { new CTriangle, new CSquare, new CCircle };

	for (int i = 0; i < 3; i++)
	{
		pShapes[i]->Draw();
	}


	for (int i = 0; i < 3; i++)
	{
		delete pShapes[i];
	}

	void(*Func_Draw)() = DrawC;
	Func_Draw();
	CInlineFunc cI;
	cI.SelfCall(5);

}


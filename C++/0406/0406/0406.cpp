// 0406.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "InlineFunc.h"

//다형성 함수 하나로 여러 기능을 하는 것.



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
		cout << "삼각형을 그리다" << endl;
	}
public:
	
};

class CSquare : public CShape
{
public:
	virtual void Draw()
	{
		cout << "사각형을 그리다." << endl;
	}
};


class CCircle : public CShape
{
public:
	virtual void Draw()
	{
		cout << "원을 그리다" << endl;
	}
};

//inline- 호출되는 함수가 그 라인에 삽입되는 형식으로 진행되는 함수

void DrawC()
{
	cout << "C를 그리다" << endl;
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


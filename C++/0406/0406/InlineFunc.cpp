#include "stdafx.h"
#include "InlineFunc.h"


CInlineFunc::CInlineFunc()
	:m_iA(10), Func(nullptr), AddFunc(nullptr)
{
}


CInlineFunc::~CInlineFunc()
{
}

int CInlineFunc::Get_A()
{
	return m_iA;
}

int CInlineFunc::Add(int a, int b)
{
	return a+b;
}

void CInlineFunc::Print(int(*get)())
{
	cout << get() << endl;
}


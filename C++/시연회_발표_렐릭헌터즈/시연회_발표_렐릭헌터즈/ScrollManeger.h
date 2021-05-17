#pragma once
class CScrollManeger
{
public:
	CScrollManeger();
	~CScrollManeger();

public:
	static void Set_ScrollX(float _fx) { m_fScrollX += _fx; }
	static void Set_ScrollY(float _fy) { m_fScrollY += _fy; }
	static float Get_ScrollX() { return m_fScrollX; }
	static float Get_ScrollY() { return m_fScrollY; }
public:
	static void ScrollLcok();

private:
	static float m_fScrollX;
	static float m_fScrollY;
};


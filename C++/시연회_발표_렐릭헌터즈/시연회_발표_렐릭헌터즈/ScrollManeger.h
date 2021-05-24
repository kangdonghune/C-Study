#pragma once
class CScrollManeger
{
public:
	CScrollManeger();
	~CScrollManeger();

public:
	static float Set_ScrollX(float _fx); 
	static float Set_ScrollY(float _fy); 
	static float Get_ScrollX() { return m_fScrollX; }
	static float Get_ScrollY() { return m_fScrollY; }
public:
	static void ScrollLcok();

private:
	static float m_fScrollX;
	static float m_fScrollY;
};


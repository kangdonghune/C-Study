#pragma once
class CMain
{
private:
	CMain();
public:
	~CMain();

public:
	static CMain* Create();

public:

	int Ready_Main();
	int Update_Main();
	int Render_Main();
	int Release_Main();

private:
	HDC m_hDC;
	D3DXVECTOR3 m_D3vec[4];
	float m_fAngle;
	int m_iC;
	D3DXVECTOR3 m_Pos;

};


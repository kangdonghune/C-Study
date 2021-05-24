#pragma once
#include "Logo.h"
class CStageLogo : public CLogo
{
	CStageLogo();
public:
	~CStageLogo();
public:
	static CStageLogo* Create(int Num);

public:

	virtual int Ready_Logo();
	virtual int Update_Logo();
	virtual int Render_Logo(HDC hdc);
	virtual int Release_Logo();

private:
	int m_iEffectNum;

};


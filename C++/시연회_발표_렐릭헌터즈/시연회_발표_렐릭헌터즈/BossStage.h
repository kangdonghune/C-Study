#pragma once
#include "Scene.h"
class CStageLogo;
class CBossStage :public CScene
{
private:
	CBossStage();
	~CBossStage();
public:
	static CScene* Create();
public:
	// CScene을(를) 통해 상속됨
	virtual int Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void Render_Scene(HDC hdc) override;
	virtual void Release_Scene() override;

private:
	CStageLogo* m_pEffect;
};


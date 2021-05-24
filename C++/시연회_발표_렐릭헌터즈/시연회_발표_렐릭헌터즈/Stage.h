#pragma once
#include "Scene.h"
class CStageLogo;
class CStage : public CScene
{
private:
	CStage();
	~CStage();
public:
	static CScene* Create();

	bool* GetStageChange() { return &m_bStageChange; }
public:
	// CScene을(를) 통해 상속됨
	virtual int Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;

private:
	bool m_bStageChange;
	CStageLogo* m_pEffect;
};


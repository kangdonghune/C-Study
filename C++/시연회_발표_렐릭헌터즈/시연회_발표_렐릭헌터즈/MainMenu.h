#pragma once
#include "Scene.h"
class CMainMenu : public CScene
{
private:
	CMainMenu();
	~CMainMenu();
public:
	static CScene* Create();
public:
	// CScene을(를) 통해 상속됨
	virtual int Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;
};


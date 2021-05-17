#pragma once
#include  "Scene.h"

class CEditor : public CScene
{
private:
	CEditor();
public:
	static CScene* Create();
public:
	~CEditor();

	// CScene��(��) ���� ��ӵ�
	virtual int Ready_Scene() override;
	virtual void Update_Scene() override;
	virtual void Render_Scene(HDC hDC) override;
	virtual void Release_Scene() override;
};


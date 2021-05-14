#pragma once
class C_Bitmap;
class CBitmapManeger
{
private:
	CBitmapManeger();
public:
	~CBitmapManeger();
public:
	static CBitmapManeger* Get_BitmapManeger();
	static void Destroy_BitmapManeger();

public:
	HDC Get_BitmapDC(const TCHAR* pKey);
	C_Bitmap* Get_Bitmap(const TCHAR* pKey);
	int Insert_BitmapManeger(const TCHAR* pKey, const TCHAR* pFilePath);
	int Release_BitmapManeger();
public:
	int Ready_BitmapManeger();
private:
	static CBitmapManeger* m_BMpInstance;
	map<const TCHAR*, C_Bitmap*> m_mapBitmap;
};


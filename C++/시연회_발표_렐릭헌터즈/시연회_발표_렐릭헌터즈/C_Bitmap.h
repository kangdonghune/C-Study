#pragma once
class C_Bitmap
{
private:
	explicit C_Bitmap();
public:
	~C_Bitmap();
public:
	static C_Bitmap* Create(const TCHAR* pFilePath);

public:
	const HDC Get_BitmapDC() { return m_BitmapDc; }
	const HBITMAP& Get_Bitmap() { return m_Bitmap; }
	void Insert_Bitmap(const TCHAR* pFilePath);
	void Release_Bitmap();


private:
	HDC m_BitmapDc;
	HBITMAP m_Bitmap;
	HBITMAP m_OldBitmap;


};


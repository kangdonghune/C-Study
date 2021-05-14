#include "stdafx.h"
#include "C_Bitmap.h"

C_Bitmap::C_Bitmap()
{
}


C_Bitmap::~C_Bitmap()
{
}

C_Bitmap * C_Bitmap::Create(const TCHAR * pFilePath)
{
	C_Bitmap* pInstance = new C_Bitmap();
	pInstance->Insert_Bitmap(pFilePath);
	return pInstance;
}

void C_Bitmap::Insert_Bitmap(const TCHAR * pFilePath)
{
	HDC hdc = GetDC(g_HWND);
	m_BitmapDc = CreateCompatibleDC(hdc);
	ReleaseDC(g_HWND,hdc);
	m_Bitmap = (HBITMAP)LoadImage(NULL, pFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION); // 0, 0 은 사진 자체 크기에 맞추겠다.
	m_OldBitmap = (HBITMAP)SelectObject(m_BitmapDc, m_Bitmap);
}



void C_Bitmap::Release_Bitmap()
{
	SelectObject(m_BitmapDc, m_OldBitmap);
	DeleteObject(m_Bitmap);
	DeleteDC(m_BitmapDc);

}




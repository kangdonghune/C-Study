// fopen_s�׽�Ʈ.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int main()
{
	FILE* fp = nullptr;
	
	errno_t err = fopen_s(&fp, "fopen_stest.txt", "r,ccs=UTF-8");
	/*char s[20];
	fgets(s, 19, fp);
	cout << s << endl;*/

	/*fseek(fp, 0, SEEK_END);
	int iSize = ftell(fp) + 1;
	char* szBuff = new char[iSize];
	fseek(fp, 0, SEEK_SET);*/
	wchar_t szBuff[256]{};
	if (!err)
	{
		cout << "������� ���� ����" << endl;
		fread(szBuff, size(szBuff),1,fp);
		cout << szBuff << endl;
		fclose(fp);
	}
	else
	{
		cout << "������� ���� ����" << endl;
	}

}


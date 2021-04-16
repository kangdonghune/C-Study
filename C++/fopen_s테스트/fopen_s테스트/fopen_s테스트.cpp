// fopen_s테스트.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
		cout << "파일통로 개방 성공" << endl;
		fread(szBuff, size(szBuff),1,fp);
		cout << szBuff << endl;
		fclose(fp);
	}
	else
	{
		cout << "파일통로 개방 실패" << endl;
	}

}


#include <iostream>

using namespace std;

int main()
{
	FILE* fPhoto;

	errno_t err1 = fopen_s(&fPhoto, "연예인사진.jfif", "rb");

	fseek(fPhoto, 0, SEEK_END);
	int iSize = ftell(fPhoto);
	char* PhotoArr = new char[iSize];
	fseek(fPhoto, 0, SEEK_SET);

	if (!err1)
	{
		cout << "사진 파일 읽기" << endl;
		fread(PhotoArr, sizeof(char), iSize, fPhoto);
		cout << "사진 저장 완료" << endl;	
		fclose(fPhoto);
	}
	else
	{
		cout << "사진 읽기 실패" << endl;
	}

	FILE* fPhoto2;
	errno_t err2 = fopen_s(&fPhoto2, "연예인사진(복사본).jfif", "wb");

	if (!err2)
	{
		cout << "사진 복사 실행" << endl;
		fwrite(PhotoArr, sizeof(char), iSize, fPhoto2);
		cout << "사진 복사 완료" << endl;
		fclose(fPhoto2);
 	}
	else
	{
		cout << "사진 복사 실패." << endl;
	}

}

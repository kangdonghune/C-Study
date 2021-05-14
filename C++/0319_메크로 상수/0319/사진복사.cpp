#include <iostream>

using namespace std;

int main()
{
	FILE* fPhoto;

	errno_t err1 = fopen_s(&fPhoto, "연예인사진.jfif", "rb");//파일 통로 개방이 정상적으로 이루어졌다면 0 반환. 상대주소 기준은 vcproj.해당 프로젝트의 폴더명, 이경우는 제일 안쪽 fopen_s예제 들어가면 있는 vcproj가 기준

	fseek(fPhoto, 0, SEEK_END); //파일위치 지시자를 제일 끝으로
	int iSize = ftell(fPhoto); //제일 끝의 위치를 int 값으로 받아 배열의 크기 반환.
	char* PhotoArr = new char[iSize]; //해당 크기 만큼의 문자 배열 동적 생성.
	fseek(fPhoto, 0, SEEK_SET);//옮겨둔 파일 위치 지시자를 제일 처음 으로 이동.

	if (!err1) 
	{
		cout << "사진 파일 읽기" << endl;
		fread(PhotoArr, sizeof(char), iSize, fPhoto);  //사진 정보를 배열에 저장.
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
		fwrite(PhotoArr, sizeof(char), iSize, fPhoto2); //배열을 긁어다가 해당 경로에 쓴다. 참고로 읽을 때는 해당 파일이 없으면 파일 통로 개방이 안되지만 쓸 때는 파일 없으시 생성하여 작성한다.
		cout << "사진 복사 완료" << endl;
		fclose(fPhoto2);
 	}
	else
	{
		cout << "사진 복사 실패." << endl;
	}

}

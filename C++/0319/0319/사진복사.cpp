#include <iostream>

using namespace std;

int main()
{
	FILE* fPhoto;

	errno_t err1 = fopen_s(&fPhoto, "�����λ���.jfif", "rb");

	fseek(fPhoto, 0, SEEK_END);
	int iSize = ftell(fPhoto);
	char* PhotoArr = new char[iSize];
	fseek(fPhoto, 0, SEEK_SET);

	if (!err1)
	{
		cout << "���� ���� �б�" << endl;
		fread(PhotoArr, sizeof(char), iSize, fPhoto);
		cout << "���� ���� �Ϸ�" << endl;	
		fclose(fPhoto);
	}
	else
	{
		cout << "���� �б� ����" << endl;
	}

	FILE* fPhoto2;
	errno_t err2 = fopen_s(&fPhoto2, "�����λ���(���纻).jfif", "wb");

	if (!err2)
	{
		cout << "���� ���� ����" << endl;
		fwrite(PhotoArr, sizeof(char), iSize, fPhoto2);
		cout << "���� ���� �Ϸ�" << endl;
		fclose(fPhoto2);
 	}
	else
	{
		cout << "���� ���� ����." << endl;
	}

}

#include <iostream>

using namespace std;

int main()
{
	FILE* fPhoto;

	errno_t err1 = fopen_s(&fPhoto, "�����λ���.jfif", "rb");//���� ��� ������ ���������� �̷�����ٸ� 0 ��ȯ. ����ּ� ������ vcproj.�ش� ������Ʈ�� ������, �̰��� ���� ���� fopen_s���� ���� �ִ� vcproj�� ����

	fseek(fPhoto, 0, SEEK_END); //������ġ �����ڸ� ���� ������
	int iSize = ftell(fPhoto); //���� ���� ��ġ�� int ������ �޾� �迭�� ũ�� ��ȯ.
	char* PhotoArr = new char[iSize]; //�ش� ũ�� ��ŭ�� ���� �迭 ���� ����.
	fseek(fPhoto, 0, SEEK_SET);//�Űܵ� ���� ��ġ �����ڸ� ���� ó�� ���� �̵�.

	if (!err1) 
	{
		cout << "���� ���� �б�" << endl;
		fread(PhotoArr, sizeof(char), iSize, fPhoto);  //���� ������ �迭�� ����.
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
		fwrite(PhotoArr, sizeof(char), iSize, fPhoto2); //�迭�� �ܾ�ٰ� �ش� ��ο� ����. ����� ���� ���� �ش� ������ ������ ���� ��� ������ �ȵ����� �� ���� ���� ������ �����Ͽ� �ۼ��Ѵ�.
		cout << "���� ���� �Ϸ�" << endl;
		fclose(fPhoto2);
 	}
	else
	{
		cout << "���� ���� ����." << endl;
	}

}

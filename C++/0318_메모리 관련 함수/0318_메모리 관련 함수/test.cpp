#include <iostream>

int main()
{
	
	FILE* fPlayerIntstatus = nullptr;
	FILE* fPlayerCharstatus = nullptr;
	errno_t err1 = fopen_s(&fPlayerIntstatus, "./../../0316/0316/Save/SaveData(int).txt", "rt");
	

	
	fseek(fPlayerIntstatus, 0, SEEK_END);
	int	iSize = ftell(fPlayerIntstatus)/4;//23 �� ������? 1 220 35 1 0 100 . �� �׷��ڴ�. int 4����Ʈ�� �ε��� 0���ʹϱ� int 6�� x 4 �ϴϱ�
	int* iOut = new int[iSize];
	fseek(fPlayerIntstatus, 0, SEEK_SET);

	if (0 == err1)
	{
		std::cout << "����"<< std::endl;
		fread(iOut, sizeof(iOut)*iSize, 1, fPlayerIntstatus);
		for (int i = 0; i < iSize; i++)
		{
			std::cout << iOut[i] << std::endl;
		}
	}
	fclose(fPlayerIntstatus);
	errno_t err2 = fopen_s(&fPlayerCharstatus, "./../../0316/0316/Save/SaveData(char).txt", "rt");
	fseek(fPlayerCharstatus, 0, SEEK_END);
	int	ichSize = ftell(fPlayerCharstatus);// ���� ���빰�� ���� ������ 6�� ũ���ε� ����� 24�� ������? ����
	char* chOut = new char[ichSize];
	fseek(fPlayerCharstatus, 0, SEEK_SET);

	if (0 == err2)
	{
		std::cout << "����" << std::endl;
		fgets(chOut, ichSize, fPlayerCharstatus);
		fputs(chOut, stdout);
	}

	delete[] chOut;
	delete[] iOut;
}
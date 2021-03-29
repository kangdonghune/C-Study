#include <iostream>

int main()
{
	
	FILE* fPlayerIntstatus = nullptr;
	FILE* fPlayerCharstatus = nullptr;
	errno_t err1 = fopen_s(&fPlayerIntstatus, "./../../0316/0316/Save/SaveData(int).txt", "rt");
	

	
	fseek(fPlayerIntstatus, 0, SEEK_END);
	int	iSize = ftell(fPlayerIntstatus)/4;//23 이 나오네? 1 220 35 1 0 100 . 왜 그러겠니. int 4바이트고 인덱스 0부터니까 int 6개 x 4 하니까
	int* iOut = new int[iSize];
	fseek(fPlayerIntstatus, 0, SEEK_SET);

	if (0 == err1)
	{
		std::cout << "성공"<< std::endl;
		fread(iOut, sizeof(iOut)*iSize, 1, fPlayerIntstatus);
		for (int i = 0; i < iSize; i++)
		{
			std::cout << iOut[i] << std::endl;
		}
	}
	fclose(fPlayerIntstatus);
	errno_t err2 = fopen_s(&fPlayerCharstatus, "./../../0316/0316/Save/SaveData(char).txt", "rt");
	fseek(fPlayerCharstatus, 0, SEEK_END);
	int	ichSize = ftell(fPlayerCharstatus);// 현재 내용물은 법사 강동훈 6개 크기인데 사이즈가 24가 나오네? 왜지
	char* chOut = new char[ichSize];
	fseek(fPlayerCharstatus, 0, SEEK_SET);

	if (0 == err2)
	{
		std::cout << "성공" << std::endl;
		fgets(chOut, ichSize, fPlayerCharstatus);
		fputs(chOut, stdout);
	}

	delete[] chOut;
	delete[] iOut;
}
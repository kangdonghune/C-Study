#include <iostream>

using namespace std;

int main()
{
	const int iNameSize = 255;
	int count = 0;
	const char Name[iNameSize] = "count6";
	//name[2] = '\0'; // 문자열 중간에 널 문자가 섞일 경우 그 뒤에 추가 문자열이 있어도 strlen에서도 count가 되지 않는다.
	
	for (int i = 0; i < sizeof(Name); i++)
	{
		if ('\0' == Name[i])
			break;
		count++;
	}
	cout << count << endl;
}
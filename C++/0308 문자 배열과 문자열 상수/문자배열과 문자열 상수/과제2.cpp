#include <iostream>

using namespace std;

int main()
{
	const int iNameSize = 255;
	int count = 0;
	const char Name[iNameSize] = "count6";
	//name[2] = '\0'; // ���ڿ� �߰��� �� ���ڰ� ���� ��� �� �ڿ� �߰� ���ڿ��� �־ strlen������ count�� ���� �ʴ´�.
	
	for (int i = 0; i < sizeof(Name); i++)
	{
		if ('\0' == Name[i])
			break;
		count++;
	}
	cout << count << endl;
}
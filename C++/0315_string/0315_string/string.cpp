#include <iostream>
#include <string>  //.h �� ���� �ֵ��� C �� ���� �ֵ�

using namespace std;

int main()
{
	string str1 = "Hello World!"; //��Ʈ���̶� Ŭ������ �⺻������ 28����Ʈ�� �����ϰ� �ִ�.
	cout << str1 << endl;
	str1 = "change";
	cout << str1 << endl;
	str1 = "hello+";
	str1 += "world";
	cout << str1 << endl;
	string str2 = str1;
	cout << str2 << endl;
	cout << (str1 == str2) << endl;
	cout << str2.size() << endl;
	cout << str1.length() << endl;//�Ѵ� ���ڱ��� ��ȯ.

	const char* pstr = str1.c_str(); //const char*Ÿ������ ��ȯ. string Ÿ���� char ���ڹ迭�� ���� �� �ֵ��� �Ѱ��ִ� �Լ�.
	cout << pstr << endl;
	char ch1[255] = "char to string"; //�ݴ�� �Ѱ��� ���� ���� �����ڸ� ���� �ȴ�. ������ �Լ� �����ε� �Ǿ��ִ�.
	str1 = ch1;
	cout << str1 << endl;
	cout << sizeof(str1) << endl;
	//�ٵ� strcmp, strlenm strcpy_s, strcat_s ���� ���� ���°��ϸ� �װ͵� �ƴѰ� ���߿� ������ ���ù��ڿ��� �� ���� �����.
	//�̷��� ������ ���ù��ڿ��� �ͼ������� ���� ���� ���� ���� �ʴ� �� ��õ�Ѵ�.
}
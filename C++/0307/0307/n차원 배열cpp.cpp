#include <iostream>
using namespace std;

int main()
{
	//n���� �迭
	//2���� �迭


	int doubleArray[2][3] =
	{
		{1,2,3}, 
		{4,5,6}
	};

	int* ptr = doubleArray[0];

	cout << doubleArray[1][1] << endl;
	cout << *(*(doubleArray + 1) + 1) << endl; // doubleArray +1 �� �ع����� 4����Ʈ �����̵��� �ƴ϶� double[0] -> double[1]�� �̵��Ѵ�.
	cout << *(doubleArray[1] + 1) << endl; 
	// ������ �迭�� 1���� �迭�� �� ���ҷ� �� �ٸ� 1���� �迭�� ������ �ֱ⿡ ������ �����ڷ� ���� �ش� 1���� �迭�� �����´�.
	// �ش� 1���� �迭�� ������ �迭[]�� �ƴ� �׳� �迭�� �ش� �迭�� ù ���� �ּҸ� ��ȯ�Ѵ�.
	// ���� �ش� �ּ� +1�� �ϰ� * �������� �ϸ� 1���� �迭 �ȿ� 1���� �迭�� Ư�� �ε����� ���� ��ȯ�ȴ�.
	cout << (*(doubleArray+1))[1] << endl;
	cout << *(ptr+4) << endl;
	//cout << doubleArray[size(doubleArray)][size(doubleArray[][])] << endl;

	//2���� �迭 ������ ����. 2���� �迭�� ���� �����Ͱ� �ƴ϶� �� �ٸ� ������ ������ ������.
	//�� �� ���� ũ��� �׻� ��ġ�ؾ� �Ѵ�.
	int(*pArr)[3] = doubleArray;

	cout << pArr[1][1] << endl;
}

void show(int arr2D[][3]) //�̷� ������ �Ű� ������ �޾� �� �� �ִµ� �ݵ�� ���� ������ �������� �Ѵ�.
{

}
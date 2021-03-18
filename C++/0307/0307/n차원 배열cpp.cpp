#include <iostream>
using namespace std;

int main()
{
	//n차원 배열
	//2차원 배열


	int doubleArray[2][3] =
	{
		{1,2,3}, 
		{4,5,6}
	};

	int* ptr = doubleArray[0];

	cout << doubleArray[1][1] << endl;
	cout << *(*(doubleArray + 1) + 1) << endl; // doubleArray +1 을 해버리면 4바이트 단위이동이 아니라 double[0] -> double[1]로 이동한다.
	cout << *(doubleArray[1] + 1) << endl; 
	// 이차원 배열은 1차원 배열이 각 원소로 또 다른 1차원 배열을 가지고 있기에 역참조 연산자로 들어가면 해당 1차원 배열을 가져온다.
	// 해당 1차원 배열이 나오고 배열[]이 아닌 그냥 배열은 해당 배열의 첫 원소 주소를 반환한다.
	// 따라서 해당 주소 +1을 하고 * 역참조를 하면 1차원 배열 안에 1차원 배열의 특정 인덱스의 값이 반환된다.
	cout << (*(doubleArray+1))[1] << endl;
	cout << *(ptr+4) << endl;
	//cout << doubleArray[size(doubleArray)][size(doubleArray[][])] << endl;

	//2차원 배열 포인터 형식. 2차원 배열은 더블 포인터가 아니라 또 다른 포인터 형식을 가진다.
	//이 때 열의 크기는 항상 일치해야 한다.
	int(*pArr)[3] = doubleArray;

	cout << pArr[1][1] << endl;
}

void show(int arr2D[][3]) //이런 식으로 매개 변수로 받아 올 수 있는데 반드시 열의 개수는 명시해줘야 한다.
{

}
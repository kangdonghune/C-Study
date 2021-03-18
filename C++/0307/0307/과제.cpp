#include <iostream>
#include <time.h>
#include <array>

using namespace std;

void BubbleSort(int* ptrArray, int size);
void Divide(int* ptrArr, int start, int size);
void InputArray(int * receiveArr, int* giveArr, int gsize);
void Merge(int* ptrArr, int start, int size);
void MergeSort(int* ptrArray, int start, int size);
void PlayLotto(int* ptrArray, int size);
void PrintArray(int* ptrArray, int size);
void Print2DArray(int(*ptr)[3], int size = 3);
void Swap(int* a, int* b);
void TurnArray(int(*ptr)[3], int size = 3);



int main()
{
	//���� 1.
	//1���� �迭�� ��ġ 2���� �迭ó�� �ٷ��. 25��¥�� 1���� �迭�� �����Ͽ� ������ ���� ����ϱ�
	//��, if�� ��� ����
	//1		2	3	4	5
	//6		7	8	9	10
	//11	12	13	14	15
	//16	17	18	19	20
	//21	22	23	24	25

	/*const int iArrSize = 25;
	int iArray[iArrSize];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
		iArray[5*i + j] = 5 * i + j;
		cout << iArray[5*i+j] << " ";
		}
	cout << "" << endl;
	}*/
	
	/*2���� �迭�� �̿��Ͽ� 90�� �ð�������� 4ȸ�� �ϱ� �� ��������̾�� �Ѵ�
	1	2	3			7	4	1
	4	5	6   ->		8	5	2  ->...
	7	8	9			9	6	3*/

	//int iArray2D[3][3] =
	//{
	//	{ 1,2,3 },
	//	{ 4,5,6 },
	//	{ 7,8,9 }
	//};

	//Print2DArray(iArray2D);
	//TurnArray(iArray2D);
	//Print2DArray(iArray2D);
	//TurnArray(iArray2D);
	//Print2DArray(iArray2D);
	//TurnArray(iArray2D);
	//Print2DArray(iArray2D);
	//TurnArray(iArray2D);
	//Print2DArray(iArray2D);


	// 1���� 1�� 2���� 2�� 3���� 3������ ������ ����.
	// �Ǵ� 1���� 3���� 2���� 2���� 3���� 1����
	// �̰� �ݺ�


	/*3. �ζ� �����ϱ�
	1~45�� ���ڸ� �������� 6�� 5ȸ�� �����Ͽ� ����ϱ� �� ȸ���� �ߺ���ȣ ����� �ϸ� ������������ ����
	�Ǿ�� �Ѵ�.
	1	5	13	22	41	45
	1	3	9	21	31	33
	������ ���� ���� ����� ��.
	*/
	//1.���� ����
	//2.�ߺ� ���� �˻�
	//3. ����

	srand(unsigned(time(NULL)));
	const int iLottosize = 5;
	//int iRand = (rand() % 45) + 1;// 1~45 ���� ���� ����.
	int *LottoNum= new int[iLottosize]; // �ζ� ��ȣ�� �� �迭. 
	int LottoSize = iLottosize;
	for (int i = 1; i < 6; i++)
	{
		cout << i << "ȸ��: ";
		PlayLotto(LottoNum, LottoSize);
		//MergeSort(LottoNum, 0, LottoSize);
		//PrintArray(LottoNum, LottoSize);
	}
		
}

void PlayLotto(int* ptrArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = (rand() % 45) + 1; //�ζ� ��ȣ �ϳ� �� ����
		for (int j = 0; j < i;)
		{
			if (ptrArray[i] == ptrArray[j])
			{
				ptrArray[i] = (rand() % 45) + 1;
				//���� �������� ������ �迭 ���ҵ� �� ���� ���� �����Ͽ� ���� �Ͱ� ���� �� ������ ����� �� ����ġ �ʱ�ȭ �� ��˻�.
				j = 0; //�ʱ�ȭ �� �� �� �������� ���ߴ� �� �߿� �ߺ��� ������ ������ �����.
				continue;
				//�� ������� 1~45���� �ִ� �迭 �ϳ��� �غ��ϰ� �ݺ����� ���� �������� ���� ���� �������ָ� �ߺ����ε� ������ ���� �������� ������ �� �ִ�.
			}
			j++;
		}
	}

	BubbleSort(ptrArray, size);
	//MergeSort(ptrArray, 0, size);
	PrintArray(ptrArray, size);
}

//MergeSort �պ� ����
//1. ��� ���Ҹ� ���� ���� ������ ���� �ش�. 2����, 1���� ������ �� ���α�.
//2. 2������ ���� �Ϳ��� ũ�� �񱳸� �ؼ� ������ ���ش�,
//3. 2�� ���� ���� �񱳸� �ϸ� ���� �� ���� �� ���� ���� �� �ؼ� ������ ������ ũ�� ��� ������ ������ �� �� ������ �ϰ� �� ��� �������� �״�� �ڿ� �̾ �ִ´�.
//
//
void InputArray(int * receiveArr,int* giveArr, int gsize)
{
	for (int i = 0; i < gsize; i++)
		receiveArr[i] = giveArr[i];
}

void MergeSort(int* ptrArray, int start, int size) //size = �迭 ũ��. 
{
	
	if (size <= 1) return; // �迭 ũ�Ⱑ 1���� ������ ���ĵ� ������ ����.
	Divide(ptrArray, start, size);// ������ ������ �� ���� �ϰ�,
	Merge(ptrArray, start, size);// �� �̻� ���� �ʿ䰡 �������� ��ġ�鼭 ����.
}

void Divide(int* ptrArr, int start, int size)
{
	MergeSort(ptrArr, 0, size / 2);
	MergeSort(ptrArr, (size / 2) + 1, size);
}

void Merge(int* ptrArr,int start, int size)
{
	int* LockerArr = new int[size];
	int count = 0;
	for (int i = start, j = (size/2); count < size;)  //�׷� �� ���� ���ϸ� �ϳ� �� ���� �迭�� �־��ش�. �� �� �׷��� �� ��� ���̻� �񱳸� ���� �ʰ� ���� �׷��� �״�� �־��ش�,
	{
		if(i >= size/2)
			LockerArr[count++] = ptrArr[j++];
		if(j > size)
			LockerArr[count++] = ptrArr[i++];
		if (ptrArr[i] > ptrArr[j])
			LockerArr[count++] = ptrArr[j++];
		if (ptrArr[i] < ptrArr[j])
			LockerArr[count++] = ptrArr[i++];
	}
	InputArray(ptrArr, LockerArr, size);
}

void BubbleSort(int* ptrArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ptrArray[i] > ptrArray[j])
				Swap(&ptrArray[i], &ptrArray[j]);
		}
	}

}

void PrintArray(int* ptrArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ptrArray[i] << " ";
	}
	cout << "" << endl;
}

void Print2DArray(int(*ptr)[3], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << (*(ptr + i))[j];
		}
		cout << "" << endl;
	}
	cout << "" << endl;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void TurnArray(int(*ptr)[3], int size)
{
	int temp[3][3];

	//cout << (*(ptr+1))[i] << endl; // (*(ptr+j))[i] �� j��° ��. 0���� 2���� 1���� 1�� 3���� 0����. 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//cout << (*(ptr + (2 - j)))[i];  //1���� 3���� 2���� 2���� 3���� 1����
			temp[i][j] = (*(ptr + (2-j)))[i]; 
			//������ ���� ���� ����ִ� �������� �ǽð����� ���� �ٲ�ٺ��� ��� ���� ������ �ǳ�?
			//�ذ�å 1. ������ �迭�� ���� �� �ش� �迭�� ���� ���� �־��ش�.
			//2. ���� �� �� �迭�� �� �־������� �� �迭�� �ٽ� ptr�� �־��ش�
			//3. �ٵ� �̰� �ù� ������ ������ �̰� �³�? �� ���� ��� ����?
			
		}
 	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Swap(&(*(ptr + i))[j], &temp[i][j]);
		}
	}
}





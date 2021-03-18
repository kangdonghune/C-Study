#include <iostream>
#include <time.h>
#include <array>

using namespace std;

void BubbleSort(int* ptrArray, int size);
void Merge(int* ptrArr, int left, int mid, int right);
void MergeSort(int* ptrArray, int left, int right);
void PlayLotto(int* ptrArray, int size);
void PrintArray(int* ptrArray, int size);
void Print2DArray(int(*ptr)[3], int size = 3);
void Swap(int* a, int* b);
void TurnArray(int(*ptr)[3], int size = 3);

const int iLottosize = 20;

int main()
{
	srand(unsigned(time(NULL)));
	
	//int iRand = (rand() % 45) + 1;// 1~45 ���� ���� ����.
	int LottoNum[iLottosize]; // �ζ� ��ȣ�� �� �迭. 
	int LottoSize = iLottosize;
	for (int i = 1; i < 6; i++)
	{
		cout << i << "ȸ��: ";
		
		for (int i = 0; i < iLottosize; i++)
		{
			LottoNum[i] = (rand() % 45) + 1; //�ζ� ��ȣ �ϳ� �� ����
			for (int j = 0; j < i;)
			{
				if (LottoNum[i] == LottoNum[j])
				{
					LottoNum[i] = (rand() % 45) + 1;
					//���� �������� ������ �迭 ���ҵ� �� ���� ���� �����Ͽ� ���� �Ͱ� ���� �� ������ ����� �� ����ġ �ʱ�ȭ �� ��˻�.
					j = 0; //�ʱ�ȭ �� �� �� �������� ���ߴ� �� �߿� �ߺ��� ������ ������ �����.
					continue;
					//�� ������� 1~45���� �ִ� �迭 �ϳ��� �غ��ϰ� �ݺ����� ���� �������� ���� ���� �������ָ� �ߺ����ε� ������ ���� �������� ������ �� �ִ�.
				}
				j++;
			}
		}
		MergeSort(LottoNum, 0, iLottosize-1); //�ش� �Լ��� ��� �ε����� ���ؼ� ������ �ϴ� size-1�� ����� ���� �÷ο찡 �� ����.
		PrintArray(LottoNum, iLottosize); 
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

	//BubbleSort(ptrArray, size);
	MergeSort(ptrArray, 0, size);
	PrintArray(ptrArray, size);
}

//MergeSort �պ� ����
//1. ��� ���Ҹ� ���� ���� ������ ���� �ش�. 2����, 1���� ������ �� ���α�.
//2. 2������ ���� �Ϳ��� ũ�� �񱳸� �ؼ� ������ ���ش�,
//3. 2�� ���� ���� �񱳸� �ϸ� ���� �� ���� �� ���� ���� �� �ؼ� ������ ������ ũ�� ��� ������ ������ �� �� ������ �ϰ� �� ��� �������� �״�� �ڿ� �̾ �ִ´�.
//
//
void InputArray(int * receiveArr, int* giveArr, int gsize)
{
	for (int i = 0; i < gsize; i++)
		receiveArr[i] = giveArr[i];
}

void MergeSort(int* ptrArray, int left, int right) //size = �迭 ũ��.  left = �迭 ����, right = �迭 ������ �ε���
{
	int mid;

	if (left < right) //�迭�� ũ�Ⱑ 2�� �̻��� ��
	{
		mid = (left + right) / 2;
		MergeSort(ptrArray, left, mid); //���� ���� ����
		MergeSort(ptrArray, mid+1, right);//�Ĺ� ���� ����
		Merge(ptrArray, left, mid, right);//���Ĺ� �� �� ����
	}
	// ũ�Ⱑ 1 ���ϸ� �ƹ��͵� ���� �ʰ� ������.
}

void Merge(int* ptrArr, int left, int mid, int right)
{
	int Sorted[iLottosize]{};

	int i, j, k, m;
	i = left;
	j = mid + 1;
	k = left;

	while (i<= mid && j <= right)// ���� �׷쵵 ���� �� �� ���°� �����ʵ� �� �� ��������
	{
		if (ptrArr[i] <= ptrArr[j])
			Sorted[k++] = ptrArr[i++];
		if (ptrArr[i] > ptrArr[j])
			Sorted[k++] = ptrArr[j++];
	}
	if (i > mid) // ���� �׷��� �� �����ȴٸ�.������� ������ �׷� �־������.
	{
		for (int l = j; l <= right; l++)
			Sorted[k++] = ptrArr[l];
	}
	else //������ �׷��� �ٻ� ��� ���� �׷��� ������� �־����.
	{
		for (int l = i; l <= mid; l++)
			Sorted[k++] = ptrArr[l];
	}

	for (int l = left; l <= right; l++)
	{
		ptrArr[l] = Sorted[l];
	}
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

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
	
	//int iRand = (rand() % 45) + 1;// 1~45 사이 난수 생성.
	int LottoNum[iLottosize]; // 로또 번호가 들어갈 배열. 
	int LottoSize = iLottosize;
	for (int i = 1; i < 6; i++)
	{
		cout << i << "회차: ";
		
		for (int i = 0; i < iLottosize; i++)
		{
			LottoNum[i] = (rand() % 45) + 1; //로또 번호 하나 씩 생성
			for (int j = 0; j < i;)
			{
				if (LottoNum[i] == LottoNum[j])
				{
					LottoNum[i] = (rand() % 45) + 1;
					//만약 이제까지 생성한 배열 원소들 중 지금 새로 생성하여 넣은 것과 같은 게 있으면 재생성 후 비교위치 초기화 후 재검사.
					j = 0; //초기화 안 할 시 이전까지 비교했던 것 중에 중복이 있으면 문제가 생긴다.
					continue;
					//이 방법보다 1~45까지 있는 배열 하나를 준비하고 반복문을 통해 랜덤으로 내부 값을 스왚해주면 중복여부도 문제가 없고 난수성도 보장할 수 있다.
				}
				j++;
			}
		}
		MergeSort(LottoNum, 0, iLottosize-1); //해당 함수의 경우 인덱스를 통해서 정렬을 하니 size-1을 해줘야 오버 플로우가 안 난다.
		PrintArray(LottoNum, iLottosize); 
	}

}

void PlayLotto(int* ptrArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		ptrArray[i] = (rand() % 45) + 1; //로또 번호 하나 씩 생성
		for (int j = 0; j < i;)
		{
			if (ptrArray[i] == ptrArray[j])
			{
				ptrArray[i] = (rand() % 45) + 1;
				//만약 이제까지 생성한 배열 원소들 중 지금 새로 생성하여 넣은 것과 같은 게 있으면 재생성 후 비교위치 초기화 후 재검사.
				j = 0; //초기화 안 할 시 이전까지 비교했던 것 중에 중복이 있으면 문제가 생긴다.
				continue;
				//이 방법보다 1~45까지 있는 배열 하나를 준비하고 반복문을 통해 랜덤으로 내부 값을 스왚해주면 중복여부도 문제가 없고 난수성도 보장할 수 있다.
			}
			j++;
		}
	}

	//BubbleSort(ptrArray, size);
	MergeSort(ptrArray, 0, size);
	PrintArray(ptrArray, size);
}

//MergeSort 합병 정렬
//1. 모든 원소를 가장 작은 단위로 묶어 준다. 2개씩, 1개만 남으면 걍 나두기.
//2. 2개끼리 묶인 것에서 크기 비교를 해서 정렬을 해준다,
//3. 2개 묶음 끼리 비교를 하며 묶음 중 제일 앞 원소 끼리 비교 해서 작으면 앞으로 크면 대기 한쪽의 묶음이 다 빌 때까지 하고 다 비면 나머지는 그대로 뒤에 이어서 넣는다.
//
//
void InputArray(int * receiveArr, int* giveArr, int gsize)
{
	for (int i = 0; i < gsize; i++)
		receiveArr[i] = giveArr[i];
}

void MergeSort(int* ptrArray, int left, int right) //size = 배열 크기.  left = 배열 시작, right = 배열 마지막 인덱스
{
	int mid;

	if (left < right) //배열의 크기가 2개 이상일 떄
	{
		mid = (left + right) / 2;
		MergeSort(ptrArray, left, mid); //전방 범위 정렬
		MergeSort(ptrArray, mid+1, right);//후방 범위 정렬
		Merge(ptrArray, left, mid, right);//전후방 비교 후 정렬
	}
	// 크기가 1 이하면 아무것도 하지 않고 끝낸다.
}

void Merge(int* ptrArr, int left, int mid, int right)
{
	int Sorted[iLottosize]{};

	int i, j, k, m;
	i = left;
	j = mid + 1;
	k = left;

	while (i<= mid && j <= right)// 왼쪽 그룹도 아직 다 안 꺼냈고 오른쪽도 다 안 꺼냈으면
	{
		if (ptrArr[i] <= ptrArr[j])
			Sorted[k++] = ptrArr[i++];
		if (ptrArr[i] > ptrArr[j])
			Sorted[k++] = ptrArr[j++];
	}
	if (i > mid) // 왼쪽 그룹을 다 빼버렸다면.순서대로 오른쪽 그룹 넣어버리기.
	{
		for (int l = j; l <= right; l++)
			Sorted[k++] = ptrArr[l];
	}
	else //오른쪽 그룹을 다뺀 경우 왼쪽 그룹을 순서대로 넣어줘라.
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

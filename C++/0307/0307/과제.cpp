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
	//숙제 1.
	//1차원 배열을 마치 2차원 배열처럼 다루기. 25개짜리 1차원 배열을 선언하여 다음과 같이 출력하기
	//단, if문 사용 금지
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
	
	/*2차원 배열을 이용하여 90도 시계방향으로 4회전 하기 단 정방행렬이어야 한다
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


	// 1열이 1행 2열이 2행 3열이 3행으로 역으로 들어간다.
	// 또는 1행이 3열로 2행이 2열로 3행이 1열로
	// 이게 반복


	/*3. 로또 구현하기
	1~45의 숫자를 무작위로 6개 5회차 추출하여 출력하기 각 회차당 중복번호 없어야 하며 오름차순으로 정렬
	되어야 한다.
	1	5	13	22	41	45
	1	3	9	21	31	33
	정렬은 버블 정렬 사용할 것.
	*/
	//1.난수 추출
	//2.중복 여부 검사
	//3. 정렬

	srand(unsigned(time(NULL)));
	const int iLottosize = 5;
	//int iRand = (rand() % 45) + 1;// 1~45 사이 난수 생성.
	int *LottoNum= new int[iLottosize]; // 로또 번호가 들어갈 배열. 
	int LottoSize = iLottosize;
	for (int i = 1; i < 6; i++)
	{
		cout << i << "회차: ";
		PlayLotto(LottoNum, LottoSize);
		//MergeSort(LottoNum, 0, LottoSize);
		//PrintArray(LottoNum, LottoSize);
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

	BubbleSort(ptrArray, size);
	//MergeSort(ptrArray, 0, size);
	PrintArray(ptrArray, size);
}

//MergeSort 합병 정렬
//1. 모든 원소를 가장 작은 단위로 묶어 준다. 2개씩, 1개만 남으면 걍 나두기.
//2. 2개끼리 묶인 것에서 크기 비교를 해서 정렬을 해준다,
//3. 2개 묶음 끼리 비교를 하며 묶음 중 제일 앞 원소 끼리 비교 해서 작으면 앞으로 크면 대기 한쪽의 묶음이 다 빌 때까지 하고 다 비면 나머지는 그대로 뒤에 이어서 넣는다.
//
//
void InputArray(int * receiveArr,int* giveArr, int gsize)
{
	for (int i = 0; i < gsize; i++)
		receiveArr[i] = giveArr[i];
}

void MergeSort(int* ptrArray, int start, int size) //size = 배열 크기. 
{
	
	if (size <= 1) return; // 배열 크기가 1보다 작으면 정렬된 것으로 본다.
	Divide(ptrArray, start, size);// 반으로 나누는 걸 먼저 하고,
	Merge(ptrArray, start, size);// 더 이상 나눌 필요가 없어지면 합치면서 정렬.
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
	for (int i = start, j = (size/2); count < size;)  //그룹 두 개를 비교하며 하나 씩 임의 배열에 넣어준다. 한 쪽 그룹이 다 비면 더이상 비교를 하지 않고 남은 그룹은 그대로 넣어준다,
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

	//cout << (*(ptr+1))[i] << endl; // (*(ptr+j))[i] 는 j번째 행. 0행은 2열로 1행은 1열 3행은 0열로. 
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			//cout << (*(ptr + (2 - j)))[i];  //1행이 3열로 2행이 2열로 3행이 1열로
			temp[i][j] = (*(ptr + (2-j)))[i]; 
			//참조라서 돌린 값을 집어넣는 과정에서 실시간으로 값이 바뀌다보니 결과 값이 엉망이 되네?
			//해결책 1. 별개의 배열을 만든 후 해당 배열에 돌린 값을 넣어준다.
			//2. 돌린 걸 새 배열에 다 넣어줬으면 그 배열을 다시 ptr에 넣어준다
			//3. 근데 이거 시바 개지랄 같은데 이거 맞냐? 더 나은 방법 없냐?
			
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





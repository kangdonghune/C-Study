#include <iostream>
using namespace std;

void main()
{
	//파일 입출력-데이터를 저장하고 불러오기 위해 사용. 
	//함수를 사용해 통로를 개방하고 폐쇄하고 해야한다.
	
	// 경로 관련 개념. 상대 경로와 절대 경로.
	// 절대 경로- 루트 파일로부터 위치 탐색. C:\Users\kangdonghune\Desktop\C++Study\C++\0318_메모리 관련 함수\text\text.txt .
	// 절대 경로는 사용자마다 파일 이름과 위치가 다르기 마련. 절대경로로하면 그런 점에서 문제가 생기기 마련.
	// 상대 경로- 특정 파일을 기준으로 위치 탐색..VC 프로젝트 기준 ..\text\text.txt ../은 기준파일 기준 부모 vc의 부모인 vc를 담고 있는 폴더로 간 후 그 안에 text폴더로 가고 거기서 안에 있는 text에 파일 경로를 연다.

	//파일 대상 통로를 열어주는 함수.
	//fopen_s(); //fopen. c스타일 파일 입출력. 반환값은 실패, 성공 여부. 0이면 성공, 그외 다른 수면 실패.
	//FILE 파일 지시자 파일 오가며 데이터 전달. 
	FILE* fp = nullptr;
	//파일이 없을 경우에는 파일을 새로 만들어주지만 폴더가 없을 경우 파일의 경로를 개방하지 못한다.
	/*
	데이터 읽기 쓰기에 따른 모드
	r  read  읽기 - 파일 없으면 통로 개방 실패
	w  write 새로 덮어쓰기 -파일 없으면 생성 후 통로 개방
	a 덧붙여쓰기. 이어 붙여 쓰기

	데이터 종류에 따른 모드
	t= text 모드 사람이 읽기 쉬운 텍스트 - 잘 사용이 되지 않는다. 보안문제로 잘 쓰이지 않는다. 느리기도 함.
	b- binary 모드 사람이 읽기 어렵고 컴퓨터가 읽기 쉬운 기계어로 저장이 되는 방식. 주로 바이너리 모드로 입출력한다. 사람이 읽기 힘들기 때문에
	*/
	/*typedef된 int*/errno_t err = fopen_s(&fp,"../text/Newtext.txt","rt"); //포인터 변수에 값을 직접적으로 넘겨주겠따. //wt write text모드
	char szBuff[256] = "";
	
	
	if (0 == err)
	{
		cout << "통로 오픈" << endl;
		//fputs("파일 입출력 테스트 중",fp);//내보낼거다. //stdout 은 모니터. 문자열을 저장할 때 널문자가 삽입되지 않는구나. 순수문자만 저장하는구나.
		fgets(szBuff, size(szBuff), fp);
		fputs(szBuff, stdout); //문자열의 끝은 \0로 파악하고 파일의 끝은 -1로, EOF로 판별. end of file
		fseek(fp,1, SEEK_SET);//파일 지시자를 내가 원하는 위치로 옮겨줄 수 있는 함수. 문자열을 읽어나가면서 파일지시자를 이동하는데 SEEK_SET로 처음위치 이동후 거기서 index만큼 이동.
		char ch = fgetc(fp); //gets 는 문자열 전체를 가져오는 반면 getc는 현재 파일지시자가 가리키는 위치의 글자 하나만 가져온다. 
		fputc(ch, stdout); 
		int i = ftell(fp); //현재 파일지시자 위치 반환.
		cout << i << endl;
		bool a = feof(fp); //파일지시자가 끝에 도달했는지 아닌지.
		cout << a << endl;
		fclose(fp);
		/*for (int i = 0; i < size(szBuff); i++)
		{
			cout << szBuff[i];
		}*/
	}
	//else {
	//	cout << "통로 개방 실패" << endl;
	//}

	errno_t err2 = fopen_s(&fp, "../text/newtext.txt", "rb"); //이건 물어보자 그냥.
	int iarr[5]{ 1,2,3,4,5 };
	int iarr1[5]{ };
	if (0 == err2)
	{
		fwrite(iarr, sizeof(int), size(iarr), fp);
		//fwrite(iarr, sizeof(iarr), 1, fp);
		fread(iarr1, sizeof(iarr1), 1, fp);
		for (int i = 0; i < size(iarr); i++)
		{
			cout << iarr[i] << endl;
		}
	}
	fclose(fp);

	////저장할 떄 포인터 값을 저장하는 것을 주의하자. 포인터 변수는 껏다킬 때마다 주소값이 변한다.


	//
}
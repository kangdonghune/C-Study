#include <iostream>

using namespace std;

int main()
{
	int iA;
	memset(&iA, 0, sizeof(int)); //�޸𸮸� �ʱ�ȭ�� �� �ַ� ���Ǵ� �Լ�. ���� �ι�° ���ڷ� �Ѱ��� value���� 1����Ʈ ������ ���� �ʱ�ȭ�Ѵ�.
	cout << iA << endl;
	//1����Ʈ ������ �ʱ�ȭ�Ǵٺ��� �ٷ�� ����� ��κ� 0�ʱ�ȭ�� �������� ���δ�.
	int iArr[5]{ 1,2,3,4,5 };
	int iArr2[5]{ 1,2,3,4,7 };
	int iPlayerArr[5]{};
	memcpy(iPlayerArr, iArr, sizeof(iArr));//���̳ʷ� �ڵ�� �ܼ� ����. �޸𸮴� �޸� ����. �Ϲ����� ���纸�ٴ� ������. ��ǥ��
	//�̰��� �ּҾȿ� ����ִ� ���̳ʸ� �ڵ� ��ü�� �ܼ� �ʱ�ȭ�̱� ������ ���������� �����͸� ������ �ִ� ��� �̷� ���� �ʱ�ȭ�� ������ �����.
	//string ���� ���. �ܼ� ������ ������ ������ ������ �����ѵ� ������ ������ �ʱ�ȭ�ؼ� ������ �ִ� ���� �ּҋ����� ������ �߻��ȴ�.
	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}

	memmove(iPlayerArr, iArr2, sizeof(iArr)); //�޸� �� �޸� ����� �Ȱ���. memcpy�� ���̷�Ʈ�� ����ִ� ���. 
	//memmove�� �ӽ÷� ���۸� ����� �����͸� �ű������ ���ۿ��� ������� �ű�. �ӵ��� �� ������. ǥ��
	
	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}
}
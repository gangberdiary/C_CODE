#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void print(int n)
{
	int i = 0;
	printf("����λ��\n");
	for (i = 30; i >= 0; i -= 2){
		if (n & (1 << i)){
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
	printf("\nż��λ��\n");
	for (i = 31; i > 0; i -= 2){
		if (n & (1 << i)){
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
}

int main()
{
	int n = 0;
	printf("������n��");
	scanf("%d", &n);
	print(n);//��ӡ���������������е�ż��λ������λ
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Print(int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//��ӡ�ո�
		int j;
		for (j = 0; j < n - 1 - i; j++)
		{
			printf(" ");
		}
		//��ӡ�Ǻ�
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//�°벿��
	for (i = 0; i< n - 1; i++)
	{
		//��ӡ�ո�
		int j;
		for (j = n - 1 - i; j < n; j++)
		{
			printf(" ");
		}
		//��ӡ�Ǻ�
		for (j = 0; j < 2 * (n - 2 - i) + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	printf("������n��ֵ��");
	scanf("%d", &n);
	Print(n);//��ӡ����
	system("pause");
	return 0;
}
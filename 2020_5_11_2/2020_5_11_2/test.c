#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Print(int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//打印空格
		int j;
		for (j = 0; j < n - 1 - i; j++)
		{
			printf(" ");
		}
		//打印星号
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//下半部分
	for (i = 0; i< n - 1; i++)
	{
		//打印空格
		int j;
		for (j = n - 1 - i; j < n; j++)
		{
			printf(" ");
		}
		//打印星号
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
	printf("请输入n的值：");
	scanf("%d", &n);
	Print(n);//打印菱形
	system("pause");
	return 0;
}
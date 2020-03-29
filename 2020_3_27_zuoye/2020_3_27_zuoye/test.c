#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Cmp_Max()
{
	int a, b;
	printf("请输入要比较的两个数：>");
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("较大值为%d\n", a);
	else
		printf("较大值为%d\n", b);
}

int main()
{
	Cmp_Max();//比较两个数字，并输出较大值
	system("pause");
	return 0;
}
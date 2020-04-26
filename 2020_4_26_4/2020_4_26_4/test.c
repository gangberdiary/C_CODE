#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Swap(int *m, int *n)
{
	*m = *m ^ *n;
	*n = *n ^ *m;
	*m = *m ^ *n;
}

int main()
{
	int m = 0;
	int n = 0;
	printf("请输入(m,n)：");
	scanf("%d,%d", &m, &n);
	printf("交换前：%d %d\n", m, n);
	Swap(&m, &n);//不创建临时变量交换m和n的值
	printf("交换后：%d %d\n", m, n);
	system("pause");
	return 0;
}
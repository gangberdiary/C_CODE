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
	printf("������(m,n)��");
	scanf("%d,%d", &m, &n);
	printf("����ǰ��%d %d\n", m, n);
	Swap(&m, &n);//��������ʱ��������m��n��ֵ
	printf("������%d %d\n", m, n);
	system("pause");
	return 0;
}
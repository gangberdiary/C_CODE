#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Cmp_Max()
{
	int a, b;
	printf("������Ҫ�Ƚϵ���������>");
	scanf("%d %d", &a, &b);
	if (a > b)
		printf("�ϴ�ֵΪ%d\n", a);
	else
		printf("�ϴ�ֵΪ%d\n", b);
}

int main()
{
	Cmp_Max();//�Ƚ��������֣�������ϴ�ֵ
	system("pause");
	return 0;
}
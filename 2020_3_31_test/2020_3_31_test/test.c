#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Swap(int* n1, int* n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void Sort()
{
	int num1, num2, num3;
	printf("请输入3个数：>");
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 < num2){
		Swap(&num1, &num2);
	}
	if (num2 < num3){
		Swap(&num2, &num3);
	}
	if (num1 < num2){
		Swap(&num1, &num2);
	}
	printf("从大到小输出为：%d %d %d\n", num1, num2, num3);
}

int main()
{
	Sort();
	return 0;
	system("pause");
}
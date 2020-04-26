#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void print(int n)
{
	int i = 0;
	printf("奇数位：\n");
	for (i = 30; i >= 0; i -= 2){
		if (n & (1 << i)){
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
	printf("\n偶数位：\n");
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
	printf("请输入n：");
	scanf("%d", &n);
	print(n);//打印该数二进制中所有的偶数位和奇数位
	system("pause");
	return 0;
}
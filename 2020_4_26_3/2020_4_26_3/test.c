#include <stdio.h>
#include <windows.h>


#pragma warning(disable:4996)


int Count(int n)
{
	int count = 0;
	while (n){
		count++;
		n &= (n - 1);
	}
	return count;
}


int main()
{
	int n = 0;
	int ret = 0;
	printf("请输入n：");
	scanf("%d", &n);
	ret = Count(n);//计算1的个数
	printf("%d有%d个1\n", n, ret);
	system("pause");
	return 0;
}
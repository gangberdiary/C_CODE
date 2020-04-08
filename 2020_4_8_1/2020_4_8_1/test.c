#include <stdio.h>
#include <windows.h>

//计算数字中有多少个9
int Count_nine(int num)
{
	int count1 = 0;
	while (num != 0){
		if (9 == num % 10){
			count1++;
		}
		num /= 10;
	}
	return count1;
}

int main()
{
	int i = 0;
	int count = 0;//存放9的个数
	for (i = 1; i <= 100; i++){
		count += Count_nine(i);
	}
	printf("1到100中出现了%d个9.\n", count);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>

int main()
{
	int num = 0;//汽水的总数
	int empty = 0;//空瓶的数量
	int count = 0;//换取的汽水数
	int money = 20;//钱的总额
	num = 20 / 1;//汽水1元1瓶
	empty = num;
	while(empty > 1){
		count = empty / 2;
		num += count;
		empty = (empty % 2) + count;
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}
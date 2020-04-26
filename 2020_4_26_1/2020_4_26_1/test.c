#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Count(int ret)
{
	int count = 0;
	while (ret){
		count++;
		ret &= (ret - 1);
	}
	return count;
}

int Dif(int m, int n)
{
	return m ^ n;
}

int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("请输入(m,n)：");
	scanf("%d,%d", &m, &n);
	ret = Dif(m, n);//将m和n二进制中不同的比特位变成1
	ret = Count(ret);//计算1的个数
	printf("%d和%d有%d个比特位不同\n", m, n, ret);
	system("pause");
	return 0;
}
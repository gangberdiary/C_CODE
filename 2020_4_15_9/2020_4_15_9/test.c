#include <stdio.h>

#pragma warning(disable:4996)

int Sum(int num)
{
	int sum = 0;
	while (num > 0){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main()
{
	int num = 0;
	int ret = 0;
	printf("ÇëÊäÈë£º>");
	scanf("%d", &num);
	ret = Sum(num);
	printf("%d", ret);
	system("pause");
	return 0;
}
#include "test.h"

int main()
{
	int num1, num2;
	printf("��ֱ�������������>");
	scanf("%d %d", &num1, &num2);
	printf("before:%2d %2d\n", num1, num2);
	Swap(&num1, &num2);
	printf("after :%2d %2d\n", num1, num2);
	system("pause");
	return 0;
}
#include "test.h"

int main()
{
	int num = 0;
	int ret = 0;
	printf("�����룺>");
	scanf("%d", &num);
	ret = Fact(num);
	printf("%d! = %d\n", num, ret);
	system("pause");
	return 0;
}
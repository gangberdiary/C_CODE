#include "test.h"

int main()
{
	int num = 100;
	printf("打印100~200之间的素数\n");
	while (num++ <= 200){
		if (Is_prime(num)){
			printf("%d ", num);
		}
	}
	system("pause");
	return 0;
}
#include "test.h"

int main()
{
	int num = 100;
	printf("��ӡ100~200֮�������\n");
	while (num++ <= 200){
		if (Is_prime(num)){
			printf("%d ", num);
		}
	}
	system("pause");
	return 0;
}
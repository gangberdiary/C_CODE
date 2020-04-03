#include <stdio.h>
#include <windows.h>

int Is_prime(int _i)
{
	int num = 2;
	for (; num < (_i / 2); num++){
		if (_i % num == 0){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 100; i <= 200; i++){
		if (Is_prime(i)){
			count++;
			printf("%d ", i);
			if (count % 10 == 0){
				printf("\n");
			}
		}
	}
	system("pause");
	return 0;
}
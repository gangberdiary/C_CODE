#include "test.h"

void Print(int k)
{
	int i = 1;
	int j;
	for (; i <= k; i++){
		for (j = i; j <= k; j++){
			printf("%2d*%2d=%3d ", i, j, i*j);
		}
		printf("\n");
	}
}
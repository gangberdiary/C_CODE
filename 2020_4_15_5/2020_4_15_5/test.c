#include "test.h"

void Print(int num)
{
	if (num > 9){
		Print(num / 10);
	}
	printf("%d ", num % 10);
}
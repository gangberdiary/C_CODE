#include "test.h"

int Fact(int num)
{
	if (num == 1){
		return 1;
	}
	else{
		return num * Fact(num - 1);
	}
}
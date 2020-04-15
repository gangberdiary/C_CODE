#include "test.h"

Is_prime(int num)
{
	int i = 2;
	for (; i < (num / 2); i++){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}
#include "test.h"

int Mystrlen(const char *s)
{
	int count = 0;
	while ((*s++) != '\0'){
		count++;
	}
	return count;
}
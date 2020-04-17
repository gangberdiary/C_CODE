#include "test.h"

void reverse_string(char * string)
{
	if (*string != '\0'){
		reverse_string(string + 1);
	}
	printf("%c",*string);
}
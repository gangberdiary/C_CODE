#include <stdio.h>
#include <windows.h>
#include <assert.h>

char* my_strcpy(char *str, const char *arr)
{
	char *ret = str;
	assert(str && arr);
	while (*str++ = *arr++){
		;
	}
	return ret;
}

int main()
{
	char arr[] = "hello word";
	char str[20] = { 0 };
	my_strcpy(str, arr);
	printf("%s\n", str);
	system("pause");
	return 0;
}
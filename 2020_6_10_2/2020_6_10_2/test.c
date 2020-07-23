#include <stdio.h>
#include <windows.h>

int my_strcmp(const char *arr, const char * str)
{
	while(*arr == *str){
		if (*arr == '\0'){
			return 0;
		}
		arr++;
		str++;
	}
	return *arr - *str;
}

int main()
{
	char arr[] = "abcde";
	char str[] = "abcdef";
	int ret = my_strcmp(arr, str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
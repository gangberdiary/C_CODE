#include <stdio.h>
#include <windows.h>

void My_strcpy(char *p, const char *str)
{
	char *pt = p;
	if (p == NULL && str == NULL){
		return;
	}
	while (*pt++ = *str++)
	{
		;
	}
}

int main()
{
	char *str = "hello world";
	char p[20] = { 0 };
	My_strcpy(p, str);
	printf("%s\n", p);
	system("pause");
	return 0;
}
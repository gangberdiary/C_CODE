#include <stdio.h>
#include <windows.h>

int My_strlen(const char *str)
{
	char *p = str;
	while (*p++){//让p指向 '\0'
	}
	return p - str - 1;
}

int main()
{
	char *str = "hellow world";
	int num = My_strlen(str);//定义自己的strlen函数
	printf("%d\n", num);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>

int My_strlen(const char *str)
{
	char *p = str;
	while (*p++){//��pָ�� '\0'
	}
	return p - str - 1;
}

int main()
{
	char *str = "hellow world";
	int num = My_strlen(str);//�����Լ���strlen����
	printf("%d\n", num);
	system("pause");
	return 0;
}
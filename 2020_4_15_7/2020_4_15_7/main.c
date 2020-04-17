#include "test.h"

int main()
{
	char s[10];
	int ret = 0;
	printf("ÇëÊäÈë:");
	scanf("%s", s);
	ret = Mystrlen(s);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>

void Table()
{
	int i = 1;
	int j = 0;
	for (; i < 10; i++){
		for (j = i; j < 10; j++){
			printf("%d * %d = %-2d  ", i, j, i*j);
		}
		printf("\n");
	}
}

int main()
{
	printf("打印乘法口诀表\n");
	Table();
	system("pause");
	return 0;
}
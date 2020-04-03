#include <stdio.h>
#include <windows.h>

int main()
{
	int i = 1000;
	int count = 0;

	printf("1000年~2000年之间的闰年：\n");
	for (; i <= 2000; i++){
		if ((0 == i % 4 && 0 != i % 100) || (0 == i % 100 && 0 == i % 400)){
			count++;
			printf("%d ", i);
			if (count % 10 == 0){
				printf("\n");
			}
		}
	}

	system("pause");
	return 0;
}
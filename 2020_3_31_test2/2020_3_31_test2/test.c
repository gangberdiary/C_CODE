#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int main()
{
	int num = 1;
	int count = 0;
	printf("Êä³ö3µÄ±¶Êý£º\n");
	while (num++ <= 100){
		if (num % 3 == 0){
			printf("%3d ", num);
			count++;
		}
		if (count % 10 == 0){
			printf("\n");
		}
	}
	printf("\n");
	system("pause");
	return 0;
}
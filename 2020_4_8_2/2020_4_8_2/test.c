#include <stdio.h>
#include <windows.h>

int main()
{
    double denominator = 0;//��ĸ
	double sum = 0;
	int flag = 1;
	for (denominator = 1; denominator <= 100; denominator++){
		sum += 1.0 / denominator;
		flag *= -1;
	}
	printf("���Ϊ��%f", sum);
	system("pause");
	return 0;
}
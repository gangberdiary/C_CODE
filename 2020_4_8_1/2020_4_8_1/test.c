#include <stdio.h>
#include <windows.h>

//�����������ж��ٸ�9
int Count_nine(int num)
{
	int count1 = 0;
	while (num != 0){
		if (9 == num % 10){
			count1++;
		}
		num /= 10;
	}
	return count1;
}

int main()
{
	int i = 0;
	int count = 0;//���9�ĸ���
	for (i = 1; i <= 100; i++){
		count += Count_nine(i);
	}
	printf("1��100�г�����%d��9.\n", count);
	system("pause");
	return 0;
}
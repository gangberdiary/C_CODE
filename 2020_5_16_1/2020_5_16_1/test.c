#include <stdio.h>
#include <windows.h>

int main()
{
	int num = 0;//��ˮ������
	int empty = 0;//��ƿ������
	int count = 0;//��ȡ����ˮ��
	int money = 20;//Ǯ���ܶ�
	num = 20 / 1;//��ˮ1Ԫ1ƿ
	empty = num;
	while(empty > 1){
		count = empty / 2;
		num += count;
		empty = (empty % 2) + count;
	}
	printf("%d\n", num);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

void game()
{
	int num = 0;//���ɵ������
	int input = 0;//���������
	srand((unsigned int)time(NULL));
	num = rand() % 100 + 1;//1~100
	while (1){
		printf("����1~100��ѡһ������>");
		scanf("%d", &input);
		if (input > num){
			printf("�´���\n");
		}
		else if (input < num){
			printf("��С��\n");
		}
		else{
			printf("��ϲ��¶��ˣ�\n");
			return;
		}
	}
}

void menu()
{
	printf("#####################\n");
	printf("#####  1.������ #####\n");
	printf("#####  2.�˳�   #####\n");
	printf("#####################\n");
}

void Guess_num()
{
	int input = 0;
	menu();
	printf("��ѡ��>");
	scanf("%d", &input);
	do{
		switch (input){
		case 1:
			game();
			menu();
			printf("����һ�֣�\n");
			scanf("%d", &input);
			break;
		case 2:
			input = 0;
			printf("��Ϸ������\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	}while (0 != input);
}

int main()
{
	Guess_num();
	system("pause");
	return 0;
}
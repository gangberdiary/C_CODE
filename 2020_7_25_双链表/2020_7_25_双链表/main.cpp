#include "dclist.h"

int main()
{
	int input = 0;

	ListNode* list = ListCreate();

	ListNode* tmp = NULL;

	do{
		printf("*****************************************\n");
		printf("    1.push_back           2.pop_back     \n");
		printf("    3.push_front          4.pop_front    \n");
		printf("    5.show                6.find_val     \n");
		printf("    7.insert_pos          8.erase_pos    \n");
		printf("    9.destory             0.exit         \n");
		printf("*****************************************\n");
		int select = 0;
		printf("��ѡ��>");
		scanf("%d", &select);
		switch (select){
		case 0:
			printf("�˳���\n");
			return 0;
		case 1:
			printf("���������ݣ���-1��������>");
			while (scanf("%d", &input) && input != -1){
				ListPushBack(list, input);
			}
			printf("β��ɹ���\n");
			break;
		case 2:
			ListPopBack(list);
			printf("ɾ���ɹ���\n");
			break;
		case 3:
			printf("���������ݣ���-1��������>");
			while (scanf("%d", &input) && input != -1){
				ListPushFront(list, input);
			}
			printf("ͷ��ɹ���\n");
			break;
		case 4:
			ListPopFront(list);
			printf("ɾ���ɹ���\n");
			break;
		case 5:
			ListPrint(list);
			break;
		case 6:
			printf("������Ҫ���ҵ�ֵ��>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			if (tmp){
				printf("���ڣ�\n");
			}
			else{
				printf("������!\n");
			}
			break;
		case 7:
			printf("���뵽�ĸ���֮ǰ��>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			printf("������Ҫ�����ֵ��>");
			scanf("%d", &input);
			ListInsert(tmp, input);
			printf("����ɹ���\n");
			break;
		case 8:
			printf("������Ҫɾ����ֵ��>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			ListErase(tmp);
			printf("ɾ���ɹ���\n");
			break;
		case 9:
			ListDestory(list);
			printf("�ݻٳɹ���\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
		system("pause");
		system("cls");
	} while (1);

	system("pause");
	return 0;
}
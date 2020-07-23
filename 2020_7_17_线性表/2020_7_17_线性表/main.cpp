#include "seqList.h"

int main()
{
	int input = 1;//����
	int select = 1;//ѡ��
	
	SeqList List;//����˳���

	SeqListInit(&List);//˳����ʼ��

	int value = 0;//ֵ
	int pos = 0;//λ��

	do{
		printf("*********************************************\n");
		printf("*  [1] push_back           [2] push_front   *\n");
		printf("*  [3] show_list           [4] find_pos     *\n");
		printf("*  [5] pop_back            [6] pop_front    *\n");
		printf("*  [7] insert_pos          [8] pop_pos   *\n");
		printf("*  [9] destory             [0]exit          *\n");
		printf("*********************************************\n");
		printf("��ѡ��:>");
		scanf("%d", &select);
		switch (select){
		case 0:
			return 0;
		case 1:
			printf("����������(��-1Ϊ������־):>");
			while (scanf("%d", &input) && input != -1){
				SeqListPushBack(&List, input);
			}
			printf("β�巨����ɹ���\n");
			break;
		case 2:
			printf("����������(��-1Ϊ������־):>");
			while (scanf("%d", &input) && input != -1){
				SeqListPushFront(&List, input);
			}
			printf("ͷ�巨����ɹ���\n");
			break;
		case 3:
			SeqListPrint(&List);
			break;
		case 4:
			printf("������Ҫ���ҵ�ֵ��>");
			scanf("%d", &value);
			printf("�±�Ϊ��%d", SeqListFind(&List, pos));
			break;
		case 5:
			SeqListPopBack(&List);
			break;
		case 6:
			SeqListPopFront(&List);
			break;
		case 7:
			printf("������Ҫ�����ֵ��>");
			scanf("%d", &value);
			printf("������Ҫ�����λ�ã�>");
			scanf("%d", &pos);
			SeqListInsert(&List, pos, value);
			break;
		case 8:
			printf("������Ҫɾ����λ�ã�>");
			scanf("%d", &pos);
			SeqListErase(&List, pos);
			break;
		case 9:
			SeqListDestory(&List);
			break;
		default:
			printf("����������������룡\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);

	system("pause");
	return 0;
}
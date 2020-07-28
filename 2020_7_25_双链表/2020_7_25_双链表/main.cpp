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
		printf("请选择：>");
		scanf("%d", &select);
		switch (select){
		case 0:
			printf("退出！\n");
			return 0;
		case 1:
			printf("请输入数据（以-1结束）：>");
			while (scanf("%d", &input) && input != -1){
				ListPushBack(list, input);
			}
			printf("尾插成功！\n");
			break;
		case 2:
			ListPopBack(list);
			printf("删除成功！\n");
			break;
		case 3:
			printf("请输入数据（以-1结束）：>");
			while (scanf("%d", &input) && input != -1){
				ListPushFront(list, input);
			}
			printf("头插成功！\n");
			break;
		case 4:
			ListPopFront(list);
			printf("删除成功！\n");
			break;
		case 5:
			ListPrint(list);
			break;
		case 6:
			printf("请输入要查找的值：>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			if (tmp){
				printf("存在！\n");
			}
			else{
				printf("不存在!\n");
			}
			break;
		case 7:
			printf("插入到哪个数之前：>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			printf("请输入要插入的值：>");
			scanf("%d", &input);
			ListInsert(tmp, input);
			printf("插入成功！\n");
			break;
		case 8:
			printf("请输入要删除的值：>");
			scanf("%d", &input);
			tmp = ListFind(list, input);
			ListErase(tmp);
			printf("删除成功！\n");
			break;
		case 9:
			ListDestory(list);
			printf("摧毁成功！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
		system("pause");
		system("cls");
	} while (1);

	system("pause");
	return 0;
}
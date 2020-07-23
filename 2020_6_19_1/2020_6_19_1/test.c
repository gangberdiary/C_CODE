#include "test.h"

void menu()
{
	printf("################################\n");
	printf("#### 1.ADD         2.DELETE ####\n");
	printf("#### 3.SERCH       4.ALTER  ####\n");
	printf("#### 5.SHOW        6.CLEAR  ####\n");
	printf("#### 7.ORDER       0.EXIT   ####\n");
	printf("################################\n");
}

void InitContact(Contact* con)//初始化通讯录
{
	assert(con);
	con->sz = 0;
	memset(con->data, 0, sizeof(con->data));
}

void Add(Contact* con)
{
	assert(con);
	printf("请输入姓名：>");
	scanf("%s", con->data[con->sz].name);
	printf("请输入电话：>");
	scanf("%s", con->data[con->sz].telephone);
	con->sz++;
}

static int FindByName(Contact* con, char str[])
{
	int i = 0;
	assert(con);
	for (; i < con->sz; i++){
		if (0 == strcmp(con->data[i].name, str)){
			return i;
		}
	}
	return -1;
}

void Delete(Contact* con)
{
	int i = 0;
	char str[20] = { 0 };
	int num = 0;
	assert(con);
	if (0 == con->sz){
		printf("通讯录已空！\n");
		return;
	}
	printf("请输入你要删除的人的名字：>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("你要删除的人不存在！\n");
	}
	for (i = num; i < con->sz - 1; i++){
		con->data[i] = con->data[i + 1];
	}
	con->sz--;
	printf("删除成功！\n");
}

void Serch(Contact* con)
{
	char str[20] = { 0 };
	int num = 0;
	assert(con);
	printf("请输入你要查找的人的名字：>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("查无此人！\n");
		return;
	}
	printf("%-3s %s\n", con->data[num].name, con->data[num].telephone);
}

void Alter(Contact* con)
{
	int num = 0;
	int input = 0;
	char str[20] = { 0 };
	assert(con);
	printf("请输入要修改的人的姓名：>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("查无此人！\n");
		return;
	}
	printf("请选择你要修改的内容(1.姓名 2.电话)：>");
	scanf("%d", &input);
	switch (input){
	case 1:
		printf("请输入修改后的姓名：>");
		scanf("%s", con->data[num].name);
		printf("修改成功！\n");
		break;
	case 2:
		printf("请输入修改后的电话：>");
		scanf("%s", con->data[num].telephone);
		printf("修改成功！\n");
		break;
	default:
		printf("输入错误，修改失败!\n");
		return;
	}
}

void Show(Contact* con)
{
	int i = 0;
	assert(con);
	if (0 == con->sz){
		printf("通讯录为空！\n");
		return;
	}
	printf("姓  名|电  话\n");
	for (; i < con->sz; i++){
		printf("%-6s %s\n", con->data[i].name, con->data[i].telephone);
	}
}

void Clear(Contact* con)
{
	InitContact(con);
}

void OrderByName(Contact* con)
{
	int i, j;
	People tmp;
	for (i = 0; i < con->sz - 1; i++)
	{
		for (j = 0; j < con->sz - 1 - i; j++)
		{
			if (0 < strcmp(con->data[j].name, con->data[j + 1].name))
			{
				tmp = con->data[j];
				con->data[j] = con->data[j + 1];
				con->data[j + 1] = tmp;
			}
		}
	}
}
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

void InitContact(Contact* con)//��ʼ��ͨѶ¼
{
	assert(con);
	con->sz = 0;
	memset(con->data, 0, sizeof(con->data));
}

void Add(Contact* con)
{
	assert(con);
	printf("������������>");
	scanf("%s", con->data[con->sz].name);
	printf("������绰��>");
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
		printf("ͨѶ¼�ѿգ�\n");
		return;
	}
	printf("��������Ҫɾ�����˵����֣�>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("��Ҫɾ�����˲����ڣ�\n");
	}
	for (i = num; i < con->sz - 1; i++){
		con->data[i] = con->data[i + 1];
	}
	con->sz--;
	printf("ɾ���ɹ���\n");
}

void Serch(Contact* con)
{
	char str[20] = { 0 };
	int num = 0;
	assert(con);
	printf("��������Ҫ���ҵ��˵����֣�>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("���޴��ˣ�\n");
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
	printf("������Ҫ�޸ĵ��˵�������>");
	scanf("%s", str);
	num = FindByName(con, str);
	if (-1 == num){
		printf("���޴��ˣ�\n");
		return;
	}
	printf("��ѡ����Ҫ�޸ĵ�����(1.���� 2.�绰)��>");
	scanf("%d", &input);
	switch (input){
	case 1:
		printf("�������޸ĺ��������>");
		scanf("%s", con->data[num].name);
		printf("�޸ĳɹ���\n");
		break;
	case 2:
		printf("�������޸ĺ�ĵ绰��>");
		scanf("%s", con->data[num].telephone);
		printf("�޸ĳɹ���\n");
		break;
	default:
		printf("��������޸�ʧ��!\n");
		return;
	}
}

void Show(Contact* con)
{
	int i = 0;
	assert(con);
	if (0 == con->sz){
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("��  ��|��  ��\n");
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
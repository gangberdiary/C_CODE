#ifndef _STACK_H_
#define _STACK_H_

#include "common.h"

#define SIZE 10

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* data;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
//��ʾ
void StackShow(Stack *ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);
///////////////////////////////////////////////////////////////////////
// ��ʼ��ջ 
bool IsFull(Stack* ps)
{
	assert(ps);
	return ps->top >= ps->capacity;
}

bool IsEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackInit(Stack* ps)
{
	assert(ps);
	ps->capacity = SIZE;
	ps->data = (STDataType*)malloc(sizeof(STDataType) * ps->capacity);
	ps->top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (IsFull(ps)){
		printf("ջ����!\n");
		return;
	}
	ps->data[ps->top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("ջ�ѿ�!\n");
		return;
	}
	ps->top--;
}

//��ʾ
void StackShow(Stack *ps)
{
	assert(ps);
	if (ps != NULL){
		int i = ps->top - 1;
		while (i >= 0){
			printf("| %2d |\n", ps->data[i--]);
		}
		printf(" ----\n");
	}
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	if (IsEmpty(ps)){
		return 1;
	}
	else{
		return 0;
	}
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->top = 0;
}

#endif _STACK_H_
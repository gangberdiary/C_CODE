#ifndef _STACK_H_
#define _STACK_H_

#include "common.h"

#define SIZE 10

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* data;
	int top;		// 栈顶
	int capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
//显示
void StackShow(Stack *ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);
///////////////////////////////////////////////////////////////////////
// 初始化栈 
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

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (IsFull(ps)){
		printf("栈已满!\n");
		return;
	}
	ps->data[ps->top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("栈已空!\n");
		return;
	}
	ps->top--;
}

//显示
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

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->data[ps->top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	if (IsEmpty(ps)){
		return 1;
	}
	else{
		return 0;
	}
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->top = 0;
}

#endif _STACK_H_
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 20

typedef struct SeqList//顺序表
{
	ElemType* data;
	size_t capacity;//容量
	size_t size;//个数
}SeqList;

void SeqListInit(SeqList* plist);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);	
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);

//////////////////////////////////////////////////////////////////////////////////
bool IsFull(SeqList* ps)
{
	assert(ps);
	return ps->size >= ps->capacity;
}

bool IsEmpty(SeqList* ps)
{
	assert(ps);
	return ps->size == 0;
}

void SeqListInit(SeqList* ps)
{
	assert(ps != NULL);
	ps->capacity = SEQLIST_DEFAULT_SIZE;
	ps->data = (ElemType*)malloc(sizeof(ElemType) * ps->capacity);
	ps->size = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	size_t i = 0;
	while (i < ps->size){
		printf("%d->", ps->data[i++]);
	}
	printf("over\n");
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps != NULL);
	if (IsFull(ps)){//判断是否已满
		printf("顺序表已满！\n");
		return;
	}
	ps->data[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsFull(ps)){//判断是否已满
		printf("顺序表已满！\n");
		return;
	}
	size_t i = ps->size;
	while (i > 0){
		ps->data[i] = ps->data[i - 1];
		i--;
	}
	ps->data[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("顺序表已空，无法删除！\n");
		return;
	}

	size_t i = 0;
	while (i < ps->size - 1){
		ps->data[i] = ps->data[i + 1];
		i++;
	}
	ps->size--;
	printf("删除成功！\n");
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("顺序表已空，无法删除！\n");
		return;
	}

	ps->size--;
	printf("删除成功！\n");
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("顺序表已空，无法查找！\n");
		return -1;
	}

	size_t i = 0;
	while (i < ps->size){
		if (ps->data[i] == x){
			return i;
		}
		i++;
	}
	return -1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	if (IsFull(ps)){//判断是否已满
		printf("顺序表已满！\n");
		return;
	}

	if (pos >= 0 && pos <= ps->size){
		size_t i = ps->size;
		while (i > pos){
			ps->data[i] = ps->data[i - 1];
			i--;
		}
		ps->data[pos] = x;
		ps->size++;
		printf("插入成功！\n");
	}
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("顺序表已空，无法删除！\n");
		return;
	}

	if (pos >= 0 && pos < ps->size){
		size_t i = pos;
		while (i < ps->size - 1){
			ps->data[i] = ps->data[i + 1];
			i++;
		}
		ps->size--;
		printf("删除成功！\n");
	}
}
#endif _SEQLIST_H_
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include "common.h"

#define SEQLIST_DEFAULT_SIZE 20

typedef struct SeqList//˳���
{
	ElemType* data;
	size_t capacity;//����
	size_t size;//����
}SeqList;

void SeqListInit(SeqList* plist);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);	
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
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
	if (IsFull(ps)){//�ж��Ƿ�����
		printf("˳���������\n");
		return;
	}
	ps->data[ps->size++] = x;
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsFull(ps)){//�ж��Ƿ�����
		printf("˳���������\n");
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
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}

	size_t i = 0;
	while (i < ps->size - 1){
		ps->data[i] = ps->data[i + 1];
		i++;
	}
	ps->size--;
	printf("ɾ���ɹ���\n");
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}

	ps->size--;
	printf("ɾ���ɹ���\n");
}

// ˳������
int SeqListFind(SeqList* ps, SLDateType x)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("˳����ѿգ��޷����ң�\n");
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
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	if (IsFull(ps)){//�ж��Ƿ�����
		printf("˳���������\n");
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
		printf("����ɹ���\n");
	}
}
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	if (IsEmpty(ps)){
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}

	if (pos >= 0 && pos < ps->size){
		size_t i = pos;
		while (i < ps->size - 1){
			ps->data[i] = ps->data[i + 1];
			i++;
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}
#endif _SEQLIST_H_
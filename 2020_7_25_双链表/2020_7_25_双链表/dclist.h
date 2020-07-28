#ifndef _DCLIST_H_
#define _DCLIST_H_

#include "common.h"

// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* pHead);
// ˫�������ӡ
void ListPrint(ListNode* pHead);
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* pHead);
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
////////////////////////////////////////////////////////////////////////////////////////////////
ListNode* BuyNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->prev = node->next = NULL;

	return node;
}

bool IsEmpty(ListNode* pHead)
{
	assert(pHead);
	return pHead->prev == pHead;
}

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->prev = head->next = head;

	return head;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* p = pHead->next;
	while (p == pHead){
		ListNode* q = p->next;
		free(p);
		p = q;
	}
	free(pHead);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* p = pHead->next;
	while (p != pHead){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over\n");
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = BuyNode(x);

	s->prev = pHead->prev;
	s->next = pHead;
	pHead->prev->next = s;
	pHead->prev = s;
}

//˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}

	ListNode* p = pHead->prev;
	pHead->prev = p->prev;
	p->prev->next = pHead;
	
	free(p);
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = BuyNode(x);

	s->prev = pHead;
	s->next = pHead->next;
	pHead->next->prev = s;
	pHead->next = s;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("����Ϊ�գ��޷�ɾ����\n");
		return;
	}

	ListNode* p = pHead->next;
	pHead->next = p->next;
	p->next->prev = pHead;
	free(p);
}

// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("����Ϊ�գ��޷����ң�\n");
		return NULL;
	}

	ListNode* p = pHead->next;
	while (p != pHead){
		if (p->data == x){
			return p;
		}
		p = p->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* s = BuyNode(x);
	s->prev = pos->prev;
	s->next = pos;
	pos->prev->next = s;
	pos->prev = s;
}

// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
}

#endif _DCLIST_H_
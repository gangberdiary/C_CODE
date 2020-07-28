#ifndef _DCLIST_H_
#define _DCLIST_H_

#include "common.h"

// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* pHead);
// 双向链表打印
void ListPrint(ListNode* pHead);
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* pHead);
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* pHead);
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
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

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->prev = head->next = head;

	return head;
}
// 双向链表销毁
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
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* p = pHead->next;
	while (p != pHead){
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = BuyNode(x);

	s->prev = pHead->prev;
	s->next = pHead;
	pHead->prev->next = s;
	pHead->prev = s;
}

//双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("链表为空，无法删除！\n");
		return;
	}

	ListNode* p = pHead->prev;
	pHead->prev = p->prev;
	p->prev->next = pHead;
	
	free(p);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* s = BuyNode(x);

	s->prev = pHead;
	s->next = pHead->next;
	pHead->next->prev = s;
	pHead->next = s;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("链表为空，无法删除！\n");
		return;
	}

	ListNode* p = pHead->next;
	pHead->next = p->next;
	p->next->prev = pHead;
	free(p);
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	if (IsEmpty(pHead)){
		printf("链表为空，无法查找！\n");
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

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* s = BuyNode(x);
	s->prev = pos->prev;
	s->next = pos;
	pos->prev->next = s;
	pos->prev = s;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
}

#endif _DCLIST_H_
#ifndef HGE_INTRUSIVELIST_H
#define HGE_INTRUSIVELIST_H

#include <stdlib.h>

typedef struct hgeIntrusiveListNode
{
	struct hgeIntrusiveListNode *next, *prev;
} hgeIntrusiveListNode;
 
void hgeIntrusiveListNode_Link(hgeIntrusiveListNode *self, hgeIntrusiveListNode *prev, hgeIntrusiveListNode *next);
void hgeIntrusiveListNode_Unlink(hgeIntrusiveListNode *self);

typedef struct hgeIntrusiveList
{
	hgeIntrusiveListNode *head, *tail;
} hgeIntrusiveList;
 
 
void hgeIntrusiveList_AddHead(hgeIntrusiveList *self, hgeIntrusiveListNode *node);
void hgeIntrusiveList_AddTail(hgeIntrusiveList *self, hgeIntrusiveListNode *node);

#endif//HGE_INTRUSIVELIST_H
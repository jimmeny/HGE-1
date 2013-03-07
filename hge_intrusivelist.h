#ifndef HGE_INTRUSIVELIST_H
#define HGE_INTRUSIVELIST_H

typedef struct hgeIntrusiveListNode
{
	struct hgeIntrusiveListNode *next, *prev;
} hgeIntrusiveListNode;
 
void hgeIntrusiveListNode_Link(hgeIntrusiveListNode *this, hgeIntrusiveListNode *prev, hgeIntrusiveListNode *next);
void hgeIntrusiveListNode_Unlink(hgeIntrusiveListNode *this);

typedef struct hgeIntrusiveList
{
	hgeIntrusiveListNode *head, *tail;
} hgeIntrusiveList;
 
 
void hgeIntrusiveList_AddHead(hgeIntrusiveList *this, hgeIntrusiveListNode *node);
void hgeIntrusiveList_AddTail(hgeIntrusiveList *this, hgeIntrusiveListNode *node);

#endif//HGE_INTRUSIVELIST_H
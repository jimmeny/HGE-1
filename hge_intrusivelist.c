#include "hge_intrusivelist.h"

void hgeIntrusiveListNode_Link(hgeIntrusiveListNode *self, hgeIntrusiveListNode *prev, hgeIntrusiveListNode *next) {
	self->prev = prev;
	self->next = next;
	if(prev != NULL) {
		prev->next = self;
	}
	if(next != NULL) {
		next->prev = self;
	}
}
 
void hgeIntrusiveListNode_Unlink(hgeIntrusiveListNode *self) {
	if(self != NULL) {
		self->next->prev = self->prev;
		self->prev->next = self->next;
		self->prev = self->next = NULL;
	}
}

void hgeIntrusiveList_AddHead(hgeIntrusiveList *self, hgeIntrusiveListNode *node) {
	if(self->head != NULL) {
		hgeIntrusiveListNode_Link(node, self->head->prev, self->head);
	} else {
		hgeIntrusiveListNode_Link(node, node, node);
	}
	self->head = node;
}
 
void hgeIntrusiveList_AddTail(hgeIntrusiveList *self, hgeIntrusiveListNode *node) {
	if(self->head != NULL) {
		hgeIntrusiveListNode_Link(node, self->head->prev, self->head);
	} else {
		hgeIntrusiveList_AddHead(self, node);
	}
	self->tail = node;
}
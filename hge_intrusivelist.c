#include "hge_intrusivelist.h"

void hgeIntrusiveListNode_Link(hgeIntrusiveListNode *this, hgeIntrusiveListNode *prev, hgeIntrusiveListNode *next) {
	this->prev = prev;
	this->next = next;
	if(prev != NULL) {
		prev->next = this;
	}
	if(next != NULL) {
		next->prev = this;
	}
}
 
void hgeIntrusiveListNode_Unlink(hgeIntrusiveListNode *this) {
	if(this != NULL) {
		this->next->prev = this->prev;
		this->prev->next = this->next;
		this->prev = this->next = NULL;
	}
}

void hgeIntrusiveList_AddHead(hgeIntrusiveList *this, hgeIntrusiveListNode *node) {
	if(this->head != NULL) {
		hgeIntrusiveListNode_Link(node, this->head->prev, this->head);
	} else {
		hgeIntrusiveListNode_Link(node, node, node);
	}
	this->head = node;
}
 
void hgeIntrusiveList_AddTail(hgeIntrusiveList *this, hgeIntrusiveListNode *node) {
	if(this->head != NULL) {
		hgeIntrusiveListNode_Link(node, this->head->prev, this->head);
	} else {
		hgeIntrusiveList_AddHead(this, node);
	}
	this->tail = node;
}
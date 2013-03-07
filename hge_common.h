#ifndef HGE_COMMON_H
#define HGE_COMMON_H

#include <stdint.h>

typedef enum hgeBool {
	hgeFalse = 0,
	hgeTrue = 1,
} hgeBool;

/* OBJECT
 * Allows for tracking of game objects with unique ids
 */
typedef unsigned long int hgeObjectID;

typedef struct hgeObject
{
	hgeObjectID uid;
} hgeObject;

void hgeObject_Init(hgeObject *this);

#endif//HGE_COMMON_H
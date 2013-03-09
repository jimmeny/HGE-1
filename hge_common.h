#ifndef HGE_COMMON_H
#define HGE_COMMON_H

#include <stdint.h>

#define DEV_SYS_WIN32 (defined(_WIN32))

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

void hgeObject_Init(hgeObject *self);

#endif//HGE_COMMON_H
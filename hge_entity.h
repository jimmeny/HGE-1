#ifndef HGE_ENTITY_H
#define HGE_ENTITY_H

#include "hge_common.h"
#include "hge_bounding.h"

typedef struct hgeEntity
{
	union
	{
		hgeObject object;
	} base;

	hgeBounding *bounds;
} hgeEntity;

#endif//HGE_ENTITY_H
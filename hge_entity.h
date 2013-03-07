#ifndef HGE_ENTITY_H
#define HGE_ENTITY_H

#include "hge_common.h"
#include "hge_vector.h"
#include "hge_bounding.h"

typedef struct hgeEntity
{
	union
	{
		hgeObject object;
	} base;

	hgeVector3f position;
	hgeVector3f acceleration;
	hgeVector3f velocity;

	hgeBounding *bounds;
} hgeEntity;

#endif//HGE_ENTITY_H
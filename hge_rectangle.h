#ifndef HGE_RECTANGLE_H
#define HGE_RECTANGLE_H

#include "hge_common.h"
#include "hge_bounding.h"

typedef struct hgeRectangle
{
	union
	{
		hgeBounding bounding;
	} base;
	hgeVector3f vertices[4];
} hgeRectangle;

void    hgeRectangle_Init(hgeRectangle *this, hgeVector3f tl, hgeVector3f br);
void    hgeRectangle_Destroy(hgeRectangle *this);

hgeBool	hgeRectangle_IntersectsBounding(hgeRectangle *this, hgeBounding *other);
hgeBool	hgeRectangle_ContainsPoint(hgeRectangle *this, hgeVector3f *point);

#endif//HGE_RECTANGLE_H
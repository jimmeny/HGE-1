#ifndef HGE_BOUNDING_H
#define HGE_BOUNDING_H

#include "hge_common.h"
#include "hge_vector.h"

typedef struct hgeBounding
{
	unsigned int vertex_count;
	hgeVector3f *vertices;
} hgeBounding;

void	hgeBounding_Init(hgeBounding *b, hgeVector3f *va, unsigned int vc);
void	hgeBounding_Destroy(hgeBounding *b);

hgeBool	hgeBounding_IntersectsBounding(hgeBounding *b, hgeBounding *other);
hgeBool	hgeBounding_ContainsPoint(hgeBounding *b, hgeVector3f *point);

#endif//HGE_BOUNDING_H
#ifndef HGE_BOUNDING_H
#define HGE_BOUNDING_H

#include "hge_common.h"
#include "hge_vector.h"

/* Basic bounding structure that is inherited by each bounding shape
 * The super shape sets the vertices pointer and vertex count
 */
typedef struct hgeBounding
{
	unsigned int vertex_count;
	hgeVector3f *vertices;
} hgeBounding;

void	hgeBounding_Init(hgeBounding *this, hgeVector3f *va, unsigned int vc);
void	hgeBounding_Destroy(hgeBounding *this);

hgeBool	hgeBounding_IntersectsBounding(hgeBounding *this, hgeBounding *other);
hgeBool	hgeBounding_ContainsPoint(hgeBounding *this, hgeVector3f *point);

#endif//HGE_BOUNDING_H
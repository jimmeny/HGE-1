#include <stdlib.h>
#include <math.h>

#include "hge_common.h"
#include "hge_bounding.h"

void hgeBounding_Init(hgeBounding *b, hgeVector3f *va, unsigned int vc) {
	b->vertex_count = vc;
	b->vertices = va;
}

void hgeBounding_Destroy(hgeBounding *b) {
	free(b->vertices);
}

hgeBool hgeBounding_IntersectsBounding(hgeBounding *b, hgeBounding *other) {
	
}

hgeBool hgeBounding_ContainsPoint(hgeBounding *b, hgeVector3f *point) {
	int side_count = 0;
	unsigned int index;
	for(index = 0; index < b->vertex_count; index++) {
		hgeVector3f *point_a = &b->vertices[index];
		hgeVector3f *point_b = &b->vertices[(index + 1) % b->vertex_count];
		int a = -(point_b->y - point_a->y);
		int b = (point_b->x - point_a->x);
		int c = -((a * point_a->x) + (b * point_a->y));
		int d = ((a * point->x) + (b * point->y) + c);
		if(d >= 0) {
			side_count += 1;
		} else {
			side_count -= 1;
		}
	}

	if(abs(side_count) == b->vertex_count) {
		return hgeTrue;
	}
	return hgeFalse;
}

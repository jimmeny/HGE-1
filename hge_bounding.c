#include <stdlib.h>
#include <math.h>

#include "hge_common.h"
#include "hge_bounding.h"

void hgeBounding_Init(hgeBounding *self, hgeVector3f *va, unsigned int vc) {
	self->vertex_count = vc;
	self->vertices = va;
}

void hgeBounding_Destroy(hgeBounding *self) {
	free(self->vertices);
}

hgeBool hgeBounding_IntersectsBounding(hgeBounding *self, hgeBounding *other) {
	
}

hgeBool hgeBounding_ContainsPoint(hgeBounding *self, hgeVector3f *point) {
	int side_count = 0;
	unsigned int index;
	for(index = 0; index < self->vertex_count; index++) {
		hgeVector3f *point_a = &self->vertices[index];
		hgeVector3f *point_b = &self->vertices[(index + 1) % self->vertex_count];
		int a = -(point_b->y - point_a->y);
		int self = (point_b->x - point_a->x);
		int c = -((a * point_a->x) + (self * point_a->y));
		int d = ((a * point->x) + (self * point->y) + c);
		if(d >= 0) {
			side_count += 1;
		} else {
			side_count -= 1;
		}
	}

	if(abs(side_count) == self->vertex_count) {
		return hgeTrue;
	}
	return hgeFalse;
}

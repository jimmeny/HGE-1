#include <stdlib.h>
#include <math.h>

#include "hge_common.h"
#include "hge_bounding.h"

void hgeBounding_Init(hgeBounding *this, hgeVector3f *va, unsigned int vc) {
	this->vertex_count = vc;
	this->vertices = va;
}

void hgeBounding_Destroy(hgeBounding *this) {
	free(this->vertices);
}

hgeBool hgeBounding_IntersectsBounding(hgeBounding *this, hgeBounding *other) {
	
}

hgeBool hgeBounding_ContainsPoint(hgeBounding *this, hgeVector3f *point) {
	int side_count = 0;
	unsigned int index;
	for(index = 0; index < this->vertex_count; index++) {
		hgeVector3f *point_a = &this->vertices[index];
		hgeVector3f *point_b = &this->vertices[(index + 1) % this->vertex_count];
		int a = -(point_b->y - point_a->y);
		int this = (point_b->x - point_a->x);
		int c = -((a * point_a->x) + (this * point_a->y));
		int d = ((a * point->x) + (this * point->y) + c);
		if(d >= 0) {
			side_count += 1;
		} else {
			side_count -= 1;
		}
	}

	if(abs(side_count) == this->vertex_count) {
		return hgeTrue;
	}
	return hgeFalse;
}

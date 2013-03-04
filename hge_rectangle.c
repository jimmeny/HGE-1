#include "hge_common.h"
#include "hge_vector.h"
#include "hge_bounding.h"
#include "hge_rectangle.h"

void hgeRectangle_Init(hgeRectangle *r, hgeVector3f tl, hgeVector3f br) {
	r->vertices[0].x = tl.x;
	r->vertices[0].y = br.y;
	r->vertices[0].z = 0;

	r->vertices[1].x = tl.x;
	r->vertices[1].y = tl.y;
	r->vertices[1].z = 0;

	r->vertices[2].x = br.x;
	r->vertices[2].y = tl.y;
	r->vertices[2].z = 0;

	r->vertices[3].x = br.x;
	r->vertices[3].y = br.y;
	r->vertices[3].z = 0;
	
	hgeBounding_Init(&(r->base.bounding), &(r->vertices[0]), 4);
}

void hgeRectangle_Destroy(hgeRectangle *r) {
	hgeBounding_Destroy(&(r->base.bounding));
}

hgeBool hgeRectangle_IntersectsBounding(hgeRectangle *r, hgeBounding *other) {
	return hgeBounding_IntersectsBounding(&(r->base.bounding), other);
}

hgeBool hgeRectangle_ContainsPoint(hgeRectangle *r, hgeVector3f *point) {
	return hgeBounding_ContainsPoint(&(r->base.bounding), point);
}
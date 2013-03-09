#include "hge_common.h"
#include "hge_vector.h"
#include "hge_bounding.h"
#include "hge_rectangle.h"

void hgeRectangle_Init(hgeRectangle *self, hgeVector3f tl, hgeVector3f br) {
	self->vertices[0].x = tl.x;
	self->vertices[0].y = br.y;
	self->vertices[0].z = 0;

	self->vertices[1].x = tl.x;
	self->vertices[1].y = tl.y;
	self->vertices[1].z = 0;

	self->vertices[2].x = br.x;
	self->vertices[2].y = tl.y;
	self->vertices[2].z = 0;

	self->vertices[3].x = br.x;
	self->vertices[3].y = br.y;
	self->vertices[3].z = 0;
	
	hgeBounding_Init(&(self->base.bounding), &(self->vertices[0]), 4);
}

void hgeRectangle_Destroy(hgeRectangle *self) {
	hgeBounding_Destroy(&(self->base.bounding));
}

hgeBool hgeRectangle_IntersectsBounding(hgeRectangle *self, hgeBounding *other) {
	return hgeBounding_IntersectsBounding(&(self->base.bounding), other);
}

hgeBool hgeRectangle_ContainsPoint(hgeRectangle *self, hgeVector3f *point) {
	return hgeBounding_ContainsPoint(&(self->base.bounding), point);
}
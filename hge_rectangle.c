#include "hge_common.h"
#include "hge_vector.h"
#include "hge_bounding.h"
#include "hge_rectangle.h"

void hgeRectangle_Init(hgeRectangle *this, hgeVector3f tl, hgeVector3f br) {
	this->vertices[0].x = tl.x;
	this->vertices[0].y = br.y;
	this->vertices[0].z = 0;

	this->vertices[1].x = tl.x;
	this->vertices[1].y = tl.y;
	this->vertices[1].z = 0;

	this->vertices[2].x = br.x;
	this->vertices[2].y = tl.y;
	this->vertices[2].z = 0;

	this->vertices[3].x = br.x;
	this->vertices[3].y = br.y;
	this->vertices[3].z = 0;
	
	hgeBounding_Init(&(this->base.bounding), &(this->vertices[0]), 4);
}

void hgeRectangle_Destroy(hgeRectangle *this) {
	hgeBounding_Destroy(&(this->base.bounding));
}

hgeBool hgeRectangle_IntersectsBounding(hgeRectangle *this, hgeBounding *other) {
	return hgeBounding_IntersectsBounding(&(this->base.bounding), other);
}

hgeBool hgeRectangle_ContainsPoint(hgeRectangle *this, hgeVector3f *point) {
	return hgeBounding_ContainsPoint(&(this->base.bounding), point);
}
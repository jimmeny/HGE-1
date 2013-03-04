#ifndef HGE_VECTOR_H
#define HGE_VECTOR_H

typedef union hgeVector3f
{
	float array[3];
	struct
	{
		float x, y, z;
	};
} hgeVector3f;

typedef union hgeVector3i
{
	int array[3];
	struct
	{
		int x, y, z;
	};
} hgeVector3i;

typedef union hgeVector3u
{
	unsigned int array[3];
	struct
	{
		unsigned x, y, z;
	};
} hgeVector3u;

#endif//HGE_VECTOR_H
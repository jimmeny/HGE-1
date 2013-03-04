#ifndef HGE_MATRIX_H
#define HGE_MATRIX_H

typedef union hgeMatrix4f
{
	float array[4 * 4];
	struct
	{
		float x1, y1, z1, w1;
		float x2, y2, z2, w2;
		float x3, y3, z3, w3;
		float x4, y4, z4, w4;
	};
} hgeMatrix4f;

typedef union hgeMatrix4i
{
	int array[4 * 4];
	struct
	{
		int x1, y1, z1, w1;
		int x2, y2, z2, w2;
		int x3, y3, z3, w3;
		int x4, y4, z4, w4;
	};
} hgeMatrix4i;

typedef union hgeMatrix4u
{
	unsigned int array[4 * 4];
	struct
	{
		unsigned int x1, y1, z1, w1;
		unsigned int x2, y2, z2, w2;
		unsigned int x3, y3, z3, w3;
		unsigned int x4, y4, z4, w4;
	};
} hgeMatrix4u;

#endif//HGE_MATRIX_H
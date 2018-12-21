#pragma once
#ifndef HEADER_QUAD_H
#define HEADER_QUAD_H
#include "Vector3f.h"
#include "Shape.h"

class Quad : public Shape{
public:
	Vector3f origin_;
	Vector3f width_;
	Vector3f height_;
	Quad(Vector3f const & origin, Vector3f const & width, Vector3f const & height);
	
};
#endif // !HEADER_QUAD_H

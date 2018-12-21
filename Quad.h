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
	Quad(Material const & mat, Vector3f const & origin, Vector3f const & width, Vector3f const & height);
	bool is_hit(Ray3f const & ray) override;
	Ray3f reflect(Ray3f const & ray) override;
	Vector3f impactPosition(Ray3f const & ray) override;
	
};
#endif // !HEADER_QUAD_H

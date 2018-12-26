#pragma once
#ifndef HEADER_QUAD_H
#define HEADER_QUAD_H
#include "Vector3f.h"
#include "Shape.h"

class Box : public Shape{
public:
	Vector3f origin_;
	Vector3f minBound_;
	Vector3f maxBound_;
	Box(Material const & mat, Vector3f const & minBound, Vector3f const & maxBound);
	bool is_hit(Ray3f const & ray, double & hitDistance) override;
	Ray3f reflect(Ray3f const & ray, Vector3f const & hitPosition) override;
	Vector3f impactPosition(Ray3f const & ray, double hitDistance) override;
	
};
#endif // !HEADER_QUAD_H

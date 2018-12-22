#pragma once
#ifndef HEADER_SHAPE_H
#define HEADER_SHAPE_H
#include "Material.h"
#include "Ray3f.h"
class Shape {
public:
	Material mat_;
	virtual bool is_hit(Ray3f const & ray, double & hitDistance) = 0;
	virtual Ray3f reflect(Ray3f const & ray) = 0;
	virtual Vector3f impactPosition(Ray3f const & ray, double hitDistance) = 0;

};
#endif // !HEADER_SHAPE_H

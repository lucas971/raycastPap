#pragma once
#ifndef HEADER_SPHERE_H
#define HEADER_SPHERE_H
#include "Vector3f.h"
#include "Shape.h"

class Sphere : public Shape {
public:
	Vector3f origin_;
	float radius_;
	Sphere(Material const & mat, Vector3f const & origin, float radius);

};
#endif // !HEADER_SPHERE_H
#pragma once
#ifndef HEADER_SHAPE_H
#define HEADER_SHAPE_H
#include "Material.h"
#include "Ray3f.h"
class Shape {
public:
	Material mat_;
	virtual bool is_hit(Ray3f ray);
	virtual Ray3f reflect(Ray3f ray);
	Shape(Material const & mat);

};
#endif // !HEADER_SHAPE_H

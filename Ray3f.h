#pragma once
#ifndef HEADER_RAY3F_H
#define HEADER_RAY3F_H
#include "Vector3f.h"

class Ray3f {
public:
	Vector3f origin_;
	Vector3f direction_;
	Vector3f invdir_;
	int sign_[3];
	Ray3f();
	Ray3f(Vector3f const & origin, Vector3f const & direction);
};
#endif // !HEADER_RAY3F_H

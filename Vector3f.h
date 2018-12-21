#pragma once
#ifndef HEADER_VECTOR3F_H
#define HEADER_VECTOR3F_H

class Vector3f {
public:
	double x_;
	double y_;
	double z_;
	Vector3f();
	Vector3f(double x, double y, double z);
	double dist(Vector3f v);
};
#endif // !HEADER_VECTOR3F_H

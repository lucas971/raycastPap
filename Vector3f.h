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
	double norm() const;
	Vector3f normalize() const;
	Vector3f operator + (Vector3f const & v);
	Vector3f operator - (Vector3f  const & v);
	double operator * (Vector3f const & v);
	Vector3f operator * (double d);
	
};
#endif // !HEADER_VECTOR3F_H

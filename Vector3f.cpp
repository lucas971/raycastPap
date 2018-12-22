#include "Vector3f.h"
#include <cmath>
//TODO: Vérifier que l'utilisation de cmath est autorisée
Vector3f::Vector3f()
{
	x_ = 0.0, y_ = 0.0, z_ = 0.0;
}

Vector3f::Vector3f(double x, double y, double z)
{
	x_ = x, y_ = y, z_ = z;
}

double Vector3f::dist(Vector3f v) {
	return sqrt(pow(x_ - v.x_, 2) + pow(y_ - v.y_, 2) + pow(z_ - v.z_, 2));
}

double Vector3f::norm() const
{
	return sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
}

Vector3f Vector3f::normalize() const {
	double norm = this->norm();
	return Vector3f(x_ / norm, y_ / norm, z_ / norm);
}

Vector3f Vector3f::operator+(Vector3f const & v) 
{
	return Vector3f(x_ + v.x_, y_ + v.y_, z_ + v.z_);
}

Vector3f Vector3f::operator-(Vector3f const & v) 
{
	return Vector3f(x_ - v.x_, y_ - v.y_, z_ - v.z_);
}

double Vector3f::operator*(Vector3f const & v) 
{
	return (x_*v.x_) + (y_ * v.y_) + (z_ * v.z_);
}

Vector3f Vector3f::operator*(double d)
{
	return Vector3f(x_*d, y_*d, z_*d);
}


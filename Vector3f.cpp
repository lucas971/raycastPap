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
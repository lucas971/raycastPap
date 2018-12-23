#include "Sphere.h"
#include <cmath>
#include <iostream>
Sphere::Sphere(Material const & mat,Vector3f const & origin, float radius)
{
	mat_ = mat, origin_ = origin, radius_ = radius;
}

bool Sphere::is_hit(Ray3f const & ray, double & hitDistance) {
	Vector3f l = ray.direction_.normalize();
	double eq = pow(l*(origin_ - ray.origin_), 2) - pow((origin_ - ray.origin_).norm(), 2) + pow(radius_, 2);
	if (eq >= 0) {
		if ((l*(origin_ - ray.origin_)) < sqrt(eq))
			hitDistance = (l*(origin_ - ray.origin_)) + sqrt(eq);
		else
			hitDistance = (l*(origin_ - ray.origin_)) - sqrt(eq);
	}
	return eq >= 0;
}

Ray3f Sphere::reflect(Ray3f const & ray)
{
	return Ray3f();
}

//Appeller is_hit() avant pour vérifier que l'objet est bien touché
Vector3f Sphere::impactPosition(Ray3f const & ray, double hitDistance)
{
	Vector3f l = ray.direction_.normalize();
	return l * hitDistance + ray.origin_;
}


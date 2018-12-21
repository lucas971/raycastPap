#include "Sphere.h"

Sphere::Sphere(Material const & mat,Vector3f const & origin, float radius)
{
	mat_ = mat, origin_ = origin, radius_ = radius;
}

bool Sphere::is_hit(Ray3f const & ray) {
	
	return true;
}

Ray3f Sphere::reflect(Ray3f const & ray)
{
	return ray;
}

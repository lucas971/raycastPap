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
	Ray3f reflected = Ray3f(ray);
}

Vector3f Sphere::impactPosition(Ray3f const & ray)
{
	return Vector3f();
}

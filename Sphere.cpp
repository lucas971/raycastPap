#include "Sphere.h"

Sphere::Sphere(Material const & mat,Vector3f const & origin, float radius):Shape(mat)
{
	origin_ = origin, radius_ = radius;
}

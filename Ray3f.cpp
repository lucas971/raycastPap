#include "Ray3f.h"

Ray3f::Ray3f()
{
	Vector3f origin_(); Vector3f direction_();
}

Ray3f::Ray3f(Vector3f const & origin, Vector3f const & direction)
{
	origin_ = origin, direction_ = direction;
}

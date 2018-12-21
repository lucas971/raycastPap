#include "Quad.h"

Quad::Quad(Material const & mat, Vector3f const & origin, Vector3f const & width, Vector3f const & height){
	mat_ = mat, origin_ = origin, width_ = width, height_ = height;
}

bool Quad::is_hit(Ray3f const & ray)  {
	return true;
}

Ray3f Quad::reflect(Ray3f const & ray)
{
	return ray;
}

Vector3f Quad::impactPosition(Ray3f const & ray)
{
	return Vector3f();
}

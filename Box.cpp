#include "Box.h"

Box::Box(Material const & mat, Vector3f const & minBound, Vector3f const & maxBound){
	mat_ = mat, minBound_ = minBound, maxBound_ = maxBound;
	origin_ = Vector3f((minBound.x_ + maxBound.x_) * (1 / 2), (minBound.y_ + maxBound.y_) * (1 / 2), (minBound.z_ + maxBound.z_) * (1 / 2));
}

bool Box::is_hit(Ray3f const & ray, double & hitDistance)  {
	double tmin, tmax, tymin, tymax, tzmin, tzmax;
	Vector3f bounds[2];
	bounds[0] = minBound_;
	bounds[1] = maxBound_;

	tmin = (bounds[ray.sign_[0]].x_ - ray.origin_.x_) * ray.invdir_.x_;
	tmax = (bounds[1 - ray.sign_[0]].x_ - ray.origin_.x_) * ray.invdir_.x_;
	tymin = (bounds[ray.sign_[1]].y_ - ray.origin_.y_) * ray.invdir_.y_;
	tymax = (bounds[1 - ray.sign_[1]].y_ - ray.origin_.y_) * ray.invdir_.y_;

	if ((tmin > tymax) || (tymin > tmax))
		return false;
	if (tymin > tmin)
		tmin = tymin;
	if (tymax < tmax)
		tmax = tymax;

	tzmin = (bounds[ray.sign_[2]].z_ - ray.origin_.z_) * ray.invdir_.z_;
	tzmax = (bounds[1 - ray.sign_[2]].z_ - ray.origin_.z_) * ray.invdir_.z_;

	if ((tmin > tzmax) || (tzmin > tmax))
		return false;
	if (tzmin > tmin)
		tmin = tzmin;
	if (tzmax < tmax)
		tmax = tzmax;
	
	if (tmin < 0 && tmax < 0)
		return false;
	else if (tmin < 0)
		hitDistance = tmax;
	else
		hitDistance = tmin;
	
	return true;
}

Ray3f Box::reflect(Ray3f const & ray)
{
	return ray;
}

Vector3f Box::impactPosition(Ray3f const & ray, double hitDistance)
{
	Vector3f l = ray.direction_.normalize();
	return l * hitDistance + ray.origin_;
}

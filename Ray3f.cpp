#include "Ray3f.h"

Ray3f::Ray3f()
{
	origin_ = Vector3f(); direction_ = Vector3f();
	invdir_ = Vector3f(1 / direction_.x_, 1 / direction_.y_, 1 / direction_.z_);
	sign_[0] = (invdir_.x_ < 0);
	sign_[1] = (invdir_.y_ < 0);
	sign_[2] = (invdir_.z_ < 0);
}

Ray3f::Ray3f(Vector3f const & origin, Vector3f const & direction)
{
	origin_ = origin, direction_ = direction;
	invdir_ = Vector3f(1 / direction_.x_, 1 / direction_.y_, 1 / direction_.z_);
	sign_[0] = (invdir_.x_ < 0);
	sign_[1] = (invdir_.y_ < 0);
	sign_[2] = (invdir_.z_ < 0);
}

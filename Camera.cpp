#include "Camera.h"

Camera::Camera()
{
	Vector3f position_(); Vector3f direction_();
}

Camera::Camera(Vector3f const & position, Vector3f const & direction)
{
	position_ = position;
	direction_ = direction;
}

#pragma once
#ifndef HEADER_CAMERA_H
#define HEADER_CAMERA_H
#include "Vector3f.h"

class Camera {
public:
	Vector3f position_;
	Vector3f direction_;
	Camera();
	Camera(Vector3f const & position, Vector3f const & direction);
};
#endif // !HEADER_CAMERA_H

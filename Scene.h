#pragma once
#ifndef HEADER_SCENE_H
#define HEADER_SCENE_H

#include "Camera.h"
#include "Shape.h"


class Scene {
public:
	Camera camera_;
	Shape** shapes_;
	Ray3f source_;
	Scene(Camera camera, Shape** shapes_, Ray3f source);
	void render(int width, int height, char* filename, Camera mainCamera);
};

#endif // !HEADER_SCENE_H

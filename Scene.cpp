#include "Scene.h"

Scene::Scene(Camera camera, Shape ** shapes, Ray3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

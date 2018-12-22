#include "Scene.h"
#include "Constantes.h"
#include <iostream>;
Scene::Scene(Camera camera, Shape ** shapes, Ray3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

void Scene::render(int width, int height, const char * filename, Camera mainCamera)
{
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++) {
			Ray3f ray = Ray3f(mainCamera.position_, Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * (VIEW_ANGLE_HORIZONTAL / width), -VIEW_ANGLE_VERTICAL / 2 + i * (VIEW_ANGLE_VERTICAL / height), 0));
			int hitIndex;
			double hitDistance = -1;
			for (int k = 0; k < N_SCENE_OBJECTS; k++) {
				double tmpHitDistance;
				if (shapes_[k]->is_hit(ray, tmpHitDistance)) {
					if (hitDistance < 0 || hitDistance > tmpHitDistance) {
						hitIndex = k;
						hitDistance = tmpHitDistance;
					}
				}
			}
			
			
			Vector3f impactPosition = shapes_[hitIndex]->impactPosition(ray, hitDistance);
			std::cout << "x = " << impactPosition.x_ << " , y = " << impactPosition.y_ << " , z = " << impactPosition.z_ << " , hitIndex = " << hitIndex << std::endl;
			//TODO Calculs liés à la source de lumière
			//TODO ecriture sur un fichier avec libpng
		}
	}
}

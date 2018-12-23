#include "Scene.h"
#include "Constantes.h"
#include <iostream>

Scene::Scene(Camera camera, Shape ** shapes, Vector3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

void Scene::render(int width, int height, const char * filename, Camera mainCamera)
{
	int hit[6];
	hit[0] = 0, hit[1] = 0, hit[2] = 0, hit[3] = 0, hit[4] = 0, hit[5] =0;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++) {
			Ray3f ray = Ray3f(mainCamera.position_, (mainCamera.direction_ + Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * (VIEW_ANGLE_HORIZONTAL / width), -VIEW_ANGLE_VERTICAL / 2 + i * (VIEW_ANGLE_VERTICAL / height), 0)).normalize());
			
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
			hit[hitIndex] ++;
			Vector3f impactPosition = shapes_[hitIndex]->impactPosition(ray, hitDistance);
			Material mat = shapes_[hitIndex]->mat_;

			//TODO : Calculs liés à la source de lumière
			Ray3f lightRay = Ray3f(source_, (impactPosition - source_).normalize());
			hitDistance = -1;
			int lightHitIndex;

			for (int k = 0; k < N_SCENE_OBJECTS; k++) {
				double tmpHitDistance;
				if (shapes_[k]->is_hit(lightRay, tmpHitDistance)) {
					if (hitDistance < 0 || hitDistance > tmpHitDistance) {
						lightHitIndex = k;
						hitDistance = tmpHitDistance;
					}
				}
			}
			
			double lightStrenght;
			if (lightHitIndex != hitIndex) {
				lightStrenght = 0;
			}
			else if (hitDistance > 10)
				lightStrenght = .5 + 5 / hitDistance;
			else
				lightStrenght = 1;
			
			//TODO : ecriture sur un fichier avec libpng en utilisant la couleur du materiel mat pour le pixel numero j de la ligne numero i de l'écran.
		
		}
	}
	for (int i = 0; i < N_SCENE_OBJECTS; i++) { //FOR STATISTIC PURPOSES
		std::cout << "N°" << i << " object touch % : " << (double)hit[i] / (double)(width*height) << std::endl;
	}
}

#include "Camera.h"
#include "Material.h"
#include "Shape.h"
#include "Vector3f.h"
#include "Ray3f.h"
#include "Scene.h"
#include "Quad.h"
#include "Sphere.h"

const double VIEW_ANGLE_HORIZONTAL = 40.0; //FOV horizontal
const double VIEW_ANGLE_VERTICAL = 27.0; //FOV vertical
const int SCREEN_WIDTH = 1280; //Résolution horizontale
const int SCREEN_HEIGHT = 720; //Résolution verticale
const double ANGLE_STEP_HORIZONTAL = VIEW_ANGLE_HORIZONTAL/ SCREEN_WIDTH; 
const double ANGLE_STEP_VERTICAL = VIEW_ANGLE_VERTICAL / SCREEN_WIDTH; 
const int N_SCENE_OBJECTS = 7; //Doit correspondre au nombre exact de "Shape" dans la scène.
const double SCENE_DEPTH = 20; //Profondeur de la scène
const double SCENE_HEIGHT = 20; //Hauteur de la scène
const double SCENE_WIDTH = 20; //Largeur de la scène


int main() {
	//Step 1 : Creation de la camera
	Camera mainCamera = Camera(Vector3f(0.0, 0.0, 0.0), Vector3f(0.0, 0.0, 1.0));



	//Step 2 : Création des quadrilatères qui représentent la scène

	Shape** shapeList = new Shape*[N_SCENE_OBJECTS];

	//TODO: Compléter les vecteurs des constructeurs de qu1, qu2, qu3 qu4, qu5

	//Fond de la boîte
	Shape* qu1 = new Quad(Material(), Vector3f(mainCamera.position_.x_, mainCamera.position_.y_, mainCamera.position_.z_ + SCENE_DEPTH), Vector3f(),  Vector3f());
	shapeList[0] = qu1;

	//Côté droit de la boîte
	Shape* qu2 = new Quad(Material(), Vector3f(mainCamera.position_.x_ + SCENE_WIDTH/2, mainCamera.position_.y_, mainCamera.position_.z_ + SCENE_DEPTH/2), Vector3f(), Vector3f());
	shapeList[1] = qu2;

	//Côté gauche de la boîte
	Shape* qu3 = new Quad(Material(), Vector3f(mainCamera.position_.x_ - SCENE_WIDTH/2, mainCamera.position_.y_, mainCamera.position_.z_ + SCENE_DEPTH/2), Vector3f(), Vector3f());
	shapeList[2] = qu3;

	//Haut de la boîte
	Shape* qu4 = new Quad(Material(), Vector3f(mainCamera.position_.x_, mainCamera.position_.y_ + SCENE_HEIGHT/2, mainCamera.position_.z_ + SCENE_DEPTH / 2), Vector3f(), Vector3f());
	shapeList[3] = qu4;

	//Bas de la boîte
	Shape* qu5 = new Quad(Material(), Vector3f(mainCamera.position_.x_, mainCamera.position_.y_, mainCamera.position_.z_ - SCENE_HEIGHT / 2 + SCENE_DEPTH / 2), Vector3f(), Vector3f());
	shapeList[4] = qu5;



	//Step 3 : Creation des objets 3D

	Shape* sp1 = new Sphere(Material(), Vector3f(0.0, 1.0, 0.0), .2);
	shapeList[5] = sp1;
	Shape* sp2 = new Sphere(Material(), Vector3f(0.0, -1.0, 0.0), .2);
	shapeList[6] = sp2;




	//Step 4 : Création de la scène
	Scene mainScene = Scene(mainCamera, shapeList, Ray3f(Vector3f(), Vector3f(0.0, 1.0, 0.0)));




	//Step 5 : Lancers de rayons de sorte à remplir chaque pixel de l'écran. On fait la correspondance entre le point d'impact, le Material et la source lumineuse pour afficher la bonne couleur.
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < SCREEN_WIDTH; j++) {

			Ray3f ray = Ray3f(mainCamera.position_, Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * ANGLE_STEP_HORIZONTAL, -VIEW_ANGLE_VERTICAL / 2 + i * ANGLE_STEP_VERTICAL, 0));

			int hitIndex;
			double hitDistance = -1;
			for (int k = 0; k < N_SCENE_OBJECTS; k++) {
				if (shapeList[k]->is_hit(ray)) {
					if (hitDistance < 0 || hitDistance > shapeList[k]->impactPosition(ray).dist(mainCamera.position_)) {
						hitIndex = k;
						hitDistance = shapeList[k]->impactPosition(ray).dist(mainCamera.position_);
					}
				}
			}
			if (hitDistance < 0)
				throw "One raycast didn't collide, the scene is incorrectly parametred.";

			Vector3f impactPosition = shapeList[hitIndex]->impactPosition(ray);

			//TODO Calculs liés à la source de lumière


		}
	}
	return 0;
}
#include "Material.h"
#include "Shape.h"
#include "Vector3f.h"
#include "Ray3f.h"
#include "Scene.h"
#include "Box.h"
#include "Sphere.h"
#include "Constantes.h"
#include <cstdio>
#include <iostream>
int main(){
	//Step 1 : Creation de la camera
	Camera mainCamera = Camera(Vector3f(0.0, 0.0, 0.0), Vector3f(0.0, 0.0, 1.0));

	//Step 1.5 : Creation d'un mur artificiel derriere la camera pour les rayons reflechis
	

	//Step 2 : Création des quadrilatères qui représentent la scène

	Shape** shapeList = new Shape*[N_SCENE_OBJECTS];

	//TODO: Compléter les vecteurs des constructeurs de qu1, qu2, qu3 qu4, qu5

	//Fond de la boîte (blanc)
	Shape* qu1 = new Box(Material(255,255,255,0), 
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH), 
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[0] = qu1;

	//Côté droit de la boîte (bleu)
	Shape* qu2 = new Box(Material(0, 0, 150, 0),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_), 
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[1] = qu2;

	//Côté gauche de la boîte (bleu)
	Shape* qu3 = new Box(Material(0, 0, 150, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[2] = qu3;

	//Haut de la boîte (violet)
	Shape* qu4 = new Box(Material(150, 0, 150, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ ),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[3] = qu4;

	//Bas de la boîte (violet)
	Shape* qu5 = new Box(Material(150, 0, 150, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[4] = qu5;

	//Step 1.5 : Creation d'un mur artificiel derriere la camera pour les rayons reflechis
	Shape* qu6 = new Box(Material(255, 255, 255, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH -100, mainCamera.position_.y_ - SCENE_HEIGHT -100, mainCamera.position_.z_ - .2),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH +100, mainCamera.position_.y_ + SCENE_HEIGHT +100, mainCamera.position_.z_ - .7));
	shapeList[7] = qu6;

	//Step 3 : Creation des objets 3D
	Shape* sph1 = new Sphere(Material(200, 0, 0, 0.3), 
		Vector3f(mainCamera.position_.x_ + 0.3, mainCamera.position_.y_, mainCamera.position_.z_ + 0.4),
		(float).2);
	shapeList[5] = sph1;

	Shape* box1 = new Box(Material(200, 0, 0, 0),
		Vector3f(mainCamera.position_.x_ -1, mainCamera.position_.y_- .2, mainCamera.position_.z_ + 0.3),
		Vector3f(mainCamera.position_.x_ -.4, mainCamera.position_.y_ + .7, mainCamera.position_.z_ + 0.8));
	shapeList[6] = box1;


	//Step 4 : Création de la scène
	Scene mainScene = Scene(mainCamera, shapeList, Vector3f(mainCamera.position_.x_, mainCamera.position_.y_ + SCENE_HEIGHT/2 - .001, mainCamera.position_.z_ + .1));
	char* newFile = (char*) "newFile.png";
	mainScene.render(SCREEN_WIDTH, SCREEN_HEIGHT, newFile, mainCamera);

	std::cout << "Program end" << std::endl;
	return 0;
}
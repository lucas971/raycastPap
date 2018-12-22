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



	//Step 2 : Cr�ation des quadrilat�res qui repr�sentent la sc�ne

	Shape** shapeList = new Shape*[N_SCENE_OBJECTS];

	//TODO: Compl�ter les vecteurs des constructeurs de qu1, qu2, qu3 qu4, qu5

	//Fond de la bo�te (blanc)
	Shape* qu1 = new Box(Material(255,255,255,0), 
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH), 
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[0] = qu1;

	//C�t� droit de la bo�te (noir)
	Shape* qu2 = new Box(Material(0, 0, 0, 0),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_), 
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[1] = qu2;

	//C�t� gauche de la bo�te (noir)
	Shape* qu3 = new Box(Material(0, 0, 0, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[2] = qu3;

	//Haut de la bo�te (blanc)
	Shape* qu4 = new Box(Material(255, 255, 255, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ ),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ + SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[3] = qu4;

	//Bas de la bo�te (blanc)
	Shape* qu5 = new Box(Material(255, 255, 255, 0),
		Vector3f(mainCamera.position_.x_ - SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_),
		Vector3f(mainCamera.position_.x_ + SCENE_WIDTH / 2, mainCamera.position_.y_ - SCENE_HEIGHT / 2, mainCamera.position_.z_ + SCENE_DEPTH));
	shapeList[4] = qu5;



	//Step 3 : Creation des objets 3D




	//Step 4 : Cr�ation de la sc�ne
	Scene mainScene = Scene(mainCamera, shapeList, Vector3f(0, SCENE_HEIGHT/2 - 0.01, SCENE_DEPTH/2));
	mainScene.render(SCREEN_WIDTH, SCREEN_HEIGHT, "newFile", mainCamera);

	std::cout << "Program end" << std::endl;
	std::getchar();
	return 0;
}
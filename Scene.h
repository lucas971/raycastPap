#pragma once
#ifndef HEADER_SCENE_H
#define HEADER_SCENE_H

/*!
 * \file Scene.h
 * \brief La scene
 * \author BARBARROUX-RIOUST
 */

#include "Camera.h"
#include "Shape.h"

/*! \class Scene
 * \brief classe representant la scene 
 *
 * La classe gere les objets de la scene et l'image obtenue via la camera
 */
class Scene {
public:
	Camera camera_;
	Shape** shapes_;
	Vector3f source_;

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Scene
	 * La scene comprend la camera, les objets 3D et la source de lumiere
	 *
	 * \param camera : camera regardant la scene
	 * \param shapes_ : ensemble des formes 3D present dans la scene
	 * \param source : source de lumiere de la scene
	 *
	 */
	Scene(Camera camera, Shape** shapes_, Vector3f source);

	/*!
     * \brief Image de la scene
     *
     * Cree une image de la scene vu par la camera
     *
     * \param width : largeur de l'image
     * \param height : hauteur de l'image
     * \param filename : nom du fichier dans lequelle l'image est sauvegardee
	 * \param mainCamera : camera regardant la scene 
	 *
	 */
	void render(int width, int height, char* filename, Camera mainCamera);
};

#endif // !HEADER_SCENE_H

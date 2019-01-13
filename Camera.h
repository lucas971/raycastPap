#pragma once
#ifndef HEADER_CAMERA_H
#define HEADER_CAMERA_H

/*!
 * \file Camera.h
 * \brief Camera regardant la scene
 * \author BARBARROUX-RIOUST
 *
 */

#include "Vector3f.h"

/*! \class Camera
 * \brief classe representant la camera par laquelle on regarde la scene
 *
 */

class Camera {
public:
	Vector3f position_;
	Vector3f direction_;

	/*!
	 * \brief Constructeur defaut
	 *
	 * Constructeur par defaut de la classe Camera
	 * 
	 */

	Camera();

	/*!
	 * \brief Constructeur 
	 *
	 * Constructeur de la classe Camera
	 *
	 * \param position : vecteur representant la postion de la camera
	 * \param direction : vecteur representant la direction de la camera
	 *
	 */
	Camera(Vector3f const & position, Vector3f const & direction);
};
#endif // !HEADER_CAMERA_H

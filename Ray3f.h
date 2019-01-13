#pragma once
#ifndef HEADER_RAY3F_H
#define HEADER_RAY3F_H

 /*!
  * \file Ray3f.h
  * \brief Un rayon
  * \author BARBARROUX-RIOUST
  */

#include "Vector3f.h"

class Ray3f {
public:
	Vector3f origin_;
	Vector3f direction_;
	Vector3f invdir_;
	int sign_[3];

	/*!
	 * \brief Constructeur defaut
	 *
	 * Constructeur par defaut de la classe Ray3f.
	 *
	 */
	Ray3f();

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Ray3f.
	 *
	 * \param origin : l'origine du rayon 
	 * \param direction : direction du rayon
	 *
	 */
	Ray3f(Vector3f const & origin, Vector3f const & direction);
};
#endif // !HEADER_RAY3F_H

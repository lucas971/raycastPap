#pragma once
#ifndef HEADER_SHAPE_H
#define HEADER_SHAPE_H

/*!
 * \file Shape.h
 * \brief Objet 3D
 * \author BARBARROUX-RIOUST
 *
 */

#include "Material.h"
#include "Ray3f.h"

/*! \class Shape
 * \brief classe representant un objet 3D
 *
 * La classe gere l'interaction de l'objet 3D avec les rayons
 */
class Shape {
public:
	Material mat_;

	/*!
  	 * \brief Test collision
	 *
	 * Test si le rayon ray intersecte l'objet 3D
	 *
	 * \param ray : le rayon
	 * \param hitDistance : la distance parcourue par le rayon
	 *
	 * \return true si l'objet 3D est touche par le rayon ray
	 */
	virtual bool is_hit(Ray3f const & ray, double & hitDistance) = 0;

	/*!
	 * \brief Rayon reflechi
	 *
	 * Renvoie le rayon reflechi par la collision avec l'objet 3D
	 *
	 * \param ray : le rayon
	 * \param hitPosition : la positon de la collision
	 *
	 * \return le rayon reflechi par l'objet 3D
	 */
	virtual Ray3f reflect(Ray3f const & ray, Vector3f const & hitPosition) = 0;

	/*!
	 * \brief Position de collision
	 *
	 * Calcule la postion de l'impact du rayon sur l'objet 3D
	 *
	 * \param ray : le rayon
	 * \param hitDistance : la distance de parcours du rayon
	 *
	 * \return la position de la collision du rayon sur l'objet 3D
	 */
	virtual Vector3f impactPosition(Ray3f const & ray, double hitDistance) = 0;

};
#endif // !HEADER_SHAPE_H

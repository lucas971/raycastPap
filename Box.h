#pragma once
#ifndef HEADER_QUAD_H
#define HEADER_QUAD_H

/*!
 * \file Box.h
 * \brief Quadrilatere 3D
 * \author BARBARROUX-RIOUST
 *
 */

#include "Vector3f.h"
#include "Shape.h"

/*! \class Box
 * \brief classe representant un quadrilatere 
 *
 * La classe gere l'interaction du quadrilatere avec les rayons
 */

class Box : public Shape{
public:
	Vector3f origin_;
	Vector3f minBound_;
	Vector3f maxBound_;

	/*!
	 * \brief Constructeur
	 * 
	 * Constructeur de la classe Box. 
	 * Le quadrilatere s'etend de x_min a x_max, de y_min a y_max et de z_min a z_max.
	 *
	 * \param mat : le material utilise pour le quadrilatere
	 * \param minBound : vecteur contenant les minimums (x_min, y_min, z_min)
	 * \param maxBound : vecteur contenant les maximums (x_max, y_max, z_max)
	 * 
	 */
	Box(Material const & mat, Vector3f const & minBound, Vector3f const & maxBound);

	/*!
	 * \brief Test collision
	 *
	 * Test si le rayon ray intersecte le quadrilatere
	 * 
	 * \param ray : le rayon
	 * \param hitDistance : la distance parcourue par le rayon 
	 *
	 * \return true si le quadrilatere est touche par le rayon ray 
	 */
	bool is_hit(Ray3f const & ray, double & hitDistance) override;

	/*!
	 * \brief Rayon reflechi
	 *
	 * Renvoie le rayon reflechi par la collision avec le quadrilatere
	 *
	 * \param ray : le rayon
	 * \param hitPosition : la positon de la collision
	 *
	 * \return le rayon reflechi par le quadrilatere
	 */
	Ray3f reflect(Ray3f const & ray, Vector3f const & hitPosition) override;

	/*!
	 * \brief Position de collision
	 *
	 * Calcule la postion de l'impact du rayon sur le quadrilatere
	 *
	 * \param ray : le rayon
	 * \param hitDistance : la distance de parcours du rayon
	 *
	 * \return la position de la collision du rayon sur le quadrilatere 
	 */
	Vector3f impactPosition(Ray3f const & ray, double hitDistance) override;
	
};
#endif // !HEADER_QUAD_H

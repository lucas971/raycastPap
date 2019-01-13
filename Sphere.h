#pragma once
#ifndef HEADER_SPHERE_H
#define HEADER_SPHERE_H

/*!
 * \file Sphere.h
 * \brief Sphere 3D
 * \author BARBARROUX-RIOUST
 *
 */

#include "Vector3f.h"
#include "Shape.h"

/*! \class Sphere
 * \brief classe representant une sphere
 *
 * La classe gere l'interaction dela sphere avec les rayons
 */
class Sphere : public Shape {
public:
	Vector3f origin_;
	float radius_;
	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Sphere
	 *
	 * \param mat : le materiel utilise pour la sphere
	 * \param origin : le centre de la sphere
	 * \param radius : le rayon de la sphere
	 *
	 */
	Sphere(Material const & mat, Vector3f const & origin, float radius);


	/*!
	 * \brief Test collision
	 *
	 * Test si le rayon ray intersecte la sphere
	 *
	 * \param ray : le rayon
	 * \param hitDistance : la distance parcourue par le rayon
	 *
	 * \return true si la sphere est touche par le rayon ray, false sinon
	 */
	bool is_hit(Ray3f const & ray, double & hitDistance) override;

	/*!
	 * \brief Rayon reflechi
	 *
	 * Renvoie le rayon reflechi par la collision avec la  sphere
	 *
	 * \param ray : le rayon
	 * \param hitPosition : la positon de la collision
	 *
	 * \return le rayon reflechi par la sphere
	 */
	Ray3f reflect(Ray3f const & ray, Vector3f const & hitPosition) override;

	/*!
	 * \brief Position de collision
	 *
	 * Calcule la postion de l'impact du rayon sur la sphere
	 *
	 * \param ray : le rayon
	 * \param hitDistance : la distance de parcours du rayon
	 *
	 * \return la position de la collision du rayon sur la sphere
	 */
	Vector3f impactPosition(Ray3f const & ray, double hitDistance) override;

};
#endif // !HEADER_SPHERE_H

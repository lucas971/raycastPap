#pragma once
#ifndef HEADER_VECTOR3F_H
#define HEADER_VECTOR3F_H

/*!
 * \file Vector3f.h
 * \brief Vecteur 3D de float
 * \author BARBARROUX-RIOUST
 *
 */


/*! \class Vector3f
 * \brief classe representant un vecteur 3D de float
 *
 * La classe gere les operations liees au vecteur
 */
class Vector3f {
public:
	double x_;
	double y_;
	double z_;
	/*!
	 * \brief Constructeur defaut
	 *
	 * Constructeur par defaut de la classe Vecteur3f (valeurs nulles par defaut)
	 *
	 */
	Vector3f();

	/*!
	 * \brief Constructeur 
	 *
	 * Constructeur par de la classe Vecteur3f 
	 *
	 * \param x : composante x du vecteur
	 * \param y : composante y du vecteur
	 * \param z : composante z du vecteur
	 *
	 */
	Vector3f(double x, double y, double z);

	/*!
	 * \brief Distance
	 *
	 * Distance entre deux vecteurs
	 *
	 * \param v : vecteur distant 
	 *
	 * \return la distance entre les deux vecteurs
	 *
	 */
	double dist(Vector3f v);


	/*!
	 * \brief Norme
	 *
	 * La norme du vecteur
	 *
	 * \return la norme du vecteur
	 *
	 */
	double norm() const;

	/*!
	 * \brief Normalise
	 *
	 * Normalise le vecteur
	 *
	 * \return le vecteur normalise
	 *
	 */
	Vector3f normalize() const;

		
	/*!
	 * \brief Operateur + 
	 *
	 * Surcharge l'operateur + pour l'addition de deux vecteurs
	 *
	 * \param v : un vecteur
	 *
	 * \return la somme des deux vecteurs
	 *
	 */
	Vector3f operator + (Vector3f const & v);

	/*!
	 * \brief Operateur -
	 *
	 * Surcharge l'operateur - pour la différence de deux vecteurs
	 *
	 * \param v : un vecteur
	 *
	 * \return la différence des deux vecteurs
	 *
	 */
	Vector3f operator - (Vector3f  const & v);

	/*!
	 * \brief Operateur *
	 *
	 * Surcharge l'operateur * pour le produit scalaire de deux vecteurs
	 *
	 * \param v : un vecteur
	 *
	 * \return le produit scalaire de deux vecteurs
	 *
	 */
	double operator * (Vector3f const & v);

	/*!
	 * \brief Operateur *
	 *
	 * Surcharge l'operateur * pour le produit d'un scalair et d'un vecteur
	 *
	 * \param d : un scalair
	 *
	 * \return le produit du scalair et du vecteur
	 *
	 */
	Vector3f operator * (double d);
	
};
#endif // !HEADER_VECTOR3F_H

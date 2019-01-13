#pragma once
#ifndef HEADER_MATERIAL_H
#define HEADER_MATERIAL_H


/*!
 * \file Material.h
 * \brief Materiel d'un objet 3D
 * \author BARBARROUX-RIOUST
 */

/*! \class Material
 * \brief Couleur et luminosite d'un objet
 *
 */
class Material {
public:
	float r_;
	float g_;
	float b_;
	float shininess_;

	/*!
	 * \brief Constructeur par defaut
	 *
	 * Constructeur par defaut de la classe Material (parametres nuls par defaut)
	 * 
	 *
	 */
	Material();

	/*!
	 * \brief Constructeur
	 *
	 * Constructeur de la classe Material
	 *
	 * \param r : de 0 à 255, determine l'intensite de rouge
	 * \param g : de 0 à 255, determine l'intensite de vert
	 * \param b : de 0 à 255, determine l'intensite de bleu
	 * \param shininess : de 0 à 1, determine l'intensite de la luminosite
	 *
	 */
	Material(float r, float g, float b, float shininess);
};
#endif // !HEADER_MATERIAL_H

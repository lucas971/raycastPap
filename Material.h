#pragma once
#ifndef HEADER_MATERIAL_H
#define HEADER_MATERIAL_H

class Material {
public:
	float r_;
	float g_;
	float b_;
	float shininess_;
	Material();
	Material(float r, float g, float b, float shininess);
};
#endif // !HEADER_MATERIAL_H

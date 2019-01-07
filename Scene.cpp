#define _CRT_SECURE_NO_DEPRECATE
#include "Scene.h"
#include "Constantes.h"
#include "include/png.h"
#include "include/zlib.h"
#include <cstdio>
#include <iostream>

Scene::Scene(Camera camera, Shape ** shapes, Vector3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

void Scene::render(int width, int height, char * filename, Camera mainCamera)
{

	FILE *fp = fopen(filename, "wb");
	if (!fp) {
		std::cout << "ERROR file open" << std::endl;
	}

	std::cout << "File successfully opened" << std::endl;

	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "Could not allocate write struct\n");
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "Could not allocate info struct\n");
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
		8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
		PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Set title
	png_text title_text;
	title_text.compression = PNG_TEXT_COMPRESSION_NONE;
	title_text.text = filename;
	png_set_text(png_ptr, info_ptr, &title_text, 0);

	png_write_info(png_ptr, info_ptr);


	// Allocate memory for one row (3 bytes per pixel - RGB)
	row = (png_bytep)png_malloc(png_ptr, 3 * width * sizeof(png_byte));
	
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++) {
			double r = 0;
			double g = 0;
			double b = 0;
			double n = 0;
			double s = 0;
			Vector3f impactPosition;
			int hitIndex = -1;
			double reflected = 0;
			Ray3f ray;
			double hitDistance = -1;
			Material mat;
			int lightHitIndex;

			while (n==0 || s!=0){
				if (n == 0)
					ray = Ray3f(mainCamera.position_, (mainCamera.direction_ + Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * (VIEW_ANGLE_HORIZONTAL / width), +VIEW_ANGLE_VERTICAL / 2 - i * (VIEW_ANGLE_VERTICAL / height), 0)).normalize());
				else {
					ray = shapes_[hitIndex]->reflect(ray, impactPosition);
					reflected++;
				}
			
				n++;

				for (int k = 0; k < N_SCENE_OBJECTS; k++) {
					double tmpHitDistance;
					if (k != hitIndex) {
						if (shapes_[k]->is_hit(ray, tmpHitDistance)) {
							if (k == 7) {
								std::cout << "ça a touche le mur derriere la camera" << std::endl;
							}
							if (hitDistance < 0 || hitDistance > tmpHitDistance) {
								hitIndex = k;
								hitDistance = tmpHitDistance;
							}
						}
					}
				}

				impactPosition = shapes_[hitIndex]->impactPosition(ray, hitDistance);

				mat = shapes_[hitIndex]->mat_;
				r += mat.r_ * (1 - mat.shininess_);
				g += mat.g_ * (1 - mat.shininess_);
				b += mat.b_ * (1 - mat.shininess_);
				s = mat.shininess_;
			}
			
			r = r / n;
			g = g / n;
			b = b / n;
			//TODO : Calculs liés à la source de lumière
			
			
			lightHitIndex = hitIndex;
			Ray3f lightRay = Ray3f(source_, (impactPosition - source_).normalize());
			hitDistance = -1;

			
			for (int k = 0; k < N_SCENE_OBJECTS; k++) {
				double tmpHitDistance;
				if (shapes_[k]->is_hit(lightRay, tmpHitDistance)) {
					if (hitDistance < 0 || hitDistance > tmpHitDistance) {
						lightHitIndex = k;
						hitDistance = tmpHitDistance;
					}
				}
			}
			
			double lightStrenght;
			if (lightHitIndex != hitIndex) {
				lightStrenght = 0;
			}
			else if (hitDistance > 10)
				lightStrenght = .5 + 5 / hitDistance;
			else
				lightStrenght = 1;
			
			
			//TODO : ecriture sur un fichier avec libpng en utilisant la couleur du materiel mat pour le pixel numero j de la ligne numero i de l'écran.
			row[j * 3] = r * lightStrenght;
			row[j * 3 + 1] = g * lightStrenght;
			row[j * 3 + 2] = b * lightStrenght;
		}

		png_write_row(png_ptr, row);
	}
	
	png_write_end(png_ptr, NULL);
}

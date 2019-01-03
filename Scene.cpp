#include "Scene.h"
#include "Constantes.h"
#include <iostream>
#include <png.h>
#include <zlib.h>


Scene::Scene(Camera camera, Shape ** shapes, Vector3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

void Scene::render(int width, int height, const char * filename, Camera mainCamera)
{
	int hit[6];
	hit[0] = 0, hit[1] = 0, hit[2] = 0, hit[3] = 0, hit[4] = 0, hit[5] = 0;

	/*Création du fichier - Pierrick*/

	/* Partie 4.1 de la doc : Setup*/

	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_byte** row_pointers;

	FILE *fp = fopen(filename, "wb");
	if (!fp) {
		std::cout << "ERROR file open" << std::endl;

	}

	row_pointers = (png_bytepp)malloc(height * sizeof(png_bytep));
	
	
	/*row_pointers = png_malloc(png_ptr, height*png_sizeof(png_bytep));*/
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		std::cout << "ERROR png_ptr" << std::endl;
		return;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		std::cout << "ERROR info_ptr" << std::endl;
		return;
	}

	if (setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		fclose(fp);
		std::cout << "ERROR set jump" << std::endl;
		return;
	}

	png_init_io(png_ptr, fp);



	/*Partie 4.2 de la doc -> pas faite car pas besoin*/

	/*Partie 4.3 de la doc : */


	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	//row_pointers = png_malloc(png_ptr, height * sizeof(png_bytep));
	
	for (int i = 0; i < height; i++){

		/*png_byte* row[width];
		row_pointers[i] = row;*/

		//row_pointers[i] = png_malloc(png_ptr, width * sizeof(Material));
		row_pointers[i] = (png_bytep)malloc(3*width * sizeof(png_byte));

		for (int j = 0; j < width; j++) {
			double r = 0;
			double g = 0;
			double b = 0;
			double n = 0;
			double s = 0;
			Vector3f impactPosition;
			int hitIndex;
			Ray3f ray;
			double hitDistance = -1;
			Material mat;
			int lightHitIndex;

			while (n==0 || s!=0){
				if (n == 0)
					ray = Ray3f(mainCamera.position_, (mainCamera.direction_ + Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * (VIEW_ANGLE_HORIZONTAL / width), -VIEW_ANGLE_VERTICAL / 2 + i * (VIEW_ANGLE_VERTICAL / height), 0)).normalize());
				else 
					ray = shapes_[hitIndex]->reflect(ray, impactPosition);
			
				n++;

				for (int k = 0; k < N_SCENE_OBJECTS; k++) {
					double tmpHitDistance;
					if (shapes_[k]->is_hit(ray, tmpHitDistance)) {
						if (hitDistance < 0 || hitDistance > tmpHitDistance) {
							hitIndex = k;
							hitDistance = tmpHitDistance;
						}
					}
				}
				hit[hitIndex] ++;
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
			
			
			/*
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
			*/
			//TODO : ecriture sur un fichier avec libpng en utilisant la couleur du materiel mat pour le pixel numero j de la ligne numero i de l'écran.
			row_pointers[i][j] = (char)floor(r);
			row_pointers[i][j+1] = (char)floor(g);
			row_pointers[i][j+2] = (char)floor(b);
		}
	}
	
	png_write_image(png_ptr, row_pointers);
	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	for (int y = 0; y < height; y++) {
		png_free(png_ptr, row_pointers[y]);
	}
	png_free(png_ptr, row_pointers);

	for (int i = 0; i < N_SCENE_OBJECTS; i++) { //FOR STATISTIC PURPOSES
		std::cout << "N°" << i << " object touch % : " << (double)hit[i] / (double)(width*height) << std::endl;
	}
}

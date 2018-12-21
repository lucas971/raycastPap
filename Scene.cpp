#define _CRT_SECURE_NO_DEPRECATE
#include "Scene.h"
#include "Constantes.h"
#include "lpng1636/png.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

Scene::Scene(Camera camera, Shape ** shapes, Ray3f source)
{
	camera_ = camera, shapes_ = shapes, source_ = source;
}

void Scene::render(int width, int height, char * filename, Camera mainCamera)
{

	//Affichage graphique
	FILE * fp;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_byte ** row_pointers = NULL;
	/* "status" contains the return value of this function. At first
	it is set to a value which means 'failure'. When the routine
	has finished its work, it is set to a value which means
	'success'. */
	int status = -1;
	/* The following number is set by trial and error only. I cannot
	see where it it is documented in the libpng manual.
	*/
	int pixel_size = 4;
	int depth = 8;

	fp = fopen(filename, "wb");
	if (!fp) {
		goto fopen_failed;
	}

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		goto png_create_write_struct_failed;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		goto png_create_info_struct_failed;
	}
	/* Set up error handling. */

	if (setjmp(png_jmpbuf(png_ptr))) {
		goto png_failure;
	}

	/* Set image attributes. */

	png_set_IHDR(png_ptr,info_ptr,bitmap->width,bitmap->height,depth,PNG_COLOR_TYPE_RGBA,PNG_INTERLACE_NONE,PNG_COMPRESSION_TYPE_DEFAULT,PNG_FILTER_TYPE_DEFAULT);


	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Ray3f ray = Ray3f(mainCamera.position_, Vector3f(-VIEW_ANGLE_HORIZONTAL / 2 + j * (VIEW_ANGLE_HORIZONTAL / width), -VIEW_ANGLE_VERTICAL / 2 + i * (VIEW_ANGLE_VERTICAL / height), 0));

			int hitIndex;
			double hitDistance = -1;
			for (int k = 0; k < N_SCENE_OBJECTS; k++) {
				if (shapes_[k]->is_hit(ray)) {
					if (hitDistance < 0 || hitDistance > shapes_[k]->impactPosition(ray).dist(mainCamera.position_)) {
						hitIndex = k;
						hitDistance = shapes_[k]->impactPosition(ray).dist(mainCamera.position_);
					}
				}
			}
			if (hitDistance < 0)
				throw "One raycast didn't collide, the scene is incorrectly parametred.";

			Vector3f impactPosition = shapes_[hitIndex]->impactPosition(ray);

			//TODO Calculs liés à la source de lumière					}	}	/* Write the image data to "fp". */

	png_init_io(png_ptr, fp);
	png_set_rows(png_ptr, info_ptr, row_pointers);
	png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);

	/* The routine has successfully written the file, so we set
	"status" to a value which indicates success. */

	status = 0;

	for (y = 0; y < bitmap->height; y++) {
		png_free(png_ptr, row_pointers[y]);
	}
	png_free(png_ptr, row_pointers);

png_failure:
png_create_info_struct_failed:
	png_destroy_write_struct(&png_ptr, &info_ptr);
png_create_write_struct_failed:
	fclose(fp);
fopen_failed:
	return status;

}

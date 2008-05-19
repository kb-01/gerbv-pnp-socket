/*------------------------------------------------------------------------------
	Filename: example5.c
	
	Description: Demonstrate the basic drawing functions available in libgerbv
		by drawing a smiley face and exporting the layer to a new RS274X file.

	Instructions: Make sure you are in the example-code directory, and compile
		this program with the following command:

	gcc -Wall -g `pkg-config --cflags gtk+-2.0 glib-2.0 libgerbv` `pkg-config \
--libs gtk+-2.0 glib-2.0 libgerbv` example5.c -o example5

	Run with the following command:
	
	./example5

------------------------------------------------------------------------------*/

#include "gerbv.h"

int
main(int argc, char *argv[]) {
	gerbv_image_t *workingImage;
	
	/* create a new, blank, image */
	workingImage = gerbv_create_image(NULL, NULL);
	
	/* draw the nose */
	gerbv_image_create_line_object (workingImage, 1.5, 1.5, 1.6, 1.3, 0.020, CIRCLE);
	gerbv_image_create_line_object (workingImage, 1.5, 1.5, 1.4, 1.3, 0.020, CIRCLE);
	gerbv_image_create_line_object (workingImage, 1.4, 1.3, 1.6, 1.3, 0.020, CIRCLE);
	
	/* draw the eyes */
	gerbv_image_create_arc_object (workingImage, 1, 2, 0.1, 0, 360, 0.020, CIRCLE);
	gerbv_image_create_arc_object (workingImage, 2, 2, 0.1, 0, 360, 0.020, CIRCLE);
	
	/* draw the mouth */
	gerbv_image_create_arc_object (workingImage, 1.5, 1.5, 0.75, -30, -150, 0.20, CIRCLE);
	
	/* draw the head */
	gerbv_image_create_arc_object (workingImage, 1.5, 1.5, 1.5, 0, 360, 0.02, CIRCLE);
	
	/* draw the ears */
	gerbv_image_create_rectangle_object (workingImage, -0.2, 1.3, 0.2, 0.4);
	gerbv_image_create_rectangle_object (workingImage, 3, 1.3, 0.2, 0.4);

	/* export the drawn image to a new rs274x file */
	gerbv_export_rs274x_file_from_image ("example5-output.gbx",	workingImage);

	/* destroy all created structures */
	gerbv_destroy_image (workingImage);
	return 0;
}

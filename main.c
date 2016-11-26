//Iarla Scaife 2016


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int width = 1000;
	int height = 1000;
	unsigned char* image_pixels = (unsigned char*)malloc(width * height * 3 * sizeof(unsigned char));
	memset(image_pixels, 255, 1000 * 1000 * 3);
	FILE *fptr = fopen("output.ppm", "w");
	fprintf(fptr, "P3\n#output.ppm\n%i %i\n255\n", width, height);

	{
		for (int row = 0; row < height; row++) {
			for (int col = 0; col < width; col++) {
				image_pixels[(((1000 * row) + col) * 3)] = (col*row) / 1200;
				image_pixels[(((1000 * row) + col) * 3)+1] = floor(200*cos(col/(row+1)));
				image_pixels[(((1000 * row) + col) * 3) + 2] = floor(100/(sin(col/(row+1))));
			};
		};
	}

	{
		for (int x = 0; x < (height*width*3); x++) {
			fprintf(fptr, "%i ",
				image_pixels[x]


					);
		};
	}

	free(image_pixels);
	return 0;
}
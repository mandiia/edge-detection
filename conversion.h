#ifndef CONVERSION_H
#define CONVERSION_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>

//void rgb_to_grayscale(unsigned char* input_image, unsigned char* output_image, int width, int height);

int perform_to8bit_conversion(const char* input_filename, const char* output_filename);

int perform_BWconversion(const char* input_filename, const char* output_filename);

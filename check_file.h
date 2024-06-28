#ifndef CHECK_FILE_H
#define CHECK_FILE_H
#include <stdio.h>

// Functions to check if the image is 8-bit and grayscale
int is_8bit(const char* filename);
int is_grayscale(const char* filename);

#endif // CHECK_FILE_H
#ifndef _SOBEL_EDGE_DETECTION_H
#define _SOBEL_EDGE_DETECTION_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>


// Function to apply Sobel operator for edge detection
void sobelEdgeDetection(unsigned char* input_image, unsigned char* output_image, int width, int height);
  
//Function which applies Sobel operator on an image and returns output BMP file
int SOBEL_performEdgeDetection(const char* input_filename, const char* output_filename);


#endif // _SOBEL_EDGE_DETECTION_H
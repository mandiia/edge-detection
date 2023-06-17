#include <math.h>
#include "sobel_kernel.h"

// Function to apply Sobel operator for edge detection
void sobelEdgeDetection(unsigned char* input_image, unsigned char* output_image, int width, int height) {
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int gx = 0, gy = 0;
            int magnitude = 0;

            // Convolve the image with the Sobel kernels
            for (int j = -1; j <= 1; j++) {
                for (int i = -1; i <= 1; i++) {
                    int pixel = input_image[(y + j) * width + (x + i)];
                    gx += sobelX[j + 1][i + 1] * pixel;
                    gy += sobelY[j + 1][i + 1] * pixel;
                }
            }

            // Calculate the magnitude of the gradient
            magnitude = sqrt(gx * gx + gy * gy);
           
            //Normalize the gradient magnitude to 0 - 255 range
            magnitude = (magnitude > 255) ? 255 : magnitude;
           
            //Apply an adaptive treshold based on local pixel intensity
            int treshold = (int)round(0.998* magnitude); //Adjust the factor as desired
           
            // Threshold the gradient to create the edge-detected image
            output_image[y * width + x] = (magnitude > treshold) ? 255 : 0;
        }
    }
}
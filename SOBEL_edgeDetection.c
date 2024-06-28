#include "SOBEL_edgeDetection.h"
#include "sobel_kernel.h"

void sobelEdgeDetection(unsigned char* input_image, unsigned char* output_image, int width, int height) {
    float tr;
    printf("Enter the desired treshold for edge detection: ");
    scanf("%f", &tr);
    while (tr < 0 || tr > 1) { 
        printf("Treshold value is not valid. Value must be between 0 and 1. Please enter a new value: \n");
        scanf("%f", &tr);
    }
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
           
            //Apply an adaptive threshold based on local pixel intensity
            int treshold = (int)round(tr * magnitude); //Adjust the factor as desired
           
            // Threshold the gradient to create the edge-detected image
            output_image[y * width + x] = (magnitude > treshold) ? 255 : 0;
        }
    }
}

int SOBEL_performEdgeDetection(const char* input_filename, const char* output_filename) {
    // Open the input BMP file in binary mode
     FILE* input_file = fopen(input_filename, "rb");
     
     // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, input_file);
   
    // Extract image dimensions from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the padding size
    int padding = (4 - (width * sizeof(unsigned char)) % 4) % 4;

    // Allocate memory for the input and output image data
    unsigned char* input_image = (unsigned char*)malloc((width + padding) * height * sizeof(unsigned char));
    unsigned char* output_image = (unsigned char*)malloc((width + padding) * height * sizeof(unsigned char));
   
     // Read the input image data (including padding)
    fread(input_image, sizeof(unsigned char), (width + padding) * height, input_file);

    // Close the input file
    fclose(input_file);

    // Perform edge detection using the Sobel operator
    sobelEdgeDetection(input_image, output_image, width, height);
   
    // Create the output BMP file
    FILE* output_file = fopen(output_filename, "wb");
    if (!output_file) {
        printf("Error creating output file: %s\n", output_filename);
        free(input_image);
        free(output_image);
        return 0;
    }

    // Write the BMP header to the output file
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // Write the output image data (including padding) to the output file
    fwrite(output_image, sizeof(unsigned char), (width + padding) * height, output_file);

    // Close the output file
    fclose(output_file);

    //printf("Edge detection completed. Output image saved as %s\n", output_filename);

    // Free the allocated memory
    free(input_image);
    free(output_image);

    return 1;
}
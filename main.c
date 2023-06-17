#include <stdlib.h>
#include "check_file.h"
#include "sobel_operator.h"

int main() {
const char* input_filename = "lena_gray.bmp";
    const char* output_filename = "lena_output_0998.bmp";
   
    int check = is_8bit_grayscale(input_filename);
   
    if(!check) {
    printf("Edge detection is not possible.\n");
    return 0;
    }
   
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
        return 1;
    }

    // Write the BMP header to the output file
    fwrite(header, sizeof(unsigned char), 54, output_file);

    // Write the output image data (including padding) to the output file
    fwrite(output_image, sizeof(unsigned char), (width + padding) * height, output_file);

    // Close the output file
    fclose(output_file);

    printf("Edge detection completed. Output image saved as %s\n", output_filename);

    // Free the allocated memory
    free(input_image);
    free(output_image);

    return 0;
   
} 
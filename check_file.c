#include "check_file.h"

int is_8bit_grayscale(const char* filename) {
// Open the BMP file in binary mode
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return 0; //Return 0 for file open error
    }
   
    // Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

// Check if the image is 8-bit
    if (header[28] != 8) {
        printf("The image is not 8-bit\n");
        fclose(file);
        return 0; //Return 0 if not 8-bit
    }
   
    // Check if the image is grayscale
    int colorTableSize = *(int*)&header[46];
    if (colorTableSize != 0) {
        printf("The image is not grayscale\n");
        fclose(file);
        return 0; //Return 0 if not grayscale
    }
   
    printf("The image is 8-bit grayscale\n");

    fclose(file);
    return 1;
}
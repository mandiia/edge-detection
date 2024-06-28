#include "check_file.h"

int is_8bit(const char* filename) {
// Open the BMP file in binary mode
    FILE* file;
    file = fopen(filename, "rb");

// Check if the file was opened successfully -trebala bi biti greska ali nije 
    if (file == NULL) { // MISRA C:2012 Rule 14.1 - Conversions shall not be performed between a pointer to a FILE and any other type
        printf("Error opening file: %s\n", filename);
        return 0; // Return 0 if file opening fails
    }
   
// Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

// Check if the image is 8-bit
    printf("Header[28] value is %d\n", header[28]);
    if (header[28] != 8) {
        printf("The image is not 8-bit\n");
        fclose(file);
        return 0; //Return 0 if not 8-bit 
     } 

    printf("The image is 8-bit.\n");
    fclose(file);
    
    return 1;
}

int is_grayscale(const char* filename) {
 // Open the BMP file in binary mode
    FILE* file = fopen(filename, "rb");

// Read the BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int colorTableSize = *(int*)&header[46];
    printf("Color Table size: %d \n", colorTableSize);
    if (colorTableSize != 0) {
        printf("The image is not grayscale\n");
        fclose(file);
        return 0; //Return 0 if not grayscale
    } 

    printf("The image is grayscale.\n");
    fclose(file);

    return 1;
}
#include "conversion.h"

int perform_to8bit_conversion(const char* input_filename, const char* output_filename)
{

}

// void rgb_to_grayscale(unsigned char* input_image, unsigned char* output_image, int width, int height) ovo je rezerva
// {
//        int imgSize = width*height;
//        unsigned char buffer[imgSize][3]; 
//        for(int i=0; i<imgSize; i++) {
//            int y = 0;
//            buffer[i][2] = getc(input_image);                   //blue
//            buffer[i][1] = getc(input_image);                   //green
//            buffer[i][0] = getc(input_image);                   //red

//             y = (buffer[i][0]*0.3) + (buffer[i][1]*0.59) + (buffer[i][2]*0.11); //conversion formula of rgb to gray

//             putc(y,output_image);
//             putc(y,output_image);
//             putc(y,output_image);
//        }


        // for (int y = 0; y < height; y++) {
        //     for (int x = 0; x < width; x++) {
        //          unsigned char r = input_image[4 * (y * width + x)];     // Red channel
        //          unsigned char g = input_image[4 * (y * width + x) + 1]; // Green channel
        //          unsigned char b = input_image[4 * (y * width + x) + 2]; // Blue channel
            
        //     // Convert RGB to grayscale using the formula: Y = 0.299R + 0.587G + 0.114B
        //     output_image[y * width + x] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
       
       
        // for (int i = 0; i < height*width; i+=3) { -beric
        // int r = input_image[i];                           // Red channel
        // int g = input_image[i + 1];          // Green channel
        // int b = input_image[i + 2];      // Blue channel

        // // Convert RGB to grayscale using the formula: Y = 0.299R + 0.587G + 0.114B
        // output_image[i] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
        //}
    //}
    // for (int i = 0; i < height*width; ++i) { -najbolji prolaz za sad
    //     int r = input_image[i];                           // Red channel
    //     int g = input_image[i + width * height];          // Green channel
    //     int b = input_image[i + 2 * width * height];      // Blue channel

    //     // Convert RGB to grayscale using the formula: Y = 0.299R + 0.587G + 0.114B
    //     output_image[i] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
    // }
//}

// int perform_BWconversion(const char* input_filename, const char* output_filename) ovu sam ostavila 
// {
//     //Open the imput BMP file in binary mode
//     FILE* input_file = fopen(input_filename, "rb");
//      if (!input_file) {
//         printf("Error opening input file: %s\n", input_filename);
//         return 0;
//     }
    
//     // Read the BMP header
//     unsigned char header[54];
//     fread(header, sizeof(unsigned char), 54, input_file);   

//     //int bitDepth = *(int*)&header[28];

//     // Extract image dimensions from the header
//     int width = *(int*)&header[18];
//     int height = abs(*(int*)&header[22]);
//     int bitDepth = *(int*)&header[28];

//     printf("width: %d\n", width);
//     printf("height: %d\n", height);
//     printf("bitDepth: %d\n", bitDepth);

//     // Calculate the padding size
//     int padding = (4 - (width * sizeof(unsigned char)) % 4) % 4;
//     printf("padding: %d\n", padding);


//     // Allocate memory for the input and output image data - staro
//     // unsigned char* input_image = (unsigned char*)malloc((width + padding) * height * sizeof(unsigned char));
//     // unsigned char* output_image = (unsigned char*)malloc((width + padding) * height * sizeof(unsigned char));

//      // Allocate memory for the input RGB image data - novo
//     unsigned char* input_image = (unsigned char*)malloc((width * 3 + padding) * height * sizeof(unsigned char));
//     if (!input_image) {
//         printf("Error allocating memory for input image\n");
//         fclose(input_file);
//         return 0;
//     }
   
//     //  // Read the input image data (including padding) - staro
//     // fread(input_image, sizeof(unsigned char), (width + padding) * height, input_file);

//      // Read the input image data (including padding) -novo
//     fread(input_image, sizeof(unsigned char), (width * 3 + padding) * height, input_file);


//     // Close the input file -staro
//     //fclose(input_file);

//       // Allocate memory for the output grayscale image data - novo
//     unsigned char* output_image = (unsigned char*)malloc(width * height * sizeof(unsigned char));
//     if (!output_image) {
//         printf("Error allocating memory for output image\n");
//         free(input_image);
//         return 0;
//     }

//     // Perform edge detection using the Sobel operator
//     //rgb_to_grayscale(input_image, output_image, width, height);

   
     
//      // Update header to reflect grayscale image (bit depth = 8) - novo
//     header[28] = 8;
   
//     // Create the output BMP file
//     FILE* output_file = fopen(output_filename, "wb");
//     if (!output_file) {
//         printf("Error creating output file: %s\n", output_filename);
//         free(input_image);
//         free(output_image);
//         return 0;
//     }

//      int imgSize = width*height; //novo
//        unsigned char buffer[imgSize][3]; 
//        for(int i=0; i<imgSize; i++) {
//            int y = 0;
//            buffer[i][2] = getc(input_file);                   //blue
//            buffer[i][1] = getc(input_file);                   //green
//            buffer[i][0] = getc(input_file);                   //red

//             y = (buffer[i][0]*0.3) + (buffer[i][1]*0.59) + (buffer[i][2]*0.11); //conversion formula of rgb to gray

//             putc(y,output_file);
//             putc(y,output_file);
//             putc(y,output_file);
//        }


//     // Write the BMP header to the output file
//     fwrite(header, sizeof(unsigned char), 54, output_file);

//     // // Write the output image data (including padding) to the output file - staro
//     // fwrite(output_image, sizeof(unsigned char), (width + padding) * height, output_file);

//     // Write the output image data (excluding padding) to the output file - novo
//     fwrite(output_image, sizeof(unsigned char), width * height, output_file);


//     // Close the input file -novo
//     fclose(input_file);

//     // Close the output file
//     fclose(output_file);

//     //printf("Edge detection completed. Output image saved as %s\n", output_filename);

//     // Free the allocated memory
//     free(input_image);
//     free(output_image);

//     printf("Grayscale conversion is done. Converted image is saved as %s. \n", output_filename);

//     return 1;

// }
    


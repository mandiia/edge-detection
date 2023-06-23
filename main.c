#include "check_file.h"
#include "SOBEL_edgeDetection.h"

int main() {
    const char* input_filename = "lena_gray.bmp";
    const char* output_filename = "lena_output_0998.bmp";
   
    int check = is_8bit_grayscale(input_filename);
   
    if(!check) {
    printf("Edge detection is not possible.\n");
    return 0;
    }
   
    int result = SOBEL_performEdgeDetection(input_filename, output_filename);

    if (!result) {
        printf("Edge detection failed./n");
        return 0;
    }

    printf("Edge detection completed. Output image saved as %s\n", output_filename);

    return 0;
} 
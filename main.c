#include "check_file.h"
#include "SOBEL_edgeDetection.h"
#include "conversion.h"

int main() {
    char input_filename[256];
    char output_filename[256] = "";
    char output_final_filename[256];

    printf("Enter the input filename: ");
    if(scanf("%255s", input_filename) != 1) {
        printf("Error reading input filename. \n");
        return 1;
    }

    FILE* file = fopen(input_filename, "rb");
    while (!file) {
        printf("Error opening file: '%s', please enter another file: \n", input_filename);
        scanf("%255s", input_filename);
        file = fopen(input_filename, "rb");
    }

    int check = is_8bit(input_filename);
    if(!check) { 
        printf("Edge detection is not possible because the image is not 8 bit. Please try with a different image.\n");
        return 0;
        //konverzija
    }

    check = is_grayscale(input_filename);
    if(!check)  {//ovdje gledaj sad konverziju
        printf("Edge detection is not possible, the image is not grayscale. Please do grayscale conversion.\n");
        printf("Enter the output filename: ");
        if(scanf("%255s", output_filename) != 1) {
             printf("Error reading output filename. \n");
        return 1;
        }
        perform_conversion(input_filename, output_filename);
        FILE* file = fopen(output_filename, "rb");
        while (!file) {
        printf("Error opening output file: '%s', please enter another file: \n", output_filename);
        scanf("%255s", output_filename);
        file = fopen(output_filename, "rb");
        }
        printf("Trebalo bi da je konverzija prosla.\n");
        return 1; // --ovo samo da testiram iskljucivo konverziju, obrisi kasnije
    } //skontati kako staviti da input filename varira u odnosu na to da li je GS check proslo 
    //ako je check == 1 onda je input input, inace je input output
    //a output je uvijek final output
    
    printf("Enter the final output filename: ");
    if (scanf("%255s", output_final_filename) !=1 ) {
        printf("That name could not be chosen. \n");
        return 1;
    }

    char name[256];
    if (check == 1)
        strcpy(name, input_filename);
    else
        strcpy(name, output_filename);

    //TODO: add conversion to grayscale - new file 
    //TODO: add conversion to 8bit ? - not here
    
    int result = SOBEL_performEdgeDetection(name, output_final_filename);

    FILE* file1 = fopen(output_final_filename, "rb");
    while (!file1) {
        printf("Error opening file: '%s', please enter another file: \n", output_final_filename);
        scanf("%255s", output_final_filename);
        file1 = fopen(output_final_filename, "rb");
    }

    if (!result) {
        printf("Edge detection failed./n");
        return 0;
    }

    printf("Edge detection completed. Output image saved as %s\n", output_final_filename);
 
    return 0;
} 
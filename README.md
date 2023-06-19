# edge-detection
Edge detection using Sobel operator 

In the repository, there are included three .h files (check_file, sobel_kernel and sobel_operator), one .c file (main) and resulting images of edge detection with different tresholds.

In the sobel_kernel.h file we have defined two 3x3 matrices which represent the kernels of the Sobel operator used for edge detection.

In the check_file.h the code checks the header of BMP image file to determineif it is an 8-bit grayscale image. It returns 1 if it is, and 0 otherwise.

In the sobel_operator.h file, we apply the Sobel operator to an input image to detect edges. It calculates the gradient magnitude, normalizes them, applies an adaptive treshold and returns the resulting edge-detected image as output.

And in the main.c is an example of a complete program that performs edge detection on a grayscale BMP image using the Sobel operator. The code loads an BMP image, checks if it is a grayscale format, then if it is, performs edge detection using the Sobel operator and saves the resulting edge-detected image to a new BMP file.



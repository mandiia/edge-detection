#ifndef SOBEL_KERNEL_H
#define SOBEL_KERNEL_H

// Define the Sobel operator kernels
const int sobelX[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

const int sobelY[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
};

#endif // SOBEL_KERNEL_H


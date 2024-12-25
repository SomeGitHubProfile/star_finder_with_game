#include "SobelFilter.h"

#include <cmath>

unsigned char clamp_sum(double sum) {
    if (sum < 0.0) {
        return 0;
    }
    if (sum > 255.0) {
        return 255;
    }
    return round(sum);
}

void get_3x3_kernels(unsigned char* shift, unsigned char* kernel_size, unsigned char*** horizontal_destination, unsigned char*** vertical_destination) {
    *shift = 1;
    *kernel_size = *shift * 2 + 1;
    const char horizontal_kernel[3][3] = {
        {+1, +2, +1},
        {+0, +0, +0},
        {-1, -2, -1}
    };
    const char vertical_kernel[3][3] = {
        {-1, +0, +1},
        {-2, +0, +2},
        {-1, +0, +1}
    };
    *horizontal_destination = new unsigned char*[*kernel_size];
    *vertical_destination = new unsigned char*[*kernel_size];
    for (int i = 0; i < *kernel_size; ++i) {
        (*horizontal_destination)[i] = new unsigned char[*kernel_size];
        (*vertical_destination)[i] = new unsigned char[*kernel_size];
        for (int j = 0; j < *kernel_size; ++j) {
            (*horizontal_destination)[i][j] = horizontal_kernel[i][j];
            (*vertical_destination)[i][j] = vertical_kernel[i][j];
        }
    }
    return;
}

void get_5x5_kernels(unsigned char* shift, unsigned char* kernel_size, unsigned char*** horizontal_destination, unsigned char*** vertical_destination) {
    *shift = 2;
    *kernel_size = *shift * 2 + 1;
    const char horizontal_kernel[5][5] = {
        {+2, +2, +4, +2, +2},
        {+1, +1, +2, +1, +1},
        {+0, +0, +0, +0, +0},
        {-1, -1, -2, -1, -1},
        {-2, -2, -4, -2, -2}
    };
    const char vertical_kernel[5][5] = {
        {+2, +1, 0, -1, -2},
        {+2, +1, 0, -1, -2},
        {+4, +2, 0, -2, -4},
        {+2, +1, 0, -1, -2},
        {+2, +1, 0, -1, -2}
    };
    *horizontal_destination = new unsigned char*[*kernel_size];
    *vertical_destination = new unsigned char*[*kernel_size];
    for (int i = 0; i < *kernel_size; ++i) {
        (*horizontal_destination)[i] = new unsigned char[*kernel_size];
        (*vertical_destination)[i] = new unsigned char[*kernel_size];
        for (int j = 0; j < *kernel_size; ++j) {
            (*horizontal_destination)[i][j] = horizontal_kernel[i][j];
            (*vertical_destination)[i][j] = vertical_kernel[i][j];
        }
    }
    return;
}

void get_kernels(unsigned char* shift, unsigned char* kernel_size, unsigned char*** horizontal_destination, unsigned char*** vertical_destination, filters::sobel::KernelTypes kernel_type) {
    switch (kernel_type) {
        case filters::sobel::KernelTypes::SobelKernel_3x3:
            get_3x3_kernels(shift, kernel_size, horizontal_destination, vertical_destination);
            break;
        case filters::sobel::KernelTypes::SobelKernel_5x5:
            get_5x5_kernels(shift, kernel_size, horizontal_destination, vertical_destination);
            break;
        default:
            get_5x5_kernels(shift, kernel_size, horizontal_destination, vertical_destination);
            break;
    }
    return;
}

void delete_kernels(unsigned char** horizontal_kernel, unsigned char** vertical_kernel, unsigned char kernel_size) {
    for (unsigned char i = 0; i < kernel_size; ++i) {
        delete[] horizontal_kernel[i];
        delete[] vertical_kernel[i];
    }
    delete[] horizontal_kernel;
    delete[] vertical_kernel;
    return;
}

images::GrayImage* filters::sobel::filter(images::GrayImage* source_image, KernelTypes kernel_type) noexcept {
    unsigned char shift, kernel_size;
    unsigned char** horizontal_kernel;
    unsigned char** vertical_kernel;
    get_kernels(&shift, &kernel_size, &horizontal_kernel, &vertical_kernel, kernel_type);
    images::GrayImage* image = new images::GrayImage(source_image->shape);
    for (unsigned x = shift; x < image->shape.x - shift; ++x) {
        for (unsigned y = shift; y < image->shape.y - shift; ++y) {
            int horizontal_sum = 0, vertical_sum = 0;
            for (int i = 0; i < kernel_size; ++i) {
                for (int j = 0; j < kernel_size; ++j) {
                    data_structures::Coordinates coordinates{x + i - shift, y + j - shift};
                    horizontal_sum += (*source_image)[coordinates].color * horizontal_kernel[i][j];
                    vertical_sum += (*source_image)[coordinates].color * vertical_kernel[i][j];
                }
            }
            data_structures::Coordinates coordinates{x, y};
            (*image)[coordinates] = pixels::GrayPixel(clamp_sum(sqrt(horizontal_sum * horizontal_sum + vertical_sum * vertical_sum)), (*source_image)[coordinates].alpha);
        }
    }
    return image;
}
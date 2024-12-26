#include "OperationSystem.h"

#include "../Dependencies/lodepng/lodepng.h"
#include "../Errors/Errors.h"

pixels::RGB_Pixel** decode_image(unsigned char* encoded_image, unsigned width, unsigned height) {
    pixels::RGB_Pixel** matrix = new pixels::RGB_Pixel * [width];
    for (unsigned x = 0; x < width; ++x) {
        matrix[x] = new pixels::RGB_Pixel[height];
    }
    for (size_t i = 0; i < width * height; ++i) {
        matrix[i % width][i / width] = pixels::RGB_Pixel(
            encoded_image[i * 4],
            encoded_image[i * 4 + 1],
            encoded_image[i * 4 + 2],
            encoded_image[i * 4 + 3]
        );
    }
    return matrix;
}

pixels::RGB_Pixel** operation_system::FileSystem::read_image(const char* path) const {
    unsigned char* encoded_image;
    unsigned error, width, height;
    error = lodepng_decode32_file(&encoded_image, &width, &height, path);
    if (error) {
        free(encoded_image);
        throw errors::FileLoadError("Lodepng: unable to decode file", path);
    }
    pixels::RGB_Pixel** decoded_image = decode_image(encoded_image, width, height);
    free(encoded_image);
    return decoded_image;
}

void delete_matrix(data_structures::Coordinates shape, pixels::RGB_Pixel** matrix) {
    for (size_t x = 0; x < shape.x; ++x) {
        delete[] matrix[x];
    }
    delete[] matrix;
}

unsigned char* encode_image(const images::Image* image) {
    unsigned char* encoded_image = new unsigned char[4 * image->shape.x * image->shape.y];
    for (int i = 0; i < image->shape.x * image->shape.y; ++i) {
        const pixels::Pixel* pixel = image->get_pixel({i % image->shape.x, i / image->shape.x});
        encoded_image[i * 4] = pixel->get_red();
        encoded_image[i * 4 + 1] = pixel->get_green();
        encoded_image[i * 4 + 2] = pixel->get_blue();
        encoded_image[i * 4 + 3] = pixel->alpha;
    }
    return encoded_image;
}

void operation_system::FileSystem::save_image(const char* path, const images::Image* image) const {
    unsigned char* encoded_image = encode_image(image);
    unsigned error = lodepng_encode32_file(path, encoded_image, image->shape.x, image->shape.y);
    delete[] encoded_image;
    if (error) {
        throw errors::FileSaveError("Lodepng: unable to save file", path);
    }
    return;
}
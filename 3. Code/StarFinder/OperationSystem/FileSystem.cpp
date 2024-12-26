#include "OperationSystem.h"

#include "../Dependencies/lodepng/lodepng.h"
#include "../Errors/Errors.h"

pixels::RGB_Pixel** decode_image(data_structures::Coordinates shape, unsigned char* encoded_image) {
    pixels::RGB_Pixel** matrix = new pixels::RGB_Pixel*[shape.x];
    for (unsigned x = 0; x < shape.x; ++x) {
        matrix[x] = new pixels::RGB_Pixel[shape.y];
    }
    for (size_t i = 0; i < shape.x * shape.y; ++i) {
        matrix[i % shape.x][i / shape.x] = pixels::RGB_Pixel(
            encoded_image[i * 4],
            encoded_image[i * 4 + 1],
            encoded_image[i * 4 + 2],
            encoded_image[i * 4 + 3]
        );
    }
    return matrix;
}

void delete_matrix(data_structures::Coordinates shape, pixels::RGB_Pixel** matrix) {
    for (size_t x = 0; x < shape.x; ++x) {
        delete[] matrix[x];
    }
    delete[] matrix;
    return;
}

images::RGB_ImageDto operation_system::FileSystem::read_image(const char* path) const {
    unsigned char* encoded_image;
    unsigned error, width, height;
    error = lodepng_decode32_file(&encoded_image, &width, &height, path);
    if (error) {
        free(encoded_image);
        throw errors::FileLoadError("Lodepng: unable to decode file", path);
    }
    data_structures::Coordinates shape{width, height};
    pixels::RGB_Pixel** decoded_image = decode_image(shape, encoded_image);
    free(encoded_image);
    images::RGB_ImageDto dto{shape, decoded_image};
    delete_matrix(shape, decoded_image);
    return dto;
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

//images::RGB_ImageDto* operation_system::FileSystem::test() const {
//    return nullptr;
//}
#include "BaseSourceImage.h"

model::base::BaseSourceImage::BaseSourceImage(const params::BaseSourceImageParams& _image_params)
    : image_params(_image_params),
    images::RGB_Image(_image_params.dto.shape),
    SourceImage(_image_params.dto.shape),
    images::Image(_image_params.dto.shape) {
    for (size_t x = 0; x < image_params.dto.shape.x; ++x) {
        for (size_t y = 0; y < image_params.dto.shape.y; ++y) {
            matrix[x][y] = image_params.dto.matrix[x][y];
        }
    }
}

void model::base::BaseSourceImage::outline_star(data_structures::Coordinates center) noexcept {
    return;
}

const pixels::Pixel* model::base::BaseSourceImage::get_pixel(data_structures::Coordinates coordinates) const {
    return matrix[coordinates.x] + coordinates.y;
}

images::Image* model::base::BaseSourceImage::outline_stars(Stars* stars) noexcept {
    images::RGB_Image* image = new images::RGB_Image(shape);
    for (size_t x = 0; x < shape.x; ++x) {
        for (size_t y = 0; y < shape.y; ++y) {
            
        }
    }
    return image;
}
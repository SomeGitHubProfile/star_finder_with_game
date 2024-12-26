#include "BaseSourceImage.h"

#include <iostream>

model::base::BaseSourceImage::BaseSourceImage(const params::BaseSourceImageParams& image_params)
    : images::RGB_Image(image_params.dto.shape),
    SourceImage(image_params.dto.shape),
    images::Image(image_params.dto.shape) {
    for (size_t x = 0; x < image_params.dto.shape.x; ++x) {
        for (size_t y = 0; y < image_params.dto.shape.y; ++y) {
            matrix[x][y] = image_params.dto.matrix[x][y];
        }
    }
}

void model::base::BaseSourceImage::outline_star(data_structures::Coordinates center) noexcept {
    std::cout << "Outlined\n";
}

const pixels::Pixel* model::base::BaseSourceImage::get_pixel(data_structures::Coordinates coordinates) const {
    return matrix[coordinates.x] + coordinates.y;
}

images::Image* model::base::BaseSourceImage::outline_stars(Stars* stars) noexcept {
    std::cout << "Outlined\n";
    return nullptr;
}
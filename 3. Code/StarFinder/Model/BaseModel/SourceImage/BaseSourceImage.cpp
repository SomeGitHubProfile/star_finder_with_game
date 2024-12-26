#include "BaseSourceImage.h"

#include <iostream>

//model::base::BaseSourceImage::BaseSourceImage(params::BaseSourceImageParams) : images::RGB_Image(shape), SourceImage(shape), images::Image(shape) {
//
//}

model::base::BaseSourceImage::BaseSourceImage(data_structures::Coordinates shape) : images::RGB_Image(shape), SourceImage(shape), images::Image(shape) {

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
#include "BaseModel.h"

using namespace model::base;

BaseImage::BaseImage(data_structures::Coordinates shape) {
    matrix = new BasePixel*[shape.x];
    for (size_t i = 0; i < shape.x; ++i) {
        matrix[i] = new BasePixel[shape.y];
    }
}

void BaseImage::outline_star(data_structures::Coordinates center) {

}


BasePixel& BaseImage::operator[](data_structures::Coordinates coordinates) {
    return matrix[coordinates.x][coordinates.y];
}

BaseImage::base_image_iterator_wrapper BaseImage::begin() noexcept {
    return base_image_iterator_wrapper(new base_image_iterator(*this));
}

BaseImage::base_image_iterator_wrapper BaseImage::end() noexcept {

}

BaseImage::const_base_image_iterator_wrapper BaseImage::begin() const noexcept {
    return const_base_image_iterator_wrapper(new const_base_image_iterator(*this));
}

BaseImage::const_base_image_iterator_wrapper BaseImage::end() const noexcept {

}
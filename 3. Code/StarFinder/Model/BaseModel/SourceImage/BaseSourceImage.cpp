#include "BaseSourceImage.h"

#include <algorithm>

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

const pixels::Pixel* model::base::BaseSourceImage::get_pixel(data_structures::Coordinates coordinates) const {
    return matrix[coordinates.x] + coordinates.y;
}

#define number_of_colors 20

pixels::RGB_Pixel get_next_color() {
    static unsigned char index = 0;
    pixels::RGB_Pixel colors[number_of_colors] = {
        {255, 0, 0, 255},
        {0, 255, 0, 255},
        {0, 0, 255, 255},
        {233, 30, 99, 255},
        {255, 0, 255, 255},
        {156, 39, 176, 255},
        {29, 233, 182, 255},
        {0, 230, 118, 255},
        {238, 255, 65, 255},
        {33, 150, 243, 255},
        {248, 187, 208, 255},
        {41, 182, 246, 255},
        {76, 175, 80, 255},
        {100, 221, 23, 255},
        {121, 85, 72, 255},
        {26, 35, 126, 255},
        {0, 137, 123, 255},
        {0, 188, 212, 255},
        {105, 240, 174, 255},
        {255, 171, 0, 255}
    };
    return colors[index++ % number_of_colors];
}

void model::base::BaseSourceImage::outline_star(Star* star, pixels::RGB_Pixel** outlined_matrix) noexcept {
    pixels::RGB_Pixel pixel = get_next_color();
    size_t x, y;
    if (image_params.minimal_outline_radius < star->radius) {
        y = std::max(static_cast<long long>(star->center.y - star->radius), 0LL);
        for (x = std::max(static_cast<long long>(star->center.x - star->radius), 0LL); x < std::min(static_cast<long long>(star->center.x + star->radius), static_cast<long long>(shape.x)); ++x) {
            outlined_matrix[x][y] = pixel;
        }
        y = std::min(static_cast<long long>(star->center.y + star->radius), static_cast<long long>(shape.y)) - 1;
        for (x = std::max(static_cast<long long>(star->center.x - star->radius), 0LL); x < std::min(static_cast<long long>(star->center.x + star->radius), static_cast<long long>(shape.x)); ++x) {
            outlined_matrix[x][y] = pixel;
        }
        x = std::max(static_cast<long long>(star->center.x - star->radius), 0LL);
        for (y = std::max(static_cast<long long>(star->center.y - star->radius), 0LL); y < std::min(static_cast<long long>(star->center.y + star->radius), static_cast<long long>(shape.y)); ++y) {
            outlined_matrix[x][y] = pixel;
        }
        x = std::min(static_cast<long long>(star->center.x + star->radius), static_cast<long long>(shape.x)) - 1;
        for (y = std::max(static_cast<long long>(star->center.y - star->radius), 0LL); y < std::min(static_cast<long long>(star->center.y + star->radius), static_cast<long long>(shape.y)); ++y) {
            outlined_matrix[x][y] = pixel;
        }
    } else {
        for (size_t x = std::max(static_cast<long long>(star->center.x - star->radius), 0LL); x < std::min(static_cast<long long>(star->center.x + star->radius), static_cast<long long>(shape.x)); ++x) {
            for (size_t y = std::max(static_cast<long long>(star->center.y - star->radius), 0LL); y < std::min(static_cast<long long>(star->center.y + star->radius), static_cast<long long>(shape.y)); ++y) {
                outlined_matrix[x][y] = pixel;
            }
        }
    }
    return;
}

images::Image* model::base::BaseSourceImage::outline_stars(Stars* stars) noexcept {
    pixels::RGB_Pixel** outlined_matrix = images::copy_matrix<pixels::RGB_Pixel>(shape, matrix);
    for (size_t i = 0; i < stars->get_size(); ++i) {
        outline_star(stars->get_star(i), outlined_matrix);
    }
    return new images::RGB_Image(shape, outlined_matrix);
}
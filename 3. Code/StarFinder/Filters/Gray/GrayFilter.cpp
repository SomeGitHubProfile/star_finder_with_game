#include "GrayFilter.h"

#include <cmath>

images::GrayImage* filters::gray::filter(images::Image* source_image) noexcept {
    images::GrayImage* image = new images::GrayImage(source_image->shape);
    for (size_t x = 0; x < image->shape.x; ++x) {
        for (size_t y = 0; y < image->shape.y; ++y) {
            data_structures::Coordinates coordinates{x, y};
            pixels::Pixel* pixel = source_image->get_pixel(coordinates);
            double red = pixel->get_red() / 255.0;
            double green = pixel->get_green() / 255.0;
            double blue = pixel->get_blue() / 255.0;
            double c = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
            unsigned char color;
            if (c <= 0.0031308) {
                color = (char)(12.92 * 255 * c);
            } else {
                color = (char)((1.055 * pow(c, 0.4166666666666667) - 0.055) * 255);
            }
            (*image)[coordinates] = pixels::GrayPixel(color, pixel->alpha);
        }
    }
    return image;
}
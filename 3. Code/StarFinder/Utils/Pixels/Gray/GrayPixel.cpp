#include "GrayPixel.h"

pixels::GrayPixel::GrayPixel() : color(0), Pixel() {}

pixels::GrayPixel::GrayPixel(unsigned char _color, unsigned char _alpha)
    : color(_color),
    Pixel(_alpha) {}

inline unsigned char pixels::GrayPixel::get_red() const noexcept {
    return color;
}

inline unsigned char pixels::GrayPixel::get_green() const noexcept {
    return color;
}

inline unsigned char pixels::GrayPixel::get_blue() const noexcept {
    return color;
}
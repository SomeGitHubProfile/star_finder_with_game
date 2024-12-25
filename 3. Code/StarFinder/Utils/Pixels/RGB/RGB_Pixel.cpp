#include "RGB_Pixel.h"

pixels::RGB_Pixel::RGB_Pixel() : red(0), green(0), blue(0), Pixel() {}

pixels::RGB_Pixel::RGB_Pixel(unsigned char _red, unsigned char _green, unsigned char _blue, unsigned char _alpha)
    : red(_red),
    green(_green),
    blue(_blue),
    Pixel(_alpha) {}

inline unsigned char pixels::RGB_Pixel::get_red() const noexcept {
    return red;
}

inline unsigned char pixels::RGB_Pixel::get_green() const noexcept {
    return green;
}

inline unsigned char pixels::RGB_Pixel::get_blue() const noexcept {
    return blue;
}
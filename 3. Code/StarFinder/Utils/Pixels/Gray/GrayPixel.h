#pragma once

#include "../Pixel.h"

namespace pixels {
    class GrayPixel : public Pixel {
    public:
        unsigned char color;

        GrayPixel();
        GrayPixel(unsigned char, unsigned char);
        virtual unsigned char get_red() const noexcept override;
        virtual unsigned char get_green() const noexcept override;
        virtual unsigned char get_blue() const noexcept override;
    };
}
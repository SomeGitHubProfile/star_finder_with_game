#pragma once

#include "../Pixel.h"

namespace pixels {
    class RGB_Pixel : public Pixel {
    private:
        unsigned char red;
        unsigned char green;
        unsigned char blue;

    public:
        RGB_Pixel();
        RGB_Pixel(unsigned char, unsigned char, unsigned char, unsigned char);
        virtual unsigned char get_red() const noexcept override;
        virtual unsigned char get_green() const noexcept override;
        virtual unsigned char get_blue() const noexcept override;
    };
}
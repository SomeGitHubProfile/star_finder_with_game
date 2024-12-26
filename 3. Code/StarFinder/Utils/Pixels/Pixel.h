#pragma once

namespace pixels {
    class Pixel {
    public:
        unsigned char alpha;

        Pixel() : alpha(0) {}
        Pixel(unsigned char _alpha) : alpha(_alpha) {}

        virtual unsigned char get_red() const noexcept = 0;
        virtual unsigned char get_green() const noexcept = 0;
        virtual unsigned char get_blue() const noexcept = 0;
    };
}
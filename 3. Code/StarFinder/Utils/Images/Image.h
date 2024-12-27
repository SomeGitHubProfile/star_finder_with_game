#pragma once

#include "../Coordinates.h"
#include "../Pixels/Pixel.h"

namespace images {
    class Image {
    public:
        const data_structures::Coordinates shape;

        Image(data_structures::Coordinates _shape) : shape(_shape) {}
        virtual ~Image() {}

        inline size_t size() const noexcept {
            return shape.x * shape.y;
        }

        virtual const pixels::Pixel* get_pixel(data_structures::Coordinates) const = 0;
        // TODO 2 - after project end
        // we can create abstract class file which will have constructor const char* and pure virtual methods write, save, etc.
        // it can be good because we can write data to one file multiple times without closing it
    };
}
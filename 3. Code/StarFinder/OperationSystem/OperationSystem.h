#pragma once

#include "../Utils/Pixels/Pixel.h"
#include "../Utils/Pixels/RGB/RGB_Pixel.h"

namespace operation_system {
    class FileSystem {
    public:
        virtual pixels::RGB_Pixel** read_image(const char* path) const = 0;
        virtual void save_image(const char* path, const pixels::Pixel** matrix) const = 0;
    };
}
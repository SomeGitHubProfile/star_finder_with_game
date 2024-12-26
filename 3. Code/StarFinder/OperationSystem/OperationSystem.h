#pragma once

#include "../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../Utils/Images/Image.h"
#include "../Utils/Images/MatrixImageDto.h"

namespace operation_system {
    static class FileSystem {
    public:
        images::RGB_ImageDto read_image(const char*) const;
        void save_image(const char*, const images::Image*) const;
    } file_system;
}
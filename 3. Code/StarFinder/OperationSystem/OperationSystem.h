#pragma once

#include "../Utils/Images/RGB_Image.h"

namespace operation_system {
    static class FileSystem {
    public:
        images::RGB_ImageDto read_image(const char*) const;
        void save_image(const char*, const images::Image*) const;
    } file_system;
}
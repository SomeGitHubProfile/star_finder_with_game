#pragma once

#include "../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../Utils/Images/Image.h"
//#include "../Utils/Images/RGB_Image.h" //!!!!!! ERROR IS HERE WHEN UNCOMMENT THIS!

namespace operation_system {
    static class FileSystem {
    public:
        //images::RGB_ImageDto* test() const;
        pixels::RGB_Pixel** read_image(const char*) const;
        void save_image(const char*, const images::Image*) const;
    } file_system;
}
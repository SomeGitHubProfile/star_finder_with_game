#pragma once

#include "MatrixImage.h"
#include "../Pixels/RGB/RGB_Pixel.h"

namespace images {
    typedef MatrixImageDto<pixels::RGB_Pixel> RGB_ImageDto;
    typedef MatrixImage<pixels::RGB_Pixel> RGB_Image;
}
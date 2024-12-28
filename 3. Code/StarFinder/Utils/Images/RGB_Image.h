#pragma once

#include "MatrixImage.h"
#include "MatrixImageDto.h"
#include "../Pixels/RGB/RGB_Pixel.h"

namespace images {
    typedef MatrixImage<pixels::RGB_Pixel> RGB_Image;
    typedef MatrixImageDto<pixels::RGB_Pixel> RGB_ImageDto;
}
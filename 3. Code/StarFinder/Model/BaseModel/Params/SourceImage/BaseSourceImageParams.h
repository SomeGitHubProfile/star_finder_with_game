#pragma once

#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../../../../Utils/Images/MatrixImageDto.h"

namespace model::base::params {
    class BaseSourceImageParams {
    public:
        images::RGB_ImageDto dto;

        enum class OutlineTypes {
            Circle,
            Square
        };

        const char* source_image_path;
        const pixels::RGB_Pixel outline_color;
        const pixels::RGB_Pixel inner_color;
        size_t boundary_width;
        size_t minimal_outline_radius;
        size_t padding;
        OutlineTypes outline_type;

        BaseSourceImageParams(const char*, pixels::RGB_Pixel, pixels::RGB_Pixel, size_t);
        void init_source_image_dto();
    };
}
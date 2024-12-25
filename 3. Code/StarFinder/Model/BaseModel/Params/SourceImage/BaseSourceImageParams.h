#pragma once

#include "../../../Params.h"
#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"

namespace model::base::params {
    class BaseSourceImageParams {
    public:
        enum class OutlineTypes {
            Circle,
            Square
        };

        const pixels::RGB_Pixel outline_color;
        const pixels::RGB_Pixel inner_color;
        size_t boundary_width;
        size_t minimal_outline_radius;
        size_t padding;
        OutlineTypes outline_type;

        BaseSourceImageParams(pixels::RGB_Pixel _outline_color, pixels::RGB_Pixel _inner_color, size_t _boundary_width);
    };
}
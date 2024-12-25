#pragma once

#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../../SourceImage/BaseSourceImage.h"

namespace model::base::params {
    class BaseSourceImageParams {
    private:
        pixels::RGB_Pixel** matrix;
        data_structures::Coordinates shape;
    public:
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
    };
}
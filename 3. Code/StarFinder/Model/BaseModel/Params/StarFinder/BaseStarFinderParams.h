#pragma once

#include "../../../Params.h"
#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../../Filters/Sobel/SobelFilter.h"

namespace model::base::params {
    class BaseStarFinderParams : public Params {
    public:
        unsigned char red_difference;
        unsigned char green_difference;
        unsigned char blue_difference;
        unsigned char alpha_difference;

        filters::gaussian::KernelTypes gaussian_kernel_type;
        filters::sobel::KernelTypes sobel_kernel_type;

        const char* image_file_path;
        const char* stars_file_path;

        BaseStarFinderParams(
            SourceImage*,
            unsigned char red_difference,
            unsigned char green_difference,
            unsigned char blue_difference,
            unsigned char alpha_difference
        );

        BaseStarFinderParams(
            SourceImage*,
            unsigned char red_difference,
            unsigned char green_difference,
            unsigned char blue_difference,
            unsigned char alpha_difference,
            filters::gaussian::KernelTypes gaussian_kernel_type,
            filters::sobel::KernelTypes sobel_kernel_type,
            const char* image_file_path,
            const char* stars_file_path
        );

        virtual Stars* new_stars() const override;
        virtual Star* new_star(data_structures::Coordinates center, size_t radius) const override;
    };
}
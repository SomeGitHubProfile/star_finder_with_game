#pragma once

#include "../../../Params.h"
#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../../Filters/Sobel/SobelFilter.h"

namespace model::base::params {
    class BaseStarFinderParams : public Params {
    public:
        const char* image_file_path;
        const char* stars_file_path;

        filters::gaussian::KernelTypes gaussian_kernel_type;
        filters::sobel::KernelTypes sobel_kernel_type;
        float boundaries_detection_strength;

        BaseStarFinderParams(SourceImage* source_image);

        virtual Stars* new_stars() const override;
    };
}
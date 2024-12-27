#pragma once

#include "../../../Params.h"
#include "../../../../Utils/Pixels/RGB/RGB_Pixel.h"
#include "../../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../../Filters/Sobel/SobelFilter.h"

namespace model::base::params {
    class BaseStarFinderParams : public Params {
    public:
        float boundaries_detection_strength; // number in segment [0, 32]

        filters::gaussian::KernelTypes gaussian_kernel_type;
        filters::sobel::KernelTypes sobel_kernel_type;

        const char* image_file_path;
        const char* stars_file_path;

        BaseStarFinderParams(SourceImage*, float);
        BaseStarFinderParams(
            SourceImage*,
            float boundaries_detection_strength,
            filters::gaussian::KernelTypes gaussian_kernel_type,
            filters::sobel::KernelTypes sobel_kernel_type,
            const char* image_file_path,
            const char* stars_file_path
        );

        virtual Stars* new_stars() const override;
        virtual Star* new_star(data_structures::Coordinates center, size_t radius) const override;
    };
}
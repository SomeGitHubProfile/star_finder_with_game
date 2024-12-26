#pragma once

#include "../../Utils/Images/GrayImage.h"

namespace filters::gaussian {
    enum class KernelTypes {
        GaussianKernel_3x3,
        GaussianKernel_5x5,
        GaussianKernel_5x5_low_value
    };

    images::GrayImage* filter(images::GrayImage* source_image, KernelTypes kernel_type) noexcept;
}
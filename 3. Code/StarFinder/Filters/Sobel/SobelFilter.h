#pragma once

#include "../../Utils/Images/GrayImage.h"

namespace filters::sobel {
    enum class KernelTypes {
        SobelKernel_3x3,
        SobelKernel_5x5
    };

    images::GrayImage* filter(images::GrayImage* source_image, KernelTypes kernel_type) noexcept;
}
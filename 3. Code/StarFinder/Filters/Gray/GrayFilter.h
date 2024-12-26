#pragma once

#include "../../Utils/Images/GrayImage.h"

namespace filters::gray {
    images::GrayImage* filter(images::Image* source_image) noexcept;
}
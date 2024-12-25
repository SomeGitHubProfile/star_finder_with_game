#pragma once

#include "../../Utils/Images/GrayImage.h"

namespace filters::median {
    images::GrayImage* filter(images::Image* source_image) noexcept;
}
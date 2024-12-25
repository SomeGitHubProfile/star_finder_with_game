#include "BaseSourceImageParams.h"

#include "../../SourceImage/BaseSourceImage.h"
#include "../../Stars/BaseStars.h"

model::base::params::BaseSourceImageParams::BaseSourceImageParams(pixels::RGB_Pixel _outline_color, pixels::RGB_Pixel _inner_color, size_t _boundary_width)
    : outline_color(_outline_color),
    inner_color(_inner_color),
    boundary_width(_boundary_width),
    minimal_outline_radius(0),
    padding(0),
    outline_type(OutlineTypes::Circle) {}
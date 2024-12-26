#include "BaseSourceImageParams.h"

#include "../../SourceImage/BaseSourceImage.h"
#include "../../Stars/BaseStars.h"
#include "../../../../OperationSystem/OperationSystem.h"

model::base::params::BaseSourceImageParams::BaseSourceImageParams(
    const char* _source_image_path,
    pixels::RGB_Pixel _outline_color,
    pixels::RGB_Pixel _inner_color,
    size_t _boundary_width
)
    : source_image_path(_source_image_path),
    outline_color(_outline_color),
    inner_color(_inner_color),
    boundary_width(_boundary_width),
    minimal_outline_radius(0),
    padding(0),
    outline_type(OutlineTypes::Circle),
    dto({0, 0}, nullptr) {}

void model::base::params::BaseSourceImageParams::init_source_image_dto() {
     dto = operation_system::file_system.read_image(source_image_path);
     return;
}
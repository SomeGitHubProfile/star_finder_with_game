#include "BaseStarFinderParams.h"

#include "../../SourceImage/BaseSourceImage.h"
#include "../../Stars/BaseStars.h"
#include "../../Star/BaseStar.h"

model::base::params::BaseStarFinderParams::BaseStarFinderParams(
    model::SourceImage* source_image,
    unsigned char _red_difference,
    unsigned char _green_difference,
    unsigned char _blue_difference,
    unsigned char _alpha_difference
)
    : Params(source_image),
    red_difference(_red_difference),
    green_difference(_green_difference),
    blue_difference(_blue_difference),
    alpha_difference(_alpha_difference),
    gaussian_kernel_type(filters::gaussian::KernelTypes::GaussianKernel_3x3),
    sobel_kernel_type(filters::sobel::KernelTypes::SobelKernel_3x3),
    image_file_path(""),
    stars_file_path("") {}

model::base::params::BaseStarFinderParams::BaseStarFinderParams(
    SourceImage*,
    unsigned char _red_difference,
    unsigned char _green_difference,
    unsigned char _blue_difference,
    unsigned char _alpha_difference,
    filters::gaussian::KernelTypes _gaussian_kernel_type,
    filters::sobel::KernelTypes _sobel_kernel_type,
    const char* _image_file_path,
    const char* _stars_file_path
) : Params(source_image),
    red_difference(_red_difference),
    green_difference(_green_difference),
    blue_difference(_blue_difference),
    alpha_difference(_alpha_difference),
    gaussian_kernel_type(_gaussian_kernel_type),
    sobel_kernel_type(_sobel_kernel_type),
    image_file_path(_image_file_path),
    stars_file_path(_stars_file_path) {}

model::Stars* model::base::params::BaseStarFinderParams::new_stars() const {
    return new model::base::BaseStars();
}


model::Star* model::base::params::BaseStarFinderParams::new_star(data_structures::Coordinates center, size_t radius) const {
    return new model::base::BaseStar(center, radius);
}
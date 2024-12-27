#include "BaseStarFinderParams.h"

#include "../../SourceImage/BaseSourceImage.h"
#include "../../Stars/BaseStars.h"
#include "../../Star/BaseStar.h"

model::base::params::BaseStarFinderParams::BaseStarFinderParams(model::SourceImage* source_image, float _boundaries_detection_strength)
    : Params(source_image),
    boundaries_detection_strength(_boundaries_detection_strength),
    gaussian_kernel_type(filters::gaussian::KernelTypes::GaussianKernel_3x3),
    sobel_kernel_type(filters::sobel::KernelTypes::SobelKernel_3x3),
    image_file_path(""),
    stars_file_path("") {}

model::base::params::BaseStarFinderParams::BaseStarFinderParams(
    SourceImage*,
    float _boundaries_detection_strength,
    filters::gaussian::KernelTypes _gaussian_kernel_type,
    filters::sobel::KernelTypes _sobel_kernel_type,
    const char* _image_file_path,
    const char* _stars_file_path
) : Params(source_image),
    boundaries_detection_strength(_boundaries_detection_strength),
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
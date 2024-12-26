#include "BaseStarFinderParams.h"

#include "../../SourceImage/BaseSourceImage.h"
#include "../../Stars/BaseStars.h"

model::base::params::BaseStarFinderParams::BaseStarFinderParams(model::SourceImage* source_image)
    : Params(source_image),
    image_file_path(""),
    stars_file_path(""),
    gaussian_kernel_type(filters::gaussian::KernelTypes::GaussianKernel_3x3),
    sobel_kernel_type(filters::sobel::KernelTypes::SobelKernel_3x3) {}

model::Stars* model::base::params::BaseStarFinderParams::new_stars() const {
    return new model::base::BaseStars();
}
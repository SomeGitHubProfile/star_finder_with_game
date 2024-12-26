#include "BaseStarFinder.h"

#include "../../../Filters/Gray/GrayFilter.h"
#include "../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../Filters/Sobel/SobelFilter.h"

model::base::BaseStarFinder::BaseStarFinder(params::BaseStarFinderParams _params) : params(_params) {}

images::GrayImage* model::base::BaseStarFinder::get_boundaries_image() const noexcept {
    images::GrayImage* gray_image = filters::gray::filter(params.source_image);
    images::GrayImage* gaussian_image = filters::gaussian::filter(gray_image, params.gaussian_kernel_type);
    delete gray_image;
    images::GrayImage* sobel_image = filters::gaussian::filter(gaussian_image, params.gaussian_kernel_type);
    delete gaussian_image;
    return sobel_image;
}

void model::base::BaseStarFinder::find_stars() noexcept {
    
}

model::SourceImage* model::base::BaseStarFinder::get_image() noexcept {
    return nullptr;
}

model::Stars* model::base::BaseStarFinder::get_stars() noexcept {
    return nullptr;
}
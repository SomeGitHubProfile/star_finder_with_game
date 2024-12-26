#include "BaseStarFinder.h"

#include "../../../Filters/Gray/GrayFilter.h"
#include "../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../Filters/Sobel/SobelFilter.h"
#include "../../../Utils/DisjointSet.h"

#include <cmath>

model::base::BaseStarFinder::BaseStarFinder(params::BaseStarFinderParams _params) : star_finder_params(_params) {}

images::GrayImage* model::base::BaseStarFinder::get_boundaries_image() const noexcept {
    images::GrayImage* gray_image = filters::gray::filter(star_finder_params.source_image);
    images::GrayImage* gaussian_image = filters::gaussian::filter(gray_image, star_finder_params.gaussian_kernel_type);
    delete gray_image;
    images::GrayImage* sobel_image = filters::gaussian::filter(gaussian_image, star_finder_params.gaussian_kernel_type);
    delete gaussian_image;
    return sobel_image;
}

size_t model::base::BaseStarFinder::get_index_in_disjoint_set(data_structures::Coordinates coordinates) const noexcept {
    return coordinates.x * star_finder_params.source_image->shape.y + coordinates.y;
}

void model::base::BaseStarFinder::find_stars() noexcept {
    images::GrayImage* boundaries_image = get_boundaries_image();
    data_structures::DisjointSet<data_structures::Coordinates> disjoint_set(star_finder_params.source_image->shape.x * star_finder_params.source_image->shape.y);
    for (size_t x = 0; x < star_finder_params.source_image->shape.x; ++x) {
        for (size_t y = 0; y < star_finder_params.source_image->shape.y; ++y) {
            disjoint_set.set[get_index_in_disjoint_set({x, y})] = new data_structures::DisjointSet< data_structures::Coordinates>::Node({x, y});
        }
    }

    for (size_t x = 0; x < star_finder_params.source_image->shape.x; ++x) {
        for (size_t y = 0; y < star_finder_params.source_image->shape.y; ++y) {
            data_structures::Coordinates pixel_coordinates{x, y};
            const pixels::Pixel* pixel = star_finder_params.source_image->get_pixel(pixel_coordinates);
            for (char i = -1; i < 2; ++i) {
                for (char j = -1; j < 2; ++j) {
                    if (i == j
                        || x + i < 0 
                        || star_finder_params.source_image->shape.x <= x + i
                        || y + j < 0 
                        || star_finder_params.source_image->shape.y <= y + j
                    ) {
                        continue;
                    }
                    data_structures::Coordinates neighbour_pixel_coordinates{x + i, y + j};
                    const pixels::Pixel* neighbour_pixel = star_finder_params.source_image->get_pixel(neighbour_pixel_coordinates);
                    float red_diff = pixel->get_red() - neighbour_pixel->get_red();
                    float green_diff = pixel->get_green() - neighbour_pixel->get_green();
                    float blue_diff = pixel->get_blue() - neighbour_pixel->get_blue();
                    float alpha_diff = pixel->alpha - neighbour_pixel->alpha;
                    float difference = sqrt(red_diff * red_diff + green_diff * green_diff + blue_diff * blue_diff + alpha_diff * alpha_diff);
                    if (difference < star_finder_params.boundaries_detection_strength) {
                        disjoint_set.unite(get_index_in_disjoint_set(pixel_coordinates), get_index_in_disjoint_set(neighbour_pixel_coordinates));
                    }
                }
            }
        }
    }

}

model::SourceImage* model::base::BaseStarFinder::get_image() noexcept {
    return nullptr;
}

model::Stars* model::base::BaseStarFinder::get_stars() noexcept {
    return nullptr;
}
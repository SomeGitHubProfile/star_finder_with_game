#include "BaseStarFinder.h"

#include "../../../Filters/Gray/GrayFilter.h"
#include "../../../Filters/Gaussian/GaussianFilter.h"
#include "../../../Filters/Sobel/SobelFilter.h"

#include <cmath>
#include <algorithm>

model::base::BaseStarFinder::BaseStarFinder(params::BaseStarFinderParams _params) : star_finder_params(_params) {}

model::base::BaseStarFinder::HashTableValue::HashTableValue(
    data_structures::Coordinates _coordinates,
    Components::Node* _component_node
) : coordinates(_coordinates),
    component_node(_component_node) {}

size_t model::base::BaseStarFinder::HashTableValue::hash() const noexcept {
    return ((coordinates.x * 18181) + (coordinates.y * 18899));
}

bool model::base::BaseStarFinder::HashTableValue::operator==(const HashTableValue& rhs) const noexcept {
    return coordinates == rhs.coordinates;
}

bool model::base::BaseStarFinder::HashTableValue::operator!=(const HashTableValue& rhs) const noexcept {
    return !(*this == rhs);
}

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

model::base::BaseStarFinder::DisjointUnionSet model::base::BaseStarFinder::make_disjoint_set() const noexcept {
    DisjointUnionSet disjoint_set(star_finder_params.source_image->shape.x * star_finder_params.source_image->shape.y);
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

    return disjoint_set;
}


inline model::base::BaseStarFinder::ComponentPtr model::base::BaseStarFinder::make_component_ptr() const noexcept {
    return std::make_shared<Component>();
}

model::base::BaseStarFinder::Components model::base::BaseStarFinder::get_components(DisjointUnionSet disjoint_set) const noexcept {
    Components components;
    data_structures::HashTable<HashTableValue> table{disjoint_set.size};
    for (size_t i = 0; i < disjoint_set.size; ++i) {
        data_structures::Coordinates coordinates = disjoint_set.set[i]->value;
        DisjointUnionSet::Node* parent = disjoint_set.find_parent(i);
        data_structures::Coordinates parent_coordinates = parent->value;
        ComponentsHashTable::Node* node = table.search(HashTableValue(parent_coordinates, nullptr));
        if (node) {
            node->value.component_node->value.get()->insert(coordinates);
        } else {
            ComponentPtr component_ptr = make_component_ptr();
            component_ptr.get()->insert(parent_coordinates);
            table.insert(HashTableValue(parent_coordinates, components.insert(component_ptr)));
            if (coordinates != parent_coordinates) {
                component_ptr.get()->insert(coordinates);
            }
        }
    }
    return components;
}

model::Star* model::base::BaseStarFinder::get_star(Component* component) const noexcept {
    data_structures::Coordinates coordinates = component->begin->value;
    size_t min_x = coordinates.x;
    size_t max_x = coordinates.x;
    size_t min_y = coordinates.y;
    size_t max_y = coordinates.y;
    for (Component::Node* node = component->begin->next; node != nullptr; node = node->next) {
        const data_structures::Coordinates& coordinates = node->value;
        if (coordinates.x < min_x) {
            min_x = coordinates.x;
        }
        if (max_x < coordinates.x) {
            max_x = coordinates.x;
        }
        if (coordinates.y < min_y) {
            min_y = coordinates.y;
        }
        if (max_y < coordinates.y) {
            max_y = coordinates.y;
        }
    }
    if (max_x - min_x < 10 && max_y - min_y < 10) {
        size_t center_x = (min_x + max_x) / 2;
        size_t center_y = (min_y + max_y) / 2;
        size_t radius = std::max(max_x - center_x, max_y - center_y);
        return star_finder_params.new_star({center_x, center_y}, radius);
    }
    return nullptr;
}

model::Stars* model::base::BaseStarFinder::find_stars() noexcept {
    //images::GrayImage* boundaries_image = get_boundaries_image();
    //DisjointUnionSet disjoint_set = make_disjoint_set();
    //Components components = get_components(disjoint_set);
    Stars* stars = star_finder_params.new_stars();
    /*for (Components::Node* node = components.begin; node != nullptr; node = node->next) {
        Star* star = get_star(node->value.get());
        if (star) {
            stars->add_star(star);
        }
    }*/
    return stars;
}
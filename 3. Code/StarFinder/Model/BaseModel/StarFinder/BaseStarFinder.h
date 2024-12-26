#pragma once

#include "../../StarFinder.h"
#include "../Params/StarFinder/BaseStarFinderParams.h"

namespace model::base {
    class BaseStarFinder : public StarFinder {
    private:
        params::BaseStarFinderParams star_finder_params;

        images::GrayImage* get_boundaries_image() const noexcept;
        size_t get_index_in_disjoint_set(data_structures::Coordinates coordinates) const noexcept;
    public:
        BaseStarFinder(params::BaseStarFinderParams);

        virtual void find_stars() noexcept override;
        virtual SourceImage* get_image() noexcept override;
        virtual Stars* get_stars() noexcept override;
    };
}
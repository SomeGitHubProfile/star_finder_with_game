#pragma once

#include "../../StarFinder.h"
#include "../Params/StarFinder/BaseStarFinderParams.h"

namespace model::base {
    class BaseStarFinder : public StarFinder {
    private:
        params::BaseStarFinderParams params;

        images::GrayImage* get_boundaries_image() const noexcept;
    public:
        BaseStarFinder(params::BaseStarFinderParams);

        virtual void find_stars() noexcept override;
        virtual SourceImage* get_image() noexcept override;
        virtual Stars* get_stars() noexcept override;
    };
}
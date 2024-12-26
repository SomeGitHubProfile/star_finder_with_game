#pragma once

#include "SourceImage.h"
#include "Stars.h"

namespace model {
    class StarFinder {
    public:
        virtual void find_stars() noexcept = 0;
        virtual SourceImage* get_image() noexcept = 0;
        virtual Stars* get_stars() noexcept = 0;
    };
}
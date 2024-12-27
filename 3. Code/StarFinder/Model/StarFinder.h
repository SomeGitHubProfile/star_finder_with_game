#pragma once

#include "Stars.h"

namespace model {
    class StarFinder {
    public:
        virtual Stars* find_stars() noexcept = 0;
    };
}
#pragma once

#include "../../Star.h"

namespace model::base {
    class BaseStar : public Star {
    public:
        BaseStar(data_structures::Coordinates, size_t);
    };
}
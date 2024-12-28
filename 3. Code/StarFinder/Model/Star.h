#pragma once

#include "../Utils/Coordinates.h"

namespace model {
    class Star {
    public:
        const data_structures::Coordinates center;
        const size_t radius;

        Star(data_structures::Coordinates _center, size_t _radius) : center(_center), radius(_radius) {}
    };
}
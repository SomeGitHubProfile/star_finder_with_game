#pragma once

#include "../Utils/Coordinates.h"

namespace model {
    class Star {
    public:
        const data_structures::Coordinates coordinates;
        const size_t radius;

        Star(data_structures::Coordinates _coordinates, size_t _radius) : coordinates(_coordinates), radius(_radius) {}
    };
}
#pragma once

namespace data_structures {
    struct Coordinates {
        size_t x;
        size_t y;

        Coordinates(size_t _x, size_t _y) : x(_x), y(_y) {}

        bool operator==(const Coordinates& rhs) const noexcept {
            return x == rhs.x && y == rhs.y;
        }

        bool operator!=(const Coordinates& rhs) const noexcept {
            return !(*this == rhs);
        }
    };
}
#pragma once

#include "../Coordinates.h"

namespace images {
    template <typename T>
    T** copy_matrix(const data_structures::Coordinates& shape, T** matrix) {
        T** new_matrix = new T * [shape.x];
        for (size_t x = 0; x < shape.x; ++x) {
            new_matrix[x] = new T[shape.y];
            for (size_t y = 0; y < shape.y; ++y) {
                new_matrix[x][y] = matrix[x][y];
            }
        }
        return new_matrix;
    }
}
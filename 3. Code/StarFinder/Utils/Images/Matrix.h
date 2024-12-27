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

    /* TODO TODO TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    * here is template function, but in operation system we have the same,
    * but only for rgb pixel.
    * This is very bad code, refactor will not help.
    * This project should be written from the beginning, with better architecture.
    */
    template <typename T>
    void delete_matrix(const data_structures::Coordinates& shape, T** matrix) {
        for (size_t x = 0; x < shape.x; ++x) {
            delete[] matrix[x];
        }
        delete[] matrix;
        return;
    }
}
#pragma once

#include "../Pixels/RGB/RGB_Pixel.h"

namespace images {
    template<typename T>
    class MatrixImageDto {
    public:
        T** matrix;
        const data_structures::Coordinates shape;

        MatrixImageDto<T>(const data_structures::Coordinates& _shape, T** _matrix) : shape(_shape) {
            matrix = new T * [shape.x];
            for (size_t x = 0; x < shape.x; ++x) {
                matrix[x] = new T[shape.y];
                for (size_t y = 0; y < shape.y; ++y) {
                    matrix[x][y] = _matrix[x][y];
                }
            }
        }

        ~MatrixImageDto<T>() {
            for (size_t x = 0; x < shape.x; ++x) {
                delete[] matrix[x];
            }
            delete[] matrix;
        }
    };

    typedef MatrixImageDto<pixels::RGB_Pixel> RGB_ImageDto;
}
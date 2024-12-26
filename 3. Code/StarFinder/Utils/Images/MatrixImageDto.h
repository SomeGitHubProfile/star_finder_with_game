#pragma once

#include "../Pixels/RGB/RGB_Pixel.h"
#include "../Coordinates.h"

namespace images {
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

    template<typename T>
    class MatrixImageDto {
    public:
        T** matrix;
        data_structures::Coordinates shape;

        MatrixImageDto<T>(const data_structures::Coordinates& _shape, T** _matrix) : shape(_shape) {
            matrix = new T*[shape.x];
            for (size_t x = 0; x < shape.x; ++x) {
                matrix[x] = new T[shape.y];
                for (size_t y = 0; y < shape.y; ++y) {
                    matrix[x][y] = _matrix[x][y];
                }
            }
        }

        MatrixImageDto<T>(const MatrixImageDto& rhs) : shape(rhs.shape) {
            matrix = new T * [shape.x];
            for (size_t x = 0; x < shape.x; ++x) {
                matrix[x] = new T[shape.y];
                for (size_t y = 0; y < shape.y; ++y) {
                    matrix[x][y] = rhs.matrix[x][y];
                }
            }
        }

        MatrixImageDto<T>(MatrixImageDto&& rhs) : shape(rhs.shape) {
            matrix = rhs.matrix;
        }

        MatrixImageDto<T>& operator=(const MatrixImageDto<T>& rhs) {
            if (this == &rhs) {
                return *this;
            }
            delete_matrix<T>(shape, matrix);
            shape = rhs.shape;
            matrix = new T*[shape.x];
            for (size_t x = 0; x < shape.x; ++x) {
                matrix[x] = new T[shape.y];
                for (size_t y = 0; y < shape.y; ++y) {
                    matrix[x][y] = rhs.matrix[x][y];
                }
            }
            return *this;
        }

        ~MatrixImageDto<T>() {
            delete_matrix<T>(shape, matrix);
        }
    };

    typedef MatrixImageDto<pixels::RGB_Pixel> RGB_ImageDto;
}
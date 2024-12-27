#pragma once

#include "../Pixels/RGB/RGB_Pixel.h"
#include "Matrix.h"

namespace images {
    template<typename T>
    class MatrixImageDto {
    public:
        T** matrix;
        data_structures::Coordinates shape;

        MatrixImageDto<T>(const data_structures::Coordinates& _shape, T** _matrix)
            : shape(_shape),
            matrix(copy_matrix<T>(_shape, _matrix)) {}

        MatrixImageDto<T>(const MatrixImageDto& rhs)
            : shape(rhs.shape),
            matrix(copy_matrix<T>(rhs.shape, rhs.matrix)) {}

        MatrixImageDto<T>(MatrixImageDto&& rhs) : shape(rhs.shape) {
            matrix = rhs.matrix;
        }

        MatrixImageDto<T>& operator=(const MatrixImageDto<T>& rhs) {
            if (this == &rhs) {
                return *this;
            }
            delete_matrix<T>(shape, matrix);
            shape = rhs.shape;
            matrix = copy_matrix<T>(shape, rhs.matrix);
            return *this;
        }

        ~MatrixImageDto<T>() {
            delete_matrix<T>(shape, matrix);
        }
    };
}
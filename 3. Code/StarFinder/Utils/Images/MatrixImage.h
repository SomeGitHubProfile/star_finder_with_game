#pragma once

#include "Image.h"
#include "MatrixImageDto.h"

namespace images {
    template <typename T>
    class MatrixImage : public virtual Image {
    protected:
        T** matrix;
    public:
        MatrixImage<T>(const data_structures::Coordinates& shape) : Image(shape) {
            matrix = new T*[shape.x];
            for (size_t x = 0; x < shape.x; ++x) {
                matrix[x] = new T[shape.y];
            }
        }

        MatrixImage<T>(const data_structures::Coordinates& shape, T** _matrix)
            : Image(shape),
            matrix(copy_matrix<T>(shape, _matrix)) {}

        MatrixImage<T>(const MatrixImageDto<T>& dto)
            : Image(dto.shape),
            matrix(copy_matrix(shape, dto.matrix)) {}

        virtual ~MatrixImage<T>() {
            delete_matrix(shape, matrix);
        }

        inline T& operator[](data_structures::Coordinates coordinates) {
            return matrix[coordinates.x][coordinates.y];
        }

        virtual inline const pixels::Pixel* get_pixel(data_structures::Coordinates coordinates) const override {
            return matrix[coordinates.x] + coordinates.y;
        }
    };
}
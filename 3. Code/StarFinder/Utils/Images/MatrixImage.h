#pragma once

#include "Image.h"

namespace images {
    template <typename T>
    class MatrixImage : public virtual Image {
    protected:
        T** matrix;
    public:
        MatrixImage<T>(data_structures::Coordinates shape) : Image(shape) {
            matrix = new T*[shape.x];
            for (size_t i = 0; i < shape.x; ++i) {
                matrix[i] = new T[shape.y];
            }
        }

        virtual ~MatrixImage<T>() {
            for (size_t i = 0; i < shape.x; ++i) {
                delete matrix[i];
            }
            delete[] matrix;
        }

        inline T& operator[](data_structures::Coordinates coordinates) {
            return matrix[coordinates.x][coordinates.y];
        }

        virtual inline const pixels::Pixel* get_pixel(data_structures::Coordinates coordinates) const override {
            return matrix[coordinates.x] + coordinates.y;
        }
    };
}
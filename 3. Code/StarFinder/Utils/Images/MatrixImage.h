#pragma once

#include "Image.h"
#include "../../Utils/Coordinates.h"
#include "../../OperationSystem/OperationSystem.h"

namespace images {
    template<typename T>
    class MatrixImageDto {
    public:
        T** matrix;
        const data_structures::Coordinates shape;

        MatrixImageDto<T>(const data_structures::Coordinates& _shape, T** _matrix) : shape(_shape) {
            matrix = new T*[shape.x];
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

        virtual void save(const char* path) const override {
            return operation_system::file_system.save_image(path, this);
        }
    };
}

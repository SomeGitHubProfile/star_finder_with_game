#pragma once

#include "Star.h"

namespace model {
    class Stars {
    private:
        size_t size;
    public:
        Stars() : size(0) {}
        Stars(size_t _size) : size(_size) {}

        inline size_t get_size() {
            return size;
        }

        virtual Star* get_star(size_t) = 0;
        virtual void add_star(Star*) noexcept = 0;
    };
}
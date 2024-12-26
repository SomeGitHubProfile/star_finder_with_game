#pragma once

#include "Star.h"

namespace model {
    class Stars {
    public:
        size_t size;

        Stars() : size(0) {}
        Stars(size_t _size) : size(_size) {}

        virtual Star* get_star(size_t) = 0;
        virtual void add_star(Star*) noexcept = 0;
    };
}
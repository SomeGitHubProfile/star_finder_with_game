#pragma once

#include "../../Stars.h"

namespace model::base {
    class BaseStars : public Stars {
    public:
        BaseStars();
        BaseStars(size_t size);

        virtual Star* operator[](size_t) override;
        virtual void add_star(Star*) noexcept override;
    };
}
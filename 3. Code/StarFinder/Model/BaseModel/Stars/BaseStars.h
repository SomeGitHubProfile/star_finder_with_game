#pragma once

#include "../../Stars.h"
#include "../../../Utils/SinglyLinkedList.h"

namespace model::base {
    class BaseStars : public Stars {
    private:
        typedef data_structures::SinglyLinkedList<Star*> List;
        List stars;
    public:
        BaseStars();
        BaseStars(size_t size);
        ~BaseStars();

        virtual Star* get_star(size_t) override;
        virtual void add_star(Star*) noexcept override;
    };
}
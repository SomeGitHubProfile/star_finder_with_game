#include "BaseStars.h"

model::base::BaseStars::BaseStars() : Stars() {}

model::base::BaseStars::BaseStars(size_t size) : Stars(size) {}


model::Star* model::base::BaseStars::operator[](size_t) {
    return nullptr;
}

void model::base::BaseStars::add_star(Star*) noexcept {

}
#include "BaseStars.h"

model::base::BaseStars::BaseStars() : Stars() {}

model::base::BaseStars::BaseStars(size_t size) : Stars(size) {}

model::base::BaseStars::~BaseStars() {
    for (List::Node* node = stars.begin; node != nullptr; node = node->next) {
        delete node->value;
    }
}


model::Star* model::base::BaseStars::get_star(size_t index) {
    List::Node* node = stars.begin;
    for (; index > 0 && node != nullptr; node = node->next, --index); // !!! may be deleted by compiler
    if (node) {
        return node->value;
    }
    return nullptr;
}

void model::base::BaseStars::add_star(Star* star) noexcept {
    stars.insert(star);
}
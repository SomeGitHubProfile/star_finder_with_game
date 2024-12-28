#include "BaseStars.h"

#include <vector>

model::base::BaseStars::BaseStars() : Stars() {}

model::base::BaseStars::BaseStars(size_t size) : Stars(size) {}

//model::base::BaseStars::~BaseStars() {
//    for (List::Node* node = stars.begin; node != nullptr; node = node->next) {
//        delete node->value;
//    }
//}

model::base::BaseStars::~BaseStars() {
        for (auto star : stars) {
            delete star;
        }
    }


model::Star* model::base::BaseStars::get_star(size_t index) {
    //List::Node* node = stars.begin;
    ////for (; index > 0 && node != nullptr; node = node->next, --index); // !!! may be deleted by compiler
    //while (index > 0 && node != nullptr) {
    //    node = node->next;
    //    --index;
    //}
    //if (node) {
    //    return node->value;
    //}
    //return nullptr;
    if (index >= size) {
        return nullptr;
    }
    return stars[index];
}

void model::base::BaseStars::add_star(Star* star) noexcept {
    ++size;
    //stars.insert(star);
    stars.push_back(star);
    return;
}
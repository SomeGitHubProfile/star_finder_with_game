#pragma once

#include "SourceImage.h"
#include "Stars.h"

#include <iostream>

namespace model {
    class Params {
    public:
        SourceImage* source_image; // TODO add const modifier, this will cause changes in filters and pixels

        Params(SourceImage* _source_image) : source_image(_source_image) {}
        virtual ~Params() {
            std::cout << "Base params destructor" << '\n';
        }

        virtual Stars* new_stars() const = 0;
    };
}
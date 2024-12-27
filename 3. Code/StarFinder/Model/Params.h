#pragma once

#include "SourceImage.h"
#include "Stars.h"

namespace model {
    class Params {
    public:
        SourceImage* source_image; // TODO add const modifier, this will cause changes in filters and pixels

        Params(SourceImage* _source_image) : source_image(_source_image) {}

        virtual Stars* new_stars() const = 0;
        virtual Star* new_star(data_structures::Coordinates center, size_t radius) const = 0;
    };
}
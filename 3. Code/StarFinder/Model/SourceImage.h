#pragma once

#include "../Utils/Images/Image.h"
#include "Stars.h"

namespace model {
    class SourceImage : public virtual images::Image {
    public:
        SourceImage(data_structures::Coordinates shape) : images::Image(shape) {} // TODO remove
        //SourceImage(const char* file_path) // TODO
        virtual Image* outline_stars(Stars* stars) noexcept = 0;
    };
}
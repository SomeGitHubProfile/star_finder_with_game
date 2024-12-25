#pragma once

#include "../../../Utils/Images/RGB_Image.h"
#include "../../SourceImage.h"
#include "../../../Utils/Pixels/RGB/RGB_Pixel.h"

namespace model::base {
    class BaseSourceImage : public virtual images::RGB_Image, public virtual SourceImage {
    private:
        void outline_star(data_structures::Coordinates center) noexcept;

    public:
        BaseSourceImage(data_structures::Coordinates shape);

        virtual pixels::Pixel* get_pixel(data_structures::Coordinates) override;
        virtual Image* outline_stars(Stars* stars) noexcept override;
    };
}
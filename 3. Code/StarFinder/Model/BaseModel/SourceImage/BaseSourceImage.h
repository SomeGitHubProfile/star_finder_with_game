#pragma once

#include "../../../Utils/Images/RGB_Image.h"
#include "../../SourceImage.h"
#include "../Params/SourceImage/BaseSourceImageParams.h"

namespace model::base {
    class BaseSourceImage : public virtual images::RGB_Image, public virtual SourceImage {
    private:
        void outline_star(data_structures::Coordinates center) noexcept;

    public:
        //BaseSourceImage(params::BaseSourceImageParams);
        BaseSourceImage(data_structures::Coordinates);

        virtual const pixels::Pixel* get_pixel(data_structures::Coordinates) const override;
        virtual Image* outline_stars(Stars* stars) noexcept override;
    };
}
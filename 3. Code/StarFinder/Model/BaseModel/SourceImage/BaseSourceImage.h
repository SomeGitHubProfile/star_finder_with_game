#pragma once

#include "../../../Utils/Images/RGB_Image.h"
#include "../../SourceImage.h"
#include "../Params/SourceImage/BaseSourceImageParams.h"

using namespace model::base::params;

namespace model::base {
    class BaseSourceImage : public virtual images::RGB_Image, public virtual SourceImage {
    private:
        BaseSourceImageParams image_params;
        void outline_star(Star*, pixels::RGB_Pixel**) noexcept;

    public:
        BaseSourceImage(const params::BaseSourceImageParams&);

        virtual const pixels::Pixel* get_pixel(data_structures::Coordinates) const override;
        virtual Image* outline_stars(Stars* stars) noexcept override;
    };
}
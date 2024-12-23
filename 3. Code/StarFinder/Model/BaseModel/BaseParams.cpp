#include "BaseModel.h"

namespace model::base {
    Image* BaseParams::new_image(data_structures::Coordinates shape) const {
        return new BaseImage(shape);
    }

    Stars* BaseParams::new_stars() const {
        return new BaseStars();
    }

    BaseParams::~BaseParams() noexcept {}
}
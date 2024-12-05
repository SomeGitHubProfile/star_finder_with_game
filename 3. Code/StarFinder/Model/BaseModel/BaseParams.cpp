#include "BaseModel.h"

namespace model::base {
    Image* BaseParams::new_image() const {
        return new BaseImage();
    }

    Stars* BaseParams::new_stars() const {

    }
    BaseParams::~BaseParams() noexcept {}
}
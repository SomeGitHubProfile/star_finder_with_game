#include "BaseModel.h"

namespace model::base {
    Image* BaseParams::new_image() const {
        //return new BaseImage();
        return nullptr;
    }

    Stars* BaseParams::new_stars() const {
        return nullptr;
    }

    BaseParams::~BaseParams() noexcept {}
}
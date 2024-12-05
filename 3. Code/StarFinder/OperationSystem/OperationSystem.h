#include "../Model/Model.h"

namespace operation_system {
    class FileSystem {
        virtual model::Image* load_image(const char* path) = 0;
        virtual void save_image(model::Image* image, const char* path) = 0;
        virtual const char* load_text(const char* path) = 0;
        virtual void save_text(const char* text, const char* path) = 0;
    };

    class Console {

    };
}
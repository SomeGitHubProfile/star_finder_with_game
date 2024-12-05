#pragma once

#include "../Model/Model.h"

namespace operation_system {
    class FileSystem {
        virtual model::Image* load_image(const char* path) = 0;
        virtual void save_image(model::Image* image, const char* path) = 0;
        virtual const char* load_text(const char* path) = 0;
        virtual void save_text(const char* text, const char* path) = 0;
    };

    class Console {
        virtual void write(const char* text) = 0;
        virtual void write_line(const char* text) = 0;
        virtual char read_char() = 0;
        virtual int read_number() = 0; // TODO
        virtual const char* read_line() = 0;
    };
}
#pragma once

namespace config {
    class Config {
        virtual void load(const char* path) = 0; // TODO maybe static?
        virtual void save() const = 0;
    };
}
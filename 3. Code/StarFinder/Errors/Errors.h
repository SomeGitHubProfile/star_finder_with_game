#pragma once

namespace errors {
    class BaseError {
        const char* text;
    };

    class FileError : public BaseError {
        const char* file_path;
    };

    class FileLoadError : public FileError {};

    class FileReadError : public FileError {
        size_t symbol_index;
    };

    class FileSaveError : public FileError {};
}
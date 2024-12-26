#pragma once

namespace errors {
    class BaseError {
    public:
        const char* text;
        BaseError(const char* _text)
            : text(_text) {}
    };

    class FileError : public BaseError {
    public:
        const char* file_path;
        FileError(const char* text, const char* _file_path)
            : BaseError(text),
            file_path(_file_path) {}
    };

    class FileLoadError : public FileError {
    public:
        FileLoadError(const char* text, const char* file_path)
            : FileError(text, file_path) {}
    };

    class FileReadError : public FileError {
    public:
        const size_t symbol_index;
        FileReadError(const char* text, const char* file_path, const size_t _symbol_index)
            : FileError(text, file_path),
            symbol_index(_symbol_index) {}
    };

    class FileSaveError : public FileError {
    public:
        FileSaveError(const char* text, const char* file_path)
            : FileError(text, file_path) {}
    };
}
#pragma once

#include "../DataStructures/DataStructures.h"

namespace model {
    class Pixel {
    public:
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
        virtual ~Pixel() noexcept = 0;
    };

    class Image {
    public:
        const size_t size;
        const data_structures::Coordinates shape;

        template <typename T>
        class ImageIterator {
        public:
            virtual T& operator*() = 0;
            virtual ImageIterator<T>& operator++() = 0;
            virtual ImageIterator<T>& operator++(int) = 0;
            virtual bool operator==(const ImageIterator<T>& rhs) const = 0;
            virtual bool operator!=(const ImageIterator<T>& rhs) const = 0;
            virtual data_structures::Coordinates get_coordinates() const noexcept = 0;
        };

        typedef ImageIterator<Pixel> image_iterator;
        typedef ImageIterator<const Pixel> const_image_iterator;

        virtual void outline_star(data_structures::Coordinates center) = 0;
        virtual Pixel& operator[](data_structures::Coordinates) = 0;
        virtual image_iterator begin() noexcept = 0;
        virtual image_iterator end() noexcept = 0;
        virtual const_image_iterator begin() const noexcept = 0;
        virtual const_image_iterator end() const noexcept = 0;
    };

    class Star {
    public:
        const data_structures::Coordinates coordinates;
        const size_t radius;
        virtual ~Star() noexcept = 0;
    };

    class Stars {
    public:
        const size_t size;

        template <typename T>
        class StarsIterator {
        public:
            virtual StarsIterator& operator=(const StarsIterator& rhs) = 0;
            virtual T& operator*() = 0;
            virtual StarsIterator<T>& operator++() = 0;
            virtual StarsIterator<T>& operator++(int) = 0;
            virtual bool operator==(const StarsIterator<T>& rhs) const = 0;
            virtual bool operator!=(const StarsIterator<T>& rhs) const = 0;
            virtual size_t get_index() const noexcept = 0;
        };

        typedef StarsIterator<Star> stars_iterator;
        typedef StarsIterator<const Star> const_stars_iterator;

        virtual Star& operator[](size_t) = 0;
        virtual stars_iterator begin() noexcept = 0;
        virtual stars_iterator end() noexcept = 0;
        virtual const_stars_iterator begin() const noexcept = 0;
        virtual const_stars_iterator end() const noexcept = 0;
    };

    class Params {
    public:
        Image* source_image;

        virtual Image* new_image() const = 0;
        virtual Stars* new_stars() const = 0;
    };

    class StarFinder {
        virtual void find_stars() = 0;
        virtual Image* get_image() = 0;
        virtual Stars* get_stars() = 0;
    };
}
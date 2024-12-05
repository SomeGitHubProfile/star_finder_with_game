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

    template <typename T>
    class ImageIterator {
    public:
        virtual T& operator*() = 0;
        virtual ImageIterator& operator++() noexcept = 0;
        virtual bool operator!=(const ImageIterator& rhs) const noexcept = 0;
        virtual DataStructures::Coordinates get_coordinates() const noexcept = 0;
    };

    typedef ImageIterator<Pixel> image_iterator;
    typedef ImageIterator<const Pixel> const_image_iterator;

    class Image {
    public:
        const size_t size;

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

    template <typename T>
    class StarsIterator {
    public:
        virtual T& operator*() = 0;
        vritual StarsIterator& operator++() noexcept = 0;
        virtual bool operator!=(const StarsIterator& rhs) const noexcept = 0;
        virtual size_t get_index() const noexcept = 0;
    };

    typedef StarsIterator<Star> stars_iterator;
    typedef StarsIterator<const Star> const_stars_iterator;

    class Stars {
    public:
        const size_t size;

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
        virtual Stars* new_star() const = 0;
    };

    class StarFinder {
        virtual void find_stars() = 0;
        virtual Image* get_image() = 0;
        virtual Stars* get_stars() = 0;
    };
}
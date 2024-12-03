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
        virtual ImageIterator& operator++() = 0;
        virtual bool operator!=(const ImageIterator& rhs) const noexcept = 0;
        virtual DataStructures::Coordinates get_coordinates() const = 0;
    };

    // TODO
    typedef ImageIterator<Pixel> image_iterator;
    typedef ImageIterator<const Pixel> const_image_iterator;

    class Image {
    public:
        const size_t size;

        virtual void outline_star(data_structures::Coordinates center) noexcept = 0;
        virtual Pixel& operator[](data_structures::Coordinates) noexcept = 0;
        virtual image_iterator begin() noexcept = 0;
        virtual image_iterator end() noexcept = 0;
        virtual const_image_iterator begin() const noexcept = 0;
        virtual const_image_iterator end() const noexcept = 0;
    };

    class Star {
    public:

    };

    class StarsIterator {
    public:

    };

    class Stars {
    public:
        
    };
}
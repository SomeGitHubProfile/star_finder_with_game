#include "../DataStructures/DataStructures.h"

namespace Model {
    class Pixel {
    public:
        unsigned char red;
        unsigned char green;
        unsigned char blue;
        unsigned char alpha;
        virtual ~Pixel() = 0;
    };

    class ImageIterator {

    };

    class Image {
    public:
        const size_t size;

        virtual void outline_star(DataStructures::Coordinates center) = 0;
        virtual Pixel& operator[](DataStructures::Coordinates) = 0;
    };
}
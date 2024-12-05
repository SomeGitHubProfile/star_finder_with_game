#pragma once

#include "../Model.h"

namespace model::base {
    struct BasePixel : public Pixel {
    public:
        virtual ~BasePixel() noexcept override;
    };

    class BaseImage : public Image {
    public:
        template <typename T>
        class BaseImageIterator : public ImageIterator<T> {
        private:
            BaseImage& image;
            data_structures::Coordinates coordinates;

        public:
            BaseImageIterator(BaseImage& image) {
                this->image = image;
                coordinates = Coordinates(0, 0);
            }

            virtual T& operator*() override {
                return image[coordinates];
            }

            virtual ImageIterator& operator++() override {
                if (coordinates.x + 1 == image.shape.x) {
                    coordinates.x = 0;
                    ++coordinates.y;
                    return;
                }
                ++coordinates.x;
            }
            
            virtual bool operator==(const ImageIterator& rhs) const override {
                return this == &rhs || &image == &rhs.image && coordinates == rhs.coordinates;
            }

            virtual bool operator!=(const ImageIterator& rhs) const override {
                return !(*this == rhs);
            }
            virtual inline data_structures::Coordinates get_coordinates() const noexcept override {
                return coordinates;
            }
        };

        typedef BaseImageIterator<BasePixel> base_image_iterator;
        typedef BaseImageIterator<const BasePixel> const_base_image_iterator;

        virtual void outline_star(data_structures::Coordinates center) override;
        virtual Pixel& operator[](data_structures::Coordinates) override;
        virtual image_iterator begin() noexcept override;
        virtual image_iterator end() noexcept override;
        virtual const_image_iterator begin() const noexcept override;
        virtual const_image_iterator end() const noexcept override;
    };

    struct BaseStar : public Star {
    public:
        virtual ~BaseStar() noexcept override;
    };

    class BaseStars : public Stars {
    public:
        template <typename T>
        class StarsIterator {
        private:
            BaseStars& stars;
            size_t index;

        public:
            virtual T& operator*() override {
                return stars[index];
            }

            virtual StarsIterator<T>& operator++() override {
                ++index;
                return index;
            }

            virtual StarsIterator<T>& operator++(int) override {
                size_t previous_index = index;
                ++index;
                return previous_index;
            }

            virtual bool operator==(const StarsIterator<T>& rhs) const override {
            }

            virtual bool operator!=(const StarsIterator<T>& rhs) const override {
            }

            virtual size_t get_index() const noexcept override {
                return 
            }
        };

        typedef StarsIterator<Star> stars_iterator;
        typedef StarsIterator<const Star> const_stars_iterator;

        virtual Star& operator[](size_t) = 0;
        virtual stars_iterator begin() noexcept = 0;
        virtual stars_iterator end() noexcept = 0;
        virtual const_stars_iterator begin() const noexcept = 0;
        virtual const_stars_iterator end() const noexcept = 0;
    };

    struct BaseParams : public Params {
    public:
        virtual Image* new_image() const override;
        virtual Stars* new_stars() const override;
        virtual ~BaseParams() noexcept;
    };

    class BaseStarFinder : public StarFinder {

    };
}
#pragma once

#include "../Model.h"

namespace model::base {
    struct BasePixel : public Pixel {
    public:
        virtual ~BasePixel() noexcept override;
    };

    class BaseImage : public Image {
    private:
        BasePixel** matrix;
    public:
        template <typename T>
        class BaseImageIterator : public ImageIterator<T> {
        private:
            BaseImage& image;
            data_structures::Coordinates coordinates;

        public:
            BaseImageIterator(BaseImage& img)
                : image(img), coordinates(0, 0) {}

            BaseImageIterator(const BaseImageIterator<T>& rhs)
                : image(rhs.image), coordinates(rhs.coordinates) {}

            virtual T& operator*() override {
                return image[coordinates];
            }

            virtual BaseImageIterator<T>& operator++() override {
                if (coordinates.x + 1 < image.shape.x) {
                    ++coordinates.x;
                } else {
                    coordinates.x = 0;
                    ++coordinates.y;
                }
                return *this;
            }

            virtual BaseImageIterator<T>& operator++(int) override {
                BaseImageIterator ret(*this);
                ++*this;
                return ret;
            }
            
            bool operator==(const ImageIterator<T>& rhs) const {
                return this == &rhs || &image == &rhs.image && coordinates == rhs.coordinates;
            }

            virtual bool operator==(const Iterator<T>* const rhs) const override {
                ImageIterator<T>* iterator = dynamic_cast<ImageIterator<T>*>(rhs);
                return iterator != nullptr && *this == *iterator;
            }

            bool operator!=(const ImageIterator<T>& rhs) const {
                return !(*this == rhs);
            }

            virtual bool operator!=(const Iterator<T>* const rhs) const override {
                ImageIterator<T>* iterator = dynamic_cast<ImageIterator<T>*>(rhs);
                return iterator == nullptr || *this != *iterator;
            }

            virtual inline data_structures::Coordinates get_coordinates() const noexcept override {
                return coordinates;
            }
            
            virtual ImageIterator<T>* copy() const noexcept override {
                return new BaseImageIterator<T>(*this);
            }
        };

        typedef BaseImageIterator<BasePixel> base_image_iterator;
        typedef BaseImageIterator<const BasePixel> const_base_image_iterator;

        typedef iterators::IteratorWrapper<BasePixel> base_image_iterator_wrapper;
        typedef iterators::IteratorWrapper<const BasePixel> const_base_image_iterator_wrapper;

        BaseImage(data_structures::Coordinates shape);

        virtual void outline_star(data_structures::Coordinates center) override;
        virtual BasePixel& operator[](data_structures::Coordinates) override;
        virtual base_image_iterator_wrapper begin() noexcept override;
        virtual base_image_iterator_wrapper end() noexcept override;
        virtual const_base_image_iterator_wrapper begin() const noexcept override;
        virtual const_base_image_iterator_wrapper end() const noexcept override;
    };

    struct BaseStar : public Star {
    public:
        virtual ~BaseStar() noexcept override;
    };

    class BaseStars : public Stars {
    public:
        template <typename T>
        class BaseStarsIterator {
        private:
            BaseStars& stars;
            size_t index;

        public:
            BaseStarsIterator(BaseStars& stars) {
                this->stars = stars;
                index = 0;
            }

            BaseStarsIterator(BaseStarsIterator<T>& rhs) {
                stars = rhs.stars;
                index = rhs.index;
            }

            virtual BaseStarsIterator<T>& operator=(const BaseStarsIterator& rhs) override {
                if (this == &rhs) {
                    return *this;
                }

                stars = rhs.stars;
                index = rhs.index;
                return *this;
            }

            virtual T& operator*() override {
                return stars[index];
            }

            virtual BaseStarsIterator<T>& operator++() override {
                ++index;
                return *this;
            }

            virtual BaseStarsIterator<T>& operator++(int) override {
                BaseStarsIterator<T> ret(*this);
                ++*this;
                return ret;
            }

            bool operator==(const BaseStarsIterator<T>& rhs) const {
                return this == &rhs || &stars == &rhs.stars && index == rhs.index;
            }

            virtual bool operator==(const Iterator<T>* const rhs) const override {
                BaseStarsIterator<T>* iterator = dynamic_cast<BaseStarsIterator<T>*>(rhs);
                return iterator != nullptr && *this == *iterator;
            }

            bool operator!=(const BaseStarsIterator<T>& rhs) const {
                return !(*this == rhs);
            }

            virtual bool operator!=(const Iterator<T>* const rhs) const override {
                BaseStarsIterator<T>* iterator = dynamic_cast<BaseStarsIterator<T>*>(rhs);
                return iterator == nullptr || *this != *iterator;;
            }

            virtual inline size_t get_index() const noexcept override {
                return index;
            }

            virtual StarsIterator<T>* copy() const noexcept override {
                return new BaseStarsIterator<T>(*this);
            }
        };

        typedef BaseStarsIterator<Star> base_stars_iterator;
        typedef BaseStarsIterator<const Star> const_base_stars_iterator;

        virtual Star& operator[](size_t) = 0;
        virtual stars_iterator begin() noexcept = 0;
        virtual stars_iterator end() noexcept = 0;
        virtual const_stars_iterator begin() const noexcept = 0;
        virtual const_stars_iterator end() const noexcept = 0;
    };

    struct BaseParams : public Params {
    public:
        virtual Image* new_image(data_structures::Coordinates) const override;
        virtual Stars* new_stars() const override;
        virtual ~BaseParams() noexcept;
    };

    class BaseStarFinder : public StarFinder {

    };
}
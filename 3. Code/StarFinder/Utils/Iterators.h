namespace iterators {
    template <typename T>
    class Iterator {
    public:
        virtual Iterator<T>& operator=(const Iterator<T>& rhs) = 0;
        virtual T& operator*() = 0;
        virtual Iterator<T>& operator++() = 0;
        virtual Iterator<T>& operator++(int) = 0;
        virtual bool operator==(const Iterator<T>& rhs) const = 0;
        virtual bool operator!=(const Iterator<T>& rhs) const = 0;
        virtual Iterator<T>* copy() const noexcept = 0;
    };


    template <typename T>
    class IteratorWrapper {
    protected:
        Iterator<T>* iterator;
    public:
        IteratorWrapper<T>(Iterator<T>* iterator) {
            this->iterator = iterator;
        }

        IteratorWrapper<T>& operator=(const IteratorWrapper<T>& rhs) {
            if (this == &rhs) {
                return *this;
            }
            delete iterator;
            iterator = rhs.iterator->copy();
            return *this;
        }

        T& operator*() {
            return **iterator;
        }

        IteratorWrapper<T>& operator++() {
            ++*iterator;
            return *this;
        }

        IteratorWrapper<T>& operator++(int) {
            IteratorWrapper<T> wrapper(iterator->copy());
            ++*iterator;
            return wrapper;
        }

        bool operator==(const IteratorWrapper<T>& rhs) const {
            return *iterator == *rhs.iterator;
        }

        bool operator!=(const IteratorWrapper<T>& rhs) const {
            return *iterator != *rhs.iterator;
        }

        ~IteratorWrapper<T>() {
            delete iterator;
        }
    };
}
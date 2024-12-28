#pragma once

#include <utility>

namespace data_structures {
    template <typename T>
    struct DisjointSet {
    public:
        struct Node {
            const T value;
            size_t rank;
            size_t index;
            Node* parent;

            Node(T _value, size_t _index)
                : value(_value),
                index(_index),
                rank(0),
                parent(this) {}

            Node(T _value, size_t _index, size_t _rank)
                : value(_value),
                index(_index),
                rank(_rank),
                parent(this) {}

            Node(T _value, size_t _index, size_t _rank, Node* _parent)
                : value(_value),
                index(_index),
                rank(_rank),
                parent(_parent) {}
        };

        size_t size;
        Node** set;

        DisjointSet<T>(size_t _size): size(_size) {
            set = new Node*[size];
            for (size_t i = 0; i < size; ++i) {
                set[i] = nullptr;
            }
        }

        DisjointSet<T>(DisjointSet<T>& rhs)
            : size(rhs.size),
            set(copy_set(rhs)) {}

        DisjointSet<T>& operator=(DisjointSet<T>& rhs) {
            clear_set();
            size = rhs.size;
            set = copy_set(rhs);
        }

        ~DisjointSet<T>() {
            clear_set();
        }

        static Node** copy_set(DisjointSet<T>& rhs) noexcept {
            Node** new_set = new Node*[rhs.size];
            for (size_t i = 0; i < rhs.size; ++i) {
                new_set[i] = nullptr;
            }

            for (size_t i = 0; i < rhs.size; ++i) {
                if (new_set[i]) {
                    continue;
                }

                Node* node = rhs.set[i];
                Node* parent = rhs.find_parent(i);
                if (!new_set[parent->index]) {
                    new_set[parent->index] = new Node(parent->value, parent->index, parent->rank);
                }
                new_set[i] = new Node(node->value, node->index, node->rank, new_set[parent->index]);
            }
            return new_set;
        }

        void clear_set() {
            for (size_t i = 0; i < size; ++i) {
                if (set[i]) {
                    delete set[i];
                }
            }
            delete[] set;
        }

        void add_node(size_t index, const T& value) {
            set[index] = new Node(value, index);
        }

        Node* find_parent(Node* node) {
            if (node->parent == node) {
                return node;
            }
            return node->parent = find_parent(node->parent);
        }

        Node* find_parent(size_t index) {
            return find_parent(set[index]);
        }

        void unite(size_t a, size_t b) {
            Node* a_parent = find_parent(a);
            Node* b_parent = find_parent(b);
            if (a_parent == b_parent) {
                return;
            }
            if (b_parent->rank < a_parent->rank) {
                std::swap(a_parent, b_parent);
            } else if (a_parent->rank == b_parent->rank) {
                ++b_parent->rank;
            }
            set[a]->parent = a_parent->parent = b_parent;
            return;
        }

        bool connected(size_t a, size_t b) {
            return find_parent(set[a]) == find_parent(set[b]);
        }
    };
}
#pragma once

#include <utility>

namespace data_structures {
    template <typename T>
    struct DisjointSet {
    public:
        struct Node {
            const T value;
            Node* parent;
            size_t rank;

            Node(T _value) : value(_value), parent(this), rank(0) {}
        };

        size_t size;
        Node** set;

        DisjointSet<T>(size_t _size): size(_size) {
            set = new Node*[size];
            for (size_t i = 0; i < size; ++i) {
                set[i] = nullptr;
            }
        }

        ~DisjointSet<T>() {
            for (size_t i = 0; i < size; ++i) {
                if (set[i] != nullptr) {
                    delete set[i];
                }
            }
            delete[] set;
        }

        Node* find_parent(Node* node) {
            if (node->parent == node) {
                return node;
            }
            return node->parent = find_parent(node->parent);
        }

        void unite(size_t a, size_t b) {
            Node* a_parent = find_parent(set[a]);
            Node* b_parent = find_parent(set[b]);
            if (a_parent == b_parent) {
                return;
            }
            if (a_parent->rank < b_parent->rank) {
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
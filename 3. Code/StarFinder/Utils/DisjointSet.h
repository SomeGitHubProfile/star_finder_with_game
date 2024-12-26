#pragma once

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

        Node* find_parent(Node* node) {
            if (node->parent == node) {
                return node;
            }
            return node->parent = find_parent(node->parent);
        }

        void unite(Node* a, Node* b) {
            Node* a_parent = find_parent(a);
            Node* b_parent = find_parent(b);
            if (a_parent == b_parent) {
                return;
            }
            if (a_parent->rank < b_parent->rank) {
                swap(a_parent, b_parent);
            } else if (a_parent->rank == b_parent->rank) {
                ++b_parent->rank;
            }
            a->parent = a_parent->parent = b_parent;
            return;
        }

        bool connected(Node* a, Node* b) {
            return find_parent(a) == find_parent(b);
        }
    };
}
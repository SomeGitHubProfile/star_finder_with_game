#pragma once

namespace data_structures {
    struct Coordinates {
        size_t x;
        size_t y;
    };

    template <typename T>
    struct DisjointUnionSet {
    public:
        struct Node {
            T value;
            Node* parent;
            size_t rank;
        };

        Node* find_parent(Node* node) {
            if (node->parent == node) {
                return node;
            }
            return find_parent(node->parent);
        }

        Node* create_set(Node* new_node, const T& value) {
            new_node->data = value;
            new_node->parent = new_node;
            new_node->rank = 0;
            return new_node;
        }

        void unite(Node* a, Node* b) {
            Node* root_a = find_parent(a);
            Node* root_b = find_parent(b);
            if (root_a == root_b) {
                return;
            }
            if (root_b->rank < root_a->rank) {
                swap(root_a, root_b);
            }
            else if (root_a == root_b) {
                ++root_b->rank;
            }
            a->parent = root_a->parent = root_b;
        }

        bool connected(Node* a, Node* b) {
            return find_parent(a) == find_parent(b);
        }
    };
}
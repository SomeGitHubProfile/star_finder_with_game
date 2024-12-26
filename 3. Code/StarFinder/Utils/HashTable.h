#pragma once

#include "Coordinates.h"

namespace data_structures {
    struct HashTable {
    public:
        struct Node {
            Coordinates coordinates;
            Node* next;

            Node(Coordinates _coordinates)
                : coordinates(_coordinates),
                next(nullptr) {}
        };

    private:
        Node** table;

    public:
        const size_t size;

        HashTable(size_t _size) : size(_size) {
            table = new Node*[size];
            for (size_t i = 0; i < size; ++i) {
                table[i] = nullptr;
            }
        }

        ~HashTable() {
            for (size_t i = 0; i < size; ++i) {
                Node* current = table[i];
                while (current != nullptr) {
                    Node* tmp = current;
                    current = current->next;
                    delete tmp;
                }
            }
            delete[] table;
        }

        inline size_t hash(const Coordinates& coordinates) {
            return ((coordinates.x * 18181) + (coordinates.y * 18899)) % size;
        }

        void insert(const Coordinates& coordinates) {
            size_t index = hash(coordinates);
            if (table[index] == nullptr) {
                table[index] = new Node(coordinates);
            }
            else {
                Node* current = table[index];
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new Node(coordinates);
            }
            return;
        }

        Node* search(const Coordinates& coordinates) {
            size_t index = hash(coordinates);
            Node* current = table[index];
            while (current != nullptr) {
                if (current->coordinates.x == coordinates.x
                    && current->coordinates.y == coordinates.y) {
                    return current;
                }
                current = current->next;
            }
            return nullptr;
        }
    };
}
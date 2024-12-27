#pragma once

#include "Coordinates.h"

namespace data_structures {
    template <typename T>
    struct HashTable {
    public:
        struct Node {
            T value;
            Node* next;

            Node(T _value)
                : value(_value),
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

        inline size_t hash(const T& value) {
            return value.hash() % size;
        }

        Node* insert(const T& value) {
            size_t index = hash(value);
            if (table[index] == nullptr) {
                return table[index] = new Node(value);
            }
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            return current->next = new Node(value);
        }

        Node* search(const T& value) {
            size_t index = hash(value);
            Node* current = table[index];
            while (current != nullptr) {
                if (value == current->value) {
                    return current;
                }
                current = current->next;
            }
            return nullptr;
        }
    };
}
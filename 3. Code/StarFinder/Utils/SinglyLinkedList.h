#pragma once

#include <type_traits>
#include "Coordinates.h"

namespace data_structures {
	template <typename T>
	struct SinglyLinkedList {
	public:
		struct Node {
			T value;
			Node* next;

			Node(T _value, Node* _next) : value(_value), next(_next) {}
			
		};

		size_t size;
		Node* begin;

		SinglyLinkedList<T>() : size(0), begin(nullptr) {}

		~SinglyLinkedList<T>() {
			Node* current = begin;
			while (current != nullptr) {
				Node* next = current->next;
				delete current;
				current = next;
			}
		}

		Node* insert(const T& value) {
			++size;
			return begin = new Node(value, begin);
		}

		Node* insert_after(Node* node, const T& value) {
			++size;
			return node->next = new Node(value, node->next);
		}
	};
}
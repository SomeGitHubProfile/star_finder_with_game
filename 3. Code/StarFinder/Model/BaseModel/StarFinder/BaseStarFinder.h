#pragma once

#include <memory>

#include "../../StarFinder.h"
#include "../Params/StarFinder/BaseStarFinderParams.h"
#include "../../../Utils/DisjointSet.h"
#include "../../../Utils/SinglyLinkedList.h"
#include "../../../Utils/HashTable.h"

namespace model::base {
    class BaseStarFinder : public StarFinder {
    private:
        typedef data_structures::DisjointSet<data_structures::Coordinates> DisjointUnionSet;
        typedef data_structures::SinglyLinkedList<data_structures::Coordinates> Component;
        typedef std::unique_ptr<Component> ComponentPtr;
        typedef data_structures::SinglyLinkedList<ComponentPtr> Components;

        struct HashTableValue {
            data_structures::Coordinates coordinates;
            Components::Node* component_node;

            HashTableValue(data_structures::Coordinates, Components::Node* component_node);
            size_t hash() const noexcept;
            bool operator==(const HashTableValue& rhs) const noexcept;
            bool operator!=(const HashTableValue& rhs) const noexcept;
        };

        typedef data_structures::HashTable<HashTableValue> ComponentsHashTable;

        params::BaseStarFinderParams star_finder_params;

        images::GrayImage* get_boundaries_image() const noexcept;
        size_t get_index_in_disjoint_set(data_structures::Coordinates coordinates) const noexcept;
        DisjointUnionSet make_disjoint_set() const noexcept;
        ComponentPtr make_component_ptr(data_structures::Coordinates coordinates) const noexcept;
        Components get_components(DisjointUnionSet disjoint_set) const noexcept;
        Star* get_star(Component* component) const noexcept;
    public:
        BaseStarFinder(params::BaseStarFinderParams);

        virtual Stars* find_stars() noexcept override;
    };
}
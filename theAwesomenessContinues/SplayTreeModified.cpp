#include "SplayTree.hpp"
#include <cassert>


bool SplayTree::Node::operator<(const Node& other) const {
    return *data < *other.data;
}

bool SplayTree::Node::operator==(const Node& other) const {
    return *data == *other.data;
}

bool SplayTree::Node::operator!=(const Node& other) const {
    return !(this == other);
}


#include "Hash.hpp"

Hash::Hash(int size) : size(size) {}

void Hash::update(int newSize) {
	size = newSize;
}

int Hash::operator()(int input) const {
	return input & size;
}


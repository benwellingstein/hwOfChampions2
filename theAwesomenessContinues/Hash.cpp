#include "Hash.hpp"

Hash::Hash(int size) : size(size) {}

void Hash::update() {
	size = size*2 + 1;
}

int Hash::operator()(int input) const {
	return input % size;
}


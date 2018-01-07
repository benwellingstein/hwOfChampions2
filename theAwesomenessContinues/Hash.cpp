#include "Hash.hpp"

Hash::Hash(int s) : size(2*s+1) {}

void Hash::update() {
	size = size*2 + 1;
}

int Hash::operator()(int input) const {
	return input % size;
}


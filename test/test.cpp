#include "TLA/math/vector.h"
#include "TLA/exceptions.h"
#include <iostream>

int main() {
	tla::vector::Vector <int> myVec{5, 4, 7, 8};
	std::cout << myVec[2];
}
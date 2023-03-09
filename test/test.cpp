#include "TLA/math/vector.h"
#include "TLA/exceptions.h"
#include <iostream>

int main() {
	tla::vector::Vector <int> myVec{5, 4, 7, 8};
	for (int i = 0; i < 20; i ++) {
		myVec.push_back(i);
		std::cout << myVec.size() << ' ' << myVec.capacity() << '\n';
		for (int j = 0; j < myVec.size(); j ++) {
			std::cout << myVec[j] << ' ';
		}
		std::cout << '\n' << "----------\n";
	}
	for (int i = 0; i < 20; i ++) {
		myVec.pop_back();
		std::cout << myVec.size() << ' ' << myVec.capacity() << '\n';
		for (int j = 0; j < myVec.size(); j ++) {
			std::cout << myVec[j] << ' ';
		}
		std::cout << '\n' << "----------\n";
	}
}
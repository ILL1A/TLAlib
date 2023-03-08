#ifndef _VECTOR_H_
#define _VECTOR_H_ 1

#include <vector>
#include <initializer_list>

namespace tla {
	namespace vector {
		template <typename T, class U = std::vector<int>>
		class Vector {
		private:
			T* vector_;
			int vector_size_;
		public:
			Vector (std::initializer_list <T> clist);
			Vector (T* ptr, int sz);
			Vector (std::vector <T> vec);
			Vector (U::iterator it, int sz);
			T& operator[](int index);
		};
	}
}

#include "../src/math/vector.cpp"

#endif // _VECTOR_H_
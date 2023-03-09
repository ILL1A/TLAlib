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
			size_t size_;
			size_t capacity_;
		public:
			Vector();
			Vector(std::initializer_list <T> clist);
			Vector(T* ptr, size_t sz);
			Vector(std::vector <T> vec);
			Vector(U::iterator it, size_t sz);
			void push_back(const T& value);
			void pop_back();
			size_t capacity();
			size_t size();
			T& operator[](size_t index);
		};
	}
}

#include "../src/math/vector.cpp"

#endif // _VECTOR_H_
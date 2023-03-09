#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_ 1

#include "TLA/math/vector.h"
#include "TLA/exceptions.h"
#include <vector>
#include <initializer_list>

namespace tla {
	namespace vector {
		template <typename T, class U>
		Vector<T, U>::Vector (std::initializer_list <T> clist) {
			vector_size_ = clist.size();
			vector_ = new T[vector_size_];
			int i = 0;
			for (auto it : clist) {
				*(vector_ + i) = it;
				i ++;
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector (T* ptr, int sz) {
			vector_size_ = sz;
			vector_ = new T[vector_size_];
			for (int i = 0; i < sz; i ++) {
				*(vector_ + i) = *(ptr + i);
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector (std::vector <T> vec) {
			vector_size_ = vec.size();
			typename std::vector <T>::iterator it = vec.begin();
			vector_ = new T[vector_size_];
			for (int i = 0; i < vector_size_; i ++) {
				*(vector_ + i) = *it;
				if (i < vector_size_ - 1) it = next(it);
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector (U::iterator it, int sz) {
			vector_size_ = sz;
			vector_ = new T[vector_size_];
			for (int i = 0; i < vector_size_; i ++) {
				*(vector_ + i) = *it;
				if (i < vector_size_ - 1) it = next(it);
			}
		}
		template <typename T, class U>
		inline T& Vector<T, U>::operator[](int index) {
			if (index >= vector_size_ || index < 0) throw IndexOutsideTheVector("Index is outside the vector borders");
	        return *(vector_ + index);
	    }
	}
}

#endif // _VECTOR_CPP_
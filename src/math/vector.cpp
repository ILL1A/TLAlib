#ifndef _VECTOR_CPP_
#define _VECTOR_CPP_ 1

#include "TLA/math/vector.h"
#include "TLA/exceptions.h"
#include <vector>
#include <initializer_list>

namespace tla {
	namespace vector {
		template <typename T, class U>
		Vector<T, U>::Vector() : size_(0), capacity_(0) {}
		template <typename T, class U>
		Vector<T, U>::Vector(std::initializer_list <T> clist) {
			size_ = clist.size();
			capacity_ = size_;
			vector_ = new T[size_];
			size_t i = 0;
			for (auto it : clist) {
				*(vector_ + i) = it;
				i ++;
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector(T* ptr, size_t sz) {
			size_ = sz;
			capacity_ = size_;
			vector_ = new T[size_];
			for (size_t i = 0; i < sz; i ++) {
				*(vector_ + i) = *(ptr + i);
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector(std::vector <T> vec) {
			size_ = vec.size();
			capacity_ = size_;
			typename std::vector <T>::iterator it = vec.begin();
			vector_ = new T[size_];
			for (size_t i = 0; i < size_; i ++) {
				*(vector_ + i) = *it;
				if (i < size_ - 1) it = next(it);
			}
		}
		template <typename T, class U>
		Vector<T, U>::Vector(U::iterator it, size_t sz) {
			size_ = sz;
			capacity_ = size_;
			vector_ = new T[size_];
			for (size_t i = 0; i < size_; i ++) {
				*(vector_ + i) = *it;
				if (i < size_ - 1) it = next(it);
			}
		}
		template <typename T, class U>
		void Vector<T, U>::push_back(const T& value) {
			if (size_ == capacity_) {
				if (capacity_ == 0) capacity_ = 1;
				else capacity_ *= 2;
				T* new_vector = new T[capacity_];
				for (size_t i = 0; i < size_; i ++) {
					new_vector[i] = vector_[i];
				}
				delete[] vector_;
				vector_ = new_vector;
			}
			vector_[size_ ++] = value;
		}
		template <typename T, class U>
		void Vector<T, U>::pop_back() {
			if (size_ == 0) throw EraseFromEmptyVector("You can't pop_back from empty vector");
			size_ --;
		}
		template <typename T, class U>
		size_t Vector<T, U>::capacity() {
			return capacity_;
		}
		template <typename T, class U>
		size_t Vector<T, U>::size() {
			return size_;
		}
		template <typename T, class U>
		inline T& Vector<T, U>::operator[](size_t index) {
			if (index >= size_ || index < 0) throw IndexOutsideTheVector("Index is outside the vector borders");
	        return *(vector_ + index);
	    }
	}
}

#endif // _VECTOR_CPP_
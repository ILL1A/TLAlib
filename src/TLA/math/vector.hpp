#ifndef _VECTOR_H_
#define _VECTOR_H_ 1

#include "TLA/iterators/iterator.hpp"
#include "TLA/exceptions/vector_exceptions.hpp"
#include <vector>
#include <initializer_list>

namespace tla {
	namespace vector {
		template <typename T, class U = std::vector<int>>
		class Vector {
		public:
			class iterator: public tla::iterator::Iterator<T> {};
			iterator begin() {
				return Vector<T, U>::iterator(vector_);
			}
			iterator end() {
				return Vector<T, U>::iterator(vector_ + size_);
			}
			Vector() : size_(0), capacity_(0) {}
			Vector(std::initializer_list <T> clist) {
				size_ = clist.size();
				capacity_ = size_;
				vector_ = new T[size_];
				size_t i = 0;
				for (auto it : clist) {
					*(vector_ + i) = it;
					i ++;
				}
			}
			Vector(T* ptr, size_t sz) {
				size_ = sz;
				capacity_ = size_;
				vector_ = new T[size_];
				for (size_t i = 0; i < sz; i ++) {
					*(vector_ + i) = *(ptr + i);
				}
			}
			Vector(std::vector <T> vec) {
				size_ = vec.size();
				capacity_ = size_;
				typename std::vector <T>::iterator it = vec.begin();
				vector_ = new T[size_];
				for (size_t i = 0; i < size_; i ++) {
					*(vector_ + i) = *it;
					if (i < size_ - 1) it = next(it);
				}
			}
			Vector(U::iterator it, size_t sz) {
				size_ = sz;
				capacity_ = size_;
				vector_ = new T[size_];
				for (size_t i = 0; i < size_; i ++) {
					*(vector_ + i) = *it;
					if (i < size_ - 1) it = next(it);
				}
			}
			void push_back(const T& value) {
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
			void pop_back() {
				if (size_ == 0) throw EraseFromEmptyVector("You can't pop_back from empty vector");
				size_ --;
			}
			size_t capacity() {
				return capacity_;
			}
			size_t size() {
				return size_;
			}
			T& operator[](size_t index) {
				if (index >= size_ || index < 0) throw IndexOutsideTheVector("Index is outside the vector borders");
	        	return *(vector_ + index);
			}
		private:
			T* vector_;
			size_t size_;
			size_t capacity_;
		};
	}
}

#endif // _VECTOR_H_
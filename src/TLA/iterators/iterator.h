#ifndef _ITERATOR_H_
#define _ITERATOR_H_ 1

#include <stdio.h>

namespace tla {
	namespace iterator {
		template <typename T>
		class Iterator {
			public:
				Iterator(T* ptr) : ptr_(ptr) {}
				T& operator*() const {
					return *ptr_;
				}
				T* operator->() {
					return ptr_;
				}
				T* get() const {
					return ptr_;
				}
				Iterator<T>& operator++() {
					ptr_ ++;
					return *this;
				}
				Iterator<T> operator++(int __placeholder) {
					Iterator<T> tmp = *this;
					++ (*this);
					return tmp;
				}
				Iterator& operator--() {
					ptr_ --;
					return *this;
				}
				Iterator operator--(int __placeholder) {
					Iterator<T> tmp = *this;
					-- (*this);
					return tmp;
				}
				Iterator& operator+=(size_t __num) {
					ptr_ += __num;
					return *this;
				}
				Iterator& operator-=(size_t __num) {
					ptr_ -= __num;
					return *this;
				}
				Iterator& operator+(size_t __num) {
					ptr_ += __num;
					return *this;
				}
				Iterator& operator-(size_t __num) {
					ptr_ -= __num;
					return *this;
				}
				Iterator operator+(Iterator& __num) {
					return Iterator<T>(ptr_ + __num.get());
				}
				Iterator operator-(Iterator& __num) {
					return Iterator<T>(ptr_ - __num.get());
				}
				bool operator<(Iterator& __num) {
					return ptr_ < __num.get();
				}
				bool operator>(Iterator& __num) {
					return ptr_ > __num.get();
				}
				bool operator<=(Iterator& __num) {
					return ptr_ <= __num.get();
				}
				bool operator>=(Iterator& __num) {
					return ptr_ >= __num.get();
				}
				bool operator==(Iterator& __num) {
					return ptr_ == __num.get();
				}
				bool operator!=(Iterator& __num) {
					return ptr_ != __num.get();
				}
			protected:
				T* ptr_;
		};
	}
}

// #include "../src/iterators/iterator.cpp"

#endif // _ITERATOR_H_
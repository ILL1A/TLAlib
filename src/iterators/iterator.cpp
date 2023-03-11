#ifndef _ITERATOR_CPP_
#define _ITERATOR_CPP_ 1

#include "TLA/iterators/iterator.h"

#include <stdio.h>

namespace tla {
	namespace iterator {
		template <typename T>
		Iterator<T>::Iterator(T* ptr) : ptr_(ptr) {}
		template <typename T>
		T& Iterator<T>::operator*() const {
			return *ptr_;
		}
		template <typename T>
		T* Iterator<T>::operator->() {
			return ptr_;
		}
		template <typename T>
		T* Iterator<T>::get() const {
			return ptr_;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator++() {
			ptr_ ++;
			return *this;
		}
		template <typename T>
		Iterator<T> Iterator<T>::operator++(int __placeholder) {
			Iterator<T> tmp = *this;
			++ (*this);
			return tmp;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator--() {
			ptr_ --;
			return *this;
		}
		template <typename T>
		Iterator<T> Iterator<T>::operator--(int __placeholder) {
			Iterator<T> tmp = *this;
			-- (*this);
			return tmp;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator+=(size_t __num) {
			ptr_ += __num;
			return *this;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator-=(size_t __num) {
			ptr_ -= __num;
			return *this;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator+(size_t __num) {
			ptr_ += __num;
			return *this;
		}
		template <typename T>
		Iterator<T>& Iterator<T>::operator-(size_t __num) {
			ptr_ += __num;
			return *this;
		}
		template <typename T>
		Iterator<T> Iterator<T>::operator+(Iterator<T>& __num) {
			return Iterator<T>(ptr_ + __num.get());
		}
		template <typename T>
		Iterator<T> Iterator<T>::operator-(Iterator<T>& __num) {
			return Iterator<T>(ptr_ - __num.get());
		}
		template <typename T>
		bool Iterator<T>::operator<(Iterator<T>& __num) {
			return ptr_ < __num.get();
		}
		template <typename T>
		bool Iterator<T>::operator>(Iterator<T>& __num) {
			return ptr_ > __num.get();
		}
		template <typename T>
		bool Iterator<T>::operator<=(Iterator<T>& __num) {
			return ptr_ <= __num.get();
		}
		template <typename T>
		bool Iterator<T>::operator>=(Iterator<T>& __num) {
			return ptr_ >= __num.get();
		}
		template <typename T>
		bool Iterator<T>::operator==(Iterator<T>& __num) {
			return ptr_ == __num.get();
		}
		template <typename T>
		bool Iterator<T>::operator!=(Iterator<T>& __num) {
			return ptr_ != __num.get();
		}
	}
}

#endif // _ITERATOR_CPP_
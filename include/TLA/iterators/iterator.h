#ifndef _ITERATOR_H_
#define _ITERATOR_H_ 1

#include <stdio.h>

namespace tla {
	namespace iterator {
		template <typename T>
		class Iterator {
			public:
				Iterator(T* ptr);
				T& operator*() const;
				T* operator->();
				T* get() const;
				Iterator<T>& operator++();
				Iterator<T> operator++(int __placeholder);
				Iterator& operator--();
				Iterator operator--(int __placeholder);
				Iterator& operator+=(size_t __num);
				Iterator& operator-=(size_t __num);
				Iterator& operator+(size_t __num);
				Iterator& operator-(size_t __num);
				Iterator operator+(Iterator& __num);
				Iterator operator-(Iterator& __num);
				bool operator<(Iterator& __num);
				bool operator>(Iterator& __num);
				bool operator<=(Iterator& __num);
				bool operator>=(Iterator& __num);
				bool operator==(Iterator& __num);
				bool operator!=(Iterator& __num);
			protected:
				T* ptr_;
		};
	}
}

#include "../src/iterators/iterator.cpp"

#endif // _ITERATOR_H_
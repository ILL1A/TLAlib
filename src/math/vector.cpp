#include "TLA/math/vector.h"

namespace tla {
	namespace vector {
		template <typename T, class U = vector <int>>
		class Vector {
		private:
			T* vec;
			int vec_size;
		public:
			Vector (initializer_list <T> clist) {
				vec_size = clist.size();
				vec = new T[vector_size];
				for (int i = 0; i < vector_size; i ++) {
					*(vec + i) = clist[i];
				}
			}
			Vector (T* ptr, int sz) {
				vec_size = sz;
				vec = new T[vector_size];
				for (int i = 0; i < len; i ++) {
					*(vec + i) = &(*(ptr + i));
				}
			}
			Vector (vector <T> vec) {
				vec_size = vec.size();
				vector <T>::iterator it = vec.begin();
				vec = new T[vector_size];
				for (int i = 0; i < vector_size; i ++) {
					*(vec + i) = &(*it);
					if (i < vector_size - 1) it = next(it);
				}
			}
			Vector (U::iterator it, int sz) {
				vec_size = sz;
				vec = new T[vector_size];
				for (int i = 0; i < vector_size; i ++) {
					*(vec + i) = &(*it);
					if (i < vector_size - 1) it = next(it);
				}
			}
			T get(int idx) {
				
			}
		}
	}
}
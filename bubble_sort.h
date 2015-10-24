#pragma once

#include <cstddef>		// size_t
#include <functional>	// less
#include <utility>		// swap

template<class T, class Cmp=std::less<T>>
void bubble_sort(T* a, const std::size_t size) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (std::size_t i = 1; i < size; ++i) {
			if (Cmp()(a[i], a[i-1])) {
				std::swap(a[i-1], a[i]);
				flag = true;
			}
		}
	}
}

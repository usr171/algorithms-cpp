#pragma once

#include <cstddef>	// size_t
#include <functional>	// less
#include <utility>	//swap


template<class T, class Cmp=std::less<T>>
void selection_sort(T* a, const std::size_t size) {
	std::size_t k;	// swap index
	for (std::size_t i = 0; i < size; ++i) {
		k = i;	// default value
		for (std::size_t j = i + 1; j < size; ++j) {
			if (Cmp()(a[j], a[k]))
				k = j;
		}
		if (k != i) {
			std::swap(a[i], a[k]);
		}
	}
}

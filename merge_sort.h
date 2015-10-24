#pragma once

#include <cstddef>	// size_t
#include <functional>	// less


// merge [lo, mid) with [mid, hi)
template<typename T, typename Cmp>
void merge_sort_merge(T* a, const std::size_t lo, const std::size_t mid, const std::size_t hi, T* aux) {
	std::size_t i = lo;	// left half to merge
	std::size_t j = mid;	// right half to merge
	std::size_t k = lo;	// merge back to a
	// copy portion to be merged to aux
	for (; i < hi; ++i)
		aux[i] = a[i];
	i = lo;
	// merge back to a
	while ((i < mid) && (j < hi)) {
		if (Cmp()(aux[j], aux[i]))
			a[k++] = aux[j++];
		else
			a[k++] = aux[i++];
	}
	while (i < mid)
		a[k++] = aux[i++];
	while (j < hi)
		a[k++] = aux[j++];
}


// merge [lo, hi)
template<typename T, typename Cmp>
void merge_sort_r(T* a, const std::size_t lo, const std::size_t hi, T* aux) {
	if ((hi - lo) < 2)
		return;
	const std::size_t mid = (lo + (hi - lo) / 2);
	merge_sort_r<T, Cmp>(a, lo, mid, aux);
	merge_sort_r<T, Cmp>(a, mid, hi, aux);
	merge_sort_merge<T, Cmp>(a, lo, mid, hi, aux);
}


template<typename T, typename Cmp=std::less<T>>
void merge_sort(T* a, const std::size_t sz) {
	if (sz < 2)
		return;
	T* aux = new T[sz];
	merge_sort_r<T, Cmp>(a, 0, sz, aux);
	delete[] aux;
}

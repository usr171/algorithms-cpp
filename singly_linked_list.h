#pragma once

#include <cstddef>	// size_t


template<class T>
class SinglyLinkedList {
	struct Node {
		T val;
		Node* next;
	};
public:
	class iterator {
		friend class SinglyLinkedList;
	public:
		iterator() = default;
		~iterator() = default;
		T& operator*(void);
		iterator& operator++(void);
		bool operator==(const iterator&) const;
		bool operator!=(const iterator&) const;
	private:
		Node* node = nullptr;
	};

	SinglyLinkedList() = default;
	~SinglyLinkedList();

	iterator begin(void);
	iterator end(void);
	bool empty(void) const;
	std::size_t size(void) const;
	T& front(void);
	const T& front(void) const;
	void push_front(const T&);
	void pop_front(void);
	void clear(void);
private:
	Node* nodes = nullptr;
	std::size_t sz = 0;
};


// iterator

template<class T>
typename SinglyLinkedList<T>::iterator& SinglyLinkedList<T>::iterator::operator++() {
	node = node->next;
	return *this;
}


template<class T>
bool SinglyLinkedList<T>::iterator::operator==(const iterator& o) const {
	return (node == o.node);
}


template<class T>
bool SinglyLinkedList<T>::iterator::operator!=(const iterator& o) const {
	return (node != o.node);
}


// singly linked list

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
	clear();
}


template<class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::begin() {
	iterator it;
	it.node = nodes;
	return it;
}


template<class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::end() {
	return iterator{};
}


template<class T>
bool SinglyLinkedList<T>::empty() const {
	return (sz == 0);
}


template<class T>
std::size_t SinglyLinkedList<T>::size() const {
	return sz;
}


template<class T>
T& SinglyLinkedList<T>::front() {
	return nodes->val;
}


template<class T>
const T& SinglyLinkedList<T>::front() const {
	return nodes->val;
}


template<class T>
void SinglyLinkedList<T>::push_front(const T& val) {
	Node* newNode = new Node;
	newNode->val = val;
	newNode->next = nodes;
	nodes = newNode;
	++sz;
}


template<class T>
void SinglyLinkedList<T>::pop_front() {
	Node* next = nodes->next;
	delete nodes;
	nodes = next;
	--sz;
}


template<class T>
void SinglyLinkedList<T>::clear() {
	while (nodes != nullptr) {
		Node* del = nodes;
		nodes = nodes->next;
		delete del;
	}
	sz = 0;
}

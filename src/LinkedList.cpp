#include "LinkedList.hpp"

using namespace llist;

// ======== DE/CONSTRUCTORS ======== //

template <typename T>
LinkedList<T>::LinkedList() : _size(0) {
	_begin = new Node<T>();
	*_begin = { nullptr, _end };
	_end = new Node<T>();
	*_end = { _begin, nullptr };
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other ) : _size(other.size()), _begin(other.begin), _end(other.end) {}

// ======== PUBLIC METHODS ======== //
// ==== GETTER ==== //
template <typename T>
Node<T>* LinkedList<T>::begin() {
	return this->_begin;
}

template <typename T>
Node<T>* LinkedList<T>::end() {

	return this->_end;
}

template <typename T>
size_t LinkedList<T>::size() {
	return this->_size;
}

template <typename T>
bool LinkedList<T>::empty() {
	return this->_size == 0;
}
	
template <typename T>
Node<T>* LinkedList<T>::at(int index) {
	if(index >= size || index < 0){
		return T();
	}

	Node<T>* node = this->_begin;
	int i = 0;

	do 
		node = node.next;
	while (++i < index);

	return node;
}

template <typename T>
int LinkedList<T>::insert_at(T t, int index) {
	Node<T>* before, after;

	after = this->at(index);
	
	if(after == T())
		return 1;
	
	before = after.prev;

	Node<T>* new_node = new Node<T>();
	new_node.value = t;

	new_node.next = after;
	new_node.prev = before;

	before.next = new_node;
	after.prev = new_node;

	inc();
	return 0;
}

template <typename T>
int LinkedList<T>::insert(T t) {
	return this->insert_at(t, this->_size);
}

template <typename T>
int LinkedList<T>::push_back(T t) {
	return this->insert_at(t, this->_size);
}

template <typename T>
int LinkedList<T>::push_front(T t) {
	return this->insert_at(t, 0);
}

template <typename T>
T LinkedList<T>::remove(int index) {
	Node<T>* to_remove = this->at(index);
	
	if (to_remove != T()) {
		T value = to_remove.value;
		
		to_remove.next.prev = to_remove.prev;
		to_remove.prev.next = to_remove.next;

		return value;
	}
	else
		return {};
}

template <typename T>
LinkedList<T> LinkedList<T>::sublist(int begin, int end) {
	if (begin >= size || end >= size || begin < 0 || end < 0)
		return LinkedList<T>();

	LinkedList<T> list;

	Node<T>* node = this->at(begin);

	Node<T>* last = list.begin;

	for (int i = begin; i <= end;
	 i++){
		Node<T>* new_node = new Node<T>();
		new_node.value = node.value;
		node = node.next;
	}

	return list;
}
#ifndef LL_HPP
#define LL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

namespace llist {
	
	template <typename T>
	struct Node {
			Node* prev;
			Node* next;
			
			T value;
	};

	template <typename T>
	class LinkedList {
		
		// template <typename T>
		// class ll_iterator {
			
		// };

		// template <typename T>
		// class ll_const_iterator {
			
		// };

		// typedef LinkedList::ll_iterator<Node*> iterator;
		// typedef LinkedList::ll_const_iterator<Node*> const_iterator;

		typedef int (CompareFunc) (T, T);

	public:
		// CONSTRUCTORS
		LinkedList();
		LinkedList(const LinkedList<T>&);
		~LinkedList();

		// PUBLIC METHODS
		// GETTER
		Node<T>* begin();
		Node<T>* end();
		Node<T>* at(int);
		LinkedList<T> sublist(int, int);
		LinkedList<T> sublist(int);
		size_t size();
		bool empty();

		// UTILITY
		int insert_at(T, int);
		int insert(T);
		int push_back(T);
		int push_front(T);
		T remove(int);
		int sort(CompareFunc);

	private:
		const Node<T>* _begin;
		const Node<T>* _end;

		size_t _size;

		void inc();
		void dec();
	};

}
#endif//LL_HPP
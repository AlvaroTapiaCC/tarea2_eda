/*
 * linkedList.hpp
 *
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "node.hpp"
#include "poscode.hpp"

namespace eda {

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList();
	void insertLast(Poscode code);
	void insertFirst(Poscode code);
	void removeFirst();
	void remove(Poscode code);
	void removeAll();
	Node* find(Poscode code);
	Node* getHead();
	void print();
	virtual ~LinkedList();
};

} /* namespace eda */

#endif /* LINKEDLIST_HPP_ */

/*
 * linkedList.hpp
 *
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include "node.hpp"

namespace eda {

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList();
	void insertLast(int val);
	void insertFirst(int val);
	void removeFirst();
	void remove(int val);
	void removeAll();
	Node* find(int val);
	Node* getHead();
	void print();
	virtual ~LinkedList();
};

} /* namespace eda */

#endif /* LINKEDLIST_HPP_ */

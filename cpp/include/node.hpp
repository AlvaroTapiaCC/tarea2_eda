/*
 * node.hpp
 *
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include "poscode.hpp"

namespace eda {

class Node {
private:
	Poscode data;
	Node* ptrNext;
public:
	Node();
	Node(Poscode _data, Node* next = nullptr);
	void setData(Poscode _data);
	void setNext(Node* _next);
	Poscode getData();
	Node* getNext();
	void print();
	virtual ~Node();
};

} /* namespace eda */

#endif /* NODE_HPP_ */

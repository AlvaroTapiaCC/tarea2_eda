#include "node.hpp"
#include "poscode.hpp"
#include <iostream>

namespace eda {


Node::Node(): data(""), ptrNext(nullptr) {
}

Node::Node(Poscode code, Node* next): data(code), ptrNext(next) {

}

void Node::setData(Poscode _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

Poscode Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data.getData() ;
}

Node::~Node() {

}

} /* namespace eda */

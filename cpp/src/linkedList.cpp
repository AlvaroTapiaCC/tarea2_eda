#include "linkedList.hpp"
#include "poscode.hpp"
#include <iostream>

namespace eda {

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {

}

void LinkedList::insertFirst(Poscode code){
	Node* node = new Node(code);
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else{
		node->setNext(head);
		head = node;
	}
}

void LinkedList::insertLast(Poscode code){
	Node* node = new Node(code);
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else{
		tail->setNext(node);
		tail = node;
	}
}

void LinkedList::removeFirst(){
	Node* ptr = head;
	if (head != nullptr){
		head = head->getNext();
		if (head == nullptr){
			tail = nullptr;
		}
		delete ptr;
	}
}

void LinkedList::remove(Poscode code){
	Node* ptr = head;
	Node* ptr_prev = nullptr;
	while (ptr != nullptr){
		if (ptr->getData() == code){
			//erase node
			if (ptr_prev == nullptr) {
				head = ptr->getNext();
				delete ptr;
				ptr = head;
			}
			else{
				ptr_prev->setNext(ptr->getNext());
				delete ptr;
				ptr = ptr_prev->getNext();
			}
		}
		else{
			ptr_prev = ptr;
			ptr = ptr->getNext();
		}
	}
}

void LinkedList::removeAll(){

	while (head != nullptr){
		removeFirst();
	}
}

Node* LinkedList::find(Poscode code){
	Node* ptr = head;
	while ((ptr != nullptr) && (ptr->getData() != code)){
		ptr = ptr->getNext();
	}
	return ptr;
}

Node* LinkedList::getHead(){
	return head;
}

void LinkedList::print(){
	Node* ptr = head;
	while (ptr != nullptr) {
		ptr->print();
		std::cout << " -> ";
		ptr = ptr->getNext();
	}
	std::cout << std::endl;
}

LinkedList::~LinkedList() {
	removeAll();
}

} /* namespace eda */

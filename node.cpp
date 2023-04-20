#include <iostream>
#include <iostream>

Node::Node() {

	int data;
	prev = NULL;
	next = NULL;
	
}

Node::~Node() {
	left = NULL;
	right = NULL;
}

Node* Node::getNext() {
	return next;
}

Node* Node::getPrev() {
	return prev;
}

Node* Node::getData() {
	return data;
}

void Node::setNext(Node* newNext) {
	next = newNext;
}
void Node::setPrev(Node* newPrev) {
	prev = newPrev;
}
void Node::setData(int newData) {
	data = newData;
}



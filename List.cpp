#include "List.h"

using namespace std;

List::List(){}

void List::append(Node node){
	if(root ==NULL){
		root = node;
	}
	else{
		Node *temp = root;
		while(temp->getNext() != NULL)
			temp->setNext(temp->getNext());
		temp->setNext(node);
	}
}

void List::removeFirst(){
	Node *temp;
	temp = root->getNext();
	delete root;
	root = temp;
}

List::~List(){
	Node *first=root;
	while(first->getNext() !=NULL)
		removeFirst();
	delete first;
}


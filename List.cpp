#include "List.h"

using namespace std;

List::List(){
  root = NULL;
  end = NULL;
}

void List::append(Node *node){
	if(root == NULL){
		root = node;
    end = node;
	}
	else{
    end->setNext(node);
    end = node;
	}
}

void List::removeFirst(){
	Node *temp;
	temp = root->getNext();
	delete root;
	root = temp;
}

Node* List::getRoot() {
  return root;
}

void List::setRoot(Node *rootIn) {
  root = rootIn;
}

List::~List(){
	Node *first=root;
	while(first->getNext() !=NULL)
		removeFirst();
	delete first;
}


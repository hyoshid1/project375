#include "List.h"

using namespace std;

//Constructors =======================================
List::List(){
  root = NULL;
  end = NULL;
}

//accessor ===========================================
Node* List::getRoot() {
  return root;
}

//mutators ===========================================
void List::setRoot(Node *rootIn) {
  root = rootIn;
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

//deconstructor ========================================
List::~List(){
	Node *first=root;
	while(first->getNext() !=NULL)
		removeFirst();
	delete first;
}


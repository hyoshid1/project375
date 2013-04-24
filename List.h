#ifndef LIST_H__
#define LIST_H__

#include "Node.h"

class List{
	private:
		Node *root;
    Node *end;
	
	public:
		List();
		void append(Node *node);
		void removeFirst();
    Node* getRoot();
    void setRoot(Node *rootIn);
		~List();
};

#endif //LIST_H__

#ifndef LIST_H__
#define LIST_H__

#include "Node.h"

class List{
	private:
		Node *root;
	
	public:
		List();
		void append(Node node);
		void removeFirst();
		~List();
};

#endif //LIST_H__

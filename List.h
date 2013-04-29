/*List used in radix Sort using buckets.
 *root and end pointers to initialize and append faster
 *accessor and mutator
 *append and remove first 
 */

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

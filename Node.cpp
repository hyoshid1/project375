#include "Node.h"

using namespace std;

//contructors =============================================
Node::Node() {
  data = 0;
  next = NULL;
}

Node::Node(BigUnsigned dataIn, Node *nextIn) {
  data = dataIn;
  next = nextIn;
}

//accessors ===============================================
BigUnsigned Node::getData() {
  return data;
}

Node* Node::getNext() {
  return next;
}

//mutators ===============================================
void Node::setData(BigUnsigned dataIn) {
  data = dataIn;
}

void Node::setNext(Node *nextIn) {
  next = nextIn;
}

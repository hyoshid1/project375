#include "Node.h"

using namespace std;

Node::Node() {
  data = 0;
  next = NULL;
}

Node::Node(BigUnsigned dataIn, Node *nextIn) {
  data = dataIn;
  next = nextIn;
}

BigUnsigned Node::getData() {
  return data;
}

Node* Node::getNext() {
  return next;
}

void Node::setData(BigUnsigned dataIn) {
  data = dataIn;
}

void Node::setNext(Node *nextIn) {
  next = nextIn;
}

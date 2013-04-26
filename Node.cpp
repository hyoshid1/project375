#include "Node.h"

using namespace std;

Node::Node() {
  data = 0;
  next = NULL;
}

Node::Node(BigInteger dataIn, Node *nextIn) {
  data = dataIn;
  next = nextIn;
}

BigInteger Node::getData() {
  return data;
}

Node* Node::getNext() {
  return next;
}

void Node::setData(BigInteger dataIn) {
  data = dataIn;
}

void Node::setNext(Node *nextIn) {
  next = nextIn;
}

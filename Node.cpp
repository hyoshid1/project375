#include "Node.h"

using namespace std;

Node::Node() {
  data = "";
  next = NULL;
}

Node::Node(string dataIn, Node *nextIn) {
  data = dataIn;
  next = nextIn;
}

string Node::getData() {
  return data;
}

Node* Node::getNext() {
  return next;
}

void Node::setData(string dataIn) {
  data = dataIn;
}

void Node::setNext(Node *nextIn) {
  next = nextIn;
}

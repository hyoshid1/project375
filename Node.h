#ifndef NODE_H
#define NODE_H
#include <string>
#include "BigIntegerLibrary.hh"

class Node {
  private:
    BigUnsigned data;
    Node *next;

  public:
    Node();
    Node(BigUnsigned dataIn, Node *nextIn);
    BigUnsigned getData();
    Node* getNext();
    void setData(BigUnsigned dataIn);
    void setNext(Node *nextIn);
};

#endif

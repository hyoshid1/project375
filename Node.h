#ifndef NODE_H
#define NODE_H
#include <string>
#include "BigIntegerLibrary.hh"

class Node {
  private:
    BigInteger data;
    Node *next;

  public:
    Node();
    Node(BigInteger dataIn, Node *nextIn);
    BigInteger getData();
    Node* getNext();
    void setData(BigInteger dataIn);
    void setNext(Node *nextIn);
};

#endif

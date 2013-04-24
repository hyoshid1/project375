#ifndef NODE_H
#define NODE_H
#include <string>

class Node {
  private:
    std::string data;
    Node *next;

  public:
    Node();
    Node(std::string dataIn, Node *nextIn);
    std::string getData();
    Node* getNext();
    void setData(std::string dataIn);
    void setNext(Node *nextIn);
};

#endif

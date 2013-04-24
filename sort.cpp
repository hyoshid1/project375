#include <iostream>
#include <sstream>
#include "List.h"
#include "Node.h"
#include "sort.h"

using namespace std;

void radixSort(string *array, int size, unsigned int maxLength) {
  int mod = 10, div = 1;
  List **adjList;
  for(unsigned int i; i < maxLength; i++) {
    adjList = new List*[10];
    for(int j = 0; j < 10; j++)
      adjList[j] = new List();
    popAdjList(adjList, array, size, mod, div);
    repopArray(adjList, array);

    delete []adjList;
    mod *= 10;
    div *= 10;
  }
}

void popAdjList(List **adjList, string *array, int size, int mod, int div) {
  int tempInt;
  stringstream ss;
  for(int i = 0; i < size; i++) {
    ss << array[i];
    ss >> tempInt;
    ss.str(""); ss.clear();
    
    adjList[(tempInt%mod)/div]->append(new Node(array[i], NULL));
  }
}

void repopArray(List **adjList, string *array) {
  Node *temp;
  int count = 0;
  for(int i = 0; i < 10; i++) {
    if(adjList[i]->getRoot() != NULL) {
      temp = adjList[i]->getRoot();
      while(temp != NULL) {
        array[count] = temp->getData();
        count++;
        temp = temp->getNext();
      }
    }
  }
}

void printArray(string *array, int size) {
  for(int i = 0; i < size; i++)
    cout << array[i] << endl;
}

#include <iostream>
#include <sstream>
#include <cmath>
#include "List.h"
#include "Node.h"
#include "sort.h"
#include "BigIntegerLibrary.hh"

using namespace std;

void radixSort(BigInteger *array, int size, string max, int maxLength) {

  long double bytes = calcBytes(max, maxLength);
  long double digits = ceil(bytes/(log(size)/log(2.0L)));
  long double r = ceil(bytes/digits);
  long k = pow(2.0, (double)r);
  cout << digits << " " << r << " " << k << endl;

  BigInteger mod = k;
  BigInteger div = 1;
  List **adjList;

  for(int i = 0; i <= digits; i++) {
    adjList = new List*[k];
    for(int j = 0; j < k; j++)
      adjList[j] = new List();
    popAdjList(adjList, array, size, mod, div);
    repopArray(adjList, array, k);

    delete []adjList;
    mod *= k;
    div *= k;
    cout << mod << " " << div << endl;
  }
}

void popAdjList(List **adjList, BigInteger *array, int size,
                BigInteger mod, BigInteger div) {
  BigInteger temp, empty;
  for(int i = 0; i < size; i++) {
    temp = array[i];
    temp.divideWithRemainder(mod, empty);
    adjList[(temp/div).toInt()]->append(new Node(array[i], NULL));
  }
}

void repopArray(List **adjList, BigInteger *array, int k) {
  Node *temp;
  int count = 0;
  for(int i = 0; i < k; i++) {
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

long double calcBytes(string max, int maxLength) {
  long double bytes = 0L, tempInt;
  int pos = maxLength-1;
  stringstream ss;
  for(int i = 1; i < maxLength/9 + 1; i++) {
    pos = (maxLength-1) - i*9;
    ss << max.substr(pos, 9);
    ss >> tempInt;
    ss.str(""); ss.clear();
    bytes += log(tempInt)/log(2.0L);
  }
  ss << max.substr(0, pos+1);
  ss >> tempInt;
  ss.str(""); ss.clear();
  bytes += log(tempInt)/log(2.0L);
  return ceil(bytes);
}

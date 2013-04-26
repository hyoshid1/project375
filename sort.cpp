#include <iostream>
#include <sstream>
#include <cmath>
#include "List.h"
#include "Node.h"
#include "sort.h"

using namespace std;

void radixSort(string *array, int size, string max, int maxLength) {

  int bytes = calcBytes(max, maxLength);
  int digits = ceil(bytes/(log(size)/log(2.0)));
  int r = ceil((double)bytes/digits);
  int k = pow(2.0, (double)r);
  cout << digits << " " << r << " " << k << endl;

  long double mod = k;
  long double div = 1;
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

void popAdjList(List **adjList, string *array, int size, int mod, int div) {
  long double temp;
  stringstream ss;
  for(int i = 0; i < size; i++) {
    ss << array[i];
    ss >> temp;
    ss.str(""); ss.clear();
    
    //adjList[(tempInt%mod)/div]->append(new Node(array[i], NULL));
    adjList[(int)(fmod(temp, mod))/div]->append(new Node(array[i], NULL));
  }
}

void repopArray(List **adjList, string *array, int k) {
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

int calcBytes(string max, int maxLength) {
  double bytes = 0, pos = maxLength-1, tempInt;
  stringstream ss;
  for(int i = 1; i < maxLength/9 + 1; i++) {
    pos = (maxLength-1) - i*9;
    ss << max.substr(pos, 9);
    ss >> tempInt;
    ss.str(""); ss.clear();
    bytes += log(tempInt)/log(2.0);
  }
  ss << max.substr(0, pos+1);
  ss >> tempInt;
  ss.str(""); ss.clear();
  bytes += log(tempInt)/log(2.0);
  return ceil(bytes);
}


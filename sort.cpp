#include "sort.h"

using namespace std;

void radixSort(BigUnsigned *array, int size, long k, int digits) {

  BigUnsigned mod = k, div = 1;

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
    //cout << mod << " " << div << endl;
  }
}

void popAdjList(List **adjList, BigUnsigned *array, int size,
                BigUnsigned mod, BigUnsigned div) {
  BigUnsigned temp, empty;
  for(int i = 0; i < size; i++) {
    temp = array[i];
    temp.divideWithRemainder(mod, empty);
    adjList[(temp/div).toInt()]->append(new Node(array[i], NULL));
  }
}

void repopArray(List **adjList, BigUnsigned *array, int k) {
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

void cRadixSort(vector<BigUnsigned> &vect, int size, long digits, int k) {
  BigUnsigned mod = k, div = 1, temp, empty;//, *sArray
  vector<BigUnsigned> sVect(size+1, 0);
  vector<int> oVect(k, 0);
  vector<int> dVect(size+1, 0);

  for(int i = 0; i <= digits; i++) {
    for(int j = 1; j <= size; j++) {
      temp = vect[j];
      temp.divideWithRemainder(mod, empty);
      dVect[j] = (temp/div).toInt();
    }

    for(int j = 0; j < k; j++) 
      oVect[j] = 0;

    for(int j = 1; j <= size; j++) 
      oVect[dVect[j]] = oVect[dVect[j]] + 1;

    for(int j = 1; j < k; j++)
      oVect[j] = oVect[j] + oVect[j-1];

    for(int j = size; j >= 1; j--) {
      int index = oVect[dVect[j]];
      sVect[index] = vect[j];
      oVect[dVect[j]] = oVect[dVect[j]]-1;
    }

    for(int j = 1; j <= size; j++)
      vect[j] = sVect[j];

  mod *= k;
  div *= k;
  }
}

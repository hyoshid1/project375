#include "sort.h"

using namespace std;

void radixSort(BigInteger *array, int size, long k, int digits) {

  BigInteger mod = k, div = 1;

  List **adjList;

//creates adjacency list and populates it
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

void popAdjList(List **adjList, BigInteger *array, int size,
                BigInteger mod, BigInteger div) {
  BigInteger temp, empty;
  for(int i = 0; i < size; i++) {
    temp = array[i];

//divideWithRemainder will divide temp by mod, 
//store the quotient in empty and set temp equal to the mod
    temp.divideWithRemainder(mod, empty);

//append number at the end of the list at temp/div 
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

int partition(BigInteger *array, int start, int size){
	BigInteger x = array[size];
	int i = start-1;
	for(int j = start; j<size; j++){
		if(array[j] > x){
			i++;
			BigInteger temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	BigInteger temp2 = array[i+1];
	array[i+1] = array[size];
	array[size] = temp2;
	return i+1;
}

void quickSort(BigInteger *array, int start, int size){
	if(start < size){
		int q = partition(array, start, size);
		quickSort(array, start, q-1);
		quickSort(array, q+1, size);
	}
}

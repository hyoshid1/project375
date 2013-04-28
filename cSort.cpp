#include "cSort.h"

void cRadixSort(BigInteger *array, int size, long digits, int k) {
  BigInteger mod = k, div = 1, *sArray, temp, empty;
  sArray = new BigInteger[size+1];
  long *dArray = new long[size+1];
  int *oArray = new int[k+1];

  
  for(int i = 0; i <= digits; i++) {
    for(int j = 0; j <= size; j++) {
      temp = array[j];
      temp.divideWithRemainder(mod, empty);
      dArray[j] = (temp/div).toInt();
    }
    for(int j = 0; j <= k; j++) {
      oArray[j] = 0;
    }
    for(int j = 1; j <= size; j++) {
      oArray[dArray[j]] = oArray[dArray[j]] + 1;
    }
    for(int j = 1; j <= k; j++) {
      oArray[j] = oArray[j] + oArray[j-1];
    }
    for(int j = size; j >= 1; j--) {
      sArray[oArray[dArray[j]]] = array[j];
      oArray[dArray[j] = oArray[dArray[j] - 1]];
    }
    for(int j = 0; j <= size; j++) {
      array[j] = sArray[j];
    }

  mod *= k;
  div *= k;
  }
  delete []sArray;
  delete []dArray;
  delete []oArray;
}

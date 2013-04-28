#include "cSort.h"

using namespace std;

void cRadixSort(BigInteger *array, int size, long digits, int k) {
  int *iArray = new int[size+1];
  for(int i = 0; i <= size; i++) {
    iArray[i] = array[i].toInt();
  }

  //BigInteger mod = 10, div = 1, *sArray, temp, empty;
  int mod = 10, div = 1, *sArray, temp, empty;

  //sArray = new BigInteger[size+1];
  sArray = new int[size+1];

  int *dArray = new int[size+1];
  int *oArray = new int[k];
  digits = 2;
  k = 10;

  for(int i = 0; i < digits; i++) {
    for(int j = 1; j <= size; j++) {
      //temp = array[j];
      temp = iArray[j];

      //temp.divideWithRemainder(mod, empty);
      temp %= mod;

      //dArray[j] = (temp/div).toInt();
      dArray[j] = temp/div;

      //cout << iArray[j] << " " << dArray[j] << endl;
    }
    cout << endl;
    for(int j = 0; j <= k; j++) {
      oArray[j] = 0;
    }
    for(int j = 1; j <= size; j++) {
      oArray[dArray[j]] = oArray[dArray[j]] + 1;
    }
    for(int j = 1; j < k; j++) {
      oArray[j] = oArray[j] + oArray[j-1];
    }

    /*
    for(int j = 0; j < k; j++) {
      cout << oArray[j] << endl;
    }
    cout << endl;
    */

    for(int j = size; j >= 1; j--) {
      int index = oArray[dArray[j]];

      //sArray[index] = array[j];
      sArray[index] = iArray[j];

      oArray[dArray[j]] = oArray[dArray[j]]-1;
      //cout << sArray[6] << endl;
    }
    cout << endl;
    for(int j = 1; j <= size; j++) {
      iArray[j] = sArray[j];
    }

  mod *= k;
  div *= k;
  }
  
  //delete []sArray;
  //delete []dArray;
  //delete []oArray;
  //delete []iArray;
}

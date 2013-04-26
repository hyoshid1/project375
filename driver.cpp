#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Node.h"
#include "List.h"
#include "sort.h"
#include "BigIntegerLibrary.hh"

using namespace std;

int main(int argc, const char **argv){
  if(argc != 3) {
    cout << "incorrect number of arguments" << endl;
    return 0;
  }
	ifstream in(argv[1]);
	ofstream out(argv[2]);
  stringstream ss;
	string line, *array, max, temp;
  int n = 0, count = 0;
  int maxLength=0;
  BigInteger maxNum(0), tempMax;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
      if((int)line.size() > maxLength) {
        maxLength = line.size();
      }
    }
  }

  array = new string[n];
  in.close(); in.open(argv[1]);

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      array[count] = line;
      count++;
    }
  }

  //find largest number
  for(int i = 0; i < n; i++) {
    if((int)array[i].size() == maxLength) {
      tempMax = stringToBigInteger(array[i]);
      if(tempMax > maxNum) {
        maxNum = tempMax;
        max = array[i];
      }
    }
  }

  radixSort(array, n, max, maxLength);
  for(int i = 0; i < n; i++)
    out << array[i] << endl;

	return 0;
}

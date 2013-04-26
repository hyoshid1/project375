#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <sys/time.h>
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
	string line, max, temp;
  int n = 0, count = 0;
  int maxLength=0;
  BigInteger maxNum(0), tempMax, *array;
  struct timeval start, finish;
  double totalTime;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
      if((int)line.size() > maxLength) {
        maxLength = line.size();
      }
      else if((int)line.size() == maxLength) {
        tempMax = stringToBigInteger(line);
        if(tempMax > maxNum) {
          maxNum = tempMax;
        }
      }
    }
  }
  max = bigIntegerToString(maxNum);

  array = new BigInteger[n];
  in.close(); in.open(argv[1]);

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      array[count] = stringToBigInteger(line);
      count++;
    }
  }

  cout << "start" << endl;
  gettimeofday(&start, NULL);
  radixSort(array, n, max, maxLength);
  gettimeofday(&finish, NULL);
  totalTime = (double)((double)(finish.tv_sec - start.tv_sec)); 
  cout << totalTime << endl;

  out << totalTime << endl;
  for(int i = 0; i < n; i++)
    out << array[i] << endl;

	return 0;
}

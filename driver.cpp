#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <vector>
#include <sys/time.h>
#include "Node.h"
#include "List.h"
#include "sort.h"
#include "BigIntegerLibrary.hh"

using namespace std;

int main(int argc, const char **argv){
//If incorrect number of commandline arguments
  if(argc != 3) {
    cout << "incorrect number of arguments" << endl;
    return 0;
  }
	ifstream in(argv[1]);
	ofstream out(argv[2]);
  stringstream ss;
	string line, max, temp;
  int n = 0, count = 1;
  int maxLength=0;
  BigUnsigned maxNum(0), tempMax;
  vector<BigUnsigned> vect; vect.push_back(0);
  struct timeval start, finish;
  double totalTime;

//While file is good to read
//Looping through file to find the max in the text file
  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
      if((int)line.size() > maxLength) {
        maxLength = line.size();
      }
      else if((int)line.size() == maxLength) {
        tempMax = stringToBigUnsigned(line);
        if(tempMax > maxNum) {
          maxNum = tempMax;
        }
      }
    }
  }

//Set max
  max = bigIntegerToString(maxNum);

  in.close(); in.open(argv[1]);

//Looping through input file to store all values
  while(in.good()) {
    getline(in, line);
    if(line != "") {
      vect.push_back(stringToBigUnsigned(line));
      count++;
    }
  }
  
//Calculate necessary params from radix sort
  long double bytes = calcBytes(max, maxLength);
  int digits = ceil(bytes/(log(n)/log(2.0L)));
  int r = ceil(bytes/digits);
  long k = pow(2.0, (double)r);

//Write time it took to sort an sorted numbers into output file
  cout << "start" << endl;
  
//Start Timer
  gettimeofday(&start, NULL);

//2 radix Sorts -> counting sort, bucket sort
  //cRadixSort(vect, n, digits, k);
  radixSort(vect, n, 12, 1000000000);
  radixSort(vect, n, digits, k);

//End Timer
  gettimeofday(&finish, NULL);

  totalTime = (double)((double)(finish.tv_sec - start.tv_sec)); 
//Write to output file
  out <<"Sor time: " << totalTime << "s" << endl;
  for(int i = 1; i <= n; i++)
    out << vect[i] << endl;

	return 0;
}

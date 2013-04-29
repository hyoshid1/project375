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

  int dArrayLength = 9;
  int dArray[9];
  long kArray[9];
  if(maxLength == 10 || maxLength == 20) {
    if(maxLength == 10) {
      dArray[0] = 10; dArray[1] = 5;
      dArray[2] = 4;  dArray[3] = 3;
      dArray[4] = 2;  dArray[5] = 2;
      dArray[6] = 2;  dArray[7] = 2;
    } 
    else {
      dArray[0] = 20; dArray[1] = 10;
      dArray[2] = 7;  dArray[3] = 5;
      dArray[4] = 4;  dArray[5] = 4;
      dArray[6] = 3;  dArray[7] = 3;
    }
    dArray[8] = digits;
    kArray[0] = 10; kArray[1] = 100;
    kArray[2] = 1000;  kArray[3] = 10000;
    kArray[4] = 100000;  kArray[5] = 1000000;
    kArray[6] = 10000000;  kArray[7] = 100000000;
    kArray[8] = k;
  }
  else if(maxLength == 100) {
    dArray[0] = 100; dArray[1] = 50;
    dArray[2] = 34;  dArray[3] = 25;
    dArray[4] = 20;  dArray[5] = 17;
    dArray[6] = 15;  dArray[7] = 13;
    dArray[8] = digits;
    kArray[0] = 10; kArray[1] = 100;
    kArray[2] = 1000;  kArray[3] = 10000;
    kArray[4] = 100000;  kArray[5] = 1000000;
    kArray[6] = 10000000;  kArray[7] = 100000000;
    kArray[8] = k;
  }
  else {
    dArray[0] = digits;
    kArray[0] = k;
    dArrayLength = 1;
  }

  for(int i = 0; i < dArrayLength; i++) {
    cout << "start " << i+1 << ": k = " << kArray[i] << endl;;
    out << "start " << i+1 << ": k = " << kArray[i] << endl;;
    gettimeofday(&start, NULL);
    cRadixSort(vect, n, dArray[i], kArray[i]);
    gettimeofday(&finish, NULL);
    totalTime = ((double)((double)(finish.tv_sec - start.tv_sec)) +
        ((double)(finish.tv_usec - start.tv_usec))/1000000);
    cout << "     " << totalTime << "s" << endl;
    out << "     " << totalTime << "s" << endl;
  }

  /*
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
    */

	return 0;
}

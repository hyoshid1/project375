#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Node.h"
#include "List.h"
#include "sort.h"

using namespace std;

int main(int argc, const char **argv){
  if(argc != 3) {
    cout << "incorrect number of arguments" << endl;
    return 0;
  }
	ifstream in(argv[1]);
	ofstream out(argv[2]);
  stringstream ss;
	string line, *array, max;
  int n = 0, count = 0, tempInt, maxInt = 0;
  int maxLength=0;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
      ss << line;
      ss >> tempInt;
      ss.str(""); ss.clear();
      if(tempInt > maxInt) {
        maxLength = line.size();
        max = line;
        maxInt = tempInt;
      }
     /*
      if((int)line.size() > maxLength) {
        maxLength = line.size();
        max = line;
      }
      */
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

  radixSort(array, n, max, maxLength);
  for(int i = 0; i < n; i++)
    out << array[i] << endl;

	return 0;
}

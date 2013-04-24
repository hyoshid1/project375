#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include "Node.h"
#include "List.h"

using namespace std;

int main(int argc, const char **argv){
  if(argc != 3) {
    cout << "incorrect number of arguments" << endl;
    return 0;
  }
	ifstream in(argv[1]);
	ofstream out(argv[2]);
  stringstream ss;
	string line;
  string *array;
  List **listArray;
  int n = 0, count = 0, tempInt;
  unsigned int maxLength=0;
  int mod = 10, div = 1;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
      if(line.size() > maxLength) maxLength = line.size();
    }
  }

  in.close();
  in.open(argv[1]);
  array = new string[n];

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      array[count] = line;
      count++;
    }
  }

  //populate adjacency list
  for(unsigned int j = 0; j < maxLength; j++) {
    listArray = new List*[10];
    for(int i = 0; i < 10; i++) {
      listArray[i] = new List();
    }

    count = 0;
    for(int i = 0; i < n; i++) {
      ss << array[i];
      ss >> tempInt;
      ss.str(""); ss.clear();

      listArray[(tempInt%mod)/div]->append(new Node(array[i], NULL));
    }

    //repopulate array of numbers
    for(int i = 0; i < 10; i++) {
      if(listArray[i]->getRoot() != NULL) {
        Node *temp = listArray[i]->getRoot();
        while(temp != NULL) {
          array[count] = temp->getData();
          //cout << temp->getData() << endl;
          count++;
          temp = temp->getNext();
        }
      }
    }
    delete []listArray;

    mod *= 10;
    div *= 10;
  }
  
  for(int i = 0; i < n; i++) {
    out << array[i] << endl;
  }

	return 0;
}

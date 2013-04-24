#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct node {
  string number;
  node *next;
};

struct list {
  node *root;
};

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
  list *listArray;
  int n = 0, count = 0, temp;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      n++;
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

  listArray = new list[10];
  for(int i = 0; i < 10; i++) {
    listArray[i].root = NULL;
  }
  for(int i = 0; i < n; i++) {
    ss << array[i];
    ss >> temp;
    ss.str(""); ss.clear();

    node *num;
    num->number = array[i];
    num->next = NULL;
    if(listArray[temp%10].root == NULL) {
      listArray[temp%10].root = num;
    }
    else {
      node *tempPtr = listArray[temp%10].root;
      while(tempPtr->next != NULL) {
        tempPtr = tempPtr->next;
      }
      tempPtr->next = num;
    }
  }
	return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

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
  vector< vector<short> > table;
  short number, count = 0;

  while(in.good()) {
    getline(in, line);
    if(line != "") {
      table.push_back(vector<short>());
      for(int i = 0; i < line.length(); i++) {
        ss << line[i];
        ss >> number;
        ss.str(""); ss.clear();
        
        table[count].push_back(number);
      }
      count++;
    }
  }

	return 0;
}

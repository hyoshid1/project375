#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
	ofstream out;
	int a,b,c,d,e;
	int max=0;
	string line;
	stringstream ss;
	out.open("50d_largeInput.txt");
	for(int i=0; i<500000; i++){
		a = rand();	b=rand();	c=rand();	d=rand(); e=rand();
		ss << a << b << c << d << e;
		ss >> line;
		if(max < line.size()) max = line.size();
		out << line << endl;
		ss.str("");
		ss.clear();
	}	
	out.close();
	cout << max << endl;
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

int main(){
	ofstream out;
	stringstream ss;
	string str;
	out.open("20d_largeInput.txt");
	int a, b, c, x, y, z;
	for(int i=0; i< 500000; i++){
		a= rand()%1000;
		b= rand()%100;
		x= rand();	
		y= rand()% 100000;
		c= rand();
		if(x<0) x*= -1;
		if(y<0) y*= -1;
		if(a<0) a*= -1;
		if(b<0) b*= -1;
		if(c<0) c*= -1;
		z=rand()%4;
		/*if(z>2)
			out << x << endl;
		else if(z<1)
			out << y << endl;
		else if(z ==1)
			out << a << endl;
		else
			out << b << endl;*/
		ss << x << c;
		ss >> str;
		out << str << endl;
		ss.str("");
		ss.clear();
	}
	out.close();
	return 0;
}

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
	out.open("100d_largeInput.txt");
	unsigned int a, b, c, x, y, z;
	int d, e, f, g, h;
	for(int i=0; i< 500000; i++){
		a= rand();
		b= rand();
		x= rand();	
		y= rand();
		c= rand();
		d= rand();
		e= rand();
		f= rand();
		g= rand();
		h= rand();
		if(x<0) x*= -1;
		if(y<0) y*= -1;
		if(a<0) a*= -1;
		if(b<0) b*= -1;
		if(c<0) c*= -1;
		z=rand();
		ss << x+z << c << a << b << y << d << e <<f <<g <<h;
		ss >> str;
		/*if(z==2)
			out << x << endl;
		else if(z==3)
			out << str << endl;
		else if(z==1)
			out << y << endl;
		else if(z ==0)
			out << a << endl;
		else
			out << b << endl;*/
		out << str << endl;
		ss.str("");
		ss.clear();
	}
	out.close();
	return 0;
}

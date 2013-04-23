#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(){
	ofstream out;
	out.open("10d_largeInput.txt");
	int a, b, x, y, z;
	for(int i=0; i< 500000; i++){
		a= rand()%1000;
		b= rand()%100;
		x= rand();	
		y= rand()% 100000;
		if(x<0) x*= -1;
		if(y<0) y*= -1;
		if(a<0) a*= -1;
		if(b<0) b*= -1;
		z=rand()%4;
		if(z>2)
			out << x << endl;
		else if(z<1)
			out << y << endl;
		else if(z ==1)
			out << a << endl;
		else
			out << b << endl;
	}
	out.close();
	return 0;
}

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream myfile;
	ofstream otherfile;
	myfile.open("paint.in");
	otherfile.open("paint.out");

	string s;
	getline(myfile,s);
	long loc=100000/2;
	int fence[100000];
	for(int i=0;i<100000;i++){
	fence[i]=0;}
	for(int i=0;i<s[0]-'0';i++){
		string t;
		getline(myfile,t);
		if(t[2]=='R'){
			for(int j=0;j<t[0]-'0';j++){
				loc++;
				fence[loc]++;
			}
		}
		else{
			for(int j=0;j<t[0]-'0';j++){
				loc--;
				fence[loc]++;
			}
		}
	}
	long two=0;
	for(long i=0;i<100000;i++){
		if(fence[i]>1){
		two++;
		}
	}
	otherfile << two;
}

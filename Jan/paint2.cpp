#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair{
long x;
long y;
	Pair(long x,long y)
	:x(x),y(y){}
};

int main(int argc, char *argv[])
{
	ifstream myfile;
	ofstream otherfile;
	myfile.open("paint.in");
	otherfile.open("paint.out");

	string s;
	getline(myfile,s);
	long loc = 0;
	long counter = 0;
	long start_loc = 0;
	char past = ' ';
	vector<Pair> pairs;

	for(int i=0;i<s[0]-'0';i++){
		string t;
		getline(myfile,t);
		loc += t[0] * t[2]=='R'?1:-1;

		if(!past==t[2]){
			long minnum = start_loc<loc?start_loc:loc;
			long maxnum = start_loc>loc?start_loc:loc;
			pairs.push_back(Pair(minnum,maxnum));
			start_loc=loc;
		}
	}
	sort(pairs,pairs.end());
	long start = pairs[0].x;
	long second_start;
	for(int i=1;i<s[0]-'0';i++){
		if(!(pairs[i].x>second_start.y)){
			second_start = pairs[i].x;
		}

	}
	long two=0;

	otherfile << two;
}

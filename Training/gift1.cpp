/*
ID:skinnersboxy
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int np;
    fin >> np;

    map<string, int> net;

    string people[np];

    for(int i=0;i<np;i++)
    {
    	fin >> people[i];
    }

    for(int i=0;i<np;i++)
    {
    	string name;
    	int money;
    	int people;
    	fin >> name >> money >> people;
    	if(people!=0)
    	{
    		net[name] -= money - money % people;

			for(int j=0;j<people;j++)
			{
				fin >> name;
				net[name] += money/people;
			}
    	}
    }

	for(int i=0;i<np;i++)
    {
    	fout << people[i] << " " << net[people[i]] << "\n";
    }

    return 0;
}

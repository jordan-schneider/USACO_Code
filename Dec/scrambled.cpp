#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char lowest(string s);
char highest(string s);

int main(int argc, char *argv[])
{
	ifstream myfile;
    myfile.open("scramble.in");

    ofstream anotherfile;
    anotherfile.open("scramble.out");


    string sizes;

    if(myfile.is_open())
    {
    	getline(myfile,sizes);
    }

    string names[sizes[0]-'0'];

	char lowestChar[sizes[0]-'0'];

    char highestChar[sizes[0]-'0'];

    for(int i = 0;i<sizes[0]-'0';i++)
    {
		getline(myfile,names[i]);
		lowestChar[i] = lowest(names[i]);
		highestChar[i] = highest(names[i]);
    }

    for(int i =0;i<sizes[0]-'0';i++)
    {
    	int potentialLowest = 1;
    	for(int j = 0;j<sizes[0]-'0';j++)
    	{
    		if(lowestChar[i]>highestChar[j]){
				potentialLowest++;
    		}
    	}
    	int potentialHighest = sizes[0]-'0';
    	for(int j = 0;j<sizes[0]-'0';j++)
    	{
    		if(highestChar[i]<lowestChar[j]){
				potentialHighest--;
    		}
    	}

    	if(anotherfile.is_open())
		{
			anotherfile << potentialLowest << " "<< potentialHighest <<endl;
		}

    }
}

char lowest(string s){
	char temp = 'z'+1;
	for(int i=0;i<s.size();i++){
		if (s[i]<temp){
		 temp = s[i];
		}
	}
	return temp;
}

char highest(string s){
	char temp='A'-1;
	for(int i=0;i<s.size();i++){
		if (s[i]>temp){
		 temp = s[i];
		}
	}
	return temp;
}

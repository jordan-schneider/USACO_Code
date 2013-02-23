#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream myfile;
    myfile.open("greetings.in");

    string sizes;

    if(myfile.is_open())
    {
    	getline(myfile,sizes);
    }

    int movMagB [sizes[0]-'0'];
    char movDirB [sizes[0]-'0'];

    for(int i=0;i<sizes[0]-'0';i++)
    {
    	string temp;
    	getline(myfile,temp);
    	movMagB[i] = temp[0]-'0';
    	//cout << movMagB[i] << endl;
    	movDirB[i] = temp[2];
    }

    int movMagE [sizes[2]-'0'];
    char movDirE [sizes[2]-'0'];

    for(int i=0;i<sizes[2]-'0';i++)
    {
    	string temp;
    	getline(myfile,temp);
    	movMagE[i] = temp[0]-'0';
    	movDirE[i] = temp[2];
    }

    int bLoc = 0;
    int eLoc = 0;
    bool metLast = true;
    int bCounter = 0;
    int eCounter = 0;
    int meetings = 0;
    int time = 0;

    while(bCounter != sizes[0]-'0' // counter starts at 0 and ends at the given max size
		 || eCounter != sizes[2]-'0'
		 || movMagB[bCounter] > 0 //if the prevoius counter = 0
		 || movMagE[eCounter] > 0)
    {
    	time++;

		if(bCounter < sizes[0]-'0'){ //if we have not maxed out our counter

			if(movMagB[bCounter]==0) //and if they are in the same spot
			{
				bCounter ++; //they have met
			}
			switch(movDirB[bCounter]) //is the cow moving left or right
			{
				case 'R':
					bLoc++;
					break;
				case 'L':
					bLoc--;
					break;
			}
				movMagB[bCounter]--; //subtract 1 from the value

		}

		if(eCounter < sizes[2]-'0'){
    	if(movMagE[eCounter]==0)
    	{
    		eCounter ++;
    	}
    	switch(movDirE[eCounter])
    	{
			case 'R':
				eLoc++;
				break;
			case 'L':
				eLoc--;
				break;
    	}
			movMagE[eCounter]--;
		}
		if(bLoc==eLoc)
		{
			if(!metLast)
			{
				meetings++;
				//cout << time << endl;
			}

			metLast = true;

		}
		else
		{
			metLast = false;
		}
			// << bLoc << " ";
			//cout << eLoc << " ";
			cout << bCounter << " ";
			cout << eCounter << " ";
			cout << sizes[0]-'0' << " ";
			cout << sizes[2]-'0' << " ";
			//cout << movMagB[bCounter] << " ";
			cout << time << endl;
			//system("PAUSE");

    }

    ofstream anotherfile;
    anotherfile.open("greetings.out");
    if(anotherfile.is_open())
    {
		anotherfile << (meetings);
    }
    anotherfile.close();

}

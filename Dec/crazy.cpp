#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int floodFill(int x,int y,char space[][51])
{
	int isCow=0;
	if(space[x][y]=='F')
	{
		return 0;
	}
	if(space[x][y]=='d')
	{
		cout << "TEST";
		return 0;

	}
	if(space[x][y]=='C')
	{
		isCow=1;

	}
	cout <<x << " " << y <<endl;
	system("PAUSE");
	space[x][y]=='d';

	return isCow + floodFill(x+1,y,space) + floodFill(x,y+1,space) + floodFill(x-1,y,space) + floodFill(x,y-1,space);

}

int main(int argc, char *argv[])
{
	ifstream myfile;
    myfile.open("crazy.in");

    ofstream anotherfile;
    anotherfile.open("crazy.out");

	string sizes;

	if(myfile.is_open())
	{
		getline(myfile,sizes);
	}

	//getting fence input
	int x1[sizes[0]-'0'];
	int x2[sizes[0]-'0'];
	int y1[sizes[0]-'0'];
	int y2[sizes[0]-'0'];

	for(int i=0;i<sizes[0]-'0';i++)
	{
		string data;
		getline(myfile,data);
		char temp[21];

		data.copy(temp,data.find(" "),0);
		x1[i] = atoi(temp);
		delete temp;
		data.copy(temp,data.size(),data.find(" "));;
		data = temp;
		delete temp;

		data.copy(temp,data.find(" "),0);
		y1[i] = atoi(temp);
		delete temp;
		data.copy(temp,data.size(),data.find(" "));
		data = temp;
		delete temp;

		data.copy(temp,data.find(" "),0);
		x2[i] = atoi(temp);
		delete temp;
		data.copy(temp,data.size(),data.find(" "));

		y2[i] = atoi(temp);

	}

	//getting cow input
	int cX[sizes[2]-'0'];
	int cY[sizes[2]-'0'];

	for(int i=0;i<sizes[2]-'0';i++)
	{
		string data;
		getline(myfile,data);
		char temp[21];

		data.copy(temp,data.find(" "),0);
		cX[i] = atoi(temp);
		delete temp;
		data.copy(temp,data.size(),data.find(" "));;

		cY[i] = atoi(temp);

	}


	//putting all cow and fence chars in place
	//F is a fence
	//C is a cow
	char space[51][51];


	for(int i=0;i<sizes[0]-'0';i++)
	{
		if(x2[i]-x1[i]==0)
		{
			for(int j=0;j<+y2[i]-y1[i];j++)
			{
				space[x1[i]+1][y1[i]+j+1]='F';
			}
		}
		else
		{
			for(int j=0;j<+x2[i]-x1[i];j++)
			{
				space[x1[i]+j+1][y1[i]+1]='F';
			}
		}
	}

	for(int i=0;i<sizes[2]-'0';i++)
	{
		space[cX[i]+1][cY[i]+1] = 'C';
	}

	for(int i=0;i<51;i++)
	{
		space[i][0] = 'F';
		space[0][i] = 'F';
		space[i][50] = 'F';
		space[50][i] = 'F';
	}

	//FLOOD SEARCH ALL THE COWS
	int max = 0;

	for(int i=0;i<sizes[2]-'0';i++) //for each cow
	{
		char tempSpace[51][51];

		for(int j=0;j<51*51;j++)
		{
			tempSpace[j/51][j%51] = space[j/51][j%51];
		}

		cout << space[49][38] << " " << space[48][38] << endl;
		int current = floodFill(cX[i]+1,cY[i]+1,tempSpace);

		if(max<current)
		{
			max=current;
		}
	}
	if(anotherfile.is_open())
    {
    anotherfile << max;
    }

}

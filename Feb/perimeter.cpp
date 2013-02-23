#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Bale
{
	int x;
	int y;
	Bale(int x,int y)
		:x(x),y(y){}
};

ifstream myfile;
vector<Bale> data;

int main(int argc, char *argv[])
{
	myfile.open("perimeter.in");

    ofstream anotherfile;
    anotherfile.open("perimeter.out");

	int num;
	myfile >> num;

	int min_x = 101;
	int min_y = 101;
	int max_x = 0;
	int max_y = 0;

	//get input + find min and max
	for(int i=0;i<num;i++)
	{
		int x=0;
		int y=0;
		myfile >> x;
		myfile >> y;

		if(x<min_x)
		{
			min_x = x;
		}
		if(x>max_x)
		{
			max_x = x;
		}
		if(y<min_y)
		{
			min_y = y;
		}
		if(y>max_y)
		{
			max_y = y;
		}

		data.push_back(Bale(x,y));
	}
	//dont make the array larger than need be
	bool farm[max_x-min_x+3][max_y-min_y+3];

	for(int i=0;i<max_x-min_x+3;i++)
	{
		for(int j=0;j<max_y-min_y+3;j++)
		{
			farm[i][j]=false;
		}
	}

	//fill in each bale
	for(int i=0;i<num;i++)
	{
		farm[data[i].x-min_x+1][data[i].y-min_y+1] = true;
	}

	//filling in holes
	for(int i=1;i<max_x-min_x+2;i++)
	{
		for(int j=1;j<max_y-min_y+2;j++)
		{
			if(farm[i+1][j])
			{
				if(farm[i-1][j])
				{
					if(farm[i][j+1])
					{
						if(farm[i][j-1])
						{
							farm[i][j] = true;
						}
					}
				}
			}
		}
	}

	int perimeter_val = 0;

	for(int i=0;i<num;i++)
	{
		//cout << farm[data[i].x+1][data[i].y] << " " << farm[data[i].x-1][data[i].y] << " " << farm[data[i].x][data[i].y+1] << " " << farm[data[i].x][data[i].y-1] << "\n";
		if(farm[data[i].x-min_x+2][data[i].y-min_y+1]==0)
		{
			perimeter_val = perimeter_val + 1;
		}
		if(farm[data[i].x-min_x][data[i].y-min_y+1]==0)
		{
			perimeter_val = perimeter_val + 1;
		}
		if(farm[data[i].x-min_x+1][data[i].y-min_y+2]==0)
		{
			perimeter_val = perimeter_val + 1;
		}
		if(farm[data[i].x-min_x+1][data[i].y-min_y]==0)
		{
			perimeter_val = perimeter_val + 1;
		}
	}

	anotherfile << perimeter_val;
}

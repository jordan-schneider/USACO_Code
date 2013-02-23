#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cow
{
	int loc;
	int dest;
	bool loopy;
	bool set;
	Cow(int loc,int dest, bool loopy, bool set)
		:loc(loc),dest(dest),loopy(loopy),set(set){}
};

ifstream myfile;
vector<Cow> data;
vector<Cow> marked;

int check(Cow c)
{
	if(c.loopy == false)
	{
		return 0;
	}

	if(c.dest == -1)
	{
		marked.push_back(c);
		return 1;
	}

	if(data[c.dest].loopy == false)
	{
		return 1;
	}

	if(data[c.dest].set==true&&data[c.dest].loopy==true)
	{
		return marked.size()*-1 - 10;
	}

	for(int i=0;i<marked.size();i++)
	{
		if(marked[i].loc==data[c.dest].loc)
		{
			return marked.size()*-1 -10;
		}
	}

	marked.push_back(c);

	return 1 + check(data[c.dest]);
}

int main(int argc, char *argv[])
{

	myfile.open("relay.in");

    ofstream anotherfile;
    anotherfile.open("relay.out");

    int num;
    myfile >> num;

    for(int i=0;i<num;i++)
    {
    	int dest;
    	myfile >> dest;
    	data.push_back(Cow(i,dest-1,true,false));
    }

    int counter = 0;

    	for(int i=0;i<data.size();i++)
		{
			int temp = check(data[i]);

			if(temp>0)
			{
				counter += temp;
				for(int j=0;j<marked.size();j++)
				{
					data[marked[j].loc].set = true;
					data[marked[j].loc].loopy = false;

				}
			}
			else if(temp != 0)
			{
				for(int j=0;j<marked.size();j++)
				{
					data[marked[j].loc].set = true;
					data[marked[j].loc].loopy = true;
				}
			}
			marked.clear();
		}

    anotherfile << counter;

}

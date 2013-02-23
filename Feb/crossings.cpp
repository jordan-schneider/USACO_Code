#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Cow
{
	signed int a;
	signed int b;
	bool safe;
	Cow(int a,int b,bool safe)
		:a(a),b(b),safe(safe){}
};


ifstream myfile;
vector<Cow> data;

void mark_unsafe(int i,int j)
{
	for(int k=i;k<=j;k++)
	{
		data[k].safe = false;
	}
}

bool comparison(Cow c, Cow d)
{
	return c.a<d.a;
}


int main(int argc, char *argv[])
{

	myfile.open("crossings.in");

    ofstream anotherfile;
    anotherfile.open("crossings.out");

	int num;
	myfile >> num;

	for(int i=0;i<num;i++)
	{
		int a,b;
		myfile >> a;
		myfile >> b;
		data.push_back(Cow(a,b,true));
	}

    sort(data.begin(),data.end(),&comparison);

    for(int i=1;i<num;i++) //looking at every cow to compare to
    {
    	for(int j=0;j<num;j++) //finding smallest cow
    	{
    		if(j==i){break;}
    		if(data[j].b>data[i].b)
    		{
				mark_unsafe(j,i);
				break;
    		}
    	}
    }

    int safe_cows=0;

    for(int i=0;i<num;i++)
    {
		if(data[i].safe)
		{
			safe_cows++;
		}
    }

    anotherfile << safe_cows;

}

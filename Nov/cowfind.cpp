#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream myfile;
    myfile.open("cowfind.in");
    string data;
    if(myfile.is_open())
    {
     getline(myfile,data);
    }
    myfile.close();
    bool pleft=false;
    bool cleft;
    string loc;
    if(data[0] == '(' )
    {
     pleft = true;
    }
    for(int i = 1;i<data.size();i++)
    {
            if(data[i]=='(')
            {
             cleft = true;
            }
            else
            {
             cleft = false;
            }
            if(cleft == pleft)
            {
              if(cleft)
              {
               loc = loc + 'l';
              }
              else
              {
               loc = loc + 'r';
              }
            }
            else{
            loc = loc + '0';
            }
            pleft = cleft;
    }
    int counter=0;
    for(int i=0;i<loc.size();i++)
    {
        if(loc[i]=='l')
        {
        for(int j=i+1;j<loc.size();j++)
        {
            if(loc[j] == 'r'){counter++;}
        }
        }
    }
    ofstream anotherfile;
    anotherfile.open("cowfind.out");
    if(anotherfile.is_open())
    {
    anotherfile << (counter);
    }
    anotherfile.close();
    return 0;
}
